#include <iostream>
#include <iomanip>
#include <time.h>

void GenerateArray(int* a, int size, int i = 0);
void PrintArray(int* a, const int size, int i = 0);
int FindSmallestOdd(const int* a, const int size, int i = 0, bool foundOdd = false, int smallestOdd = -1);

template <typename T>
void GenerateArray_templates(T* a, int size, int i = 0);

template <typename T>
void PrintArray_templates(const T* a, const int size, int i = 0);

template <typename T>
T FindSmallestOdd_templates(const T* a, const int size, int i = 0, bool foundOdd = false, T smallestOdd = -1);

int main() {
    const int size = 26;
    int a[size];

    srand(time(0));

    GenerateArray(a, size);

    std::cout << "Original Array: ";
    std::cout << std::endl;
    PrintArray(a, size);

    int smallestOdd = FindSmallestOdd(a, size);
    std::cout << "Smallest odd number: " << smallestOdd << std::endl;
    std::cout << std::endl;

    GenerateArray_templates(a, size);

    std::cout << "Original Array: ";
    std::cout << std::endl;
    PrintArray_templates(a, size);

    int smallestOdd_templates = FindSmallestOdd_templates(a, size);
    std::cout << "Smallest odd number: " << smallestOdd_templates << std::endl;
    return 0;
}

void GenerateArray(int* a, const int size, int i) {
    if (i == size) {
        return;
    }

    int Low = -40;
    int High = 20;

    a[i] = Low + rand() % (High - Low + 1);

    GenerateArray(a, size, i + 1);
}

void PrintArray(int* a, const int size, int i) {
    if (i == size) {
        std::cout << std::endl;
        return;
    }

    std::cout << std::setw(4) << a[i];

    PrintArray(a, size, i + 1);
}

int FindSmallestOdd(const int* a, const int size, int i, bool foundOdd, int smallestOdd) {
    if (i == size) {
        if (!foundOdd) {
            std::cout << "Немає непарних чисел у масиві." << std::endl;
        }
        return smallestOdd;
    }

    if (a[i] % 2 != 0) {
        if (!foundOdd || a[i] < smallestOdd) {
            smallestOdd = a[i];
            foundOdd = true;
        }
    }

    return FindSmallestOdd(a, size, i + 1, foundOdd, smallestOdd);
}

template <typename T>
void GenerateArray_templates(T* a, int size, int i) {
    if (i == size) {
        return;
    }

    int Low = -40;
    int High = 21;

    a[i] = Low + rand() % (High - Low + 1);

    GenerateArray_templates(a, size, i + 1);
}

template <typename T>
void PrintArray_templates(const T* a, const int size, int i) {
    if (i == size) {
        std::cout << std::endl;
        return;
    }

    std::cout << std::setw(4) << a[i];

    PrintArray_templates(a, size, i + 1);
}

template <typename T>
T FindSmallestOdd_templates(const T* a, const int size, int i, bool foundOdd, T smallestOdd) {
    if (i == size) {
        if (!foundOdd) {
            std::cout << "Немає непарних чисел у масиві." << std::endl;
        }
        return smallestOdd;
    }

    if (a[i] % 2 != 0) {
        if (!foundOdd || a[i] < smallestOdd) {
            smallestOdd = a[i];
            foundOdd = true;
        }
    }

    return FindSmallestOdd_templates(a, size, i + 1, foundOdd, smallestOdd);
}
