/*
 * IMPLMENTATION OF A QUEUE USING LINKED LISTS
 * RELATED FUNCTIONS ALSO IMPLEMENTED
 *
 * USING TWO POINTERS IN ORDER TO BE ABLE TO
 * ENQUEUE AND DEQUEUE IN CONSTANT TIME
 *
 * If front == NULL the queue is empty
 * If front == rear it means there is only one
 *      element in the queue
 *
 * Matteo Buscaroli
 */

#include <stdio.h>
#include <stdlib.h>

// DATA STRUCTURES

struct Node{
    int data;
    struct Node *next;
};

struct Queue{
    struct Node *front;
    struct Node *rear;
};

// FUNCTIONS

/*
 * Initializes a queue structure.
 * Both front and rear pointing to NULL.
 */
void init_queue(struct Queue *q){
    q->front = NULL;
    q->rear = NULL;
}

/*
 * Inserts (euqueues) a new node in the queue.
 */
void enqueue(struct Queue *q, int key){
    struct Node *temp = (struct Node*) malloc (sizeof(struct Node));
    // Checking memory could be allocated
    if (temp == NULL) {
        printf("%s\n", "Queue is Full");
    }
    else {
        temp->data = key;
        temp->next = NULL;
        // Case inserting first element
        if (q->front == NULL){
            q->front = temp;
            q->rear = temp;
        }
        // Case inserting any other element
        else {
            q->rear->next = temp;
            q->rear = temp;
        }
    }
}

/*
 * Removes (dequeues) the element at the front of the queue.
 * Needs to consider three separate cases:
 *  1) Queue is Empty
 *  2) Queue has one element (front == rear)
 *  3) Queue has more than one element
 *
 * Returns the data of the element at the front.
 */
int dequeue (struct Queue *q){
    int ret = -1;

    // Case queue is empty
    if (q->front == NULL){
        printf("%s\n", "Empty queue, nothing to dequeue");
    }
    else {
        struct Node *temp = q->front;
        // Case queue has only one element
        if (q->front == q->rear){
            ret = q->front->data;
            init_queue(q);
        }
        // Case queue has 2+ elements
        else{
            ret = q->front->data;
            q->front = q->front->next;
        }
        free(temp);
    }

    return ret;
}

void display(struct Queue *q){
    struct Node *current = q->front;
    if (current == NULL){
        printf("%s\n", "Queue is Empty");
    }
    else {
        while (current != NULL){
            printf("%3d ->", current->data);
            current = current->next;
        }
        printf("%s", "\n");
    }
}


// MAIN

int main(void){

    struct Queue first;

    // Initialise the queue
    init_queue(&first);

    // Add five elements to the queue
    for (int i = 1; i < 6; i++){
        enqueue(&first, i*10);
    }

    // Display the elements
    display(&first);

    // Remove the element at the front and
    // print its value
    printf("The item at the front was %d\n", dequeue(&first));

    // Display the queue after one item
    // has been removed
    display(&first);

    // Deleting all the elements and more
    printf("The item at the front was %d\n", dequeue(&first));
    printf("The item at the front was %d\n", dequeue(&first));
    printf("The item at the front was %d\n", dequeue(&first));
    printf("The item at the front was %d\n", dequeue(&first));
    printf("The item at the front was %d\n", dequeue(&first));

    display(&first);

    return 0;
}
