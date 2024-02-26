// integration_JM2.c
#include "mapping.h"
#include "shipment.h"
#include "integration.h"
#include <assert.h>

void integrationJM2() {
    // Test the distance function
    struct Point point1 = { 0, 0 };
    struct Point point2 = { 3, 4 };
    double calculatedDistance = distance(&point1, &point2);
    assert(calculatedDistance == 5.0);

    // Test the addPointToRoute function
    struct Route testRoute = { {0, 0}, 0, DIVERSION };
    addPointToRoute(&testRoute, 1, 2);
    addPointToRoute(&testRoute, 3, 4);
    assert(testRoute.numPoints == 2);

    // Test the getPossibleMoves function
    struct Map testMap = populateMap();
    struct Point currentPoint = { 1, 1 };
    struct Point backpath = { 0, 0 };
    struct Route possibleMoves = getPossibleMoves(&testMap, currentPoint, backpath);
    assert(possibleMoves.numPoints > 0);

    // Additional test cases for addPointToRoute function
    addPointToRoute(&testRoute, 5, 6);
    assert(testRoute.numPoints == 3);

    // Additional test cases for getPossibleMoves function
    struct Point currentPoint2 = { 0, 0 };
    struct Point backpath2 = { 1, 1 };
    struct Route possibleMoves2 = getPossibleMoves(&testMap, currentPoint2, backpath2);
    assert(possibleMoves2.numPoints == 2);  // Two valid moves: (0,1) and (1,0)

    printf("Integration test for multiple path functions passed!\n");
}
