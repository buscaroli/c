/* Matteo "Mmontyy" Buscaroli
 *
 * CREATING A STACK DATA STRUCTURE IN C
 * IMPLEMENTED WITH A DINAMICALLY ALLOCATED ARRAY
 * WHOSE SIZE IS USER DEFINED AT RUN-TIME.
 * ALSO IMPLEMENTED A FEW RELATED FUNCTIONS.
 */
#include <stdio.h>
#include <stdlib.h>

// DATA STRUCTURE
struct stack {
    int size;
    int top;
    int *arr;
};

// FUNCTIONS

/*
 * Creates the stack structure by asking the user to insert
 * the size of the stack and then initializing the structures's
 * variables to the initial values
 */
void create_stack(struct stack *s){
    printf("%s\n", "Please enter the size of the Stack:");
    scanf("%d", &(s->size));
    s->arr = (int*) malloc ((s->size)*sizeof(int));
    s->top = -1;

}

/*
 * Displays the elements of the stack top to bottom and
 * highlights if the stack is empty
 */
void display_stack(struct stack s){
    if (s.size == 0){
        printf("%s\n", "Empty Stack");
        return;
    }

    for (int i = s.top; i >= 0; i--){
        printf("%3d: %d\n", i, s.arr[i]);
    }
}

/*
 * Pushes an element onto the top of the stack
 * making sure it's not already full, otherwise
 * would print an error message and return
 */
void push(struct stack *s, int key){
    if (s->top == s->size-1){
        printf("%s\n", "Stack Overflow");
        return;
    }

    s->top++;
    s->arr[s->top] = key;
}

/*
 * Removes (Pops) the element at the top of the stack.
 * If empty warns the user with a message and then exits
 * with error code -1.
 */
int pop(struct stack *s){
    int ret;

    if (s->top == -1){
        printf("%s\n", "Stack Underflow");
        exit (-1);
    }
    ret = s->arr[s->top];
    s->top--;
    return ret;

}

// MAIN

/*
 * Main functions used to play with the functions implemented
 */
int main(void){
    struct stack first;
    create_stack(&first);
    for (int i = 1; i < 7; i++){
        push(&first, i*10);
    }

    display_stack(first);

    for (int i = 0; i < 7; i++){
        printf("item removed: %d\n", pop(&first));
    }

    return 0;
}
