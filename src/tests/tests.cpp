#include <gtest/gtest.h>

//#pragma comment(lib,"sin_shared_lib.lib")
//#include "sin.h"

#include <Windows.h>
#include <stdexcept>

typedef float(*function)(float x);

#include <cmath> 
#include <ctime>
#include<iostream>



TEST(SineTest, constTest) {
	HMODULE hm = LoadLibrary("sin_shared_lib.dll");
	if (hm == NULL)
	{
		throw std::runtime_error("Failed to load sin library");
	}
	else
	{
		function mySine = (function)GetProcAddress(hm, "mySine");
		if (mySine == NULL)
		{
			throw std::runtime_error("Failed to load sin function from sin library");
		}
		else
		{
			const float *ERR;
			(FARPROC &)ERR = GetProcAddress(hm, "ERR");
			if (ERR == NULL)
			{
				throw std::runtime_error("Failed to load sin library");
			}

			EXPECT_NEAR(sin(0), mySine(0), *ERR);
			EXPECT_NEAR(sin(0.5), mySine(0.5), *ERR);
			EXPECT_NEAR(sin(1.488), mySine(1.488), *ERR);
			EXPECT_NEAR(sin(10), mySine(10), *ERR);
			EXPECT_NEAR(sin(100), mySine(100), *ERR);
			EXPECT_NEAR(sin(-0.5), mySine(-0.5), *ERR);
			EXPECT_NEAR(sin(-1.488), mySine(-1.488), *ERR);
			EXPECT_NEAR(sin(-10), mySine(-10), *ERR);
			EXPECT_NEAR(sin(-100), mySine(-100), *ERR);

		}
	}
	FreeLibrary(hm);
}




int main(int argc, char* argv[])
{

    ::testing::InitGoogleTest(&argc, argv);

    return RUN_ALL_TESTS();
}