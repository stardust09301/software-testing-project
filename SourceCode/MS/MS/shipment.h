// new header file
//M5 V1
#include <stdio.h>
#include "mapping.h"


#define MIN_WEIGHT 1
#define MAX_WEIGHT 1500
#define MAX_VOLUME 48
#define BOX_SIZE_1 0.5
#define BOX_SIZE_2 1
#define BOX_SIZE_3 2

//STRUCTURES
/*A Size to use for measuring everything regarding size of shipment*/
struct Size
{
    float weight;
    float volume;
};

/*Shipment information*/
struct Shipment
{
    struct Size box;
    struct Point destination;
};

/*Truck information*/
struct Truck
{
    int truckId;
    struct Size loaded;
    struct Size Capacity;
    int allocatedShipments;
    int* noOfDestinations;
};

//FUNCTIONS

/**
* It calculates the remaining capacity of a truck based on the loaded weight and volume of the items in the truck.
* This function provides a way to determine the remaining capacity of a truck based on its loaded weight and volume,
  considering different scenarios.
* @param p - struct Truck that has information about loaded boxes
* @returns - Capacity
*/
struct Size calCapacity(const struct Truck truck);

/**
* This function essentially checks whether the destination specified in the input shipment exists in the provided route.
  If a match is found, it sets valid to 1, indicating a valid destination, and returns this status. If no match is found,
it returns 0, indicating an invalid destination.
* @param p1 - passing pointer to the constant Shipment route
* @param p2 - customer input struct Shipment
* @return - 1 if customer input has valid destination
*           0 if customer input has invalid destination
*/
int validateDestination(const struct Route* route, struct Shipment input);

/*
* Validate box size of customer input
* @param - customer input box size
* return - integer code indicating the validity status of the box within the shipment
*        0 if size of the box is valid
*        1 if size of the box is invalid
*/
int validBoxSize(double boxSize);

/*
* Validate box weight of customer input
* @param - customer input box weight
* return - integer code indicating the validity status of the box within the shipment
*        0 if weight of the box is valid
*        1 if weight of the box is invalid
*/
int validBoxWeight(int weight);

/**
* Validate box size of customer input
* This function provides a simple way to check the validity of the weight and volume of a box within a shipment.
* @param p - customer input struct Shipment
* @returns - integer code indicating the validity status of the box within the shipment
             0 if size of the box is valid
             1 if weight of the box is invalid
*            2 if volume of the box is invalid

int validateBox(struct Shipment input);*/

/**
* Check if the truck can take box by checking capacity
* @param p1 - the truck that we want to check
* @param p2 - the shipment with it's weight
* @returns - 1 if there is capacity, 0 if there is no capacity
*/
int checkTruckWeightCap(struct Truck truck, struct Shipment shipment);

/*
checks if a given route intersects with any buildings on the map.
route (const struct Route): The route to check for intersections with buildings.
map (const struct Map *): A pointer to the Map structure containing the buildings on the map.
returns an integer value: 1 if the route intersects with a building, and 0 if it does not
*/
int detectBuildings(const struct Route route, const struct Map* map);


/**
*Get all possible Truck route for shipment
* @param p1 - customer shipment information
* @param p2 - passing map with all route
* @return - array of struct Route with the members of possible route
*/
void possibleTruckRoute(struct Shipment shipment, struct Truck truck, const struct Map* map, struct Route routes[MAX_ROUTE], int* size);

/**
*Get best route for shipment
* @paran p1 - shipment information
* @param p2 - passing map with all route
* @param p3 -
* @return - Struct route(best one)
*/
int bestRoute(struct Route* routes[MAX_ROUTE], struct Shipment shipment, int size);
