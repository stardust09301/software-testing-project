#include "pch.h"
#include "CppUnitTest.h"
#include "shipment_r.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTestcheckTruckWeightCap
{
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
}
