#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "hospital.h"
#include "patient.h"
#include "bed.h"
#include "billing.h"
#include "report.h"

int main()
{
    int choice;

    initializeBeds();

    do
    {
        printf("\n=============================================\n");
        printf("     SMART HOSPITAL RESOURCE SYSTEM            \n");
        printf("============================================= \n");

        printf("\n1. Register Patient");
        printf("\n2. Display Bed Status");
        printf("\n3. Display Patients by Priority");
        printf("\n4. Generate Performance Report");
        printf("\n5. Display Specialties");
        printf("\n6. Display Wards");
        printf("\n7. Save Data");
        printf("\n0. Exit");

        printf("\n\nEnter your choice: ");
        scanf("%d", &choice);

        switch(choice)
        {
            case 1:
                registerPatient();
                break;

            case 2:
                displayBeds();
                break;

            case 3:
                displayPatientsByPriority();
                break;

            case 4:
                generateReport();
                break;

            case 5:
                displaySpecialties();
                break;

            case 6:
                displayWards();
                break;

            case 7:
                 saveBeds();

                 if(patientCount > 0)
                 {
                     int i;
                     for(i = 0; i < patientCount; i++)
                     {
                         savePatientRecord(i);
                     }
                 }

                 break;

            case 0:
                printf("\nExiting Smart Hospital System...\n");
                break;

            default:
                printf("\nInvalid choice. Please try again.\n");
        }

    } while(choice != 0);

    return 0;
}



