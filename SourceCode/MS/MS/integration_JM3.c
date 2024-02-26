// integration_JM3

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include "shipment.h"
#include "integration.h"

// #1. Test cases for detectBuildings();
void intTest_detectBuildings()
{
    // Test Case 1: Route does not intersect with any buildings
    struct Point point1 = { 0, 0 };
    struct Point point2 = { 1, 1 };
    struct Point point3 = { 2, 2 };
    struct Route route1 = { {point1, point2, point3}, 3 }; // Route with three points
    struct Map map1 = {
        {
            {0, 0, 0},
            {0, 0, 0},
            {0, 0, 0}
        }
    };

    int expect1 = 0;
    int result1 = detectBuildings(route1, &map1);
    printf("Test case 1: Expected: %d, Result: %d\n", expect1, result1);

    // Test Case 2: Route intersects with a building
    struct Point point4 = { 1, 1 };
    struct Point point5 = { 2, 2 };
    struct Point point6 = { 1, 2 };
    struct Route route2 = { {point4, point5, point6}, 3 }; // Route with three points
    struct Map map2 = {
        {
            {0, 0, 0},
            {0, 2, 0},
            {0, 0, 0}
        }
    };

    int expect2 = 1;
    int result2 = detectBuildings(route2, &map2);
    printf("Test case 2: Expected: %d, Result: %d\n", expect2, result2);

    // Test Case 3: Route with Multiple Intersections
    struct Point point7 = { 1, 1 };
    struct Point point8 = { 2, 2 };
    struct Point point9 = { 1, 2 };
    struct Point point10 = { 2, 1 };
    struct Route route3 = { {point7, point8, point9, point10}, 4 }; // Route with four points
    struct Map map3 = {
        {
            {0, 0, 0},
            {0, 2, 0},
            {0, 0, 0}
        }
    };

    int expect3 = 1;
    int result3 = detectBuildings(route3, &map3);
    printf("Test case 3: Expected: %d, Result: %d\n", expect3, result3);

    // Test Case 4: Route Completely Outside the Map
    struct Point point11 = { 5, 5 };
    struct Point point12 = { 6, 6 };
    struct Route route4 = { {point11, point12}, 2 }; // Route with two points
    struct Map map4 = {
        {
            {0, 0, 0},
            {0, 0, 0},
            {0, 0, 0}
        }
    };

    int expect4 = 0;
    int result4 = detectBuildings(route4, &map4);
    printf("Test case 4: Expected: %d, Result: %d\n", expect4, result4);


    // Test Case 5: Route with No Intersections
    struct Point point13 = { 1, 1 };
    struct Point point14 = { 2, 2 };
    struct Route route5 = { {point13, point14}, 2 }; // Route with two points
    struct Map map5 = {
        {
            {0, 0, 0},
            {0, 0, 0},
            {0, 0, 0}
        }
    };

    int expect5 = 0;
    int result5 = detectBuildings(route5, &map5);
    printf("Test case 5: Expected: %d, Result: %d\n", expect5, result5);
}

// #2. Test cases for validateDestination();
void intTest_validateDestination()
{
    // Test case 1: Shipment destination is present in the route
    struct Point point1 = { 0, 0 };
    struct Point point2 = { 1, 1 };
    struct Point point3 = { 2, 2 };
    struct Point destination1 = { 2, 2 };
    struct Route route1 = { {point1, point2, point3}, 3 }; // Route with three points
    struct Shipment shipment1 = { 0, 0, destination1 };

    int result1 = validateDestination(&route1, shipment1);
    printf("Test case 1: Expected: 1, Result: %d\n", result1);

    // Test case 2: Shipment destination is not present in the route
    struct Point point4 = { 1, 1 };
    struct Point point5 = { 2, 2 };
    struct Point point6 = { 1, 2 };
    struct Point destination2 = { 0, 0 };
    struct Route route2 = { {point4, point5, point6}, 3 }; // Route with three points
    struct Shipment shipment2 = { 0, 0, destination2 };

    int result2 = validateDestination(&route2, shipment2);
    printf("Test case 2: Expected: 0, Result: %d\n", result2);

    // Test case 3: Empty route, destination should not be validated
    struct Route route3 = { NULL, 0 };
    struct Shipment shipment3 = { 1, 1, { 1, 1 } };

    int result3 = validateDestination(&route3, shipment3);
    printf("Test case 3: Expected: 0, Result: %d\n", result3);

    // Test case 4: Shipment destination matches the first point in the route
    struct Point point7 = { 0, 0 };
    struct Point point8 = { 1, 1 };
    struct Point point9 = { 2, 2 };
    struct Point destination3 = { 0, 0 };
    struct Route route4 = { {point7, point8, point9}, 3 }; // Route with three points
    struct Shipment shipment4 = { 1, 1, destination3 };

    int result4 = validateDestination(&route4, shipment4);
    printf("Test case 4: Expected: 1, Result: %d\n", result4);

    // Test case 5: Shipment destination matches the last point in the route
    struct Point point10 = { 0, 0 };
    struct Point point11 = { 1, 1 };
    struct Point point12 = { 2, 2 };
    struct Point destination4 = { 2, 2 };
    struct Route route5 = { {point10, point11, point12}, 3 }; // Route with three points
    struct Shipment shipment5 = { 1, 1, destination4 };

    int result5 = validateDestination(&route5, shipment5);
    printf("Test case 5: Expected: 1, Result: %d\n", result5);

    // Test case 6: Shipment destination matches a middle point in the route
    struct Point point13 = { 0, 0 };
    struct Point point14 = { 1, 1 };
    struct Point point15 = { 2, 2 };
    struct Point destination5 = { 1, 1 };
    struct Route route6 = { {point13, point14, point15}, 3 }; // Route with three points
    struct Shipment shipment6 = { 1, 1, destination5 };

    int result6 = validateDestination(&route6, shipment6);
    printf("Test case 6: Expected: 1, Result: %d\n", result6);

    // Test case 7: Shipment destination is outside the route bounds
    struct Point point16 = { 0, 0 };
    struct Point point17 = { 1, 1 };
    struct Point point18 = { 2, 2 };
    struct Point destination6 = { 3, 3 };
    struct Route route7 = { {point16, point17, point18}, 3 }; // Route with three points
    struct Shipment shipment7 = { 1, 1, destination6 };

    int result7 = validateDestination(&route7, shipment7);
    printf("Test case 7: Expected: 0, Result: %d\n", result7);

}
void integrationJM3(){
    printf("#3.Test cases for detectBuilding\n");
    intTest_detectBuildings();
    printf("\n");

    printf("#4.Test cases for validateDestination\n");
    intTest_validateDestination();
    printf("\n");
}
