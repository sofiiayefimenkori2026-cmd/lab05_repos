#include "pch.h"
#include "CppUnitTest.h"
#include "Lab_05_2.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest052
{
	TEST_CLASS(UnitTest052)
	{
	public:
		
		TEST_METHOD(TestMethod1)
		{
			// Тестування допоміжної функції обчислення доданку ряду Тейлора A(x, n, a)
			// R = -(2n - 1) / ((2n + 1) * x * x)
			// При x = 2.0, n = 1, a = -0.5:
			// R = -(2 - 1) / ((2 + 1) * 4) = -1 / 12
			// a_новий = -0.5 * (-1/12) = 1.0 / 24.0 ~= 0.0416667
			double a = -0.5;
			A(2.0, 1, a);
			Assert::AreEqual(1.0 / 24.0, a, 0.0001);
		}
	};
}
