#include "linked_list.h"

int main(void) {

    Node* node1 = create_node(1);
    List* head = create_list(node1);
    Node* node2 = create_node(2);
    Node* node3 = create_node(3);
    Node* node4 = create_node(4);
    Node* node5 = create_node(5);
    append(&head, node4);
    insert_node(&head, 1, node2);
    remove_node(&head, 20);
    append(&head, node3);
    sort(&head);
    print_list(&head);
    free_list(&head);

    return 0;
}