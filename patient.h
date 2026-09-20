#ifndef PATIENT_H
#define PATIENT_H

#define MAX_PATIENTS 100
#define MAX_NAME 50

extern int patientCount;

extern char patientName[MAX_PATIENTS][MAX_NAME];
extern int patientAge[MAX_PATIENTS];
extern int urgencyLevel[MAX_PATIENTS];
extern int patientSpecialty[MAX_PATIENTS];
extern int admitted[MAX_PATIENTS];
extern int patientWard[MAX_PATIENTS];
extern int admittedDays[MAX_PATIENTS];
extern int assignedBed[MAX_PATIENTS];

extern double baseFee[MAX_PATIENTS];
extern double surcharge[MAX_PATIENTS];
extern double wardCost[MAX_PATIENTS];
extern double grossTotal[MAX_PATIENTS];
extern double discount[MAX_PATIENTS];
extern double finalAmount[MAX_PATIENTS];
extern double waitingTime[MAX_PATIENTS];

extern int specialtyQueue[4];

void registerPatient();

#endif
