#include "pch.h"
#include "CppUnitTest.h"
#include "tests_r.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTestvalidatePackageBox
{
	TEST_CLASS(UnitTestvalidatePackageBox)
	{
	public:
		
		TEST_METHOD(T05_validBoxSizing1)
		{
			bool expectedResult = true;
			double input = 0.5;
			bool actualResult = validatePackageBox(input);
			Assert::AreEqual(expectedResult, actualResult);
		}
		TEST_METHOD(T06_validBoxSizing2)
		{
			bool expectedResult = true;
			double input = 1;
			bool actualResult = validatePackageBox(input);
			Assert::AreEqual(expectedResult, actualResult);
		}
		TEST_METHOD(T07_validBoxSizing3)
		{
			bool expectedResult = true;
			double input = 2;
			bool actualResult = validatePackageBox(input);
			Assert::AreEqual(expectedResult, actualResult);
		}
		TEST_METHOD(T08_validBoxSizing3)
		{
			bool expectedResult = true;
			double input = 4;
			bool actualResult = validatePackageBox(input);
			Assert::AreEqual(expectedResult, actualResult);
		}

		TEST_METHOD(T09_invalidBoxSizing4)
		{
			bool expectedResult = false;
			double input = 45;
			bool actualResult = validatePackageBox(input);
			Assert::AreEqual(expectedResult, actualResult);
		}
	};
}
