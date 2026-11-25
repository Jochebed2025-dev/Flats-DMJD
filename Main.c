#include <stdio.h>
#include <stdbool.h>
#include "flat.h"
#include "header_1.h"
#include "header_2.h"
#include "header3.h"

int main() {

    int num = 4;
    int choice;
    int room;
    int month;
    int flat_number;
    char name[50];
    float totalRent;

    struct Flat flats[4] = {
        {101, 2, "Sunny Loft", "Alice Smith", true, "12 Maple Street", 1250.00f},
        {102, 3, "Garden View", "Bob Johnson", false, "45 Oak Avenue", 1600.50f},
        {201, 1, "Cozy Studio", "Clara Oswald", true, "78 Pine Road", 890.00f},
        {202, 4, "Penthouse Suite", "David Miller", false, "10 Elm Boulevard", 2450.75f}
    };
    // enterFlats(flats,&num,MAX_FlATS);
    // num = read_from_file(flats,MAX_FlATS);
    do {
        menu();
        printf("Kindly enter your choice:\n");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                printf("##########   AVAILABLE FLATS:  #########\n");
                displaysAll(flats,num);
                break;
            case 2:
                printf("Kindly enter the number of rooms you need:\n");
                scanf("%d", &room);
                displayflats(flats,num,room);
                break;
            case 3:
                printf("Kindly enter your preferred flat name:\n");
                scanf(" %35[^\n]", name);
                searchFlat(name,flats,num);
                break;
            case 4:
                printf("\n##########   FLATS AVAILABLE FOR BOOKING   ##########\n");
                if (displayFreeFlats(flats, num) == 0)
                {
                    break;
                }
                printf("\nKindly enter the flat number you want to book: ");
                scanf("%d", &flat_number);

                BookFlat(flats, flat_number, num);
                break;
            case 5:
                printf("\n########## FLAT RENT CALCULATOR ##########\n");
                displaysAll(flats, num);
                printf("\nKindly enter the flat number: ");
                scanf("%d", &flat_number);
                printf("Kindly enter the number of months: ");
                scanf("%d", &month);
                if (month <= 0)
                {
                    printf("Please enter a valid number of months.\n");
                    break;
                }
                totalRent = CalculateRent(flats, month, flat_number, num);
                if (totalRent >= 0)
                {
                    printf("Total rent: %.2f\n", totalRent);
                }
                break;
            case 6:
                write_to_file(flats,num);
                //printf("Your flats have been saved\n");
                break;
            case 7:
                read_from_file(flats,num);
                printf("Your flats have been loaded:\n");
                break;
            case 8:
                write_to_file(flats,num);
                printf("Thank You!!!\n");
                break;
            default:
                printf("Please enter a valid choice:Thank You.\n");

        }
    }while (choice != 8);

    return 0;
}
