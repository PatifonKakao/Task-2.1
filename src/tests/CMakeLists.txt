# задаем набор исходников
set(SOURCES
    tests.cpp
)

# создаем исполняемый файл
add_executable(test_shared_lib ${SOURCES})

# подключаем библиотеки:
# 1. Тестируемая библиотека
# 2. gest
target_link_libraries(test_shared_lib PUBLIC sin_shared_lib)
target_link_libraries(test_shared_lib PUBLIC gtest_main)

# В solution эта библиотека лежит в tests/test_shared_lib
set_property(TARGET test_shared_lib PROPERTY FOLDER "tests/test_shared_lib")