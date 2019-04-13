/* Matteo "Mmontyy" Buscaroli
 *
 * STACK IMPLEMENTE WITH SINGLY LINKED LIST IN C
 * ALSO IMPLEMENTED RELATED UTILITY FUNCTIONS
 */

#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

// DATA STRUCTURE

struct Node {
    int data;
    struct Node *next;
};

// FUNCTIONS

/*
 * Initializes the stack by setting the pointer to
 * the first node to zero
 */
void init_stack(struct Node **head){
    printf("CREATE INTRO OK\n");
    *head = NULL;
    printf("CREATE EXIT OK\n");

}

/*
 * Inserts (Pushes) the given value into the top position
 * of the Stack, allocating memory for it.
 * In case of Stack Overflow displays an error and returns
 * INT_MIN
 */
void push(struct Node **head, int key){
    struct Node *temp;
    temp = (struct Node*) malloc (sizeof(struct Node));
    if (temp == NULL){
        printf("%s\n", "Error: Malloc Overflow");
        return INT_MIN;
    }
    else {
        temp->data = key;
        temp->next = *head;
        *head = temp;
    }
}

/*
 * Removes (Pops) the value of the element at the top of the Stack.
 * Displays an error msg if the stack is empty and returns INT_MIN.
 * Frees the memory previously allocated by the node before returning.
 */
int pop(struct Node **head){
    struct Node *p;
    p = *head;

    if (p == NULL){
        printf("%s\n", "Stack is empty");
        return (INT_MIN);
    }
    else {
        int popped = p->data;
        *head = (*head)->next;
        free(p);
        p = NULL;
        return popped;

    }
}

/*
 * Displays the elements of the Stack.
 * In case the stack is empty, it displays a msg.
 */
void display(struct Node *head){
    if (head == NULL){
        printf("%s\n", "Stack Empty");
        return;
    }
    else {
        while (head != NULL){
            printf("%3d\n", head->data);
            head = head->next;
        }
    }
}

//MAIN

int main(void){
    struct Node *first;

    init_stack(&first);

    for (int i = 1; i < 5; i++){
        push(&first, i*10);
    }

    display(first);

    for (int i = 1; i < 10; i++){
        printf("The item removed is %3d\n", pop(&first));
    }

    display(first);



    return 0;
}
