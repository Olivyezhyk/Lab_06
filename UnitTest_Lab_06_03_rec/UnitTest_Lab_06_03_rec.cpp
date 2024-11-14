#include "pch.h"
#include "CppUnitTest.h"
#include "../Lab_06_03_rec/Lab_06_03_rec.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTestLab0603rec
{
	TEST_CLASS(UnitTestLab0603rec)
	{
	public:

		TEST_METHOD(TestFindSmallestOdd_ValidArray)
		{
			int a[] = { 10, -20, 15, 7, 9 };
			int size = sizeof(a) / sizeof(a[0]);
			int expected = 7;

			int result = FindSmallestOdd(a, size);
			Assert::AreEqual(expected, result);
		}

		TEST_METHOD(TestFindSmallestOdd_NoOddNumbers)
		{
			int a[] = { 10, -20, 30, 40, 50 };
			int size = sizeof(a) / sizeof(a[0]);
			int expected = -1;

			int result = FindSmallestOdd(a, size);
			Assert::AreEqual(expected, result);
		}


		TEST_METHOD(TestFindSmallestOdd_SingleOddNumber)
		{
			int a[] = { 10, -20, 25 };
			int size = sizeof(a) / sizeof(a[0]);
			int expected = 25;

			int result = FindSmallestOdd(a, size);
			Assert::AreEqual(expected, result);
		}

		TEST_METHOD(TestFindSmallestOdd_AllOddNumbers)
		{
			int a[] = { 13, 7, 5, 9, 25 };
			int size = sizeof(a) / sizeof(a[0]);
			int expected = 5;

			int result = FindSmallestOdd(a, size);
			Assert::AreEqual(expected, result);
		}
	};
}
