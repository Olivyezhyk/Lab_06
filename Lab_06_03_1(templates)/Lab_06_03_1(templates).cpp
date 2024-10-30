#include <iostream>
#include <random>
#include <iomanip>

using namespace std;

template <typename T>
void GenerateArray(T array[], const int size, T Low, T High);

template <typename T>
void PrintArray(const T array[], const int size);

template <typename T>
T FindSmallestOddIterative(const T array[], const int size);

int main() {
    const int size = 26;
    int array[size];

    GenerateArray(array, size, -40, 20);

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

template <typename T>
void GenerateArray(T array[], const int size, T Low, T High) {
    srand(time(0));
    for (int i = 0; i < size; i++) {
        array[i] = Low + rand() % (High - Low + 1);
    }
}

template <typename T>
void PrintArray(const T array[], const int size) {
    for (int i = 0; i < size; ++i) {
        cout << setw(3) << array[i] << " ";
    }
    cout << endl;
}

template <typename T>
T FindSmallestOddIterative(const T array[], const int size) {
    T smallestOdd = -1;
    for (int i = 0; i < size; ++i) {
        if (array[i] % 2 != 0) {
            if (smallestOdd == -1 || array[i] < smallestOdd) {
                smallestOdd = array[i];
            }
        }
    }
    return smallestOdd;
}
