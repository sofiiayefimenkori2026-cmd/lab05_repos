#include "pch.h"
#include "CppUnitTest.h"
#include "Lab_05_1.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest051
{
	TEST_CLASS(UnitTest051)
	{
	public:
		
		TEST_METHOD(TestMethod1)
		{
			// Тестування допоміжної функції g(a, b) = sin(a * b) / (a * a + b * b)
			// При a = 0, b = 1: g(0, 1) = sin(0) / (0 + 1) = 0.0
			double t = g(0.0, 1.0);
			Assert::AreEqual(0.0, t, 0.0001);
		}
	};
}
