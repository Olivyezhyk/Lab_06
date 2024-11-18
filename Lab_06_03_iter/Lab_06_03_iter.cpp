#include <iostream>
#include <iomanip>
#include <time.h>

void GenerateArray(int* a, int size);
void PrintArray(int* a, const int size);
int FindSmallestOdd(const int* a, const int size);

template <typename T>
void GenerateArray_templates(T* a, int size);

template <typename T>
void PrintArray_templates(const T* a, const int size);

template <typename T>
T FindSmallestOdd_templates(const T* a, const int size);

int main() {
    const int size = 26;
    int a[size];

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
        std::cout << std::setw(4) << a[i];
    }
    std::cout << std::endl;
}

int FindSmallestOdd(const int* a, const int size) {
    bool hasOdd = false;
    int smallestOdd = -1;

    for (int i = 0; i < size; i++) {
        if (a[i] % 2 != 0) {
            hasOdd = true;
            smallestOdd = a[i];
            break;
        }
    }

    if (!hasOdd) {
        std::cout << "Немає непарних чисел у масиві." << std::endl;
        return -1;
    }

    for (int i = 0; i < size; i++) {
        if (a[i] % 2 != 0 && a[i] < smallestOdd) {
            smallestOdd = a[i];
        }
    }

    return smallestOdd;
}



template <typename T>
void GenerateArray_templates(T* a, const int size) {
    int Low = -40;
    int High = 21;

    srand(time(0));

    for (int i = 0; i < size; i++) {
        a[i] = Low + rand() % (High - Low + 1);
    }
}

template <typename T>
void PrintArray_templates(const T* a, const int size) {
    for (int i = 0; i < size; ++i) {
        std::cout << std::setw(4) << a[i];
    }
    std::cout << std::endl;
}

template <typename T>
T FindSmallestOdd_templates(const T* a, const int size) {
    bool hasOdd = false;
    T smallestOdd = -1;

    for (int i = 0; i < size; i++) {
        if (a[i] % 2 != 0) {
            hasOdd = true;
            smallestOdd = a[i];
            break;
        }
    }

    if (!hasOdd) {
        std::cout << "Немає непарних чисел у масиві." << std::endl;
        return static_cast<T>(-1);
    }

    for (int i = 0; i < size; i++) {
        if (a[i] % 2 != 0 && a[i] < smallestOdd) {
            smallestOdd = a[i];
        }
    }

    return smallestOdd;
}
