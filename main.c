#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "hospital.h"

#define MAX_PATIENTS 100
#define MAX_NAME 50

int patientCount = 0;

char patientName[MAX_PATIENTS][MAX_NAME];
int patientAge[MAX_PATIENTS];
int urgencyLevel[MAX_PATIENTS];
int patientSpecialty[MAX_PATIENTS];
int admitted[MAX_PATIENTS];
int patientWard[MAX_PATIENTS];
int admittedDays[MAX_PATIENTS];
int assignedBed[MAX_PATIENTS];

double baseFee[MAX_PATIENTS];
double surcharge[MAX_PATIENTS];
double wardCost[MAX_PATIENTS];
double grossTotal[MAX_PATIENTS];
double discount[MAX_PATIENTS];
double finalAmount[MAX_PATIENTS];
double waitingTime[MAX_PATIENTS];

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

