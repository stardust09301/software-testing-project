#include "pch.h"
#include "CppUnitTest.h"
#include "shipment_r.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTests
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
        
        TEST_METHOD(PartiallyLoadedTruck)
        {
            struct Truck partiallyLoadedTruck = { 2, {1000.0f, 30.0f}, {0.0f, 0.0f}, 0, nullptr };
            struct Size result = calCapacity(partiallyLoadedTruck);

            Assert::AreEqual(result.weight, static_cast<float>(1500 - 1000.0f));
            Assert::AreEqual(result.volume, static_cast<float>(48 - 30.0f));
        }
        
    };
}
