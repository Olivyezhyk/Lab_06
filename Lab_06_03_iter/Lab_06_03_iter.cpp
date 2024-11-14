#include <iostream>
#include <iomanip>
#include <time.h>

void GenerateArray(int* a, int size);
void PrintArray(int* a, const int size);

template <typename T>
T FindSmallestOdd(const T a[], const int size);


int main() {
    const int size = 26;
    int a[size];

    GenerateArray(a, size);

    std::cout << "Original Array: ";
    std::cout << std::endl;
    PrintArray(a, size);
    std::cout << std::endl;

    int smallestOdd = FindSmallestOdd(a, size);
    std::cout << "Smallest odd number: " << smallestOdd << std::endl;

    return 0;
}

void GenerateArray(int* a, const int size) {
    int Low = -40;
    int High = 20;

    srand(time(0));

    for (int i = 0; i < size; i++) {
        a[i] = Low + rand() % (High - Low + 1);
    }
}

void PrintArray(int* a, const int size) {
    for (int i = 0; i < size; ++i) {
        std::cout << "(" << "a[" << (i) << "] = " << a[i] << ")" << " ";
    }
    std::cout << std::endl;
}

template <typename T>
T FindSmallestOdd(const T a[], const int size) {
    T smallestOdd = -1;
    for (int i = 0; i < size; ++i) {
        if (a[i] % 2 != 0) {
            if (smallestOdd == -1 || a[i] < smallestOdd) {
                smallestOdd = a[i];
            }
        }
    }
    return smallestOdd;
}
