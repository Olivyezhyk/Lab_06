#include <iostream>
#include <random>
#include <iomanip>

using namespace std;

void GenerateArray(int array[], const int size, int index = 0);
void PrintArray(const int array[], const int size, int index = 0);
int FindMaxIndexRecursive(const int array[], int size, int index = 0, int maxIndex = 0);
int FindMinIndexRecursive(const int array[], int size, int index = 0, int minIndex = 0);
double CalculateAverageIndexRecursive(int maxIndex, int minIndex, int sum = 0, int count = 2);

int main() {
    const int size = 26;
    int array[size];

    GenerateArray(array, size);

    cout << "Array: ";
    PrintArray(array, size);
    cout << endl;

    int maxIndex = FindMaxIndexRecursive(array, size);
    int minIndex = FindMinIndexRecursive(array, size);
    double averageIndex = CalculateAverageIndexRecursive(maxIndex, minIndex);

    cout << "Average index = " << averageIndex << endl;

    return 0;
}

void GenerateArray(int array[], const int size, int index) {
    int Low = -40;
    int High = 20;

    if (index >= size) {
        return;
    }

    if (index == 0) { 
        srand(time(0));
    }

    array[index] = Low + rand() % (High - Low + 1);
    GenerateArray(array, size, index + 1);
}

void PrintArray(const int array[], const int size, int index) {
    if (index >= size) {
        return;
    }

    cout << setw(3) << array[index] << " ";
    PrintArray(array, size, index + 1);
}

int FindMaxIndexRecursive(const int array[], int size, int index, int maxIndex) {
    if (index >= size) {
        return maxIndex;
    }
    if (array[index] > array[maxIndex]) {
        maxIndex = index;
    }
    return FindMaxIndexRecursive(array, size, index + 1, maxIndex);
}

int FindMinIndexRecursive(const int array[], int size, int index, int minIndex) {
    if (index >= size) {
        return minIndex;
    }
    if (array[index] < array[minIndex]) {
        minIndex = index;
    }
    return FindMinIndexRecursive(array, size, index + 1, minIndex);
}

double CalculateAverageIndexRecursive(int maxIndex, int minIndex, int sum, int count) {
    if (count == 0) {
        return sum / 2.0;
    }
    sum += (count == 2) ? maxIndex : minIndex;
    return CalculateAverageIndexRecursive(maxIndex, minIndex, sum, count - 1);
}
