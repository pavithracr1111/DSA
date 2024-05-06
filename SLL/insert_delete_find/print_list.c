#include "sll.h"

// function to print the list
void print_last(Slist *head) 
{
    if(head == NULL)
    {
        printf("NO nodes to print\n");
    }
    else
    {
        printf("head -> ");
        while(head)
        {
            printf("%d -> ",head->data);
            head = head->link;
        }
        printf("NULL\n");
    }
}                