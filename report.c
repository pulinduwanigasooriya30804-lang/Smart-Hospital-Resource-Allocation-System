#include <stdio.h>
#include "report.h"
#include "patient.h"

void generateReport()
{
    printf("\n========== HOSPITAL PERFORMANCE REPORT ==========\n");

    printf("Total Registered Patients : %d\n", patientCount);

    printf("===============================================\n");
}
