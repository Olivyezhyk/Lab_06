#include "pch.h"
#include "CppUnitTest.h"
#include "../Lab_06_03_iter/Lab_06_03_iter.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTestLab0603iter
{
	TEST_CLASS(UnitTestLab0603iter)
	{
	public:

		TEST_METHOD(TestFindSmallestOdd_AllOdd)
		{
			int a[] = { 1, 3, 5, 7, 9 };
			int size = sizeof(a) / sizeof(a[0]);
			int expected = 1;

			int result = FindSmallestOdd(a, size);
			Assert::AreEqual(expected, result);
		}

		TEST_METHOD(TestFindSmallestOdd_AllEven)
		{
			int a[] = { 2, 4, 6, 8, 10 };
			int size = sizeof(a) / sizeof(a[0]);
			int expected = -1;

			int result = FindSmallestOdd(a, size);
			Assert::AreEqual(expected, result);
		}

		TEST_METHOD(TestFindSmallestOdd_Mixed)
		{
			int a[] = { 2, 3, 5, 7, 8, 10 }; 
			int size = sizeof(a) / sizeof(a[0]);
			int expected = 3;

			int result = FindSmallestOdd(a, size);
			Assert::AreEqual(expected, result);
		}

		TEST_METHOD(TestFindSmallestOdd_NegativeNumbers)
		{
			int a[] = { -2, -5, -8, -11, -3 };
			int size = sizeof(a) / sizeof(a[0]);
			int expected = -11;

			int result = FindSmallestOdd(a, size);
			Assert::AreEqual(expected, result);
		}

		TEST_METHOD(TestFindSmallestOdd_NoOddNumbers)
		{
			int a[] = { 2, 4, 6, 8, 10, 12 };
			int size = sizeof(a) / sizeof(a[0]);
			int expected = -1;

			int result = FindSmallestOdd(a, size);
			Assert::AreEqual(expected, result);
		}
	};
}
