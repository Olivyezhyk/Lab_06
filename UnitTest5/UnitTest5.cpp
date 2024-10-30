#include "pch.h"
#include "CppUnitTest.h"
#include <iostream>
#include <random>
#include <iomanip>
#include "../Lab_06_03_1/Lab_06_03_1.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest5
{
    TEST_CLASS(UnitTest5)
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

        TEST_METHOD(TestFindSmallestOddIterative)
        {
            int array1[] = { 2, 4, 6, 8 };
            int smallestOdd1 = FindSmallestOddIterative(array1, 4);
            Assert::AreEqual(-1, smallestOdd1);

            int array2[] = { 1, 3, 5, 7 };
            int smallestOdd2 = FindSmallestOddIterative(array2, 4);
            Assert::AreEqual(1, smallestOdd2);

            int array3[] = { 2, 3, 5, 1, 4 };
            int smallestOdd3 = FindSmallestOddIterative(array3, 5);
            Assert::AreEqual(1, smallestOdd3);

            int array4[] = { -1, -3, -2, -4 };
            int smallestOdd4 = FindSmallestOddIterative(array4, 4);
            Assert::AreEqual(-3, smallestOdd4);
        }
    };
}
