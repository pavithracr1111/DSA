#include "sll.h"

// function to delete list
int sl_delete_list(Slist **head)
{
    // checking if list is empty or not
    if (*head == NULL) // if list is empty
    {
        return FAILURE;
    }
    else
    {
        Slist *temp = *head; //create a local reference pointer temp
        while (temp != NULL) // run a loop till temp equals to NULL
        {
            temp = *head; //points temp to first node by using head
            *head = temp->link; //head will be points to next node (sec node)
            free(temp); // deallocate the temp memory(first node memory)
            temp = *head; // points next node by using head to temp
        }
        *head = NULL; //deallocate the memory of head by NULL
        return SUCCESS;
    }
}