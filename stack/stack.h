#ifndef STACK_H
#define STACK_H

#include <stdio.h>
#define SIZE 10

int stack[SIZE] = {0};
int top = -1;
int push(int value) {
    if (top == SIZE) {
        printf("Buffer overflow\n");
        return 1;
    }
    else {
        top++;
        stack[top] = value;
        return 0;
    }
}

int pop() {
    if (top == -1) {
        printf("Buffer underflow\n");
        return 1;
    }
    else {
        top--;
        return 0;
    }
}

void printList() {
    if (top == -1) {
        printf("Stack empty\n");
    }
    else {
        printf("START\n");
        for (int i = 0; i < top; i++) {
            printf("%d\n", stack[i]);
        }
        printf("END\n");
    }
}

#endif