#include "sll.h"

// Function to insert a node at the nth position in a singly linked list
int sl_insert_nth(Slist **head, data_t data, data_t n)
{
    // Allocate memory for the new node
    Slist *new = malloc(sizeof(Slist));
    if (new == NULL)
    {
        return FAILURE; // Memory allocation failed
    }

    // Update new node with the given data
    new->data = data;
    new->link = NULL;

    // Check if insertion is at the beginning (n=1)
    if (n == 1)
    {
        // Insert at the beginning
        new->link = *head;
        *head = new;
        return SUCCESS;
    }
    else if (*head == NULL)
    {
        return LIST_EMPTY; // List is empty and n is not 1
    }
    else
    {
        // List is not empty
        Slist *temp = *head;
        int count = 1;

        // Traverse the list to find the (n-1)th node or the end of the list
        while (temp->link != NULL && count < n - 1)
        {
            temp = temp->link;
            count++;
        }

        // Insert the new node at the end if n exceeds the length of the list
        if (temp->link == NULL && count == n - 1)
        {
            temp->link = new;
            return SUCCESS;
        }

        // If n is greater than the length of the list, return POSITION_NOT_FOUND
        if (count < n - 1)
        {
            free(new); // Free the allocated memory
            return POSITION_NOT_FOUND;
        }

        // Insert the new node at the nth position
        new->link = temp->link;
        temp->link = new;
        return SUCCESS; // Node successfully inserted at nth position
    }
}
