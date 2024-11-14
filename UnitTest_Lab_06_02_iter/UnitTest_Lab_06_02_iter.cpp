#include "pch.h"
#include "CppUnitTest.h"
#include "../Lab_06_02_iter/Lab_06_02_iter.cpp" 


using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTestLab0602iter
{
	TEST_CLASS(UnitTestLab0602iter)
	{
	public:

		TEST_METHOD(TestFindMinIndex)
		{
			int a[] = { 10, -20, 15, -5, 0, 25 };
			int size = sizeof(a) / sizeof(a[0]);
			int expectedMinIndex = 1;

			int result = FindMinIndex(a, size);

			Assert::AreEqual(expectedMinIndex, result);
		}

		TEST_METHOD(TestFindMaxIndex)
		{
			int a[] = { 10, -20, 15, -5, 0, 25 };
			int size = sizeof(a) / sizeof(a[0]);
			int expectedMaxIndex = 5;

			int result = FindMaxIndex(a, size);

			Assert::AreEqual(expectedMaxIndex, result);
		}

		TEST_METHOD(TestCalculateAverageIndex)
		{
			int maxIndex = 5;
			int minIndex = 1;
			double expectedAverageIndex = 3.0;

			double result = CalculateAverageIndex(maxIndex, minIndex);

			Assert::AreEqual(expectedAverageIndex, result);
		}

		TEST_METHOD(TestEmptyArrayFindMinIndex)
		{
			int* a = nullptr;
			int size = 0;

			int result = FindMinIndex(a, size);

			Assert::AreEqual(-1, result);
		}

		TEST_METHOD(TestEmptyArrayFindMaxIndex)
		{
			int* a = nullptr;
			int size = 0;

			int result = FindMaxIndex(a, size);

			Assert::AreEqual(-1, result);
		}
	};
}
