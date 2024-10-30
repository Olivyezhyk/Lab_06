#include "pch.h"
#include "CppUnitTest.h"
#include <random>
#include <iomanip>
#include "../Lab_06_01_2/Lab_06_01_2.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest2
{
	TEST_CLASS(UnitTest2)
	{
	public:

		TEST_METHOD(TestCountFiltered)
		{
			const int size = 10;
			int array[size] = { -5, 6, -10, 12, -15, 8, -20, 5, -25, 10 };
			Assert::AreEqual(5, CountFiltered(array, size, 0));
		}

		TEST_METHOD(TestSumFiltered)
		{
			const int size = 10;
			int array[size] = { -5, 6, -10, 12, -15, 8, -20, 5, -25, 10 };
			Assert::AreEqual(-75, SumFiltered(array, size, 0));
		}

		TEST_METHOD(TestReplaceFilteredWithZero)
		{
			const int size = 10;
			int array[size] = { -5, 6, -10, 12, -15, 8, -20, 5, -25, 10 };
			ReplaceFilteredWithZero(array, size, 0);
			int expected[size] = { 0, 6, 0, 12, 0, 8, 0, 5, 0, 10 };
			for (int i = 0; i < size; i++) {
				Assert::AreEqual(expected[i], array[i]);
			}
		}
	};
}
