#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "hospital.h"
#include "patient.h"

int bedOccupancy[MAX_WARDS][MAX_BEDS];

void initializeBeds();

int main()
{
    int choice;

    initializeBeds();

    printf("==========Smart Hospital System==========\n");
    return 0;
}

void initializeBeds()
{
    int i, j;
    for(i=0; i< MAX_WARDS; i++)
    {
        for(j=0; j < MAX_BEDS; j++)
        {
            bedOccupancy[i][j] = 0;
        }
    }
}

