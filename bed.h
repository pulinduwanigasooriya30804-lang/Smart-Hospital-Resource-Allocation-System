#ifndef BED_H
#define BED_H

#include "hospital.h"

extern int bedOccupancy[MAX_WARDS][MAX_BEDS];

void initializeBeds();
int findAvailableBed(int ward);
void displayBeds();
void saveBeds();
void loadBeds();

#endif
