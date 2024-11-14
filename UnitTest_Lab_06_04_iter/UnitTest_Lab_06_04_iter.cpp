#include "pch.h"
#include "CppUnitTest.h"
#include "../Lab_06_04_iter/Lab_06_04_iter.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTestLab0604iter
{
	TEST_CLASS(UnitTestLab0604iter)
	{
	public:

		TEST_METHOD(TestFindMaxAbsoluteElement)
		{
			double a[] = { -15.2, 10.1, -30.4, 22.5, 11.0 };
			int n = sizeof(a) / sizeof(a[0]);
			double expected = -30.4;

			double result = findMaxAbsoluteElement(a, n);
			Assert::AreEqual(expected, result);
		}

		TEST_METHOD(TestSumBetweenFirstTwoPositives)
		{
			double a[] = { -5.5, 0.0, 12.3, 8.7, 5.1, -1.0, 6.4 };
			int n = sizeof(a) / sizeof(a[0]);
			double expected = 0;

			double result = sumBetweenFirstTwoPositives(a, n);
			Assert::AreEqual(expected, result);
		}

		TEST_METHOD(TestSumBetweenFirstTwoPositives_NoPositives)
		{
			double a[] = { -5.5, -3.3, -2.1 };
			int n = sizeof(a) / sizeof(a[0]);
			double expected = 0.0;

			double result = sumBetweenFirstTwoPositives(a, n);
			Assert::AreEqual(expected, result);
		}

		TEST_METHOD(TestMoveZerosToEnd)
		{
			double a[] = { 0.0, 3.5, 0.0, 2.1, 0.0, -4.7 };
			int n = sizeof(a) / sizeof(a[0]);
			double expected[] = { 3.5, 2.1, -4.7, 0.0, 0.0, 0.0 };

			moveZerosToEnd(a, n);

			for (int i = 0; i < n; ++i) {
				Assert::AreEqual(expected[i], a[i]);
			}
		}

		TEST_METHOD(TestMoveZerosToEnd_NoZeros)
		{
			double a[] = { 1.2, 3.4, -5.6, 7.8 };
			int n = sizeof(a) / sizeof(a[0]);
			double expected[] = { 1.2, 3.4, -5.6, 7.8 };

			moveZerosToEnd(a, n);

			for (int i = 0; i < n; ++i) {
				Assert::AreEqual(expected[i], a[i]);
			}
		}
	};
}
