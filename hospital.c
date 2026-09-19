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
