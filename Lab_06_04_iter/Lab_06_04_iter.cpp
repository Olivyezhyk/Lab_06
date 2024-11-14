#include <iostream>
#include <iomanip>
#include <cmath>
#include <ctime>

void GenerateArray(double* a, const int n);
void PrintArray(double* a, const int n);
double findMaxAbsoluteElement(const double* a, int n);
double sumBetweenFirstTwoPositives(const double* a, int n);
void moveZerosToEnd(double* a, int n);

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

void GenerateArray(double* a, const int n)
{
    double Low = -40.0;
    double High = 20.0;

    for (int i = 0; i < n; i++) {
        a[i] = Low + (rand() / (RAND_MAX + 1.0)) * (High - Low);
        a[i] = round(a[i] * 10.0) / 10.0;
    }
}

void PrintArray(double* a, const int n)
{
    std::cout << std::fixed << std::setprecision(1);
    for (int i = 0; i < n; ++i) {
        std::cout << "(" << "a[" << i << "] = " << a[i] << ") ";
    }
    std::cout << std::endl;
}

double findMaxAbsoluteElement(const double* a, int n)
{
    double maxElement = a[0];
    for (int i = 1; i < n; i++) {
        if (std::abs(a[i]) > std::abs(maxElement)) {
            maxElement = a[i];
        }
    }
    return maxElement;
}

double sumBetweenFirstTwoPositives(const double* a, int n)
{
    int firstPositive = -1, secondPositive = -1;
    double sum = 0;

    for (int i = 0; i < n; i++) {
        if (a[i] > 0) {
            if (firstPositive == -1) {
                firstPositive = i;
            }
            else {
                secondPositive = i;
                break;
            }
        }
    }

    if (firstPositive != -1 && secondPositive != -1)
    {
        for (int i = firstPositive + 1; i < secondPositive; i++) {
            sum += a[i];
        }
    }
    return sum;
}

void moveZerosToEnd(double* a, int n)
{
    int j = 0;
    const double epsilon = 0.1;

    for (int i = 0; i < n; i++) {
        if (std::abs(a[i]) >= epsilon) {
            a[j++] = a[i];
        }
    }
    while (j < n) {
        a[j++] = 0.0;
    }
}
