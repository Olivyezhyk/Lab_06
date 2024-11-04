#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <ctime>
#include <cmath>

using namespace std;

void GenerateArray(double* array, int n)
{
    srand(static_cast<unsigned int>(time(0)));

    for (int i = 0; i < n; i++)
    {
        array[i] = (static_cast<double>(rand() % 6000) / 100.0) - 40.0;
    }
}


double findMaxAbsoluteElement(const double* array, int n)
{
    double maxElement = array[0];
    for (int i = 1; i < n; i++)
    {
        if (abs(array[i]) > abs(maxElement))
        {
            maxElement = array[i];
        }
    }
    return maxElement;
}

double sumBetweenFirstTwoPositives(const double* array, int n)
{
    int firstPositive = -1, secondPositive = -1;
    double sum = 0;

    for (int i = 0; i < n; i++)
    {
        if (array[i] > 0)
        {
            if (firstPositive == -1)
            {
                firstPositive = i;
            }
            else
            {
                secondPositive = i;
                break;
            }
        }
    }

    if (firstPositive != -1 && secondPositive != -1)
    {
        for (int i = firstPositive + 1; i < secondPositive; i++)
        {
            sum += array[i];
        }
    }
    return sum;
}

void moveZerosToEnd(double* array, int n)
{
    int j = 0;
    for (int i = 0; i < n; i++)
    {
        if (array[i] != 0)
        {
            array[j++] = array[i];
        }
    }
    while (j < n)
    {
        array[j++] = 0;
    }
}

int main()
{
    srand(time(0));

    int n;
    cout << "Enter the number of elements in the array: ";
    cin >> n;

    double* array = new double[n];
    GenerateArray(array, n);

    cout << "Original Array: ";
    for (int i = 0; i < n; i++)
    {
        cout << "(" << "A[" << (i) << "] = " << array[i] << ")" << " ";
    }
    cout << "" << endl;

    double maxAbsolute = findMaxAbsoluteElement(array, n);
    cout << "Maximum absolute element: " << maxAbsolute << endl;

    double sumBetweenPositives = sumBetweenFirstTwoPositives(array, n);
    cout << "Sum of elements between the first and second positive elements: " << sumBetweenPositives << endl;

    moveZerosToEnd(array, n);

    cout << "Modified Array: ";
    for (int i = 0; i < n; i++) {
        cout << "(" << "A[" << (i) << "] = " << array[i] << ")" << " ";
    }
    cout << "" << endl;

    delete[] array;
    return 0;
}