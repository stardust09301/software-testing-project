// integration_JM4.c
//Scenario : Invalid Destination
//Objective : Test the scenario where the shipment has an invalid destination.

#include <stdio.h>
#include "mapping.h"
#include "shipment.h"
#include "integration.h"

void integrationJM4() {
    // Initialize a map
    struct Map deliveryMap = populateMap();

    // Test 1: Invalid Destination - Test case from the original code
    struct Shipment invalidDestinationShipment1;
    invalidDestinationShipment1.box.weight = 700;
    invalidDestinationShipment1.box.volume = 1;
    invalidDestinationShipment1.destination.row = 30;  // Invalid row
    invalidDestinationShipment1.destination.col = 'F';

    // Validate the destination
    int isValidDestination1 = validateDestination(&deliveryMap.routes, invalidDestinationShipment1);

    // Perform integration testing
    if (!isValidDestination1) {
        printf("Integration Test 1 Passed: Invalid Destination\n");
    }
    else {
        printf("Integration Test 1 Failed: Invalid Destination\n");
    }

    // Test 2: Invalid Destination - Additional Test case 1
    struct Shipment invalidDestinationShipment2;
    invalidDestinationShipment2.box.weight = 500;
    invalidDestinationShipment2.box.volume = 2;
    invalidDestinationShipment2.destination.row = 15;
    invalidDestinationShipment2.destination.col = 'K';  // Invalid column

    // Validate the destination
    int isValidDestination2 = validateDestination(&deliveryMap.routes, invalidDestinationShipment2);

    // Perform integration testing
    if (!isValidDestination2) {
        printf("Integration Test 2 Passed: Invalid Destination\n");
    }
    else {
        printf("Integration Test 2 Failed: Invalid Destination\n");
    }

    // Test 3: Invalid Destination - Additional Test case 2
    struct Shipment invalidDestinationShipment3;
    invalidDestinationShipment3.box.weight = 900;
    invalidDestinationShipment3.box.volume = 1;
    invalidDestinationShipment3.destination.row = 20;  // Invalid row
    invalidDestinationShipment3.destination.col = 'Z';  // Invalid column

    // Validate the destination
    int isValidDestination3 = validateDestination(&deliveryMap.routes, invalidDestinationShipment3);

    // Perform integration testing
    if (!isValidDestination3) {
        printf("Integration Test 3 Passed: Invalid Destination\n");
    }
    else {
        printf("Integration Test 3 Failed: Invalid Destination\n");
    }

    // Test 4: Invalid Destination - Additional Test case 3
    struct Shipment invalidDestinationShipment4;
    invalidDestinationShipment4.box.weight = 600;
    invalidDestinationShipment4.box.volume = 2;
    invalidDestinationShipment4.destination.row = 25;
    invalidDestinationShipment4.destination.col = '1';  // Invalid column

    // Validate the destination
    int isValidDestination4 = validateDestination(&deliveryMap.routes, invalidDestinationShipment4);

    // Perform integration testing
    if (!isValidDestination4) {
        printf("Integration Test 4 Passed: Invalid Destination\n");
    }
    else {
        printf("Integration Test 4 Failed: Invalid Destination\n");
    }

    return 0;
}

