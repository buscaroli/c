/* BINARY SEARCH TREE
 * IMPLEMENTATION OF THE DATA STRUCTURE AND
 * ASSOCIATED FUNCTIONS
 *
 * Also Using the Circular QUeue Data Structure to
 * enter the tree nodes by hand
 *
 * Matteo Buscaroli
 */

#include <stdio.h>
#include <stdlib.h>

// DATA STRUCTURES

struct Node {
    struct Node *lchild;
    int data;
    struct Node *rchild;
};

struct Queue{
    int size;   //size of the queue, from user
    int front;  //points to the front of the queue
    int rear;   // points to the rear of the queue
    struct Node **arr;   // array containing the elements
};

// FUNCTIONS: QUEUE and BST

    // ----------QUEUE---------------------

/*
 * Creates the queue using a dynamically allocated
 * array and initializes the DS parameters.
 * Both front and rear starts at 0.
 */
void createQ(struct Queue *q){
    printf("%s\n", "Enter the size of the queue:");
    scanf("%d", &(q->size));

    q->arr = (int**) malloc (q->size * sizeof(struct Node* ));
    if (q->arr == NULL) exit (-1);

    q->front = 0;
    q->rear = 0;
}

/*
 * Inserts (Enqueues) a given element at the rear of
 * the circular queue.
 */
void enqueue(struct Queue *q, struct Node *x){
    if (((q->rear +1) % q->size )== q->front){
        printf("%s\n", "Queue is Full");
        return;
    }
    else {
        q->rear = (q->rear + 1) % q->size;
        q->arr[q->rear] = x;
    }
}

/*
 * Deletes (Dequeues) the element at the front of the
 * circular queue.
 */
struct Node* dequeue(struct Queue *q){
    struct Node *ret = NULL;
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


    // ----------BST------------------

/*
 * Initializes a Binary Search Tree
 * Data Structure by making the root node
 * point to NULL
 */
void Init_bst(struct Node **root){
    *root = NULL;
}

/*
 * Create a BST asking for each node's value
 * starting from the root node and then following
 * from top to bottom and from left to right.
 * Enter -1 if the node is missing, you will be
 * asked to enter a node number until a full level
 * has been entered.
 *
 * Uses a Circular Queue to keep track of the nodes
 * that have been entered.
 */
void create_bst(struct Node **root){
    struct Node *p, *t;
    int x;
    struct Queue q;

    createQ(&q);

    printf("%s\n", "Enter value of root:");
    scanf("%d", &x);
    *root = (struct Node *) malloc(sizeof(struct Node));
    if (*root == NULL) exit (-1);
    (*root)->data = x;
    (*root)->lchild = (*root)->rchild=NULL;
    enqueue(&q, *root);

    while (!isEmpty(q)){
        p = dequeue(&q);
        printf("Enter left child of %d [-1 if not present]:\n", p->data);
        scanf("%d", &x);
        if (x != -1){
            t = (struct Node*) malloc (sizeof(struct Node));
            if (t == NULL) exit (-1);
            t->data = x;
            t->lchild = t->rchild = NULL;
            p->lchild = t;
            enqueue(&q, t);
        }
        printf("Enter right child of %d [-1 if not present]:\n", p->data);
        scanf("%d", &x);
        if (x != -1){
            t = (struct Node*) malloc (sizeof(struct Node));
            if (t == NULL) exit (-1);
            t->data = x;
            t->lchild = t->rchild = NULL;
            p->rchild = t;
            enqueue(&q, t);
        }

    }
}

/*
 * Prints the values of the nodes in Preorder
*/
void preorder(struct Node *p){
    if (p){
        printf("%d ", p->data);
        preorder(p->lchild);
        preorder(p->rchild);
    }
}

/*
 * Prints the values of the nodes in Postorder
*/
void postorder(struct Node *p){
    if (p){
        preorder(p->lchild);
        preorder(p->rchild);
        printf("%d ", p->data);
    }
}

/*
 * Prints the values of the nodes in Inorder
*/
void inorder(struct Node *p){
    if (p){
        preorder(p->lchild);
        printf("%d ", p->data);
        preorder(p->rchild);
    }
}

/*
 * Counts the nodes in the Binary Tree.
 * It's a recursive function, at the beginning
 * checks if the current node is NULL, if it is
 * ir returns 0, otherwise it returns the result
 * of the call of its sub-trees + 1 (the current node).
 *
 * Returns the number of nodes in the Tree.
 */
int countNodes(struct Node *p){
    int x, y;

    if (p){ // same as p != NULL
        x = countNodes(p->lchild);
        y = countNodes(p->rchild);

        return x+y+1;
    }
    return 0;
}

/*
 * Counts the nodes whose degree is 2.
 * It's a recursive function, and it's a
 * modification of the function countNodes.
 *
 * Returns the number of deg2 nodes in the Tree.
 */
int countDeg2(struct Node *p){
    int x = 0, y = 0;

    if (p != NULL){
        x = countDeg2(p->lchild);
        y = countDeg2(p->rchild);
        if (p->lchild && p->rchild)
            return x+y+1;
        else
            return x+y;
    }
    return 0;
}

/*
 * Counts the leaves of the Tree.
 * It's a recursive function, and it's a
 * modification of the function countNodes.
 *
 * Returns the number of Leaves in the Tree.
 */
int countLeaves(struct Node *p){
    int x = 0, y = 0;

    if (p != NULL){
        x = countLeaves(p->lchild);
        y = countLeaves(p->rchild);
        if (p->lchild == 0 && p->rchild == 0)
            return x+y+1;
        else
            return x+y;
    }
    return 0;
}

/*
 * Counts the sum of the values of the nodes.
 * It's a recursive function, and it's a
 * modification of the function countNodes.
 *
 * Returns the sum of the nodes in the Tree.
 */
int countSum(struct Node *p){
    int x = 0, y = 0;

    if (p != NULL){
        x = countSum(p->lchild);
        y = countSum(p->rchild);

        return x+y+(p->data);
    }
    return 0;
}


// MAIN ---------------------------------------

/*
 * Everything inside main is used
 * to experiment with the code and for
 * debugging purposes
 */
int main (void){

    struct Node *root;
    Init_bst(&root);

    create_bst(&root);

    preorder(root);

    printf("\nThere are %d nodes\n", countNodes(root));

    printf("\nThere are %d nodes with a degree of 2\n", countDeg2(root));

    printf("\nThe sum of the values of the nodes is %d\n", countSum(root));

    printf("\nThere are %d leaves\n", countLeaves(root));

    //inorder(root);

    //postorder(root);
    return 0;
}
