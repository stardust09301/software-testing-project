// integration_TH3.c
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include "shipment.h"
#include "integration.h"

// Test cases for validBoxSize
void intTest_validBoxSize()
{
    // Test case 1: Valid box size
    struct Shipment shipment1 = { {100, 5.0}, {0, 0} };
    int result1 = validBoxSize(shipment1.box.volume);
    printf("Test case 1: Expected: 0 (Valid box size), Result: %d\n", result1);

    // Test case 2: Invalid box weight
    struct Shipment shipment2 = { {-10, 5.0}, {0, 0} };
    int result2 = validBoxSize(shipment2.box.volume);
    printf("Test case 2: Expected: 1 (Invalid box weight), Result: %d\n", result2);

    // Test case 3: Invalid box volume
    struct Shipment shipment3 = { {50, -3.0}, {0, 0} };
    int result3 = validBoxSize(shipment3.box.volume);
    printf("Test case 3: Expected: 2 (Invalid box volume), Result: %d\n", result3);

    // Test case 4: Valid box size
    struct Shipment shipment4 = { {75, 7.5}, {0, 0} };
    int result4 = validBoxSize(shipment4.box.volume);
    printf("Test case 4: Expected: 0 (Valid box size), Result: %d\n", result4);
}


// Test cases for validBoxWeight
void intTest_validBoxWeight()
{
    // Test case 1: Valid box weight
    int weight1 = 30;
    int result1 = validBoxWeight(weight1);
    printf("Test case 1: Expected: 0 (Valid box weight), Result: %d\n", result1);

    // Test case 2: Invalid box weight
    int weight2 = -5;
    int result2 = validBoxWeight(weight2);
    printf("Test case 2: Expected: 1 (Invalid box weight), Result: %d\n", result2);

    // Test case 3: Valid box weight
    int weight3 = 50;
    int result3 = validBoxWeight(weight3);
    printf("Test case 3: Expected: 0 (Valid box weight), Result: %d\n", result3);

    // Test case 4: Valid box weight
    int weight4 = 0;
    int result4 = validBoxWeight(weight4);
    printf("Test case 4: Expected: 0 (Valid box weight), Result: %d\n", result4);
}

void integrationTH3()
{
    printf("#1. Test cases for validBoxSize\n");
    intTest_validBoxSize();
    printf("\n");

    printf("#2. Test cases for validBoxWeight\n");
    intTest_validBoxWeight();
    printf("\n");
}
