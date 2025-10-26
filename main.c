#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_CITIES 30
#define NAME_LENGTH 50

void cityMenu(char cityList[MAX_CITIES][NAME_LENGTH], int *totalCities);

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
            cityMenu(cityList, &totalCities);
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

void cityMenu(char cityList[MAX_CITIES][NAME_LENGTH], int *totalCities)
{
    int menuOption;
    void addCity(char cityList[MAX_CITIES][NAME_LENGTH], int *totalCities);
    void listCities(char cityList[MAX_CITIES][NAME_LENGTH], int totalCities);
    void removeCity(char cityList[MAX_CITIES][NAME_LENGTH], int *totalCities);
    void renameCity(char cityList[MAX_CITIES][NAME_LENGTH], int totalCities);


    do
    {
        printf("\n--- City Management Menu ---\n");
        printf("1. Add New City\n");
        printf("2. Show All Cities\n");
        printf("3. Delete a City\n");
        printf("4. Update City Name\n");
        printf("5. Return to Main Menu\n");
        printf("Select an option: ");
        scanf("%d", &menuOption);
        getchar();

        switch (menuOption)
        {
        case 1:
            addCity(cityList, totalCities);
            break;

        case 2:
            listCities(cityList, *totalCities);
            break;

        case 3:
            removeCity(cityList, totalCities);
            break;

        case 4:
            renameCity(cityList, *totalCities);
            break;

        case 5:
            printf("Returning to main menu...\n");
            break;

        default:
            printf("Invalid input! Please select a valid option.\n");
            break;
        }

    } while (menuOption != 5);
}

void addCity(char cityList[MAX_CITIES][NAME_LENGTH], int *totalCities)
{
    if (*totalCities >= MAX_CITIES)
    {
        printf("City limit reached! Cannot add more cities.\n");
        return;
    }

    printf("Enter city name: ");
    fgets(cityList[*totalCities], NAME_LENGTH, stdin);
    cityList[*totalCities][strcspn(cityList[*totalCities], "\n")] = '\0';

    (*totalCities)++;
    printf("City added successfully!\n");
}

void listCities(char cityList[MAX_CITIES][NAME_LENGTH], int totalCities)
{
    printf("\n--- List of Registered Cities ---\n");

    if (totalCities == 0)
    {
        printf("No cities available yet.\n");
        return;
    }

    for (int i = 0; i < totalCities; i++)
    {
        printf("%d. %s\n", i + 1, cityList[i]);
    }
}

void removeCity(char cityList[MAX_CITIES][NAME_LENGTH], int *totalCities)
{
    if (*totalCities == 0)
    {
        printf("No cities to delete.\n");
        return;
    }

    listCities(cityList, *totalCities);

    int index;
    printf("Enter the number of the city to remove: ");
    scanf("%d", &index);
    getchar();

    if (index < 1 || index > *totalCities)
    {
        printf("Invalid selection. Try again.\n");
        return;
    }

    for (int i = index - 1; i < *totalCities - 1; i++)
    {
        strcpy(cityList[i], cityList[i + 1]);
    }

    (*totalCities)--;
    printf("City removed successfully!\n");
}

void renameCity(char cityList[MAX_CITIES][NAME_LENGTH], int totalCities)
{
    if (totalCities == 0)
    {
        printf("No cities available to rename.\n");
        return;
    }

    listCities(cityList, totalCities);

    int index;
    printf("Enter the number of the city to rename: ");
    scanf("%d", &index);
    getchar();

    if (index < 1 || index > totalCities)
    {
        printf("Invalid city number. Try again.\n");
        return;
    }

    printf("Enter new name for '%s': ", cityList[index - 1]);
    fgets(cityList[index - 1], NAME_LENGTH, stdin);
    cityList[index - 1][strcspn(cityList[index - 1], "\n")] = '\0';

    printf("City name updated successfully!\n");
}

