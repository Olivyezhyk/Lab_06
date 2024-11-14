#include <iostream>
#include <random>
#include <iomanip>

void GenerateArray(int* a, int size);
void PrintArray(int* a, int size);
int CountFiltered(int* a, int size);
int SumFiltered(int* a, int size);
void ReplaceFilteredWithZero(int* a, int size);

int main() {
    const int size = 26;
    int a[size];

    GenerateArray(a, size);

    std::cout << "Original Array: ";
    std::cout << std::endl;
    PrintArray(a, size);

    int count = CountFiltered(a, size);
    int sum = SumFiltered(a, size);

    ReplaceFilteredWithZero(a, size);

    std::cout << std::endl;
    std::cout << "Count (by criterion) = " << count << std::endl;
    std::cout << "Sum (by criterion) = " << sum << std::endl;
    std::cout << std::endl;

    std::cout << "Modified Array: ";
    std::cout << std::endl;
    PrintArray(a, size);

    return 0;
}

void GenerateArray(int* a, const int size)
{
    int Low = -40;
    int High = 20;

    srand(time(0));

    for (int i = 0; i < size; i++)
    {
        a[i] = Low + rand() % (High - Low + 1);
    }
}

void PrintArray(int* a, const int size)
{
    for (int i = 0; i < size; ++i){
        std::cout << "(" << "a[" << (i) << "] = " << a[i] << ")" << " ";
    }
    std::cout << std::endl;
}

int CountFiltered(int* a, int size) {
    int count = 0;
    for (int i = 0; i < size; i++) {
        if (a[i] > 0 || i % 2 != 0)
        {
            count++;
        }
    }
    return count;
}

int SumFiltered(int* a, int size)
{
    int sum = 0;
    for (int i = 0; i < size; i++) {
        if (a[i] > 0 || i % 2 != 0) {
            sum += a[i];
        }
    }
    return sum;
}

void ReplaceFilteredWithZero(int* a, int size)
{
    for (int i = 0; i < size; i++) {
        if (!(a[i] > 0 || i % 2 != 0)) {
            a[i] = 0;
        }
    }
}



