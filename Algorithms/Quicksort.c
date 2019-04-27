/***************************************************************
 * UNINETTUNO UNIVERSITY - ALGORITHM AND DATA STRUCTURES
 *
 * Matteo Buscaroli
 *
 * Implementation of Quicksort, Sorting Algorithm
 *
 **************************************************************/

#include <stdio.h>
#include <stdlib.h>

void Quicksort (int* arr, int p, int r);
int Partition (int* arr, int p, int r);
void swap (int* arr, int a, int b);

int main()
{
    int arr[12] = {1, 4, 3, 7, 5, 9, 2, 24, 15, 32, 6, 8};

    printf("\n%s\n", "The unsorted array is:");
    for (int i = 0; i < 12; i++)
        printf("%4d", arr[i]);

    Quicksort(arr, 0, 11);
    printf("\n%s\n", "The sorted array is:");
    for (int i = 0; i < 12; i++)
        printf("%4d", arr[i]);

    return 0;
}

// Sorting algorithm
void Quicksort (int* arr, int p, int r){
    int q;
    // Partition sceglie il pivot ed esegue gli scambi degli
    // elementi alla sx ed alla dx del pivot (riordinamento
    // dei due sottovettori)
    // Poi la funzione quicksort viene richiamate sui due
    // sottovettori utilizzando il pivot q ottenuto dalla
    // funzione Partition
    if (p < r){
        q = Partition(arr, p, r);
        Quicksort(arr, p, q-1);
        Quicksort(arr, q+1, r);
    }
}

int Partition (int* arr, int p, int r){
    // x is the pivot, selecting the first element but any
    // element of the array would do
    int x = arr[p];

    // il puntatore p parte da sx e scorre tutti gli elementi
    // dell'array fin quando ne trova uno maggiore del pivot
    while (1){
        while (arr[p] < x)
            p++;
    // il puntatore r parte da dx e scorre tutti gli elementi
    // dell'array fin quando ne trova uno minore del pivot
        while (arr[r] > x)
            r--;

    // Se p e' minore di r, cioe' se non si sono ancora incontrati
    // al centro, swappali, altrimenti significa che si sono incontrati
    // ed il valore di r sara' il nuovo pivot da ritornare
        if (p < r)
            swap (arr, p, r);
        else
            return r;
    }
}


// Utility function to swap two elements of an array giver the array
// and the two indexes
void swap (int* arr, int a, int b){
    int temp;

    temp = arr[a];
    arr[a] = arr[b];
    arr[b] = temp;
}
