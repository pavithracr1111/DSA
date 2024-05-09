#include "sll.h" 
int sl_delete_element(Slist **head, data_t data)
{
    if (*head == NULL)
    {
        return FAILURE; // Empty list
    }
    else
    {
        Slist *temp = *head;
        Slist *prev = NULL;

        // If the node to be deleted is the head node
        if (temp->data == data)
        {
            *head = temp->link; // Update head to the next node
            free(temp); // Free the memory of the deleted node
            return SUCCESS;
        }

        // Search for the node with the given data
        while (temp != NULL)
        {
            if (temp->data == data)
            {
                prev->link = temp->link; // Update the link of the previous node
                free(temp); // Free the memory of the deleted node
                return SUCCESS; // Data found and deleted
            }
            prev = temp;
            temp = temp->link;
        }

        return DATA_NOT_FOUND; // Data not found in the list
    }
}
