#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include "shipment.h"
#include "integration.h"
void integrationHJ() {
    /*When there is capacity for both weight and volume
    * shipment_a : valid input
    * shipment_b : invalid weight
    * shipmnet_c : invalid volume
    */
    struct Truck truck1 = { 1, {1000,47}, {0,0}, 0, 0 };
    struct Shipment testShipment1_a = { {30,0.5},{'a',1} };
    struct Shipment testShipment1_b = { {1000,1},{'a',1} };
    struct Shipment testShipment1_c = { {100,2.0},{'a',1} };
    
    if (intergrationTest_capacity(truck1, testShipment1_a)) { printf("Test passed\n"); }
    else { printf("Test failed\n"); };
    if (!intergrationTest_capacity(truck1, testShipment1_b)) { printf("Test passed\n"); }
    else { printf("Test failed\n"); };
    if (intergrationTest_capacity(truck1, testShipment1_c)) { printf("Test passed\n"); }
    else { printf("Test failed\n"); }

    /*when truck is empty
    * shipment_a : valid input
    * shipment_b : invalid weight
    * shipment_c : invalid volume
    */
    struct Truck truck2 = { 2, {0,0}, {0,0}, 0,0 };
    struct Shipment testShipment2_a = { {30,0.5},{'a',1} };
    struct Shipment testShipment2_b = { {3000,1},{'a',1} };
    struct Shipment testShipment2_c = { {100,50},{'a',1} };

    if (intergrationTest_capacity(truck2, testShipment2_a)) { printf("Test passed\n"); }
    else { printf("Test failed\n"); }
    if (!intergrationTest_capacity(truck2, testShipment2_b)) { printf("Test passed\n"); }
    else { printf("Test failed\n"); }
    if (intergrationTest_capacity(truck2, testShipment2_c)) { printf("Test passed\n"); }
    else { printf("Test failed\n"); }

    /*when there is no capacity for weight
    * shipment_a : valid input
    * shipment_b : invalid weight
    */
    struct Truck truck3 = { 3, {1500, 2.0}, {0,0},0,0 };
    struct Shipment testShipment3_a = { {30,0.5},{'a',1} };
    struct Shipment testShipment3_b = { {100,50},{'a',1} };

    if (!intergrationTest_capacity(truck3, testShipment3_a)) { printf("Test passed\n"); }
    else { printf("Test failed\n"); }
    if (!intergrationTest_capacity(truck3, testShipment3_b)) { printf("Test passed\n"); }
    else { printf("Test failed\n"); }

    
    /*when there is no capacity for volume
    * shipment_a : valid input
    * shipment_b : invalid input
    */
    struct Truck truck4 = { 4, {500, 48},{0,0},0,0 };
    struct Shipment testShipment4_a = { {30,0.5},{'a',1} };
    struct Shipment testShipment4_b = { {3000,1},{'a',1} };    

    if (intergrationTest_capacity(truck4, testShipment4_a)) { printf("Test passed\n"); }
    else { printf("Test failed\n"); }
    if (!intergrationTest_capacity(truck4, testShipment4_b)) { printf("Test passed\n"); }
    else { printf("Test failed\n"); }
}

int intergrationTest_capacity(struct Truck testTruck, struct Shipment testShipment) {
    int weightCheck;
    int result;
    testTruck.Capacity = calCapacity(testTruck);
    weightCheck = checkTruckWeightCap(testTruck, testShipment);
    if (weightCheck) {
        //when truck is not full
        result = 1;
    }
    else {
        //when truck is full
        result = 0;
    }
    return result;
}