#include "sll.h"

// Function to insert a node before a given node containing a specific data value
int sl_insert_before(Slist **head, data_t g_data, data_t ndata)
{
    // Allocate memory for the new node
    Slist *new = malloc(sizeof(Slist));
    if (new == NULL)
    {
        return FAILURE; // Memory allocation failed
    }

    // Update new node with the given data
    new->data = ndata;
    new->link = NULL;

    // Check if the list is empty
    if (*head == NULL)
    {
        // List is empty
        return LIST_EMPTY;
    }
    else if((*head)->data == g_data)
    {
        // Special case: Insert before the head
        new->link = *head;
        *head = new;
        return SUCCESS;
    }
    else
    {
        Slist *temp = *head; // Pointer to traverse the list
        Slist *prev = NULL;  // Pointer to track the previous node

        // Traverse the list to find the node with the given data
        while (temp != NULL)
        {
            if (temp->data != g_data) // If data doesn't match, move to the next node
            {
                prev = temp;
                temp = temp->link;
            }
            else
            {
                // Insert before the node with the given data
                new->link = prev->link;
                prev->link = new;
                return SUCCESS;
            }
        }
        return DATA_NOT_FOUND; // If the node with the given data is not found
    }
}
