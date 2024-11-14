#include <iostream>
#include <iomanip>
#include <time.h>

void GenerateArray(int* a, int size, int i = 0);
void PrintArray(int* a, const int size, int i = 0);
int FindMinIndex(int* a, int size, int currentIndex = 0, int minIndex = 0);
int FindMaxIndex(int* a, int size, int currentIndex = 0, int maxIndex = 0);
double CalculateAverageIndex(int maxIndex, int minIndex, int sum = 0, int count = 2);

int main() {

    const int size = 26;
    int a[size];

    GenerateArray(a, size);

    std::cout << "Original Array: ";
    std::cout << std::endl;
    PrintArray(a, size);
    std::cout << std::endl;

    int minIndex = FindMinIndex(a, size);
    std::cout << "a[" << minIndex << "] = " << a[minIndex];
    std::cout << std::endl;

    int maxIndex = FindMaxIndex(a, size);
    std::cout << "a[" << maxIndex << "] = " << a[maxIndex];
    std::cout << std::endl;

    double averageIndex = CalculateAverageIndex(maxIndex, minIndex);
    std::cout << "Average index = " << averageIndex << std::endl;

    return 0;
}

void GenerateArray(int* a, int size, int i) {
    int Low = -40;
    int High = 20;

    if (i == 0) {
        srand(time(0));
    }

    if (i < size) {
        a[i] = Low + rand() % (High - Low + 1);
        GenerateArray(a, size, i + 1);
    }
}

void PrintArray(int* a, const int size, int i) {
    if (i < size) {
        std::cout << "(" << "a[" << i << "] = " << a[i] << ")" << " ";
        PrintArray(a, size, i + 1);
    }
    else {
        std::cout << std::endl;
    }
}

int FindMaxIndex(int* a, int size, int currentIndex, int i) {
    int max = a[currentIndex];
    if (currentIndex == -1) {
        std::cout << "No elements satisfying the condition" << std::endl;
        return 0;
    }

    if (i < size) {
        if (a[i] > max) {
            max = a[i];
            currentIndex = i;
        }
        return FindMaxIndex(a, size, currentIndex, i + 1);
    }
    return currentIndex;
}


int FindMinIndex(int* a, int size, int currentIndex, int i) {
    int min = a[currentIndex];
    if (currentIndex == -1) {
        std::cout << "No elements satisfying the condition" << std::endl;
        return 0;
    }

    if (currentIndex + i < size) {
        if (a[i] < min) {
            min = a[i];
            currentIndex = i;
        }
        return FindMinIndex(a, size, currentIndex, i + 1);
    }
    return currentIndex;
}

double CalculateAverageIndex(int maxIndex, int minIndex, int sum, int count)
{
    if (count == 0) {
        return sum / 2.0;
    }

    if (count == 2) {
        sum += maxIndex;
    }
    else {
        sum += minIndex;
    }
    return CalculateAverageIndex(maxIndex, minIndex, sum, count - 1);
}
