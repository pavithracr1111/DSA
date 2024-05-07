#include "sll.h"

// function to find the node with given data
int find_node(Slist *head, data_t data)
{
    // checking if list is empty or not
    if (head == NULL) // if list is empty
    {
        return FAILURE;
    }
    else
    {
        int count = 1; // set a count to 1 to track the nodes
        Slist *temp = head; //create a local reference pointer to points to first node
        while (temp != NULL) // run a loop till temp points to NULL
        {
            if (temp->data != data) //check the given data is present or not
            {
                temp = temp->link;//if not present in the list, traverse to next node
                count++; //then increment the count to count the nodes
            }
            else
            {
                return count; //if data is present return the node postion
            }
        }
        return FAILURE;//return failure mess if data is not present in the list
    }
}