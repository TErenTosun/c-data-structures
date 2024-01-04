#include "linked_list.h"

enum returnList {
    SUCCESS = 0,
    FAILURE = 1,
    NULL_NODE_INSERTION = -1,
    UNINITIALISED_LIST = -2, 
    INDEX_OUT_OF_BOUNDS = -3,
};

Node* create_node(int value) {
    Node* newNode = (Node*)malloc(sizeof(Node*));
    newNode->value = value;
    newNode->next = NULL;
    return newNode;
}

List* create_list(Node* head) {
    if (head == NULL) {
        printf("Cannot assign a null pointer as the head node\n");
        return NULL;
    }
    List* newList = (List*)malloc(sizeof(List**));
    newList->head = head;
    newList->length = 1;
    return newList;
}

int listchk(List** listPtr) {
    if ((*listPtr)->head == NULL)
        return FAILURE;
    else return SUCCESS;
}

int append(List** listPtr, Node *newNode) {
    if (listchk(listPtr)) {
        printf("ERROR: Cannot append to an uninitalised list\n");
        return UNINITIALISED_LIST;
    }
    if (newNode == NULL) {
        printf("ERROR: Cannot append null node\n");
        return NULL_NODE_INSERTION;
    }
    Node* temp = (*listPtr)->head;
    while (temp->next != NULL) {
        temp = temp->next;
    }
    temp->next = newNode;
    (*listPtr)->length++;
    return SUCCESS;
}

int pop(List** listPtr) {
    if (listchk(listPtr)) {
        printf("ERROR: Cannot pop from an uninitalised list\n");
        return UNINITIALISED_LIST;
    }
    Node* temp = (*listPtr)->head;
    while (temp->next->next != NULL) {
        temp = temp->next;
    }
    temp->next = NULL;
    (*listPtr)->length--;
    return SUCCESS;
}

int search(List** listPtr, int target) {
    if (listchk(listPtr)) {
        printf("ERROR: Cannot search an uninitialised list\n");
        return UNINITIALISED_LIST;
    }
    Node* temp = (*listPtr)->head;
    while (temp != NULL) {
        if (temp->value == target) {
            printf("INFO: Element found\n");
            return SUCCESS;
        }
        temp = temp->next;
    }
    free(temp);
    printf("INFO: Element not found\n");
    return FAILURE;
}

int remove_node(List **listPtr, int position) {
    //Implement head node removal.
    if (listchk(listPtr)) {
        printf("ERROR: Cannot remove from an uninitialised list\n");
        return UNINITIALISED_LIST;
    }
    if (position > (*listPtr)->length || position <= 0) {
        printf("ERROR: Index %d is out of bounds\n", position);
        return FAILURE;
    }
    Node* temp = (*listPtr)->head;
    int found = 0;
    while (temp != NULL) {
        if (temp->next->value == position+1) {
            found = 1;
            break;
        }
        else {
            temp = temp->next;
        }
    }
    if (found) {
        (*listPtr)->length--;
        temp->next = temp->next->next;
        return SUCCESS;
    }
}

int insert_node(List **listPtr, int index, Node *newNode) {
    //Implement head insertion.
    if (listchk(listPtr)) {
        printf("ERROR: Cannot insert to an uninitalised list\n");
        return UNINITIALISED_LIST;
    }
    if (index > (*listPtr)->length || index <= 0) {
        printf("ERROR: Index %d is out of bounds\n", index);
        return INDEX_OUT_OF_BOUNDS;
    }
    if (newNode == NULL) {
        printf("ERROR: Cannot insert null node\n");
        return NULL_NODE_INSERTION;
    }
    //This part is rather shoddy but who cares.
    else if (index == (*listPtr)->length) {
        append(listPtr, newNode);
        return SUCCESS;
    }
    Node* temp = (*listPtr)->head;
    int i = 0;
    while (i != index) {
        temp = temp->next;
        i++;
    }
    newNode->next = temp->next;
    temp->next = newNode;
    (*listPtr)->length++;
    return SUCCESS;
}

int swap(Node* a, Node* b) {
    if (a == NULL || b == NULL) {
        printf("ERROR: Cannot operate on null nodes\n");
        if (a == NULL) printf("Primary node is null\n");
        if (b == NULL) printf("Secondary node is null\n");
        return FAILURE;
    }
    int temp = a->value;
    a->value = b->value;
    b->value = temp;
    return SUCCESS;
}

int sort(List **listPtr) {
    if (listchk(listPtr)) {
        printf("ERROR: Cannot sort an uninitialised list\n");
        return UNINITIALISED_LIST;
    }
    Node* temp1;
    Node* temp2 = NULL;
    int swapped;
    do {
        swapped = 0;
        temp1 = (*listPtr)->head;
        while (temp1->next != temp2) {
            if (temp1->value > temp1->next->value) {
                if (swap(temp1, temp1->next)) {
                    return FAILURE;
                }
                else swapped = 1;
            }
            temp1 = temp1->next;
        }
        temp2 = temp1;
    }
    while (swapped);
    printf("INFO: List sorted\n");
    return SUCCESS;
}

void print_list(List** listPtr) {
    if (listchk(listPtr)) {
        printf("ERROR: Cannot print an uninitialised list\n");
        return;
    }
    Node* temp = (*listPtr)->head;
    printf("START ");
    while (temp != NULL) {
        if (temp->next == NULL)
            printf("%d", temp->value);
        else 
            printf("%d -> ", temp->value);
        temp = temp->next;
    }
    free(temp);
    printf(" END\n");    
}

void free_list(List** listPtr) {
    if (listchk(listPtr)) {
        printf("ERROR: Cannot free an uninitialised list\n");
        return;
    }
    Node* temp;
    Node* head = (*listPtr)->head;
    while (head != NULL) {
        temp = head;
        head = head->next;
        free(temp);
    }
    (*listPtr)->head = NULL;
    (*listPtr)->length = 0;
    printf("INFO: List deallocated\n");
}
