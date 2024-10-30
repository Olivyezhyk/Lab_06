#include <iostream>
#include <random>
#include <iomanip>

using namespace std;

void GenerateArray(int array[], const int size);
void PrintArray(const int array[], const int size);
int FindSmallestOddIterative(const int array[], const int size);

int main() {
    const int size = 26;
    int array[size];

    GenerateArray(array, size);

    cout << "Array: ";
    PrintArray(array, size);
    cout << endl;

    int smallestOddIterative = FindSmallestOddIterative(array, size);

    if (smallestOddIterative != -1) {
        cout << "Smallest odd element (iterative) = " << smallestOddIterative << endl;
    }
    else {
        cout << "Smallest odd element (iterative) = not found" << endl;
    }

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
    cout << endl;
}

int FindSmallestOddIterative(const int array[], const int size) {
    int smallestOdd = -1;
    for (int i = 0; i < size; ++i) {
        if (array[i] % 2 != 0) {
            if (smallestOdd == -1 || array[i] < smallestOdd) {
                smallestOdd = array[i];
            }
        }
    }
    return smallestOdd;
}
