#include <iostream>
#include <iomanip>
#include <time.h>

void GenerateArray(int* a, int size);
void PrintArray(int* a, const int size);
int  FindMinIndex(int* a, int size);
int FindMaxIndex(int* a, int size);
double CalculateAverageIndex(int maxIndex, int minIndex);


int main(){

	const int size = 26;
	int a[size];

	GenerateArray(a, size);

	std::cout << "Original Array: ";
	std::cout << std::endl;
	PrintArray(a, size);
	std::cout << std::endl;

	int minIndex = FindMinIndex(a, size);
	std::cout << "a[" << minIndex << "] = " << a[minIndex];
	std::cout << std::endl;

	int maxIndex = FindMaxIndex(a, size);
	std::cout << "a[" << maxIndex << "] = " << a[maxIndex];
	std::cout << std::endl;

	double averageIndex = CalculateAverageIndex(maxIndex, minIndex);
	std::cout << "Average index = " << averageIndex << std::endl;

	return 0;
}

void GenerateArray(int* a, const int size)
{
	int Low = -40;
	int High = 20;

	srand(time(0));

	for (int i = 0; i < size; i++)
	{
		a[i] = Low + rand() % (High - Low + 1);
	}
}

void PrintArray(int* a, const int size)
{
	for (int i = 0; i < size; ++i) {
		std::cout << "(" << "a[" << (i) << "] = " << a[i] << ")" << " ";
	}
	std::cout << std::endl;
}

int  FindMaxIndex(int* a, int size) {
	if (size <= 0) {
		std::cerr << "No elements satisfying the condition" << std::endl;
		return -1;
	}

	int maxIndex = 0;
	int max = a[0];

	for (int i = 1; i < size; i++) {
		if (a[i] > max) {
			max = a[i];
			maxIndex = i;
		}
	}
	return maxIndex;
}

int  FindMinIndex(int* a, int size) {
	if (size <= 0) {
		std::cerr << "No elements satisfying the condition" << std::endl;
		return -1;
	}

	int minIndex = 0;
	int min = a[0];

	for (int i = 1; i < size; i++) {
		if (a[i] < min) {
			min = a[i];
			minIndex = i;
		}
	}
	return minIndex;
}

double CalculateAverageIndex(int maxIndex, int minIndex)
{
	return (static_cast<double>(maxIndex) + static_cast<double>(minIndex)) / 2.0;
}