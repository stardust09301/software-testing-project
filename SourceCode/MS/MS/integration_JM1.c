// integration_JM1.c
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include "shipment.h"
#include "integration.h"

// #1 Test cases for checkTruckWeightCap();
void intTest_checkTruckWeightCap()
{
    // Test case 1: Truck's weight capacity is 1500, and shipment weight is 1450
    struct Truck truck1 = { 1500 };
    struct Shipment shipment1 = { 1450 };
    int result1 = checkTruckWeightCap(truck1, shipment1);
    printf("Test case 1: Expected: 1, Result: %d\n", result1);

    // Test case 2: Truck's weight capacity is 300, and shipment weight is 300
    struct Truck truck2 = { 300 };
    struct Shipment shipment2 = { 300 };
    int result2 = checkTruckWeightCap(truck2, shipment2);
    printf("Test case 2: Expected: 1, Result: %d\n", result2);

    // Test case 3: Truck's weight capacity is not exceeded
    struct Truck truck3 = { 700 };
    struct Shipment shipment3 = { 200 };
    int result3 = checkTruckWeightCap(truck3, shipment3);
    printf("Test case 3: Expected: 1, Result: %d\n", result3);

    // Test case 4: Truck's weight capacity is exactly 1000
    struct Truck truck4 = { 1000 };
    struct Shipment shipment4 = { 0 };
    int result4 = checkTruckWeightCap(truck4, shipment4);
    printf("Test case 4: Expected: 1, Result: %d\n", result4);

}
// #2. Test cases for bestRoute();
void intTest_bestRoute()
{
    // Test case 1: No routes available
    struct Route* routes1[MAX_ROUTE] = { NULL };
    struct Shipment shipment1 = { 0, 0, {3, 3} };
    int size1 = 0;

    int result1 = bestRoute(routes1, shipment1, size1);
    printf("Test case 1: Expected: -1 (No routes available), Result: %d\n", result1);

    // Test case 2: Single route, shortest distance
    struct Point point2_1 = { 0, 0 };
    struct Point point2_2 = { 3, 4 };
    struct Point point2_3 = { 5, 5 };
    struct Route route2 = { {point2_1, point2_2, point2_3}, 3 }; // Route with three points
    struct Route* routes2[MAX_ROUTE] = { &route2 };
    struct Shipment shipment2 = { 0, 0, {5, 5} };
    int size2 = 1;

    int result2 = bestRoute(routes2, shipment2, size2);
    printf("Test case 2: Expected: 0, Result: %d\n", result2);

    // Test case 3: Single route, equal distances
    struct Point point3_1 = { 0, 0 };
    struct Point point3_2 = { 3, 4 };
    struct Point point3_3 = { 5, 5 };
    struct Route route3 = { {point3_1, point3_2, point3_3}, 3 }; // Route with three points
    struct Route* routes3[MAX_ROUTE] = { &route3 };
    struct Shipment shipment3 = { 0, 0, {5, 5} };
    int size3 = 1;

    int result3 = bestRoute(routes3, shipment3, size3);
    printf("Test case 3: Expected: 0, Result: %d\n", result3);

    // Test case 4: Multiple routes, different distances
    struct Point point4_1 = { 0, 0 };
    struct Point point4_2 = { 1, 1 };
    struct Point point4_3 = { 3, 3 };
    struct Point point4_4 = { 5, 5 };
    struct Route route4_1 = { {point4_1, point4_2, point4_3}, 3 }; // Route with three points
    struct Route route4_2 = { {point4_4, point4_1, point4_2, point4_3}, 4 }; // Route with four points
    struct Route* routes4[MAX_ROUTE] = { &route4_1, &route4_2 };
    struct Shipment shipment4 = { 0, 0, {5, 5} };
    int size4 = 2;

    int result4 = bestRoute(routes4, shipment4, size4);
    printf("Test case 4: Expected: 1, Result: %d\n", result4);

    // Test case 5: No routes available
    struct Route* routes5[MAX_ROUTE] = { NULL };
    struct Shipment shipment5 = { 0, 0, {3, 3} };
    int size5 = 0;

    int result5 = bestRoute(routes5, shipment5, size5);
    printf("Test case 5: Expected: -1 (No routes available), Result: %d\n", result5);
}
void integrationJM1()
{
    printf("#1.Test cases for checkTruckWeightCap\n");
    intTest_checkTruckWeightCap();
    printf("\n");

    printf("#2.Test cases for bestRoute\n");
    intTest_bestRoute();
    printf("\n");
}
