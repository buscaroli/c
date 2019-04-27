/***************************************************************
 * UNINETTUNO UNIVERSITY - ALGORITHM AND DATA STRUCTURES
 *
 * Matteo Buscaroli
 *
 * Implementation of Counting Sort, Sorting Algorithm
 *
 **************************************************************/

#include <stdio.h>
#include <stdlib.h>

void Counting_sort (int* arr, int size, int range);

int main()
{
    int arr[12] = {1, 4, 3, 0, 5, 3, 2, 3, 2, 4, 5, 2};

    printf("\n%s\n", "The unsorted array is:");
    for (int i = 0; i < 12; i++)
        printf("%4d", arr[i]);

    Counting_sort(arr, 12, 20);
    printf("\n%s\n", "The sorted array is:");
    for (int i = 0; i < 12; i++)
        printf("%4d", arr[i]);

    return 0;
}

// Sorting algorithm
void Counting_sort (int* A, int n, int k) {
    // n is the size of the array, k is the range of the values
    // A = Original array
    // B = copy of original array
    // C = Counting array, holds frequency of elements
    int B[n]; // will store the sorted array

    int C[k];  // will hold the frequency of each value

    // Initializing it to 0
    for (int i = 0; i < k; i++)
        C[i] = 0;

    // Calculating the frequency of every element in A and
    // storing it into C[]
    for (int i = 0; i < n; i++)
        C[A[i]]++;

    // Calculating the starting index of each element. C[] will
    // hold cumulative values of frequency of each element
    for (int i = 1; i < k; i++)
        C[i] = C[i-1] + C[i];

    // Creating the sorted array
    for (int i=n; i >= 0; i--){
        B[C[A[i]]-1] = A[i];
        C[A[i]]--;
    }

    // Copying the sorted array back into the original one
    for (int i = 0; i < n; i++)
        A[i] = B[i];
}

