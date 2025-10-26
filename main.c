#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_CITIES 30
#define NAME_LENGTH 50

int main() {
    char cityList[MAX_CITIES][NAME_LENGTH];
    int distanceMap[MAX_CITIES][MAX_CITIES] = {0};
    int totalCities = 0;
    int menuOption;

    do {
        printf("\n===== Logistics Control System =====\n\n");
        printf("1. Manage Cities\n");
        printf("2. Manage Distances\n");
        printf("3. Vehicle Information\n");
        printf("4. Delivery Handling\n");
        printf("5. Reports Section\n");
        printf("6. Quit Program\n");
        printf("-----------------------------------\n");
        printf("Select an option: ");
        scanf("%d", &menuOption);
        getchar();

        switch (menuOption) {
        case 1:

            break;

        case 2:

            break;

        case 3:

            break;

        case 4:

            break;

        case 5:

            break;

        case 6:
            printf("Thank you for using the system. Goodbye!\n");
            break;

        default:
            printf("Invalid selection. Please try again.\n");
            break;
        }

    } while (menuOption != 6);

    return 0;
}

