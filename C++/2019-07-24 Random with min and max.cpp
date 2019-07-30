#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

int main() {
	randValue = randBool(100.0,150.0);
	return 0;
}

float randBool(float min, float max) {
	float result = min + rand()%max;
	return result;
}