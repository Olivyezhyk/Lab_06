#include "pch.h"
#include "CppUnitTest.h"
#include <random>
#include <iomanip>
#include "../Lab_06_01_1/Lab_06_01_1.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest1
{
	TEST_CLASS(UnitTest1)
	{
	public:

		TEST_METHOD(TestCountFiltered)
		{
			const int size = 10;
			int array[size] = { -5, 6, -10, 12, -15, 8, -20, 5, -25, 10 };
			Assert::AreEqual(5, CountFiltered(array, size));
		}

		TEST_METHOD(TestSumFiltered)
		{
			const int size = 10;
			int array[size] = { -5, 6, -10, 12, -15, 8, -20, 5, -25, 10 };
			Assert::AreEqual(-75, SumFiltered(array, size));
		}

		TEST_METHOD(TestReplaceFilteredWithZero)
		{
			const int size = 10;
			int array[size] = { -5, 6, -10, 12, -15, 8, -20, 5, -25, 10 };
			ReplaceFilteredWithZero(array, size);
			int expected[size] = { 0, 6, 0, 12, 0, 8, 0, 5, 0, 10 };
			for (int i = 0; i < size; i++) {
				Assert::AreEqual(expected[i], array[i]);
			}
		}
	};
}
