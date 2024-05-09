#include "dll.h"

/* Function to delete the first node from a doubly linked list */
int dl_delete_first(Dlist **head, Dlist **tail)
{
    // Check if the list is empty
    if (*head == NULL && *tail == NULL)
    {
        return FAILURE; // Return failure if the list is empty
    }
    else
    {
        // Check if there is only one node in the list
        if (*head == *tail)
        {
            free(*head); // Free memory occupied by the single node
            *head = *tail = NULL; // Set both head and tail to NULL as the list is empty now
            return SUCCESS; // Return success
        }
        else
        {
            Dlist *temp = *head; // Create a temporary pointer to the head node
            *head = temp->next; // Move the head pointer to the next node
            (*head)->prev = NULL; // Set the previous pointer of the new head to NULL
            free(temp); // Free memory occupied by the old head node
            return SUCCESS; // Return success
        }
    }
}
