#include <iostream>
#include <random>
#include <iomanip>

using namespace std;

void GenerateArray(int array[], const int size, int index = 0);
void PrintArray(const int array[], const int size, int index = 0);
int FindSmallestOddRecursive(const int array[], int size, int index, int smallestOdd);

int main() {
    const int size = 26;
    int array[size];

    GenerateArray(array, size);

    cout << "Array: ";
    PrintArray(array, size);
    cout << endl;

    int smallestOddRecursive = FindSmallestOddRecursive(array, size, 0, -1);

    if (smallestOddRecursive != -1) {
        cout << "Smallest odd element (recursive) = " << smallestOddRecursive << endl;
    }
    else {
        cout << "Smallest odd element (recursive) = not found" << endl;
    }

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
        cout << endl;
        return;
    }

    cout << setw(3) << array[index] << " ";
    PrintArray(array, size, index + 1);
}

int FindSmallestOddRecursive(const int array[], int size, int index, int smallestOdd) {
    if (index >= size) {
        return smallestOdd;
    }

    if (array[index] % 2 != 0) {
        if (smallestOdd == -1 || array[index] < smallestOdd) {
            smallestOdd = array[index];
        }
    }

    return FindSmallestOddRecursive(array, size, index + 1, smallestOdd);
}
