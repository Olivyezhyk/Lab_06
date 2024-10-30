#include "pch.h"
#include "CppUnitTest.h"
#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <ctime>
#include <cmath>
#include "../Lab_06_04_1/Lab_06_04_1.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest9
{
    TEST_CLASS(UnitTest9)
    {
    public:
        TEST_METHOD(TestGenerateArray)
        {
            const int size = 5;
            double array[size];
            GenerateArray(array, size);

            for (int i = 0; i < size; ++i) {
                Assert::IsTrue(array[i] >= -40.0 && array[i] <= 61.0);
            }
        }

        TEST_METHOD(TestFindMaxAbsoluteElement)
        {
            double array1[] = { -3.5, -2.0, 1.5, 4.0 };
            double maxAbsolute1 = findMaxAbsoluteElement(array1, 4);
            Assert::AreEqual(4.0, maxAbsolute1, 0.001);

            double array2[] = { -5.5, 3.0, -2.0, 6.0 };
            double maxAbsolute2 = findMaxAbsoluteElement(array2, 4);
            Assert::AreEqual(6.0, maxAbsolute2, 0.001);

            double array3[] = { 0.0, -1.0, -2.0, 1.0 };
            double maxAbsolute3 = findMaxAbsoluteElement(array3, 4);
            Assert::AreEqual(-2.0, maxAbsolute3, 0.001);
        }

        TEST_METHOD(TestSumBetweenFirstTwoPositives)
        {
            double array1[] = { -1.0, 2.0, 3.0, 4.0, 5.0 };
            double sum1 = sumBetweenFirstTwoPositives(array1, 5);
            Assert::AreEqual(0.0, sum1, 0.001);

            double array2[] = { -1.0, -2.0, 3.0, 4.0 };
            double sum2 = sumBetweenFirstTwoPositives(array2, 4);
            Assert::AreEqual(0.0, sum2, 0.001);

            double array3[] = { 1.0, 0.0, 2.0, 3.0, 4.0 };
            double sum3 = sumBetweenFirstTwoPositives(array3, 5);
            Assert::AreEqual(0.0, sum3, 0.001);
        }

        TEST_METHOD(TestMoveZerosToEnd)
        {
            double array1[] = { 1.0, 0.0, 2.0, 0.0, 3.0 };
            moveZerosToEnd(array1, 5);
            Assert::AreEqual(1.0, array1[0], 0.001);
            Assert::AreEqual(2.0, array1[1], 0.001);
            Assert::AreEqual(3.0, array1[2], 0.001);
            Assert::AreEqual(0.0, array1[3], 0.001);
            Assert::AreEqual(0.0, array1[4], 0.001);

            double array2[] = { 0.0, 0.0, 0.0 };
            moveZerosToEnd(array2, 3);
            Assert::AreEqual(0.0, array2[0], 0.001);
            Assert::AreEqual(0.0, array2[1], 0.001);
            Assert::AreEqual(0.0, array2[2], 0.001);

            double array3[] = { 1.0, 2.0, 3.0 };
            moveZerosToEnd(array3, 3);
            Assert::AreEqual(1.0, array3[0], 0.001);
            Assert::AreEqual(2.0, array3[1], 0.001);
            Assert::AreEqual(3.0, array3[2], 0.001);
        }
    };
}
