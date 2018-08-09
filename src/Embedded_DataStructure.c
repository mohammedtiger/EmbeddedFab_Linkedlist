/*
 ============================================================================
 Name        : Embedded_DataStructure.c
 Author      : mohammed nabil
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>

typedef struct node Node;

struct node
{
	int data ;
	Node *next;
};




void printList(Node *node);
void push(Node **head_ref , int new_data);
void append(Node **head_ref , int new_data);
void insertAfter( Node* prev_node, int new_data);
void deleteNodePosition( Node **head_ref, int position);
void deleteList( Node** head_ref);


int main(void) {

	Node *head = NULL;

	push(&head , 1);
	push(&head , 2);
	push(&head , 3);
	push(&head , 4);
	insertAfter( head , 10);

	deleteNodePosition( &head , 3);

	printList(head);

	return EXIT_SUCCESS;
}




void push(Node **head_ref , int new_data)
{
	Node *new_node = (Node*) malloc(sizeof(Node));

	new_node->data = new_data;

	new_node->next = (*head_ref);

	(*head_ref) = new_node;
}








void append(Node **head_ref , int new_data)
{
	Node *new_node = (Node*) malloc(sizeof(Node));


	Node *last = *head_ref;

	new_node->data = new_data;
	new_node->next = NULL;

	if (*head_ref == NULL)
	{
		(*head_ref) = new_node;
		return;
	}

	while (last->next != NULL)
		last = last->next;

	last->next = new_node;

}









void printList(Node *node)
{
	while (node != NULL)
	{
		printf(" %d ", node->data);
		node = node->next;
	}
}

void insertAfter( Node* prev_node, int new_data)
{
	if (prev_node == NULL)
	{
		printf("the given previous node cannot be NULL");
		return;
	}

	Node* new_node =( Node*) malloc(sizeof( Node));

	new_node->data  = new_data;

	new_node->next = prev_node->next;

	prev_node->next = new_node;
}


void deleteNode( Node **head_ref, int key)
{
     Node* temp = *head_ref, *prev;

    if (temp != NULL && temp->data == key)
    {
        *head_ref = temp->next;
        free(temp);
        return;
    }


    while (temp != NULL && temp->data != key)
    {
        prev = temp;
        temp = temp->next;
    }

    if (temp == NULL) return;

    prev->next = temp->next;

    free(temp);
}





void deleteNodePosition( Node **head_ref, int position)
{
   // If linked list is empty
   if (*head_ref == NULL)
      return;

   // Store head node
    Node* temp = *head_ref;

    // If head needs to be removed
    if (position == 0)
    {
        *head_ref = temp->next;   // Change head
        free(temp);               // free old head
        return;
    }

    // Find previous node of the node to be deleted
    for (int i=0; temp!=NULL && i<position-1; i++)
         temp = temp->next;

    // If position is more than number of ndoes
    if (temp == NULL || temp->next == NULL)
         return;

    // Node temp->next is the node to be deleted
    // Store pointer to the next of node to be deleted
     Node *next = temp->next->next;

    // Unlink the node from linked list
    free(temp->next);  // Free memory

    temp->next = next;  // Unlink the deleted node from list
}







void deleteList( Node** head_ref)
{
   /* deref head_ref to get the real head */
    Node* current = *head_ref;
    Node* next;

   while (current != NULL)
   {
       next = current->next;
       free(current);
       current = next;
   }

   /* deref head_ref to affect the real head back
      in the caller. */
   *head_ref = NULL;
}
