#include "sll.h"

int sl_delete_first(Slist **head) // function to delete at first
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