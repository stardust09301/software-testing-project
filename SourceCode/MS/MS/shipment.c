// new source file
//MS5 V1
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <limits.h>
#include "mapping.h"
#include "shipment.h"


struct Size calCapacity(const struct Truck truck) {
    struct Size capacity;
    //When truck has nothing loaded
    if (truck.loaded.weight == 0 && truck.loaded.volume == 0) {
        capacity.weight = MAX_WEIGHT;
        capacity.volume = MAX_VOLUME;
    }
    //When truck has loaded boxes with some but not full
    else if (truck.loaded.weight < MAX_WEIGHT && truck.loaded.volume < MAX_VOLUME) {
        capacity.weight = MAX_WEIGHT - truck.loaded.weight;
        capacity.volume = MAX_VOLUME - truck.loaded.volume;
    }
    //When truck is full
    else {
        capacity.weight = 0;
        capacity.volume = 0;
    }
    return capacity;
}

int validateDestination(const struct Route* route, struct Shipment input) {
    int i, valid = 0;
    for (i = 0; i < route->numPoints; i++) {
        //comparing rows&columns if any matches
        if (route->points[i].row == input.destination.row && route->points[i].col == input.destination.col) {
            valid = 1;
        }
    }
    return valid;
}

int validateBox(struct Shipment input) {
    //if both weight & volume are valid, return code 0
    int inValidCode = 0;
    //if weight is not valid, return code 1
    if (input.box.weight < 1 || input.box.weight > 1000) {
        inValidCode = 1;
    }
    //if weight is valid but volume is invalid, return code 2
    else {
        if (!(input.box.volume == BOX_SIZE_1 || input.box.volume == BOX_SIZE_2 || input.box.volume == BOX_SIZE_3)) {
            inValidCode = 2;
        }
    }
    return inValidCode;
}


int checkTruckWeightCap(struct Truck truck, struct Shipment shipment) {
    int notFull = 0;
    if (truck.Capacity.weight <= MAX_WEIGHT) {
        truck.loaded.weight += shipment.box.weight;
        if (truck.loaded.weight <= MAX_WEIGHT) {
            notFull = 1;
        }
    }
    return notFull;
}

int checkTruckVolCap(struct Truck truck, float volume) {
    int notFull = 0;
    if (truck.Capacity.volume <= MAX_VOLUME) {
        truck.Capacity.volume += volume;
        if (truck.Capacity.volume <= MAX_VOLUME) {
            notFull = 1;
        }
    }
    return notFull;
}

int detectBuildings(const struct Route route, const struct Map* map) {
    for (int i = 0; i < route.numPoints; i++)
    {
        // Check if the point in the route is a building on the map
        if (map->squares[route.points[i].row][route.points[i].col] == 2)
        {
            return 1; // The route intersects with a building
        }
    }
    return 0; // The route does not intersect with any buildings
}

void possibleTruckRoute(struct Shipment shipment, struct Truck truck, const struct Map* map, struct Route routes[MAX_ROUTE], int* size) {
    int count = 0;
    for (int i = 0; i < truck.allocatedShipments; i++)
    {
        // Check if the truck's destination count matches the shipment's destination
        if (truck.noOfDestinations[i] == validateDestination(&routes[i], shipment))
        {
            // Check if the route intersects with buildings on the map
            if (!detectBuildings(routes[i], map))
            {
                routes[count++] = routes[i];
            }
        }
    }
    *size = count;
}

int validBoxWeight(int weight) {
    int result = 0;
    if (weight < MIN_WEIGHT || weight > MAX_WEIGHT) {
        result = 1;
    }

    return result;
}

int validBoxSize(double boxSize) {
    const double small = 0.5;
    const double midium = 1.0;
    const double large = 2.0;

    int result = 0;

    if (boxSize == small || boxSize == midium || boxSize == large)
    {
        result = 1;
    }
    else
    {
        printf("Box size is not valid.\n");
    }

    return result;
}

int bestRoute(struct Route* routes[MAX_ROUTE], struct Shipment input, int size) {
    double shortDistance = INT_MAX;
    int shortIndex = -1;
    int i;
    double route;

    for (i = 0; i < size; i++)
    {
        route = distance(&routes[i]->points[0], &input.destination);
        if (route < shortDistance)
        {

            shortDistance = route;
            shortIndex = i;
        }
    }

    return shortIndex;
}
