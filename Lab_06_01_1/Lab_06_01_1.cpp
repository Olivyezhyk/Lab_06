#include <iostream>
#include <random>
#include <iomanip>

using namespace std;

void GenerateArray(int array[], const int size);
void PrintArray(const int array[], const int size);
int CountFiltered(const int array[], const int size);
int SumFiltered(const int array[], const int size);
void ReplaceFilteredWithZero(int array[], const int size);

int main()
{
    const int size = 26;
    int array[size];

    GenerateArray(array, size);

    cout << "Original Array: ";
    cout << "" << endl;
    PrintArray(array, size);

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

void GenerateArray(int array[], const int size)
{
    int Low = -40;
    int High = 20;

    srand(time(0));

    for (int i = 0; i < size; i++)
    {
        array[i] = Low + rand() % (High - Low + 1);
    }
}

void PrintArray(const int array[], const int size)
{
    for (int i = 0; i < size; ++i)
    {
        cout << "(" << "A[" << (i) << "] = " << array[i] << ")" << " ";
    }
    cout << "" << endl;
}

int CountFiltered(const int array[], const int size)
{
    int count = 0;
    for (int i = 0; i < size; ++i)
    {
        if (array[i] > 0 || i % 2 != 0)
        {
            continue;
        }
        count++;
    }
    return count;
}

int SumFiltered(const int array[], const int size)
{
    int sum = 0;
    for (int i = 0; i < size; ++i) 
    {
        if (array[i] > 0 || i % 2 != 0)
        {
            continue;
        }
        sum += array[i];
    }
    return sum;
}

void ReplaceFilteredWithZero(int array[], const int size)
{
    for (int i = 0; i < size; ++i)
    {
        if (array[i] > 0 || i % 2 != 0)
        {
            continue;
        }
        array[i] = 0;
    }
}