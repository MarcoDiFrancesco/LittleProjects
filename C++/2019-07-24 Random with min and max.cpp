#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

int randInt(int,int);
int calculateAverage(int[]);

int main() {
	int numbers[1000];
	
	int average = calculateAverage(numbers);

	cout << average;
	return 0;
}

int randInt(int min, int max) {
	srand(time(NULL));
	int result = min + rand()%(max-min);
	return result;
}

int calculateAverage(int numbers[1000]) {
	int sum = 0;

	// fill array with random numbers
	for(int i = 0; i < 1000; i++) {
		int randomNumber = randInt(100,200);
		cout << randomNumber << endl;
		numbers[i] = randomNumber;
		sum += randomNumber;
	}
	int average = sum / 1000;
	return average;
}