#include <iostream>
#include <iomanip>
#include <cmath>
#include <ctime>

void GenerateArray(double* a, int n, int i = 0);
void PrintArray(double* a, int n, int i = 0);
double findMaxAbsoluteElement(const double* a, int n, int i = 0, double maxElement = -1.0);
double sumBetweenFirstTwoPositives(const double* a, int n, int i = 0, int firstPositive = -1, int secondPositive = -1, double sum = 0);
void moveZerosToEnd(double* a, int n, int i = 0, int j = 0);

int main()
{
    srand(static_cast<unsigned>(time(0)));

    int n;
    std::cout << "Enter the number of elements in the array: "; std::cin >> n;

    double* a = new double[n];
    GenerateArray(a, n);

    std::cout << "Original Array: " << std::endl;
    PrintArray(a, n);
    std::cout << std::endl;

    double maxAbsolute = findMaxAbsoluteElement(a, n);
    std::cout << "Maximum absolute element: " << maxAbsolute << std::endl;

    double sumBetweenPositives = sumBetweenFirstTwoPositives(a, n);
    std::cout << "Sum of elements between the first and second positive elements: " << sumBetweenPositives << std::endl;
    std::cout << std::endl;

    moveZerosToEnd(a, n);

    std::cout << "Modified Array: " << std::endl;
    PrintArray(a, n);
    std::cout << std::endl;

    delete[] a;
    return 0;
}

void GenerateArray(double* a, int n, int i)
{
    double Low = -40.0;
    double High = 20.0;

    if (i < n) {
        a[i] = Low + (rand() / (RAND_MAX + 1.0)) * (High - Low);
        a[i] = round(a[i] * 10.0) / 10.0;
        GenerateArray(a, n, i + 1);
    }
}

void PrintArray(double* a, int n, int i)
{
    if (i < n) {
        std::cout << std::fixed << std::setprecision(1) << "(" << "a[" << i << "] = " << a[i] << ") ";
        PrintArray(a, n, i + 1);
    }
    else {
        std::cout << std::endl;
    }
}

double findMaxAbsoluteElement(const double* a, int n, int i, double maxElement)
{
    if (i == 0) {
        maxElement = a[0];
    }
    if (i < n) {
        if (std::abs(a[i]) > std::abs(maxElement)) {
            maxElement = a[i];
        }
        return findMaxAbsoluteElement(a, n, i + 1, maxElement);
    }
    return maxElement;
}

double sumBetweenFirstTwoPositives(const double* a, int n, int i, int firstPositive, int secondPositive, double sum)
{
    if (i >= n) {
        return sum;
    }

    if (firstPositive == -1 && a[i] > 0) {
        firstPositive = i;
    }
    else if (firstPositive != -1 && secondPositive == -1 && a[i] > 0) {
        secondPositive = i;
    }
    else if (firstPositive != -1 && secondPositive == -1) {
        sum += a[i];
    }

    if (secondPositive != -1) {
        return sum;
    }
    return sumBetweenFirstTwoPositives(a, n, i + 1, firstPositive, secondPositive, sum);
}

void moveZerosToEnd(double* a, int n, int i, int j)
{
    if (i >= n) {
        while (j < n) {
            a[j++] = 0.0;
        }
        return;
    }

    const double epsilon = 0.1;
    if (std::abs(a[i]) >= epsilon) {
        a[j++] = a[i];
    }
    moveZerosToEnd(a, n, i + 1, j);
}
