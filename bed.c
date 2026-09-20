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

void saveBeds()
{
    FILE *file;
    int i, j;

    file = fopen("beds_status.txt", "w");

    if(file == NULL)
    {
        printf("\nError opening beds_status.txt\n");
        return;
    }

    for(i = 0; i < MAX_WARDS; i++)
    {
        fprintf(file, "%s\n", wardName[i]);

        for(j = 0; j < wardCapacity[i]; j++)
        {
            fprintf(file, "%d %d\n",
                    j + 1,
                    bedOccupancy[i][j]);
        }
    }

    fclose(file);

    printf("\nBed data saved successfully.\n");
}
