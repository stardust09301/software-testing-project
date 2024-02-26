#include "pch.h"
#include "CppUnitTest.h"
#include "shipment_r.h"
#include "mapping_r.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest
{
    TEST_CLASS(TruckCapacityTests)
    {
    public:

        TEST_METHOD(EmptyTruck)
        {
            struct Truck emptyTruck = { 1, {0.0f, 0.0f}, {0.0f, 0.0f}, 0, nullptr };
            struct Size result = calCapacity(emptyTruck);

            Assert::AreEqual(result.weight, static_cast<float>(1500));
            Assert::AreEqual(result.volume, static_cast<float>(48));
        }

        TEST_METHOD(PartiallyLoadedTruck)
        {
            struct Truck partiallyLoadedTruck = { 2, {30.0f, 15.0f}, {0.0f, 0.0f}, 0, nullptr };
            struct Size result = calCapacity(partiallyLoadedTruck);

            Assert::AreEqual(result.weight, static_cast<float>(1500 - 30.0f));
            Assert::AreEqual(result.volume, static_cast<float>(48 - 15.0f));
        }

        TEST_METHOD(FullTruck)
        {
            struct Truck fullTruck = { 3, {1500.0f, 48.0f}, {0.0f, 0.0f}, 0, nullptr };
            struct Size result = calCapacity(fullTruck);

            Assert::AreEqual(result.weight, 0.0f);
            Assert::AreEqual(result.volume, 0.0f);
        }

        TEST_METHOD(PartiallyLoadedTruck_)
        {
            struct Truck partiallyLoadedTruck = { 2, {1000.0f, 30.0f}, {0.0f, 0.0f}, 0, nullptr };
            struct Size result = calCapacity(partiallyLoadedTruck);

            Assert::AreEqual(result.weight, static_cast<float>(1500 - 1000.0f));
            Assert::AreEqual(result.volume, static_cast<float>(48 - 30.0f));
        }

    };

    TEST_CLASS(UnitTestcheckTruckWeightCap)
    {
    public:

        TEST_METHOD(TestTruckWeightCapacity)
        {
            // Arrange
            struct Truck truck = { 0, {0, 0}, {0, 1500}, 0, NULL };
            struct Shipment shipment = { {0, 0}, {0, 0} };

            // Act
            truck.loaded.weight = 200;
            shipment.box.weight = 300;
            int result = checkTruckWeightCap(truck, shipment);

            // Assert
            Assert::AreEqual(1, result, L"Truck should not be full with this weight");
        }

        TEST_METHOD(TestTruckWeightCapacityNotFull)
        {
            struct Truck truck = { 0, {0, 0}, {0, 1500}, 0, nullptr };
            struct Shipment shipment = { {0, 0}, {0, 0} };

            // Act
            // The truck and shipment weights are such that the truck is not full
            truck.loaded.weight = 200;
            shipment.box.weight = 100;
            int result = checkTruckWeightCap(truck, shipment);

            // Assert
            Assert::AreEqual(1, result, L"Truck should not be full with this weight");
        }

        TEST_METHOD(TestTruckWeightCapacityFull1)
        {
            struct Truck truck = { 0, {0, 0}, {0, 1500}, 0, nullptr };
            struct Shipment shipment = { {0, 0}, {0, 0} };

            // Act
            // The truck and shipment weights are such that the truck is not full
            truck.loaded.weight = 1500;
            shipment.box.weight = 100;
            int result = checkTruckWeightCap(truck, shipment);

            // Assert
            Assert::AreEqual(0, result, L"Truck should be full with this weight");
        }

        TEST_METHOD(TestTruckWeightCapacityFull2)
        {
            struct Truck truck = { 0, {0, 0}, {0, 1500}, 0, nullptr };
            struct Shipment shipment = { {0, 0}, {0, 0} };

            // Act
            // The truck and shipment weights are such that the truck is not full
            truck.loaded.weight = 1000;
            shipment.box.weight = 600;
            int result = checkTruckWeightCap(truck, shipment);

            // Assert
            Assert::AreEqual(0, result, L"Truck should be full with this weight");
        }

        TEST_METHOD(TestTruckWeightCapacityFullwithShipment)
        {
            struct Truck truck = { 0, {0, 0}, {0, 1500}, 0, nullptr };
            struct Shipment shipment = { {0, 0}, {0, 0} };

            // Act
            // The truck and shipment weights are such that the truck is not full
            truck.loaded.weight = 1000;
            shipment.box.weight = 500;
            int result = checkTruckWeightCap(truck, shipment);

            // Assert
            Assert::AreEqual(1, result, L"Truck should not be full with this weight");
        }
    };

    //TEST_CLASS(DistanceTests)
    //{
    //public:
    //    TEST_METHOD(CalculateDistanceBetweenPoints)
    //    {
    //        struct Point p1 = { 0, 0 };
    //        struct Point p2 = { 3, 4 };
    //        double result = distance(&p1, &p2);
    //        //Assert::AreEqual(5.0, result, 0.0001); convert result to double before comparing it with the expected value
    //        Assert::AreEqual(5.0, static_cast<double>(result), 0.0001);
    //    }

    //    TEST_METHOD(CalculateDistanceWithNegativeCoordinates)
    //    {
    //        struct Point p3 = { -1, -1 };
    //        struct Point p4 = { 2, 3 };
    //        double result = distance(&p3, &p4);
    //        //Assert::AreEqual(5.0, result, 0.0001);
    //        Assert::AreEqual(5.0, static_cast<double>(result), 0.0001);
    //    }

    //    TEST_METHOD(CalculateDistanceBetweenSamePoint)
    //    {
    //        struct Point p5 = { 0, 0 };
    //        struct Point p6 = { 0, 0 };
    //        double result = distance(&p5, &p6);
    //        //Assert::AreEqual(0.0, result, 0.0001);
    //        Assert::AreEqual(0.0, static_cast<double>(result), 0.0001);

    //    }
    //    TEST_METHOD(CalculateDistanceWithDecimalCoordinates)
    //    {
    //        struct Point p7 = { 1.5, 2.5 };
    //        struct Point p8 = { 4.5, 6.5 };
    //        double result = distance(&p7, &p8);
    //        Assert::AreEqual(5.0, static_cast<double>(result), 0.0001);
    //    }
    //};

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
