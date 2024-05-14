#include "sll.h"

// Function to insert a node with data into a singly linked list in sorted order
int insert_sorted(Slist **head, data_t data)
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

    // Check if the list is empty or if the new node should be inserted at the beginning
    if (*head == NULL || data < (*head)->data)
    {
        new->link = *head; // Update the link of the new node to point to the current head
        *head = new;       // Update the head pointer to point to the new node
        return SUCCESS;    // Return SUCCESS indicating successful insertion
    }
    else
    {
        Slist *temp = *head; // Temporary pointer to traverse the list
        Slist *prev = NULL;  // Pointer to track the previous node

        // Traverse the list to find the correct position to insert the new node
        while (temp != NULL && temp->data < data)
        {
            prev = temp;      // Update prev pointer to current node
            temp = temp->link; // Move temp pointer to the next node
        }

        // Insert the new node at the correct position
        prev->link = new; // Update link of the previous node to point to the new node
        new->link = temp; // Update link of the new node to point to the next node

        return SUCCESS; // Return SUCCESS indicating successful insertion
    }
}
