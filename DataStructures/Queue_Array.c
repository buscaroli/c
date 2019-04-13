/*
 * IMPLEMENTATION OF A QUEUE USING AN ARRAY
 * ALSO IMPLEMENTING BASIC FUNCTIONS
 *
 * Matteo Buscaroli
 */
#include <stdio.h>
#include <stdlib.h>

// DATA STRUCTURE

struct Queue{
    int size;   //size of the queue, from user
    int front;  //points to the front of the queue
    int rear;   // points to the rear of the queue
    int *arr;   // array containing the elements
};


// FUNCTIOINS

/*
 * Creates the queue using a dynamically allocated
 * array and initializes the DS parameters.
 * Both front and rear starts at -1.
 */
void createQ(struct Queue *q){
    printf("%s\n", "Enter the size of the queue:");
    scanf("%d", &(q->size));

    q->arr = (int*) malloc (q->size * sizeof(int));
    if (q->arr == NULL) exit (-1);

    q->front = -1;
    q->rear = -1;
}

/*
 * Inserts (Enqueues) a given element at the rear of
 * the queue.
 */
void enqueue(struct Queue *q, int key){
    if (q->rear == q->size -1){
        printf("%s\n", "Queue is Full");
        return;
    }
    else {
        q->rear++;
        q->arr[q->rear] = key;
    }
}

/*
 * Deletes (Dequeues) the element at the front of the queue.
 */
int dequeue(struct Queue *q){
    int ret = -1;
    if (q->front == q->rear){
        printf("%s\n", "Queue is Empty");
    }
    else {
        int ret = q->arr[q->front];
        q->front++;
    }
    return ret; // -1 if empty
}

/*
 * Checks if the queue is empty and returns a boolean.
 * 1 = Empty
 * 0 = Not EMpty
 */
int isEmpty(struct Queue q){
    return (q.front == q.rear);
}

/*
 * Checks if the queue is full and returns a boolean.
 * 1 = Full
 * 0 = Not Full
 */
int isFull(struct Queue q){
    return (q.rear == q.size-1);
}

/*
 * Displays all the elements of the queue.
 */
void displayQ(struct Queue q){
    if (q.rear == q.front){
        printf("%s\n", "Queue is Empty");
        return;
    }
    else {
        for (int i = q.front+1; i <= q.rear; i++){
            printf("%d\n", q.arr[i]);
        }
    }
}

// MAIN

/*
 * Everythinginside main has been used to test
 * the functions
 */
int main(void){

    struct Queue first;

    createQ(&first);

    displayQ(first);

    printf("The queue %s empty\n", isEmpty(first)? "is" : "is not");
    printf("The queue %s full\n", isFull(first)? "is" : "is not");

//    enqueue(&first, 55);

    for (int i = 1; i < 5; i++){
        enqueue(&first, i*10);
    }

    printf("The queue %s empty\n", isEmpty(first)? "is" : "is not");
    printf("The queue %s full\n", isFull(first)? "is" : "is not");


    displayQ(first);

    printf("The value returned was %d\n", dequeue(&first));

    return 0;
}
