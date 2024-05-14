#include "dll.h"

// Function to delete the entire doubly linked list
int dl_delete_list(Dlist **head, Dlist **tail)
{
    if (*head == NULL) // Check if the list is empty
    {
        return FAILURE; // If the list is empty, return FAILURE
    }
    else
    {
        Dlist *temp = *head; // Create a temporary pointer to traverse the list
        while (temp != NULL)
        {
            *head = temp->next; // Move head pointer to the next node
            free(temp); // Free the memory allocated for the current node
            temp = *head; // Move temp pointer to the new head
        }
        *tail = NULL; // Set tail pointer to NULL as the list is now empty
        return SUCCESS; // Return SUCCESS indicating list is deleted
    }
}
