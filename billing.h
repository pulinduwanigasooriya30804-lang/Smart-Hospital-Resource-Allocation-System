#ifndef BILLING_H
#define BILLING_H

double calculateSurcharge(double fee, int urgency);
double calculateWardCost(int ward, int days);
double calculateDiscount(double gross, int age);
void displayPatientBill(int index);

#endif
