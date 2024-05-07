#include "sll.h"

// function to delete at first
int delete_at_first(Slist **head)
{
    // checking if list is empty or not
    if (*head == NULL) // if list is empty
    {
        return FAILURE;
    }
    else
    {
        Slist *temp = *head; // create a local reference pointer
        *head = temp->link;  // add temp link to head, so that it deletes the first node
        free(temp);          // deallocate the memory of temp
        return SUCCESS;
    }
}