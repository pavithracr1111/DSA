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
            printf("Enter data to insert at first\n");
            scanf("%d", &data);

            if (insert_at_first(&head, data) == FAILURE)
            {
                printf("Failed to inset at first\n");
            }
            break;
        case 3:
            if (delete_at_first(&head, data) == FAILURE)
            {
                printf("Failed to delete at first\n");
            }
            break;
        case 4:

            if (delete_at_last(&head, data) == FAILURE)
            {
                printf("Failed to  delete at last\n");
            }
            break;
        case 5:
            print_last(head);
            break;
        }
        printf("Want to continue (Y / N) -> ");
        scanf(" %c", &option);
    } while (option == 'y' || option == 'Y');

    return 0;
}

// function to select the opartion

int select_operation(void)
{
    int choice;
    printf("Options : \n");
    printf("1. Insert at last\n");
    printf("2. Insert at first\n");
    printf("3. Delete at first\n");
    printf("4. Delete at last\n");
    printf("5. Print the list\n");

    scanf("%d", &choice);

    return choice;
}