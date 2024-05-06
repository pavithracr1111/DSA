#ifndef SLL_H
#define SLL_H

#include <stdio.h>
#include <stdlib.h>

#define SUCCESS 0
#define FAILURE -1

typedef int data_t;
typedef struct node
{
    data_t data;
    struct node *link;
} Slist;

int select_operation(void);                    // function to select the operation
int insert_at_last(Slist **head, data_t data); // function to insert at last
void print_last(Slist *head);                  // function to print the list

#endif