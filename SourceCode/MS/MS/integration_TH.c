
#include "mapping.h"
#include "shipment.h"
#include "integration.h"
#include <assert.h>

// #1 Test cases for getNumRow
void intTest_getNumRow()
{
    // Test case 1: Map with 5 rows
    struct Map testMap1 = populateMap();
    int numRows1 = getNumRow(&testMap1);
    printf("Test case 1: Expected: 5, Result: %d\n", numRows1);

    // Test case 2: Map with 3 rows
    struct Map testMap2;
    testMap2.numRows = 3;
    testMap2.numCols = 4;
    int numRows2 = getNumRow(&testMap2);
    printf("Test case 2: Expected: 3, Result: %d\n", numRows2);
}

// #2 Test cases for getNumCols
void intTest_getNumCols()
{
    // Test case 1: Map with 6 columns
    struct Map testMap1 = populateMap();
    int numCols1 = getNumCols(&testMap1);
    printf("Test case 1: Expected: 6, Result: %d\n", numCols1);

    // Test case 2: Map with 2 columns
    struct Map testMap2;
    testMap2.numRows = 4;
    testMap2.numCols = 2;
    int numCols2 = getNumCols(&testMap2);
    printf("Test case 2: Expected: 2, Result: %d\n", numCols2);
}

void integrationTH()
{
    printf("#1. Test cases for getNumRow\n");
    intTest_getNumRow();
    printf("\n");

    printf("#2. Test cases for getNumCols\n");
    intTest_getNumCols();
    printf("\n");
}
