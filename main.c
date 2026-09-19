#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_PATIENTS 100
#define MAX_NAME 50
#define MAX_WARDS 4
#define MAX_BEDS 20

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

int main()
{
    printf("==========Smart Hospital System==========\n");
    return 0;
}
