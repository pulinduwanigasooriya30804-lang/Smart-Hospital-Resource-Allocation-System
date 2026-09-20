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

void sortPatientsByPriority()
{
    int i, j, maxIndex;

    for(i = 0; i < patientCount - 1; i++)
    {
        maxIndex = i;

        for(j = i + 1; j < patientCount; j++)
        {
            if(urgencyLevel[j] > urgencyLevel[maxIndex])
            {
                maxIndex = j;
            }
        }

        if(maxIndex != i)
        {
            int tempInt;
            double tempDouble;
            char tempName[MAX_NAME];

            strcpy(tempName, patientName[i]);
            strcpy(patientName[i], patientName[maxIndex]);
            strcpy(patientName[maxIndex], tempName);

            tempInt = patientAge[i];
            patientAge[i] = patientAge[maxIndex];
            patientAge[maxIndex] = tempInt;

            tempInt = urgencyLevel[i];
            urgencyLevel[i] = urgencyLevel[maxIndex];
            urgencyLevel[maxIndex] = tempInt;

            tempInt = patientSpecialty[i];
            patientSpecialty[i] = patientSpecialty[maxIndex];
            patientSpecialty[maxIndex] = tempInt;

            tempInt = admitted[i];
            admitted[i] = admitted[maxIndex];
            admitted[maxIndex] = tempInt;

            tempInt = patientWard[i];
            patientWard[i] = patientWard[maxIndex];
            patientWard[maxIndex] = tempInt;

            tempInt = admittedDays[i];
            admittedDays[i] = admittedDays[maxIndex];
            admittedDays[maxIndex] = tempInt;

            tempInt = assignedBed[i];
            assignedBed[i] = assignedBed[maxIndex];
            assignedBed[maxIndex] = tempInt;

            tempDouble = baseFee[i];
            baseFee[i] = baseFee[maxIndex];
            baseFee[maxIndex] = tempDouble;

            tempDouble = surcharge[i];
            surcharge[i] = surcharge[maxIndex];
            surcharge[maxIndex] = tempDouble;

            tempDouble = wardCost[i];
            wardCost[i] = wardCost[maxIndex];
            wardCost[maxIndex] = tempDouble;

            tempDouble = grossTotal[i];
            grossTotal[i] = grossTotal[maxIndex];
            grossTotal[maxIndex] = tempDouble;

            tempDouble = discount[i];
            discount[i] = discount[maxIndex];
            discount[maxIndex] = tempDouble;

            tempDouble = finalAmount[i];
            finalAmount[i] = finalAmount[maxIndex];
            finalAmount[maxIndex] = tempDouble;

            tempDouble = waitingTime[i];
            waitingTime[i] = waitingTime[maxIndex];
            waitingTime[maxIndex] = tempDouble;
        }
    }
}

void displayPatientsByPriority()
{
    int i;

    if(patientCount == 0)
    {
        printf("\nNo patients registered.\n");
        return;
    }

    sortPatientsByPriority();

    printf("\n========== PATIENTS BY PRIORITY ==========\n");

    for(i = 0; i < patientCount; i++)
    {
        printf("\nPatient %d\n", i + 1);
        printf("Name      : %s\n", patientName[i]);
        printf("Age       : %d\n", patientAge[i]);
        printf("Urgency   : ");

        if(urgencyLevel[i] == 3)
            printf("Emergency\n");
        else if(urgencyLevel[i] == 2)
            printf("Urgent\n");
        else
            printf("Normal\n");

        printf("Specialty : %s\n",
               specialtyName[patientSpecialty[i]]);

        if(admitted[i] == 1)
        {
            printf("Ward      : %s\n",
                   wardName[patientWard[i]]);
            printf("Bed       : %d\n",
                   assignedBed[i] + 1);
        }
        else
        {
            printf("Ward      : Not Admitted\n");
            printf("Bed       : Not Assigned\n");
        }

        printf("Final Bill: Rs. %.2f\n",
               finalAmount[i]);
    }
}

void savePatientRecord(int index)
{
    FILE *file;

    file = fopen("patient_records.txt", "a");

    if(file == NULL)
    {
        printf("\nError opening patient_records.txt\n");
        return;
    }

    fprintf(file,
            "%s,%d,%d,%d,%d,%d,%d,%d,%.2f\n",
            patientName[index],
            patientAge[index],
            urgencyLevel[index],
            patientSpecialty[index],
            admitted[index],
            patientWard[index],
            admittedDays[index],
            assignedBed[index],
            finalAmount[index]);

    fclose(file);

    printf("\nPatient record saved successfully.\n");
}

void loadPatientRecords()
{
    FILE *file;

    file = fopen("patient_records.txt", "r");

    if(file == NULL)
    {
        printf("\nNo saved patient records found.\n");
        return;
    }

    patientCount = 0;

    while(patientCount < MAX_PATIENTS)
    {
        if(fscanf(file,
                  " %49[^,],%d,%d,%d,%d,%d,%d,%d,%lf",
                  patientName[patientCount],
                  &patientAge[patientCount],
                  &urgencyLevel[patientCount],
                  &patientSpecialty[patientCount],
                  &admitted[patientCount],
                  &patientWard[patientCount],
                  &admittedDays[patientCount],
                  &assignedBed[patientCount],
                  &finalAmount[patientCount]) != 9)
        {
            break;
        }

        baseFee[patientCount] =
            consultationFee[patientSpecialty[patientCount]];

        surcharge[patientCount] =
            calculateSurcharge(
                baseFee[patientCount],
                urgencyLevel[patientCount]
            );

        wardCost[patientCount] =
            calculateWardCost(
                patientWard[patientCount],
                admittedDays[patientCount]
            );

        grossTotal[patientCount] =
            baseFee[patientCount]
            + surcharge[patientCount]
            + wardCost[patientCount];

        discount[patientCount] =
            calculateDiscount(
                grossTotal[patientCount],
                patientAge[patientCount]
            );

        waitingTime[patientCount] = 0;

        patientCount++;
    }

    fclose(file);

    printf("\nPatient records loaded successfully.\n");
}
