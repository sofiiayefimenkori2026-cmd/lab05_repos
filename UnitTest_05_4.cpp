#include "pch.h"
#include "CppUnitTest.h"
#include "Lab_05_4.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest054
{
	TEST_CLASS(UnitTest054)
	{
	public:
		
		TEST_METHOD(TestMethod1)
		{
			// Тестування обчислення виразу для K = 1, N = 2:
			// i = 1: 1/1 + 1/2 = 1.5
			// i = 2: 1/2 + 2/2 = 1.5
			// Добуток = 1.5 * 1.5 = 2.25
			double expected = 2.25;
			double res0 = P0(1, 2);
			double res1 = P1(1, 2, 1);
			double res2 = P2(1, 2, 2);
			double res3 = P3(1, 2, 1, 1.0);
			double res4 = P4(1, 2, 2, 1.0);

			Assert::AreEqual(expected, res0, 0.0001);
			Assert::AreEqual(expected, res1, 0.0001);
			Assert::AreEqual(expected, res2, 0.0001);
			Assert::AreEqual(expected, res3, 0.0001);
			Assert::AreEqual(expected, res4, 0.0001);
		}
	};
}
