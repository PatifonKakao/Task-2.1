
#include "sin.h"

#define _USE_MATH_DEFINES
#include <math.h>
#include <stdexcept>


float myAbs(float a) {
	return a >= 0 ? a : -a;
}

float mySine(float x) {

	//Cast
	if (myAbs(x) > 2 * M_PI) {
		int wh_p = x / (2 * M_PI); 
		x -= wh_p * 2 * M_PI;
	}

	float currentResult = 0; 
	float currTerm = x; 
	unsigned int i = 1;

	do {
		currentResult += currTerm;
		currTerm *= (-1)*x*x / ((2 * i)*(2 * i + 1));
		i++;
		if (i >= std::numeric_limits<unsigned int>::max()) {
			throw std::runtime_error("Failed to calculate sin");
		}
	} while (myAbs(currTerm) > ERR);

	return currentResult;
}




