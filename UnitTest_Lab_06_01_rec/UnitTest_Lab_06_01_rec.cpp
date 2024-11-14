#include "pch.h"
#include "CppUnitTest.h"
#include "../Lab_06_01_rec/Lab_06_01_rec.cpp" 

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTestLab0601rec
{
    TEST_CLASS(UnitTestLab0601rec)
    {
    public:

        TEST_METHOD(TestCountFiltered)
        {
            int a[] = { -5, 15, -10, 20, -3, 10 };
            int size = sizeof(a) / sizeof(a[0]);
            int expectedCount = 3;

            int result = CountFiltered(a, size, 0, 0);

            Assert::AreEqual(expectedCount, result);
        }

        TEST_METHOD(TestSumFiltered)
        {
            int a[] = { -5, 15, -10, 20, -3, 10 };
            int size = sizeof(a) / sizeof(a[0]);
            int expectedSum = 15 + 20 + 10;

            int result = SumFiltered(a, size, 0, 0);

            Assert::AreEqual(expectedSum, result);
        }

        TEST_METHOD(TestReplaceFilteredWithZero)
        {
            int a[] = { -5, 15, -10, 20, -3, 10 };
            int size = sizeof(a) / sizeof(a[0]);
            int expected[] = { 0, 15, 0, 20, 0, 10 };

            ReplaceFilteredWithZero(a, size, 0);

            for (int i = 0; i < size; i++) {
                Assert::AreEqual(expected[i], a[i]);
            }
        }

        TEST_METHOD(TestGenerateArray)
        {
            const int size = 10;
            int a[size];

            GenerateArray(a, size, 0);

            bool inRange = true;
            for (int i = 0; i < size; ++i) {
                if (a[i] < -40 || a[i] > 20) {
                    inRange = false;
                    break;
                }
            }

            Assert::IsTrue(inRange);
        }
    };
}

