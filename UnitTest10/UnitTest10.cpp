#include "pch.h"
#include "CppUnitTest.h"
#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <ctime>
#include <cmath>
#include "../Lab_06_04_2/Lab_06_04_2.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest5
{
    TEST_CLASS(UnitTest5)
    {
    public:
        TEST_METHOD(TestGenerateArray)
        {
            const int size = 5;
            double array[size];
            GenerateArray(array, size);

            for (int i = 0; i < size; ++i) {
                Assert::IsTrue(array[i] >= -40.0 && array[i] <= 61.0, L"Element out of range");
            }
        }

        TEST_METHOD(TestFindMaxAbsoluteElementRecursive)
        {
            double array1[] = { -1.0, 2.0, -3.0, 4.0, -5.0 };
            double maxAbsolute1 = findMaxAbsoluteElementRecursive(array1, 5);
            Assert::AreEqual(-5.0, maxAbsolute1, 0.001);

            double array2[] = { -2.0, -3.0, -1.0, -4.0 };
            double maxAbsolute2 = findMaxAbsoluteElementRecursive(array2, 4);
            Assert::AreEqual(-4.0, maxAbsolute2, 0.001);

            double array3[] = { 0.0, 0.0, 0.0, 0.0 };
            double maxAbsolute3 = findMaxAbsoluteElementRecursive(array3, 4);
            Assert::AreEqual(0.0, maxAbsolute3, 0.001);

            double array4[] = { -2.0, 0.0, 3.0, -1.0 };
            double maxAbsolute4 = findMaxAbsoluteElementRecursive(array4, 4);
            Assert::AreEqual(3.0, maxAbsolute4, 0.001);

            double array5[] = { -7.0 };
            double maxAbsolute5 = findMaxAbsoluteElementRecursive(array5, 1);
            Assert::AreEqual(-7.0, maxAbsolute5, 0.001);
        }

        TEST_METHOD(TestSumBetweenFirstTwoPositivesRecursive)
        {
            double array1[] = { -1.0, 2.0, 3.0, 4.0, 5.0 };
            double sum1 = sumBetweenFirstTwoPositivesRecursive(array1, 5);
            Assert::AreEqual(0.0, sum1, 0.001);

            double array2[] = { -1.0, -2.0, -3.0 };
            double sum2 = sumBetweenFirstTwoPositivesRecursive(array2, 3);
            Assert::AreEqual(0.0, sum2, 0.001);

            double array3[] = { -1.0, 2.0, -3.0, 4.0 };
            double sum3 = sumBetweenFirstTwoPositivesRecursive(array3, 4);
            Assert::AreEqual(-3.0, sum3, 0.001);

            double array4[] = { 1.0, 0.0, 2.0, 3.0, 4.0 };
            double sum4 = sumBetweenFirstTwoPositivesRecursive(array4, 5);
            Assert::AreEqual(0.0, sum4, 0.001);

            double array5[] = { 1.0, -2.0, 3.0, 4.0, -5.0 };
            double sum5 = sumBetweenFirstTwoPositivesRecursive(array5, 5);
            Assert::AreEqual(-2.0, sum5, 0.001);
        }

        TEST_METHOD(TestMoveZerosToEndRecursive)
        {
            double array1[] = { 1.0, 0.0, 2.0, 0.0, 3.0 };
            moveZerosToEndRecursive(array1, 5);
            Assert::AreEqual(1.0, array1[0], 0.001);
            Assert::AreEqual(2.0, array1[1], 0.001);
            Assert::AreEqual(3.0, array1[2], 0.001);
            Assert::AreEqual(0.0, array1[3], 0.001);
            Assert::AreEqual(0.0, array1[4], 0.001);

            double array2[] = { 0.0, 0.0, 0.0 };
            moveZerosToEndRecursive(array2, 3);
            Assert::AreEqual(0.0, array2[0], 0.001);
            Assert::AreEqual(0.0, array2[1], 0.001);
            Assert::AreEqual(0.0, array2[2], 0.001);

            double array3[] = { 1.0, 2.0, 3.0 };
            moveZerosToEndRecursive(array3, 3);
            Assert::AreEqual(1.0, array3[0], 0.001);
            Assert::AreEqual(2.0, array3[1], 0.001);
            Assert::AreEqual(3.0, array3[2], 0.001);

            double array4[] = { 0.0, 1.0, 0.0, 2.0 };
            moveZerosToEndRecursive(array4, 4);
            Assert::AreEqual(1.0, array4[0], 0.001);
            Assert::AreEqual(2.0, array4[1], 0.001);
            Assert::AreEqual(0.0, array4[2], 0.001);
            Assert::AreEqual(0.0, array4[3], 0.001);
        }
    };
}
