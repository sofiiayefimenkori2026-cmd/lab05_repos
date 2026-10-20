#include "pch.h"
#include "CppUnitTest.h"
#include "Lab_05_5.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest055
{
	TEST_CLASS(UnitTest055)
	{
	public:
		
		TEST_METHOD(TestMethod1)
		{
			// Тестування рекурсивної функції обчислення НСД(48, 18):
			// НСД(48, 18) = 6, глибина рекурсії = 3 (рівні 1, 2, 3)
			int depth = 0;
			int res = gcd(48, 18, 1, depth);
			Assert::AreEqual(6, res);
			Assert::AreEqual(3, depth);
			Assert::AreEqual(6, gcd_iter(48, 18));
		}
	};
}
