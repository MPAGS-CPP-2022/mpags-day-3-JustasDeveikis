# - Build sub-script for the MPAGSCipher library unit tests

# Basic test
add_executable(testHello testHello.cpp)
add_test(NAME test-hello COMMAND testHello)
