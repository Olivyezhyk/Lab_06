#include "pch.h"
#include "CppUnitTest.h"
#include <iostream>
#include <random>
#include <iomanip>
#include "../Lab_06_03_2(templates)/Lab_06_03_2(templates).cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest8
{
    TEST_CLASS(UnitTest8)
    {
    public:

        TEST_METHOD(TestGenerateArray)
        {
            const int size = 5;
            int array[size];
            GenerateArray(array, size, -40, 20);

            for (int i = 0; i < size; ++i) {
                Assert::IsTrue(array[i] >= -40 && array[i] <= 20);
            }
        }

        TEST_METHOD(TestFindSmallestOddRecursive)
        {
            int array1[] = { 2, 4, 6, 8 };
            int smallestOdd1 = FindSmallestOddRecursive(array1, 4, 0, -1);
            Assert::AreEqual(-1, smallestOdd1);

            int array2[] = { 1, 3, 5, 7 };
            int smallestOdd2 = FindSmallestOddRecursive(array2, 4, 0, -1);
            Assert::AreEqual(1, smallestOdd2);

            int array3[] = { 2, 3, 5, 1, 4 };
            int smallestOdd3 = FindSmallestOddRecursive(array3, 5, 0, -1);
            Assert::AreEqual(1, smallestOdd3);

            int array4[] = { -1, -3, -2, -4 };
            int smallestOdd4 = FindSmallestOddRecursive(array4, 4, 0, -1);
            Assert::AreEqual(-3, smallestOdd4);
        }
    };
}
