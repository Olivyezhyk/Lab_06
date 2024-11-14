#include "pch.h"
#include "CppUnitTest.h"
#include "../Lab_06_01_iter/Lab_06_01_iter.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTestLab0601iter
{
    TEST_CLASS(UnitTestLab0601iter)
    {
    public:

        TEST_METHOD(TestCountFiltered)
        {
            int a[] = { -5, 15, -10, 20, -3, 10 };
            int size = sizeof(a) / sizeof(a[0]);
            int expectedCount = 3;

            int result = CountFiltered(a, size);

            Assert::AreEqual(expectedCount, result);
        }

        TEST_METHOD(TestSumFiltered)
        {
            int a[] = { -5, 15, -10, 20, -3, 10 };
            int size = sizeof(a) / sizeof(a[0]);
            int expectedSum = 15 + 20 + 10;

            int result = SumFiltered(a, size);

            Assert::AreEqual(expectedSum, result);
        }

        TEST_METHOD(TestReplaceFilteredWithZero)
        {
            int a[] = { -5, 15, -10, 20, -3, 10 };
            int size = sizeof(a) / sizeof(a[0]);
            int expected[] = { 0, 15, 0, 20, 0, 10 };

            ReplaceFilteredWithZero(a, size);

            for (int i = 0; i < size; i++) {
                Assert::AreEqual(expected[i], a[i]);
            }
        }
    };
}

