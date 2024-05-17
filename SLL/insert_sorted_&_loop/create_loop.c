#include "sll.h"

// Function to create a loop in a singly linked list
int create_loop(Slist **head, data_t data)
{
    // Check if the list is empty
    if (*head == NULL)
    {
        return LIST_EMPTY; // Return LIST_EMPTY if the list is empty
    }
    else
    {
        Slist *t1 = *head; // Pointer to traverse the list
        Slist *t2 = NULL;  // Pointer to track the previous node

        // Traverse the list to find the last node
        while (t1->link != NULL)
        {
            // If a node with the given data is found, create a loop
            if (t1->data == data)
            {
                t2 = t1; // Update t2 to point to the current node
            }
            t1 = t1->link; // Move t1 to the next node
        }

        // If the given data is found, create a loop
        if (t2 != NULL)
        {
            t1->link = t2;  // Create a loop by linking t1 to t2
            return SUCCESS; // Return SUCCESS indicating loop creation
        }
        else
        {
            return DATA_NOT_FOUND; // Return FAILURE if the given data is not found
        }
    }
}
