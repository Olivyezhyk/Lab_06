#include <iostream>
#include <iomanip>
#include <time.h>

void GenerateArray(int* a, int size, int i);
void PrintArray(int* a, const int size, int i);
int CountFiltered(int* a, int size, int count, int i);
int SumFiltered(int* a, int size, int sum, int i);
void ReplaceFilteredWithZero(int* a, int size, int i);

int main(){

    const int size = 26;
    int array[size];

    GenerateArray(array, size, 0);

    std::cout << "Original Array: ";
    std::cout << std::endl;
    PrintArray(array, size, 0);
    std::cout << std::endl;

    int count = CountFiltered(array, size, 0, 0);
    int sum = SumFiltered(array, size, 0, 0);

    ReplaceFilteredWithZero(array, size, 0);

    std::cout << std::endl;
    std::cout << "Count (by criterion) = " << count << std::endl;
    std::cout << "Sum (by criterion) = " << sum << std::endl;
    std::cout << std::endl;

    std::cout << "Modified Array: ";
    std::cout << std::endl;
    PrintArray(array, size, 0);

    return 0;
}

void GenerateArray(int* a, int size, int i) {
    
int Low = -40;
    int High = 20;

    a[i] = Low + rand() % (High - Low + 1);
    if (i < size - 1) {
        GenerateArray(a, size, i + 1);
    }
}

void PrintArray(int* a, const int size, int i)
{
    std::cout << "(" << "a[" << (i) << "] = " << a[i] << ")" << " ";
    if (i < size - 1) {
    PrintArray(a, size, i + 1);
    }
}

int CountFiltered(int* a, int size, int count, int i) {
    if (i < size) {
        if (a[i] > 0 || i % 2 != 0) {
            count++;
        }
        return CountFiltered(a, size, count, i + 1);
    }
    return count;
}

int SumFiltered(int* a, int size, int sum, int i) {
    if (i < size) {
        if (a[i] > 0 || i % 2 != 0) {
            sum += a[i];
        }
        return SumFiltered(a, size, sum, i + 1);
    }
    return sum;
}

void ReplaceFilteredWithZero(int* a, int size, int i) {
    if (i < size) {
        if (!(a[i] > 0 || i % 2 != 0)) {
            a[i] = 0;
        }
        ReplaceFilteredWithZero(a, size, i + 1);
    }
}
