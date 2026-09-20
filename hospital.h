#ifndef HOSPITAL_H
#define HOSPITAL_H

#define MAX_WARDS 4
#define MAX_BEDS 20

extern const char *specialtyName[4];
extern const double consultationFee[4];
extern const int consultationTime[4];
extern const int dailyPatientCap[4];

extern const char *wardName[4];
extern const double wardDailyRate[4];
extern const int wardCapacity[4];

void displaySpecialties();
void displayWards();

#endif
