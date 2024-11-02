#include "pch.h"
#include "CppUnitTest.h"
#include <iostream>
#include <random>
#include <iomanip>
#include "../Lab_06_02_2/Lab_06_02_2.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest4
{
    TEST_CLASS(UnitTest4)
    {
    public:

        TEST_METHOD(TestGenerateArray)
        {
            const int size = 5;
            int array[size];
            GenerateArray(array, size);

            for (int i = 0; i < size; ++i) {
                Assert::IsTrue(array[i] >= -40 && array[i] <= 20);
            }
        }

        TEST_METHOD(TestFindMaxIndexRecursive)
        {
            int array[] = { 1, 3, 5, 7, 2 };
            int maxIndex = FindMaxIndexRecursive(array, 5);
            Assert::AreEqual(3, maxIndex);
        }

        TEST_METHOD(TestFindMinIndexRecursive)
        {
            int array[] = { 1, 3, 5, 7, 2 };
            int minIndex = FindMinIndexRecursive(array, 5);
            Assert::AreEqual(0, minIndex);
        }

        TEST_METHOD(TestCalculateAverageIndex)
        {
            double averageIndex = CalculateAverageIndexRecursive(3, 0);
            Assert::AreEqual(1.5, averageIndex, 0.001);
        }
    };
}
