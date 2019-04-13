#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

// DATA STRUCTURE
struct Node{
	int data;
	struct Node *next;
}*first, *second;

// FUNCTIONS
/*
 * Creates a linked list from an array of int
 */ 
void create(int A[], int n){
	int i;
	struct Node *t, *last;
	first=(struct Node*) malloc (sizeof(struct Node));
	first->data = A[0];
	first->next = NULL;
	last = first;
	
	for (i = 1; i<n; i++){
		t = (struct Node*)malloc(sizeof(struct Node));
		t->data = A[i];
		t->next = NULL;
		last->next = t;
		last = t ;
	}
}

void Display(struct Node *p){
	
	while (p != NULL){
		printf("%3d -> ", p->data);
		p = p->next;
	}
	printf("%s", "\n");
}

/*
 * Recursive varsion of Display - Tail Call
 */
void Display_r(struct Node *p){
	if (p != NULL){
		printf("%3d -> ", p->data);
		Display_r(p->next);
	}
	
}

/*
* Recursive varsion of Display - Head Call
* Elements will be printed in reverse order
*/
void Display_r_rev(struct Node *p){
	if (p != NULL){
		Display_r_rev(p->next);
		printf("%3d -> ", p->data);
	}
	
	
}

 /*
  * Counts the nodes in the list
  */
  int count(struct Node *p){
  	int counter = 0;
  	
  	while (p != NULL){
  		counter++;
  		p = p->next;
	  }
	return counter;
  }

/*
  * Counts the nodes in the list
  */
  int count_r(struct Node *p){
  	
  	if ( p == NULL){
  		return 0;
	  }
  	else {
		return count_r(p->next) + 1; 
		
    }
    
  }

/*
 * Sums the dada of all the elements of the list
 */ 
int sum (struct Node *p){
	int total = 0;
	
	while (p != NULL){
		total += p->data;
		p = p->next;
	}	
	return total;
}

/*
 * Sums the dada of all the elements of the list
 */ 
int sum_r(struct Node *p){
	if (p == 0){
		return 0;
	}
	else {
		return sum_r(p->next) + p->data;
	}
}


/*
 * Finds and returns the minimum number in the list
 */
 int minimum(struct Node *p){
 	int m = INT_MAX;
 	
 	while (p != NULL){
 		if (p->data < m){
 			m = p->data;
		 }
		 p = p->next;
	 }
	 return m;
 }
 
/*
 * Finds and returns the maximum number in the list
 */
 int maximum(struct Node *p){
 	int m = INT_MIN;
 	
 	while (p != NULL){
 		if (p->data > m){
			m = p->data;
		}
		p = p->next;
	 }
 	return m;
 }
 
/*
 * Finds and returns the maximum number in the list
 * Recursive version
 */
 int maximum_r(struct Node *p){
 	int x;
	if (p == NULL){
 		return INT_MIN;
	}
	else {
		x = maximum_r(p->next);
		if (x > p->data){
	 		return x;
	 	} else {
	 		return (p->data);
		 }
	}
 		
 }
 
 /*
 * Finds and returns the maximum number in the list
 * Recursive version, ternary operator
 */
 int maximum_r_ternary(struct Node *p){
 	int x;
	if (p == NULL){
 		return INT_MIN;
 	}
 	else {
		x = maximum_r_ternary(p->next);
		return x > p->data ? x : p->data;
 	}
 }
 
 /*
  * Srearch for an element inside the list and 
  * returns the pointer to the item
  */
struct Node* search(struct Node *p, int key){
	while (p != NULL){
		if (p->data == key){
			return p;
		}
		p = p->next;
	}
	return NULL;
}
 
 /*
  * Srearch for an element inside the list and 
  * returns the pointer to the item
  * RECURSIVE version
  */
struct Node* search_r(struct Node *p, int key){
	if (p == NULL){
		return NULL;
	}

	if (p->data == key){
		return p;
	}
	else {
		return search_r(p->next, key);
	}
}
 
 /*
  * Search for an element inside the list and 
  * returns the pointer to the item, if found
  * applies "move to head": item is moved to
  * the first element of the list so
  * the next time the search will be faster
  */
struct Node* search_mth(struct Node **head, int key){

	struct Node *p, *q;
	p = *head;
	q = NULL;
	
	while (p != NULL){
		if (p->data == key){
			q->next = p->next;
			p->next = *head;
			*head = p;
			return p;
		}
		q = p;
		p = p->next;
	}
	return NULL;
}

/*
 * Inserts an item at a given index
 */
void insert(struct Node **head, int index, int x){
	struct Node *temp, *p;
	p = *head;
	
	
	if (index < 0 || index > count(p)){
		return;
	}
	
	temp = (struct Node*)malloc(sizeof(struct Node));
	temp->data = x;
	temp->next = NULL;
	
	// 2 cases: at the head of the list
	//          after a node
	if (index == 0){
		temp->next = p;
		*head = temp;
	}
	else {
		for (int i = 0; i < index-1 ; i++){
			p = p->next;
		}
		temp->next = p->next;
		p->next = temp;
	}	
	
}

/*
 * Inserts an item at the tail of the list
 */
void insert_tail(struct Node **head, int key){
	struct Node *p = *head, *temp;
	/* same as struct Node *p; p = *head; */
	
	temp = (struct Node*)malloc(sizeof(struct Node));
	if (!temp) exit(-1);
	temp->data = key;
	temp->next = NULL;
	
	if (*head == NULL){
		*head = temp;
	}
	else {
		p = *head;
		while (p->next != NULL){
			p = p->next;
		}
		p->next = temp;
	}
}

/*
 * Inserts value in the right position given an
 * ordered list
 */
void insert_ordered(struct Node **head, int key){
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
		while (p->data < key && p != NULL ){
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
 
/*
 * Deletes the node at the given index
 */ 
 
 void delete(struct Node **head, int index){
 	struct Node *p, *q;
 	p = *head;
 	q = NULL;
 	
 	if (p == NULL || index < 0 || index > count(p)){
 		return;
	 }
	
	for (int i = 0; i < index-1; i++){
		q = p;
		p = p->next;
	}
	if (p == *head){
		*head = p->next;
		free(p);
		p = NULL;
	}
	else {
		q->next = p->next;
		free(p);
		p = NULL;	
	}
 }
// MAIN

int main (void){
	int A[] = {3, 5, 7, 10, 15};
	struct Node *temp;
	
	create(A, 5);
	Display(first);
	Display_r(first);  
	printf("%s", "\n");
	Display_r_rev(first);
	printf("%s", "\n");
	printf("There are %d elements in the list\n", count(first));
	printf("There are %d elements in the list\n", count_r(first));
	printf("The total is %d \n", sum(first));
	printf("The total is %d \n", sum_r(first));
	printf("The min is %d \n", minimum(first));
	printf("The max is %d \n", maximum(first));
	printf("The max is %d \n", maximum_r(first));
	printf("The max is %d \n", maximum_r_ternary(first));
	temp = search_mth(&first, 7);
	printf("Moved to head: %d\n", temp->data);
	Display(first);
	insert(&first, 0, 30);
	Display(first);
	insert(&first, 3, 40);
	Display(first);
	insert_tail(&first, 100);
	Display(first);
	printf("%s\n","Second list:");
	for (int i = 1; i <= 5; i++){
		insert_tail(&second, i*10);
	}
	Display(second);
	insert_ordered(&second, 25);
	Display(second);
	insert_ordered(&second, 5);
	Display(second);
	delete(&second, 2);
	Display(second);
	delete(&second, 0);
	Display(second);
	delete(&second, 10);
	Display(second);
	delete(&second, -5);
	Display(second);
		
	return 0;
}


