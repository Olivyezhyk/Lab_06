#include <iostream>
#include <iomanip>
#include <time.h>

void GenerateArray(int* a, int size, int i = 0);
void PrintArray(int* a, const int size, int i = 0);

template <typename T>
T FindSmallestOdd(const T a[], const int size, int i = 0, T smallestOdd = -1);

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

void GenerateArray(int* a, int size, int i) {
    int Low = -40;
    int High = 20;

    if (i == 0) {
        srand(time(0));
    }

    if (i < size) {
        a[i] = Low + rand() % (High - Low + 1);
        GenerateArray(a, size, i + 1);
    }
}

void PrintArray(int* a, const int size, int i) {
    if (i < size) {
        std::cout << "(" << "a[" << i << "] = " << a[i] << ")" << " ";
        PrintArray(a, size, i + 1);
    }
    else {
        std::cout << std::endl;
    }
}

template <typename T>
T FindSmallestOdd(const T a[], const int size, int i, T smallestOdd) {
    if (i >= size) 
        return smallestOdd;

    if (a[i] % 2 != 0) {
        if (smallestOdd == -1 || a[i] < smallestOdd) {
            smallestOdd = a[i];
        }
    }

    return FindSmallestOdd(a, size, i + 1, smallestOdd);
}
