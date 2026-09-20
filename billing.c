#include <stdio.h>
#include "billing.h"
#include "hospital.h"
#include "patient.h"

double calculateSurcharge(double fee, int urgency)
{
    if(urgency == 3)
        return fee * 0.30;
    else if(urgency == 2)
        return fee * 0.15;
    else
        return 0.00;
}

double calculateWardCost(int ward, int days)
{
    return wardDailyRate[ward] * days;
}

double calculateDiscount(double gross, int age)
{
    if(age >= 60)
        return gross * 0.20;
    else if(age < 12)
        return gross * 0.10;
    else
        return 0.00;
}

void displayPatientBill(int index)
{
    printf("\n========== PATIENT BILL ==========\n");

    printf("Patient Name : %s\n", patientName[index]);
    printf("Base Fee     : %.2f\n", baseFee[index]);
    printf("Surcharge    : %.2f\n", surcharge[index]);
    printf("Ward Cost    : %.2f\n", wardCost[index]);
    printf("Gross Total  : %.2f\n", grossTotal[index]);
    printf("Discount     : %.2f\n", discount[index]);
    printf("Final Amount : %.2f\n", finalAmount[index]);
}
