/* BINARY SEARCH TREE
 * IMPLEMENTATION OF THE DATA STRUCTURE AND
 * ASSOCIATED FUNCTIONS
 *
 * Matteo Buscaroli
 *
 * ----- TO DO : BST_DELETE ------
 */

#include <stdio.h>
#include <stdlib.h>

// DATA STRUCTURES

struct Node {
    struct Node *lchild;
    int data;
    struct Node *rchild;
};

// FUNCTIONS


/*
 * Initializes a Binary Search Tree
 * Data Structure by making the root node
 * point to NULL
 */
void Init_bst(struct Node **root){
    *root = NULL;
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
 * Searches for a value in the given tree.
 * If found returns the node's address, otherwise
 * returns NULL.
 * RECURSIVE VERSION
 *
 */
struct Node* BST_search(struct Node *q, int key){
    if (q == NULL){
        return NULL;
    }

    if (q->data == key){
        return q;
    }
    else if (key < q->data){
        return BST_search(q->lchild, key);
    }
    else{
        return BST_search(q->rchild, key);
    }


    return NULL;
}

/*
 * Searches for a value in the given tree.
 * If found returns the node's address, otherwise
 * returns NULL.
 * ITERATIVE VERSION
 *
 */
struct Node* BST_search_iter(struct Node *q, int key){

    while (q){
        if (q->data == key){
        return q;
        }
        else if (key < q->data){
            q = q->rchild;
        }
        else if (key > q->data){
            q = q->rchild;
        }
    }

    return NULL;
}

/*
 * Auxillary function to BST_insert that creates
 * a node in case the tree is empty
 */
struct Node* create_node(int key){

    struct Node* t = (struct Node*) malloc (sizeof(struct Node));
    if (!t) {
        puts("Error, malloc overflow");
        exit (-1);
    }
    t->data = key;
    t->lchild = t->rchild = NULL;
    return t;

};

/*
 * Inserts a node in a BST
 * Uses the auxillary function create_node
 * NB Using struct Node *node and not **node as the
 * ** are required only if I intend to modify the pointer
 * I am passing to the function!
 *
 * Also note the need to "start" the tree when calling the
 * function the first time with something like:
 * first = BST_insert(NULL, int);
 *
 */
struct Node* BST_insert(struct Node *node, int key){

    if (node == NULL){
        return create_node(key);
//  What follows in the comments has been replaced by
//  the above line that invokes create_root
//        struct Node *t;
//        t = (struct Node*) malloc (sizeof(struct Node));
//        t->data = key;
//        t->lchild = t->rchild = NULL;
//        return t;
    }
    if (key < node->data){
        node->lchild = BST_insert(node->lchild, key);
    }
    else if (key > node->data){
        node->rchild = BST_insert(node->rchild, key);
    }
    return node;
}

 /*
  * Utility function, used by BST_delete, that
  * finds the inorder predecessor of the given node
  * and returns it.
  */
struct Node* inorder_predecessor(struct Node *node){
    if (node == NULL)
        return node;

    if (node->lchild == NULL && node->rchild == NULL){
        return node->lchild;
    }
    else {
        struct Node *p = node->lchild;
        while (p->rchild != NULL){
            p = p->rchild;
        }
        return p;
    }
}

// BST_delete to be implemented


// MAIN

/*
 * Everything in main is just for testing
 * purposes.
 */
int main (void){

    struct Node *first;
    Init_bst(&first);
    first = BST_insert(first, 15); // same as first = BST_insert(NULL, 15);
    BST_insert(first, 5);
    BST_insert(first, 3);
    BST_insert(first, 12);
    BST_insert(first, 13);
    BST_insert(first, 20);
    BST_insert(first, 35);
    BST_insert(first, 40);
    struct Node *x = inorder_predecessor(first);
    printf("pred -> %d\n", x->data);

    preorder(first);
    return 0;
}
