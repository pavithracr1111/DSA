#include "sll.h"

int select_operation(void);
int main()
{
    system("clear");
    Slist *head = NULL;

    int choice;
    int data;
    char option;

    do
    {
        choice = select_operation();
        switch (choice)
        {
        case 1:
            printf("Enter data to insert at last\n");
            scanf("%d", &data);

            if (insert_at_last(&head, data) == FAILURE)
            {
                printf("Failed to inset at last\n");
            }
            break;
        case 2:
            print_last(head);
            break;
        }
        printf("Want to continue (Y / N) -> ");
        scanf(" %c", &option);
    } while (option == 'y' || option == 'Y');

    return 0;
}

//function to select the opartion 

int select_operation(void)
{
    int choice;
    printf("Options : \n");
    printf("1. Insert at first\n");
    printf("2. Print the list\n");

    scanf("%d",&choice);

    return choice;
}