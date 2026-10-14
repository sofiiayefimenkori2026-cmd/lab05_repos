#include "pch.h"
#include "CppUnitTest.h"
#include "Lab_05_3.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest053
{
	TEST_CLASS(UnitTest053)
	{
	public:
		
		TEST_METHOD(TestMethod1)
		{
			// Тестування розгалуженої функції s(x) для |x| < 1
			// При x = 0: сума для i=0 дає 0^0/0! = 1, решта доданків = 0
			// Результат s(0) має дорівнювати точно 1.0
			double res = s(0.0);
			Assert::AreEqual(1.0, res, 0.0001);
		}
	};
}
