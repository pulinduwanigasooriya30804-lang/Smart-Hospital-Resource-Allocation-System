#include <stdio.h>
#include "hospital.h"



const char *specialtyName[4] = {
    "General Practice (OPD)",
    "Paediatrics",
    "Cardiology",
    "Neurology"
};

const double consultationFee[4] = {
    1500.00,
    2500.00,
    4500.00,
    5000.00
};

const int consultationTime[4] = {
    15,
    20,
    30,
    30
};

const int dailyPatientCap[4] = {
    30,
    20,
    12,
    10
};

const char *wardName[4] = {
    "General Ward",
    "Paediatric Ward",
    "Surgical Ward",
    "ICU (Intensive Care Unit)"
};

const double wardDailyRate[4] = {
    3000.00,
    6000.00,
    12000.00,
    25000.00
};

const int wardCapacity[4] = {
    20,
    10,
    10,
    5
};

void displaySpecialties()

{

    int i;

    printf("\n========== SPECIALTIES ==========\n");

    for(i = 0; i < 4; i++)

    {

        printf("%d. %s - Rs. %.2f - %d minutes\n",

               i + 1,

               specialtyName[i],

               consultationFee[i],

               consultationTime[i]);

    }

}

void displayWards()

{

    int i;

    printf("\n========== WARDS ==========\n");

    for(i = 0; i < 4; i++)

    {

        printf("%d. %s - Rs. %.2f/day - Capacity: %d\n",

               i + 1,

               wardName[i],

               wardDailyRate[i],

               wardCapacity[i]);

    }

}
