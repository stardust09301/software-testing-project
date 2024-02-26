
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include "mapping.h"
#include "shipment.h"

int main(void)
{
    struct Map baseMap = populateMap();
    struct Route blueRoute = getBlueRoute();
    struct Route greenRoute = getGreenRoute();
    struct Route yellowRoute = getYellowRoute();
    struct Map routeMap = addRoute(&baseMap, &blueRoute);
    routeMap = addRoute(&routeMap, &greenRoute);
    routeMap = addRoute(&routeMap, &yellowRoute);
    routeMap = addRoute(&routeMap, &blueRoute);

    struct Shipment input;
    int weight;
    float boxSize;
    int destination1;
    char destination2;
    int flag = 1;

    while (flag)
    {
        printf("Enter shipment weight, box size and destination (0 0 x to stop): ");
        scanf("%d %f %d %c", &weight, &boxSize, &destination1, &destination2);

        if (weight == 0 && boxSize == 0)
            break;

        input.box.weight = weight;

        if (weight < 1 || weight > 1000)
        {
            printf("Invalid weight (must be 1-1000 Kg.)\n");
            continue;
        }

        if (!validBoxSize(boxSize))
        {
            continue;
        }

        int row = 0;
        int col = 0;

        if (destination2 >= 'A' && destination2 <= 'Y')
        {
            // row = destination[0] = 'A';  // This line does not update 'row'.
            if (destination1 >= 1 && destination1 <= 25)
            {
                // col = destination[1] - '0';  // This line does not update 'col'.
                if (row >= 0 && row < routeMap.numRows && col >= 0 && col < routeMap.numCols)
                {
                    // struct Point dest = {row, col};  // This line is commented out, and 'dest' is not used.
                    int size = 0;
                    struct Route* validRoutes[MAX_ROUTE] = { 0 };

                    validRoutes[0] = malloc(sizeof(struct Route));
                    validRoutes[1] = malloc(sizeof(struct Route));
                    validRoutes[2] = malloc(sizeof(struct Route));

                    // Call possibleTruckRoute for each truck
                    possibleTruckRoute(input, *routeMap.trucks[0], &routeMap, validRoutes, &size);
                    possibleTruckRoute(input, *routeMap.trucks[1], &routeMap, validRoutes, &size);
                    possibleTruckRoute(input, *routeMap.trucks[2], &routeMap, validRoutes, &size);

                    int shortestRouteIndex = bestRoute(validRoutes, input, size);

                    if (shortestRouteIndex != -1)
                    {
                        struct Route shortestRoute = *validRoutes[shortestRouteIndex];
                        printf("Ship on ");
                        if (shortestRoute.routeSymbol == BLUE)
                            printf("BLUE LINE");
                        else if (shortestRoute.routeSymbol == GREEN)
                            printf("GREEN LINE");
                        else if (shortestRoute.routeSymbol == YELLOW)
                            printf("YELLOW LINE");
                        printf(", no diversion\n");
                    }
                    else
                    {
                        printf("No valid route found to the destination\n");
                    }
                }
                else
                {
                    printf("Invalid destination\n");
                }
            }
            else
            {
                printf("Invalid destination\n");
            }
        }
        else
        {
            printf("Invalid destination\n");
        }
    }

    printf("Thanks for shipping with Seneca!\n");
    return 0;
}