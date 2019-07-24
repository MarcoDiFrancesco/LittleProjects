#include <iostream>
#include <cstdlib>

using namespace std;

int main()
{
	int a[10] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};

	for (int i = 0; i < 10; i++)
	{
		cout << a[i];
	}
	int reverse[10];
	for (int i = 0; i < 10; i++)
	{
		reverse[9 - i] = a[i];
	}
	cout << "\n";
	for (int i = 0; i < 10; i++)
	{
		cout << reverse[i];
	}
}