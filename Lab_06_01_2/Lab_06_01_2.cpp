#include <iostream>
#include <random>
#include <iomanip>

using namespace std;

void GenerateArray(int array[], const int size, int index = 0);
void PrintArray(const int array[], const int size, int index = 0);
int CountFiltered(const int array[], int size, int index = 0);
int SumFiltered(const int array[], int size, int index = 0);
void ReplaceFilteredWithZero(int array[], int size, int index = 0);

int main()
{
    const int size = 26;
    int array[size];

    GenerateArray(array, size);

    cout << "Original Array: ";
    cout << "" << endl;
    PrintArray(array, size);
    cout << "" << endl;

    int count = CountFiltered(array, size);
    int sum = SumFiltered(array, size);

    ReplaceFilteredWithZero(array, size);

    cout << "Count (by criterion) = " << count << endl;
    cout << "Sum (by criterion) = " << sum << endl;

    cout << "Modified Array: ";
    cout << "" << endl;
    PrintArray(array, size);

    return 0;
}

void GenerateArray(int array[], const int size, int index)
{
    int Low = -40;
    int High = 20;

    if (index >= size) 
    {
        return;
    }

    if (index == 0) {
        srand(time(0));
    }

    array[index] = Low + rand() % (High - Low + 1);
    GenerateArray(array, size, index + 1);
}

void PrintArray(const int array[], const int size, int index)
{
    if (index >= size)
    {
        return;
    }

    cout << "(" << "A[" << (index) << "] = " << array[index] << ")" << " ";
    PrintArray(array, size, index + 1);
}

int CountFiltered(const int array[], int size, int index)
{
    if (index >= size)
    {
        return 0;
    }
    int count = 0;
    if (array[index] < 0 && index % 2 == 0)
    {
        count = 1;
    }
    return count + CountFiltered(array, size, index + 1);
}

int SumFiltered(const int array[], int size, int index)
{
    if (index >= size)
    {
        return 0;
    }

    int sum = 0;
    if (array[index] < 0 && index % 2 == 0)
    {
        sum = array[index];
    }

    return sum + SumFiltered(array, size, index + 1);
}

void ReplaceFilteredWithZero(int array[], int size, int index)
{
    if (index >= size) 
    {
        return;
    }
    if (array[index] < 0 && index % 2 == 0)
    {
        array[index] = 0;
    }
    ReplaceFilteredWithZero(array, size, index + 1);
}