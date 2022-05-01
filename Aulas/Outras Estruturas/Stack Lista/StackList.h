//-----------------------------------------------------------------------
// <copyright file="StackLista.h" company="IPCA">
//     Copyright IPCA. All rights reserved.
// </copyright>
// <date>20120</date>
// <author>lufer</author>
// <email></email>
// <version></version>
// <desc>Manipular Stack com Listas (LIFO)</desc>
//-----------------------------------------------------------------------


#include <stdio.h>

#ifndef STACKLIST
#define STACKLIST
#define   MAX_LEN    1000
#define   EMPTY      -1
#define   FULL       (MAX_LEN - 1)

struct Node
{
	int data;
	struct Node* next;
};

struct Node* InitStack(struct Node* head);
struct Node* PushStack(struct Node* head, int data);
struct Node* PopStack(struct Node *head, int *element);
int EmptyStack(struct Node* head);
void ShowStack(struct Node *top);

#endif 