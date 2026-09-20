#include <stdio.h>
#include <string.h>
#include "patient.h"
#include "hospital.h"
#include "bed.h"
#include "billing.h"

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

int specialtyQueue[4] = {0, 0, 0, 0};

void registerPatient()
{
    if(patientCount >= MAX_PATIENTS)
    {
        printf("\nPatient limit reached.\n");
        return;
    }

    printf("\n========== PATIENT REGISTRATION ==========\n");

    printf("Enter patient name: ");
    scanf(" %49[^\n]", patientName[patientCount]);

    printf("Enter age: ");
    scanf("%d", &patientAge[patientCount]);

    printf("\nUrgency Level\n");
    printf("1. Normal\n");
    printf("2. Urgent\n");
    printf("3. Emergency\n");

    printf("Enter urgency level: ");
    scanf("%d", &urgencyLevel[patientCount]);

    displaySpecialties();

    printf("\nSelect specialty: ");
    scanf("%d", &patientSpecialty[patientCount]);

    patientSpecialty[patientCount]--;

    admitted[patientCount] = 0;
    patientWard[patientCount] = -1;
    admittedDays[patientCount] = 0;
    assignedBed[patientCount] = -1;

    baseFee[patientCount] =
        consultationFee[patientSpecialty[patientCount]];

    surcharge[patientCount] = 0;
    wardCost[patientCount] = 0;
    grossTotal[patientCount] = baseFee[patientCount];
    discount[patientCount] = 0;
    finalAmount[patientCount] = baseFee[patientCount];
    waitingTime[patientCount] = 0;

    printf("\nDo you want to admit the patient?\n");
    printf("1. Yes\n");
    printf("2. No\n");

    printf("Enter choice: ");
    scanf("%d", &admitted[patientCount]);

    if(admitted[patientCount] == 1)
    {
        displayWards();

        printf("\nSelect ward: ");
        scanf("%d", &patientWard[patientCount]);

        patientWard[patientCount]--;

        printf("Enter number of admitted days: ");
        scanf("%d", &admittedDays[patientCount]);
    }
    else
    {
        patientWard[patientCount] = -1;
        admittedDays[patientCount] = 0;
    }

   specialtyQueue[patientSpecialty[patientCount]]++;

   patientCount++;

   allocateBed(patientCount - 1);

   surcharge[patientCount - 1] =
       calculateSurcharge(
           baseFee[patientCount - 1],
           urgencyLevel[patientCount - 1]
       );

   wardCost[patientCount - 1] =
       calculateWardCost(
           patientWard[patientCount - 1],
           admittedDays[patientCount - 1]
       );

   grossTotal[patientCount - 1] =
       baseFee[patientCount - 1]
       + surcharge[patientCount - 1]
       + wardCost[patientCount - 1];

   discount[patientCount - 1] =
       calculateDiscount(
           grossTotal[patientCount - 1],
           patientAge[patientCount - 1]
       );

   finalAmount[patientCount - 1] =
       grossTotal[patientCount - 1]
       - discount[patientCount - 1];

   printf("\nPatient registered successfully!\n");

   displayPatientBill(patientCount -1);
}


void allocateBed(int index)
{
    int bed;

    if(admitted[index] != 1)
    {
        return;
    }

    bed = findAvailableBed(patientWard[index]);

    if(bed == -1)
    {
        printf("\nNo available bed in the selected ward.\n");

        assignedBed[index] = -1;

        return;
    }

    assignedBed[index] = bed;

    bedOccupancy[patientWard[index]][bed] = 1;

    printf("\nBed allocated successfully!\n");
    printf("Ward : %s\n", wardName[patientWard[index]]);
    printf("Bed  : %d\n", bed + 1);
}
