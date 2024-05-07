#include "sll.h"

// function to delete list
int delete_list(Slist **head)
{
    // checking if list is empty or not
    if (*head == NULL) // if list is empty
    {
        return FAILURE;
    }
    else
    {
        Slist *temp = *head;
        while (temp->link != NULL)
        {
            *head = temp->link;
            free(temp);
        }
        *head = temp->link;
        free(head);
        *head = NULL;
        return SUCCESS;
    }
}