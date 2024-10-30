#include <iostream>
#include <random>
#include <iomanip>

using namespace std;

void GenerateArray(int array[], const int size);
void PrintArray(const int array[], const int size);
int CountFiltered(const int array[], int size, int index = 0);
int SumFiltered(const int array[], int size, int index = 0);
void ReplaceFilteredWithZero(int array[], int size, int index = 0);

int main() {
    const int size = 26;
    int array[size];

    GenerateArray(array, size);

    cout << "Original Array: ";
    PrintArray(array, size);
    cout << endl;

    int count = CountFiltered(array, size);
    int sum = SumFiltered(array, size);

    ReplaceFilteredWithZero(array, size);

    cout << "Count (by criterion) = " << count << endl;
    cout << "Sum (by criterion) = " << sum << endl;

    cout << "Modified Array: ";
    PrintArray(array, size);
    cout << endl;

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

int CountFiltered(const int array[], int size, int index) {
    if (index >= size) {
        return 0;
    }
    int count = ((array[index] < 0 && index % 2 == 0) ? 1 : 0);
    return count + CountFiltered(array, size, index + 1);
}

int SumFiltered(const int array[], int size, int index) {
    if (index >= size) {
        return 0;
    }
    int sum = ((array[index] < 0 && index % 2 == 0) ? array[index] : 0);
    return sum + SumFiltered(array, size, index + 1);
}

void ReplaceFilteredWithZero(int array[], int size, int index) {
    if (index >= size) {
        return;
    }
    if (array[index] < 0 && index % 2 == 0) {
        array[index] = 0;
    }
    ReplaceFilteredWithZero(array, size, index + 1);
}