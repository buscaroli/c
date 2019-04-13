/*
 * IMPLEMENTATION OF A CIRCULAR QUEUE USING AN ARRAY
 * ALSO IMPLEMENTING BASIC FUNCTIONS
 *
 * Matteo Buscaroli
 *
 * Circular Queue implemented with an Array:
 *      Achieved using the following operations
 *      to advance the pointers:
 *          Rear = (Rear + 1) % size
 *          Front = (Front + 1) % size
 *
 * e.g. with Rear and an array size of 7:
 *
 * Rear | (Rear + 1) % 7    | Result
 * 0    | (0 + 1) % 7       | 1
 * 1    | (1 + 1) % 7       | 2
 * ...
 * 6    | (6 + 1) % 7       | 0 <- going back to the
 *                                 first position
 *
 * Both rear and Front are initialized to 0 and
 * once starting to add elements the only time
 * rear == front is when the queue is empty.
 *
 * NOTE : If the size of the queue is "n", only
 * "n-1" elements can be stored, as front always
 * points to an empty position.
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
 * Both front and rear starts at 0.
 */
void createQ(struct Queue *q){
    printf("%s\n", "Enter the size of the queue:");
    scanf("%d", &(q->size));

    q->arr = (int*) malloc (q->size * sizeof(int));
    if (q->arr == NULL) exit (-1);

    q->front = 0;
    q->rear = 0;
}

/*
 * Inserts (Enqueues) a given element at the rear of
 * the circular queue.
 */
void enqueue(struct Queue *q, int key){
    if (((q->rear +1) % q->size )== q->front){
        printf("%s\n", "Queue is Full");
        return;
    }
    else {
        q->rear = (q->rear + 1) % q->size;
        q->arr[q->rear] = key;
    }
}

/*
 * Deletes (Dequeues) the element at the front of the
 * circular queue.
 */
int dequeue(struct Queue *q){
    int ret = -1;
    if (q->front == q->rear){
        printf("%s\n", "Queue is Empty");
    }
    else {
        q->front = (q->front + 1) % (q->size);
        ret = q->arr[q->front];
    }
    return ret; // -1 if empty
}

/*
 * Checks if the queue is empty and returns a boolean.
 * The queue is empty only when front == rear.
 * Returns:
 *      1 = Empty
 *      0 = Not Empty
 */
int isEmpty(struct Queue q){
    return (q.front == q.rear);
}

/*
 * Checks if the queue is full and returns a boolean.
 * The queue is full when the front is one position
 * behind the rear.
 * Returns:
 *      1 = Full
 *      0 = Not Full
 */
int isFull(struct Queue q){
    return (((q.front + 1) % q.size) == q.rear);
}

/*
 * Displays all the elements of the queue.
 * Starts from the front + 1, increments using
 * mod size as the array is circular and ends when
 * the rear is reached.
 */
void displayQ(struct Queue q){
    int i = q.front + 1;
    if (q.rear == q.front){
        printf("%s\n", "Queue is Empty");
        return;
    }
    else {
        do {
            printf("%d \n", q.arr[i]);
            i = (i+1) % q.size;
        } while (i != (q.rear + 1) % q.size);
    }
}

// MAIN

/*
 * Everything inside main has been used to test
 * the functions
 */
int main(void){

    struct Queue first;

    createQ(&first);

    displayQ(first);

    printf("The queue %s empty\n", isEmpty(first)? "is" : "is not");
    printf("The queue %s full\n", isFull(first)? "is" : "is not");

    for (int i = 1; i < 5; i++){
        enqueue(&first, i*10);
    }
    printf("%s\n", "Inserted 4 elements:");

//    printf("The queue %s empty\n", isEmpty(first)? "is" : "is not");
//    printf("The queue %s full\n", isFull(first)? "is" : "is not");


    displayQ(first);

    printf("The value returned was %d\n", dequeue(&first));

    displayQ(first);

    return 0;
}
