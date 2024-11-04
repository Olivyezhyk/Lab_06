#include <iostream>
#include <random>
#include <iomanip>

using namespace std;

void GenerateArray(int array[], const int size);
void PrintArray(const int array[], const int size);
int FindMaxIndex(const int array[], const int size);
int FindMinIndex(const int array[], const int size);
double CalculateAverageIndex(int maxIndex, int minIndex);

int main() {
    const int size = 26;
    int array[size];

    GenerateArray(array, size);

    cout << "Array: ";
    PrintArray(array, size);

    int maxIndex = FindMaxIndex(array, size);
    int minIndex = FindMinIndex(array, size);
    double averageIndex = CalculateAverageIndex(maxIndex, minIndex);

    cout << "Average index = " << averageIndex << endl;

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

int FindMaxIndex(const int array[], const int size)
{
    int maxIndex = 0;
    for (int i = 1; i < size; ++i)
    {
        if (array[i] > array[maxIndex])
        {
            maxIndex = i;
        }
    }
    return maxIndex;
}

int FindMinIndex(const int array[], const int size)
{
    int minIndex = 0;
    for (int i = 1; i < size; ++i)
    {
        if (array[i] < array[minIndex])
        {
            minIndex = i;
        }
    }
    return minIndex;
}

double CalculateAverageIndex(int maxIndex, int minIndex)
{
    return (static_cast<double>(maxIndex) + static_cast<double>(minIndex)) / 2.0;
}
