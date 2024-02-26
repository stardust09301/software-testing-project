#include "pch.h"
#include "CppUnitTest.h"
#include "tests_r.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTestvalidatePackageWeight
{
	TEST_CLASS(UnitTestvalidatePackageWeight)
	{
	public:
		
		TEST_METHOD(T01_lowestweight)
		{
			bool expectedResult = true;
			double input = 1;
			bool actualResult = validatePackageWeight(input);
			Assert::AreEqual(expectedResult, actualResult);
		}

		TEST_METHOD(T02_highestweight)
		{
			bool expectedResult = true;
			double input = 1500;
			bool actualResult = validatePackageWeight(input);
			Assert::AreEqual(expectedResult, actualResult);
		}

		TEST_METHOD(T03_outOfRangeWeight1)
		{
			bool expectedResult = true;
			double input = 2500;
			bool actualResult = validatePackageWeight(input);
			Assert::AreEqual(expectedResult, actualResult);
		}

		TEST_METHOD(T04_outOfRangeWeight2)
		{
			bool expectedResult = false;
			double input = -5;
			bool actualResult = validatePackageWeight(input);
			Assert::AreEqual(expectedResult, actualResult);
		}
	};
}
