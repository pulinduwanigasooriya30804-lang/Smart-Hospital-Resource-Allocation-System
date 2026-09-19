#include <stdio.h>
#include "bed.h"

int bedOccupancy[MAX_WARDS][MAX_BEDS];

void initializeBeds()
{
    int i, j;

    for(i = 0; i < MAX_WARDS; i++)
    {
        for(j = 0; j < MAX_BEDS; j++)
        {
            bedOccupancy[i][j] = 0;
        }
    }
}

int findAvailableBed(int ward)
{
    int i;

    for(i = 0; i < wardCapacity[ward]; i++)
    {
        if(bedOccupancy[ward][i] == 0)
        {
            return i;
        }
    }

    return -1;
}

void displayBeds()
{
    int i, j;

    printf("\n========== BED STATUS ==========\n");

    for(i = 0; i < MAX_WARDS; i++)
    {
        printf("\n%s:\n", wardName[i]);

        for(j = 0; j < wardCapacity[i]; j++)
        {
            if(bedOccupancy[i][j] == 0)
            {
                printf("Bed %d : Available\n", j + 1);
            }
            else
            {
                printf("Bed %d : Occupied\n", j + 1);
            }
        }
    }
}
