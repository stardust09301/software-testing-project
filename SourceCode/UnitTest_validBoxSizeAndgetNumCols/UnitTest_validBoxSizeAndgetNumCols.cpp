#include "pch.h"
#include "CppUnitTest.h"
#include "milestone_r.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace MathTestSuite
{
	// Unit test for validBoxSize
	TEST_CLASS(ValidBoxSize)
	{
	public:

		TEST_METHOD(ValidSmallSizeBox)
		{
			Assert::IsTrue(validBoxSize(0.5));
		}

		TEST_METHOD(ValidMidiumSizeBox)
		{
			Assert::IsTrue(validBoxSize(1.0));
		}

		TEST_METHOD(ValidLargeSizeBox)
		{
			Assert::IsTrue(validBoxSize(2.0));
		}
	};

	TEST_CLASS(InvalidBoxSize)
	{
	public:

		TEST_METHOD(InvalidSmallSizeBox)
		{
			Assert::IsFalse(validBoxSize(0.3));
		}

		TEST_METHOD(InvalidMidiumSizeBox)
		{
			Assert::IsFalse(validBoxSize(1.5));
		}

		TEST_METHOD(InvalidLargeSizeBox)
		{
			Assert::IsFalse(validBoxSize(5.0));
		}
	};

	TEST_CLASS(MapTest)
	{
	public:

		TEST_METHOD(ValidNumCols_LessThan_Max_Value)
		{
			// Arrange
			struct Map testMap = populateMap();

			// Act
			int numCols = getNumCols(&testMap);

			// Assert
			Assert::IsTrue(numCols < MAP_COLS + 1);
		}
		TEST_METHOD(InvalidNumCols_GreaterThan_Max_Value)
		{
			// Arrange
			struct Map testMap = populateMap();

			// Act
			int numCols = getNumCols(&testMap);

			// Assert
			Assert::IsFalse(numCols > MAP_COLS);
		}

		TEST_METHOD(NumCols_Same_As_Max_Cols)
		{
			// Arrange
			struct Map testMap = populateMap();

			// Act
			int numCols = getNumCols(&testMap);

			// Assert
			Assert::IsTrue(numCols == MAP_COLS);
		}

		TEST_METHOD(InvalidNumCols1)
		{
			// Arrange
			struct Map testMap = populateMap();

			// Act
			int numCols = getNumCols(&testMap);

			// Assert
			Assert::IsFalse(numCols == 35);
		}

		TEST_METHOD(InvalidNumCols2)
		{
			// Arrange
			struct Map testMap = populateMap();

			// Act
			int numCols = getNumCols(&testMap);

			// Assert
			Assert::IsFalse(numCols == 56);
		}

		TEST_METHOD(InvalidNumCols3)
		{
			// Arrange
			struct Map testMap = populateMap();

			// Act
			int numCols = getNumCols(&testMap);

			// Assert
			Assert::IsFalse(numCols == 29);
		}
		// Add more test methods as needed
	};

}
