#include <stdio.h>
#include <stdbool.h>
#include "flat.h"
#include "header_1.h"
#include "header_2.h"
#include "header3.h"
#include "list.h"
int main() {

    int num = 4;
    int choice;
    int room;
    int month;
    int flat_number;
    char name[50];
    float totalRent;

    struct Flat *head = NULL;
    addFlats(&head, createFlat(101, 2, "Sunny Loft", "Alice Smith", true, "12 Maple Street", 1250.00f));
    addFlat(&head, createFlat(102, 3, "Garden View", "Bob Johnson", false, "45 Oak Avenue", 1600.50f));
    addFlat(&head, createFlat(201, 1, "Cozy Studio", "Clara Oswald", true, "78 Pine Road", 890.00f));
    addFlat(&head, createFlat(202, 4, "Penthouse Suite", "David Miller", false, "10 Elm Boulevard", 2450.75f));
    do {
        menu();
        printf("Kindly enter your choice:\n");
        if (scanf("%d", &choice)!=1) {
            while (getchar()!='\n');
            choice = 0;
        };
        switch (choice) {
            case 1:
                printf("##########   AVAILABLE FLATS:  #########\n");
                displaysAll(head);
                break;
            case 2:
                printf("Kindly enter the number of rooms you need:\n");
                scanf("%d", &room);
                displayflats(head,room);
                break;
            case 3:
                printf("Kindly enter your preferred flat name:\n");
                scanf(" %49[^\n]", name);
                searchFlat(name,head);
                break;
            case 4:
                printf("\n##########   FLATS AVAILABLE FOR BOOKING   ##########\n");
                if (displayFreeFlats(head) == 0)
                {
                    break;
                }
                printf("\nKindly enter the flat number you want to book: ");
                scanf("%d", &flat_number);

                BookFlat(head, flat_number);
                break;
            case 5:
                printf("\n########## FLAT RENT CALCULATOR ##########\n");
                displaysAll(head);
                printf("\nKindly enter the flat number: ");
                scanf("%d", &flat_number);
                printf("Kindly enter the number of months: ");
                scanf("%d", &month);
                if (month <= 0)
                {
                    printf("Please enter a valid number of months.\n");
                    break;
                }
                totalRent = CalculateRent(head, month, flat_number);
                if (totalRent >= 0)
                {
                    printf("Total rent: %.2f\n", totalRent);
                }
                break;
            case 6:
                write_to_file(head);
                break;
            case 7:{
                int loaded = read_from_file(&head);
                if (loaded >= 0)
                    printf("%d flats have been loaded.\n", loaded);
                break;
            }
            case 8:{
                int number, rooms;
                char fname[50], owner[50], street[50];
                float rent;
                printf("Flat number: ");
                scanf("%d", &number);
                printf("Number of rooms: ");
                scanf("%d", &rooms);
                printf("Flat name: ");
                scanf(" %49[^\n]", fname);
                printf("Owner: ");
                scanf(" %49[^\n]", owner);
                printf("Street: ");
                scanf(" %49[^\n]", street);
                printf("Monthly rent: ");
                scanf("%f", &rent);
                addFlat(&head, createFlat(number, rooms, fname, owner, false, street, rent));
                printf("Flat added! There are now %d flats.\n", countFlats(head));
                break;
            }
            default:
                printf("Please enter a valid choice:Thank You.\n");
        }
        case 9:
        write_to_file(head);
        printf("Thank You!!!\n");
        break;
        default:
        printf("Please enter a valid choice:Thank You.\n");
       }
    }while (choice != 9);
freeList(&head);
    return 0;
}
