#include <stdio.h>
#include <stdlib.h>
#include "chaining.h"

/* Search for the given key and return 1 if found
 * or NULL if Not found
 * Uses two utility functions to calculate the hash key
 * and to search a lined list, which is how elements of
 * an Open Addressing Hash Table are stored.
 */
int Search_chaining(struct Node **p, int key){

    int index = Hash_modulo10(key);

    // If the node of the key is NULL
    // the element is not in the table
    if (p[index] == NULL){
        return 0;
    } else {
        return Search_ll(p[index], key);
    }
}
/*
  * Search for an element inside the linked list and
  * returns 1 if found, NULL if NOT FOUND
  */
int Search_ll(struct Node *p, int key){
	while (p != NULL){
		if (p->data == key){
			return 1;
		}
		p = p->next;
	}
	return NULL;
}


/* HASH FUNCTION:  Simple module function
 * Using 10 as easier to understand, however for a real
 * project the use of power of 10 and 2 should be avoided
 * and the use of prime numbers is strongly encouraged
 */
 int Hash_modulo10 (int key){
    return key%10;
 }

/* FUNCTION TO INSERT ELEMENT (HT)
 * The insertion is ordered to increase the speed of
 * the search, which is one of the main reason to use
 * a hash table in the first place
 */
 void Insert_hashtable (struct Node **H, int key){
    int index = Hash_modulo10(key);
    Insert_ordered(&H[index], key);
 }


/*
 * Inserts value in the right position given an
 * ordered list
 */
void Insert_ordered(struct Node **head, int key){
	struct Node *p, *q;
	struct Node *temp = (struct Node *) malloc(sizeof(struct Node));
	if (!temp) exit(-1);
	temp->data = key;
	temp->next = NULL;

	p = *head;
	q = NULL;

	if (p == NULL) {
		*head = temp;
	}
	else {
            // Mind the order is important!! First check if p is NULL then
            // check if p->data is < key !!
		while (p != NULL  && p->data < key ){
			q = p;
			p = p->next;
		}
		if (p == *head){
			temp->next = *head;
			*head = temp;
		}
		else{
			temp->next = q->next;
			q->next = temp;

		}

	}

}

