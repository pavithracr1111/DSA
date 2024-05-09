#include "dll.h"

/* Function to delete the last node from a doubly linked list */
int dl_delete_last(Dlist **head, Dlist **tail)
{
    // Check if the list is empty
    if (*head == NULL && *tail == NULL)
    {
        return FAILURE; // Return failure if the list is empty
    }

    // Check if there is only one node in the list
    if (*tail == *head)
    {
        free(*tail); // Free memory occupied by the single node
        *head = NULL; // Set both head and tail to NULL as the list is empty now
        *tail = NULL;
        return SUCCESS; // Return success
    }
    else
    {
        *tail = (*tail)->prev; // Move the tail pointer to the previous node
        free((*tail)->next); // Free memory occupied by the last node
        (*tail)->next = NULL; // Set the next pointer of the new tail to NULL
        return SUCCESS; // Return success
    }
}
