#include <iostream>
#include <random>
#include <iomanip>

using namespace std;

template <typename T>
void GenerateArray(T array[], const int size, T Low, T High, int index = 0);

template <typename T>
void PrintArray(const T array[], const int size, int index = 0);

template <typename T>
T FindSmallestOddRecursive(const T array[], int size, int index, T smallestOdd);

int main() {
    const int size = 26;
    int array[size];

    GenerateArray(array, size, -40, 20);

    cout << "Array: [";
    PrintArray(array, size);
    cout << "]" << endl;

    int smallestOddRecursive = FindSmallestOddRecursive(array, size, 0, -1);

    if (smallestOddRecursive != -1) 
    {
        cout << "Smallest odd element (recursive) = " << smallestOddRecursive << endl;
    }
    else 
    {
        cout << "Smallest odd element (recursive) = not found" << endl;
    }

    return 0;
}

template <typename T>
void GenerateArray(T array[], const int size, T Low, T High, int index) 
{
    if (index >= size) 
    {
        return;
    }

    if (index == 0) 
    {
        srand(time(0));
    }

    array[index] = Low + rand() % (High - Low + 1);
    GenerateArray(array, size, Low, High, index + 1);
}

template <typename T>
void PrintArray(const T array[], const int size, int index) 
{
    if (index >= size) 
    {
        return;
    }

    cout << setw(3) << array[index] << " ";
    PrintArray(array, size, index + 1);
}

template <typename T>
T FindSmallestOddRecursive(const T array[], int size, int index, T smallestOdd) 
{
    if (index >= size) 
    {
        return smallestOdd;
    }

    if (array[index] % 2 != 0) {
        if (smallestOdd == -1 || array[index] < smallestOdd) 
        {
            smallestOdd = array[index];
        }
    }

    return FindSmallestOddRecursive(array, size, index + 1, smallestOdd);
}
