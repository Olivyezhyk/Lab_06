#include <iostream>
#include <random>
#include <iomanip>

using namespace std;

void GenerateArray(int array[], const int size);
void PrintArray(const int array[], const int size);
int FindMaxIndexRecursive(const int array[], int size, int index = 0, int maxIndex = 0);
int FindMinIndexRecursive(const int array[], int size, int index = 0, int minIndex = 0);
double CalculateAverageIndex(int maxIndex, int minIndex);

int main() {
    const int size = 26;
    int array[size];

    GenerateArray(array, size);

    cout << "Array: ";
    PrintArray(array, size);
    cout << endl;

    int maxIndex = FindMaxIndexRecursive(array, size);
    int minIndex = FindMinIndexRecursive(array, size);
    double averageIndex = CalculateAverageIndex(maxIndex, minIndex);

    cout << "Average index = " << averageIndex << endl;

    return 0;
}

void GenerateArray(int array[], const int size) {
    int Low = -40;
    int High = 20;

    srand(time(0));

    for (int i = 0; i < size; i++) {
        array[i] = Low + rand() % (High - Low + 1);
    }
}

void PrintArray(const int array[], const int size) {
    for (int i = 0; i < size; ++i) {
        cout << setw(3) << array[i] << " ";
    }
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

double CalculateAverageIndex(int maxIndex, int minIndex) {
    return (maxIndex + minIndex) / 2.0;
}
