#include "pch.h"
#include "CppUnitTest.h"
#include "../Lab_06_02_rec/Lab_06_02_rec.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTestLab0602rec
{
    TEST_CLASS(UnitTestLab0602rec)
    {
    public:

        TEST_METHOD(TestFindMaxIndex_NonEmptyArray)
        {
            int a[] = { 10, -20, 15, -5, 0, 25 };
            int size = sizeof(a) / sizeof(a[0]);
            int expectedMaxIndex = 5;

            int result = FindMaxIndex(a, size, 0, 0);

            Assert::AreEqual(expectedMaxIndex, result);
        }

        TEST_METHOD(TestFindMinIndex_NonEmptyArray)
        {
            int a[] = { 10, -20, 15, -5, 0, 25 };
            int size = sizeof(a) / sizeof(a[0]);
            int expectedMinIndex = 1;

            int result = FindMinIndex(a, size, 0, 0);

            Assert::AreEqual(expectedMinIndex, result);
        }

        TEST_METHOD(TestFindMaxIndex_AllSameValues)
        {
            int a[] = { 5, 5, 5, 5, 5 };
            int size = sizeof(a) / sizeof(a[0]);
            int expectedMaxIndex = 0;

            int result = FindMaxIndex(a, size, 0, 0);

            Assert::AreEqual(expectedMaxIndex, result);
        }

        TEST_METHOD(TestFindMinIndex_AllSameValues)
        {
            int a[] = { 5, 5, 5, 5, 5 };
            int size = sizeof(a) / sizeof(a[0]);
            int expectedMinIndex = 0;

            int result = FindMinIndex(a, size, 0, 0);

            Assert::AreEqual(expectedMinIndex, result);
        }

    };
}
