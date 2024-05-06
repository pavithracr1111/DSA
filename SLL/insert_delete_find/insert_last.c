#include "sll.h"

// function to insert at last
int insert_at_last(Slist **head, data_t data)
{
    Slist *new = malloc(sizeof(Slist)); // create a node
    if (new == NULL)                    // error checking (memory allocated or not)
    {
        return FAILURE;
    }

    // update data and link to new node
    new->data = data;
    new->link = NULL;

    // checking if list is empty or not
    if (*head == NULL) // if list is empty
    {
        *head = new;
        return SUCCESS;
    }
    // else // if list is non empty
    // {
    //     Slist *temp = *head;       // create a local reference pointer to traverse through the list till end
    //     while (temp->link != NULL) // check for null
    //     {
    //         temp = temp->link; // traverse to next node
    //     }
    //     temp->link = new; // establishing a link b/w last node and new node

    //     return SUCCESS;
    // }
    else
    {
        new->link = *head; //head has first node address, so update newlink with head
        *head = new; // then point new to head
        return SUCCESS;
    }
}