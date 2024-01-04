#ifndef LINKED_LIST
#define LINKED_LIST

#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int value;
    struct Node* next;
} Node;

typedef struct List {
    Node* head;
    int length;
} List;

/*
Error codes:
    - SUCCESS = 0
    - FAILURE = 1
    - NULL_NODE_INSERTION = -1
    - UNINITIALISED_LIST = -2 
    - INDEX_OUT_OF_BOUNDS = -3
*/

//Returns a node pointer.
Node* create_node(int value);

//Initialises a head node.
//Returns null if a null node is provided.
List* create_list(Node* head);

//Checks if the list's head has been deallocated or not.
//Returns FAILURE if the list has been deallocated
//Returns SUCCESS if the list has not been deallocated.
int listchk(List** listPtr);

//Adds element to the end of the list.
//Returns SUCCESS if succeeds.
//Returns UNINITIALISED_LIST if the list has been deallocated.
//Returns NULL_NODE_INSERTION if a null node is provided.
int append(List** listPtr, Node* newNode);

//Removes element from the end of the list.
//Returns SUCCESS if succeeds.
//Returns UNINITIALISED_LIST if the list has been deallocated.
int pop(List** listPtr);

//Performs linear search on the list. 
//Returns SUCCEED if target is found
//Returns FAILURE if target is not found.
//Returns UNINITIALISED_LIST if the list has been deallocated.
int search(List** listPtr, int target);

//Removes an element from any index of the list.
//Returns SUCCEED if successful.
//Returns FAILURE if target is out of bounds.
//Returns UNINITIALISED_LIST if the list has been deallocated.
int remove_node(List** listPtr, int target);

//Inserts an element after the provided index.
//Returns SUCCEED if successful.
//Returns FAILURE if the provided index is out of bounds.
//Returns NULL_NODE_INSERTION if a null node is being provided.
//Returns UNINITIALISED_LIST if the list has been deallocated.
int insert_node(List** listPtr, int index, Node* newNode);

//Swap function for sorting. Not to be called by the user.
//Returns SUCCESS if succeeds.
//Returns FAILURE if fails.
int swap(Node* a, Node* b);

//Sorts the list using bubble sort. (Ascending)
//Returns SUCCESS if succeeds.
//Returns FAILURE if the swap function fails at any point.
//Returns UNINITIALISED_LIST if the list has been deallocated.
int sort(List** listPtr);

//Prints the entire list
void print_list(List** listPtr);

//Frees the linked list.
void free_list(List** listPtr);

#endif