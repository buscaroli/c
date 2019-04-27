/**********************************************************
 * UNINETTUNO UNIVERSITY - DATA STRUCTURES AND ALGORITHMS
 *
 * Matteo Buscaroli - Lesson 12, Ex 12.1
 *
 * Implement the Heapsort algorithm, using the
 * data structure and functions already implemented in
 * a previous lesson.
 *
 *********************************************************/

#include <stdio.h>
#include <stdlib.h>
#include "functions.h"

int main()
{

    struct heap heap01;

    // INITIALIZING THE HEAP
    Heap_init(&heap01);

    // FILLING THE HEAP WITH RANDOM NUMBERS
    Heap_create_random(&heap01);


    // PRINTING THE HEAP AS A LIST
    printf("%s\n", "Printing the array:");
    Heap_print(&heap01);

    // PRINTING THE HEAP AFTER BUILD_HEAP
    printf("%s\n", "Printing the array after Heap_build_heap:");
    Heap_build_heap(&heap01);
    Heap_print(&heap01);

    // PRINTING THE HEAP AFTER HEAPSORT
    printf("%s\n", "Sorting the array:");
    Heap_heapsort(&heap01);
    Heap_print(&heap01);


    return 0;
}
