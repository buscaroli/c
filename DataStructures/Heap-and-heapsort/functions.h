#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define MAX_SIZE    12

// DATA STRUCTURES

struct heap {
    int index;
    int arr[MAX_SIZE];
};

// PROTOTYPES

void Heap_init(struct heap *h);
void Heap_heapify(struct heap *h, int node);

int Heap_max(struct heap *h, int a, int b, int c);
void Heap_swap (struct heap *h, int a, int b);
void Heap_build_heap(struct heap *h);
void Heap_print(const struct heap *h);
void Heap_create_random(struct heap *h);
void Heap_insert_tail(struct heap *h, int value);
int Heap_extract_max( struct heap *h);
int Heap_parent_node(int node);
void Heap_insert (struct heap *h, int value);
void Heap_heapsort(struct heap *h);


