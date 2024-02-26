#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <float.h>
#include <ctype.h>
#include "tests.h"
#include "mapping.h"
#include "shipment.h"
#include "mapping.h"



//if box weight is between the range it returns 1(true) else 0(false)
int validatePackageWeight(double num) {
	return (num >= MIN_WEIGHT && num <= MAX_WEIGHT) ? 1 : 0;
}


//if box is equal to any of the valid cubic meters it returns 1(true) else 0(false)
int validatePackageBox(double num) {

	return (num == BOX_SIZE_1 || num == BOX_SIZE_2 || num == BOX_SIZE_3) ? 1 : 0;
}
