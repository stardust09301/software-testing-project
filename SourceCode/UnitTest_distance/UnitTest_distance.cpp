#include "pch.h"
#include "CppUnitTest.h"
#include "mapping_r.h"


using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest1
{
	TEST_CLASS(DistanceTests)
		
	{
	public:
		TEST_METHOD(CalculateDistanceBetweenPoints)
		{
			struct Point p1 = { 0, 0 };
			struct Point p2 = { 3, 4 };
			double result = distance(&p1, &p2);
			//Assert::AreEqual(5.0, result, 0.0001); convert result to double before comparing it with the expected value
			Assert::AreEqual(5.0, static_cast<double>(result), 0.0001);
		}

		TEST_METHOD(CalculateDistanceWithNegativeCoordinates)
		{
			struct Point p3 = { -1, -1 };
			struct Point p4 = { 2, 3 };
			double result = distance(&p3, &p4);
			//Assert::AreEqual(5.0, result, 0.0001);
			Assert::AreEqual(5.0, static_cast<double>(result), 0.0001);
		}

		TEST_METHOD(CalculateDistanceBetweenSamePoint)
		{
			struct Point p5 = { 0, 0 };
			struct Point p6 = { 0, 0 };
			double result = distance(&p5, &p6);
			//Assert::AreEqual(0.0, result, 0.0001);
			Assert::AreEqual(0.0, static_cast<double>(result), 0.0001);

		}
		TEST_METHOD(CalculateDistanceWithDecimalCoordinates)
		{
			struct Point p7 = { 1.5, 2.5 };
			struct Point p8 = { 4.5, 6.5 };
			double result = distance(&p7, &p8);
			Assert::AreEqual(5.0, static_cast<double>(result), 0.0001);
		}
	};
}

