#include <stdio.h>
#include "report.h"
#include "patient.h"

void generateReport()
{
    int i;
    int admittedCount = 0;
    int outpatientCount = 0;
    double totalRevenue = 0.0;
    double averageBill = 0.0;

    for(i = 0; i < patientCount; i++)
    {
        if(admitted[i] == 1)
        {
            admittedCount++;
        }
        else
        {
            outpatientCount++;
        }

        totalRevenue += finalAmount[i];
    }

    if(patientCount > 0)
    {
        averageBill = totalRevenue / patientCount;
    }

    printf("\n========== HOSPITAL PERFORMANCE REPORT ==========\n");

    printf("Total Registered Patients : %d\n", patientCount);
    printf("Admitted Patients         : %d\n", admittedCount);
    printf("Outpatients               : %d\n", outpatientCount);
    printf("Total Revenue             : Rs. %.2f\n", totalRevenue);
    printf("Average Bill Amount       : Rs. %.2f\n", averageBill);

    printf("=================================================\n");
}
