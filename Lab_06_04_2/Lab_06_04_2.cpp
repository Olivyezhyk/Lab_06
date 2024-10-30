﻿#include <iostream>
#include <cstdlib>
#include <ctime>
#include <cmath>
#include <iomanip>

using namespace std;

void GenerateArray(double array[], int n) {
    for (int i = 0; i < n; i++) {
        array[i] = (rand() % 6100 - 4000) / 100.0;
    }
}

double findMaxAbsoluteElementRecursive(const double array[], int n, int index = 0, double currentMax = 0) {
    if (index == 0) currentMax = array[0];
    if (index == n) return currentMax;
    if (abs(array[index]) > abs(currentMax)) currentMax = array[index];
    return findMaxAbsoluteElementRecursive(array, n, index + 1, currentMax);
}

double sumBetweenFirstTwoPositivesRecursive(const double array[], int n, int index = 0, int firstPositive = -1, int secondPositive = -1, double summation = 0) {
    if (index == n) return (firstPositive != -1 && secondPositive != -1) ? summation : 0;
    if (array[index] > 0) {
        if (firstPositive == -1) return sumBetweenFirstTwoPositivesRecursive(array, n, index + 1, index, secondPositive, 0);
        if (secondPositive == -1) return sumBetweenFirstTwoPositivesRecursive(array, n, index + 1, firstPositive, index, summation);
    }
    else if (firstPositive != -1 && secondPositive == -1) {
        summation += array[index];
    }
    return sumBetweenFirstTwoPositivesRecursive(array, n, index + 1, firstPositive, secondPositive, summation);
}

void moveZerosToEndRecursive(double array[], int n, int index = 0, int nonZeroIndex = 0) {
    if (index == n) {
        for (int i = nonZeroIndex; i < n; i++) {
            array[i] = 0;
        }
        return;
    }
    if (array[index] != 0) {
        array[nonZeroIndex++] = array[index];
    }
    moveZerosToEndRecursive(array, n, index + 1, nonZeroIndex);
}

int main() {
    srand(time(0));

    int n;
    cout << "Enter the number of elements in the array: ";
    cin >> n;

    double* array = new double[n];
    GenerateArray(array, n);

    cout << "Initial array: ";
    for (int i = 0; i < n; i++) {
        cout << fixed << setprecision(2) << array[i] << " ";
    }
    cout << endl;

    double maxAbsolute = findMaxAbsoluteElementRecursive(array, n);
    cout << "Maximum absolute element: " << maxAbsolute << endl;

    double sumBetweenPositives = sumBetweenFirstTwoPositivesRecursive(array, n);
    cout << "Sum of elements between the first and second positive elements: " << sumBetweenPositives << endl;

    moveZerosToEndRecursive(array, n);

    cout << "Modified array: ";
    for (int i = 0; i < n; i++) {
        cout << fixed << setprecision(2) << array[i] << " ";
    }
    cout << endl;

    return 0;
}