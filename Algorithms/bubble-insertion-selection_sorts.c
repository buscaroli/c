#include <stdio.h>
#include <stdlib.h>

void Print_array(int arr[], int size);
void Insertion_sort_iterative( int *arr, int size);
void swap( int*, int*);
void Bubble_sort(int *arr, int size);
void Selection_sort(int *arr, int size);

int main()
{

    int array1[10] = {3, 7, 4, 1, 8, 9, 2, 5, 6, 0};
    int array2[10] = {3, 7, 4, 1, 8, 9, 2, 5, 6, 0};
    int array3[10] = {3, 7, 4, 1, 8, 9, 2, 5, 6, 0};

    Print_array(array1, 10);
    Insertion_sort_iterative(array1, 10);
    Print_array(array1, 10);

    Print_array(array2, 10);
    Bubble_sort(array2, 10);
    Print_array(array2, 10);


    Print_array(array3, 10);
    Selection_sort(array3, 10);
    Print_array(array3, 10);


    return 0;
}

/*********************************************************
 * FUNCTION: PRINT_ARRAY
 *
 * Prints a given array
 *
 ********************************************************/
void Print_array(int arr[], int size){

    for (int i = 0; i < size; i++){
        printf("%3d", arr[i]);
    }
    printf("%s", "\n");
}

/**********************************************************
 * FUNCTION: INSERTION_SORT_ITERATIVE
 *
 * Sorts an array using the insertion sort algorithm.
 * Needs the address of the array and its size. It relies
 * on the swap function to swap two contiguous numbers of
 * the array.
 *
 * Best case input: Array already sorted.
 *      Linear running time O(n)
 * Worst case input: Array sorted in reverse order.
 *      Quadratic running time O(n^2)
 * Average Case input: Quadratic running time O(n^2)
 * It's a stable sorting algorithm.
 *
 *Very fast for small arrays (up to 10 elements), even
 * quicker than Quicksort; for this reason most quicksort
 * algorithm include a insertion_sort for small arrays.
 *
 *********************************************************/
void Insertion_sort_iterative( int *arr, int size){
    // i points to each element of the array starting
    // from the second position (index = 1) up to the
    // last element.
    // j starts by pointing at the same element as i,
    // compares that element with the one preceding and
    // swaps them appropriately. The it iterates down to
    // the second element so that all the elements before
    // i are sorted
    int i, j;

    for (i = 1; i < size; i++){
        j = i;
        while (j>0 && arr[j-1] > arr[j]){
            swap (&arr[j-1], &arr[j]);
            j--;
        }
    }


}

/**********************************************************
 * FUNCTION: SWAP
 *
 * Swaps two elements of an array.
 * Takes in the two addresses of the elements.
 *
 * Used in the Insertion_sort_iterative function.
 *
 *********************************************************/
void swap (int *arr1, int *arr2){

        int temp;

        temp = *arr1;
        *arr1 = *arr2;
        *arr2 = temp;
}

/**********************************************************
 * FUNCTION: BUBBLE_SORT
 *
 * Orders an array of int using the bubblesort algorithm.
 * Takes array's address and its size.
 *
 * Bubblesort is a very slow algorithm.
 * Best Case Input: all numbers already ordered O(n).
 * Worst Case Input ans Average Case Input O(n^2).
 * It's a stable sorting algorithm.
 *
 *********************************************************/
void Bubble_sort(int *arr, int size){
    // The outer loop is run (a number of times equal to
    // the length of the array), whereas  the inner loop
    // runs a number of times the size of the array minus
    // one on its first run (j starts from 1)
    // and one time less after every iteration after that,
    // because the largest number is taken to the end of
    // the array on the first iteration, so there is no
    // need to reach the end of the array in any subsequent
    // iteration. The same is true for the second iteration:
    // the second largest number is put in place so no need
    // to reach that position anymore.
    for (int i = 0; i < size; i++){
        for (int j = 1; j < size - i; j++){
            if (arr[j-1] > arr[j])
                swap(&arr[j-1], &arr[j]);
        }
        printf("%2d :", i+1);
        Print_array(arr, 10);

    }
}

/**********************************************************
 * FUNCTION: SELECTION_SORT
 *
 * Sorts an array of int using the selection sort algorithm
 * Takes in the address of the array and its size.
 *
 * Performs better than Bubblesort but worse than Insertion
 * sort. It's a non stable algorithm.
 *
 * Could be a better allternative than Insertion sort for
 * reducing the number of writes (using EEPROM or flash mem)
 * as does O(n) swaps instead of O(n^2) swaps.
 *
 * Worst Case Input: O(n^2)
 * Average Case Input: O(n^2)
 *
 *********************************************************/
void Selection_sort(int *arr, int size){
    int min_index;
    // Walking through the whole array a number of times
    // equal to its size.
    // Consider i as the partition line between the sorted
    // elements (at its left) and the non sorted elements
    // from i onwards
    // At each iteration the sorted part of the array (left)
    // grows and the unsorted (right) shrinks
    for (int i = 0; i < size; i++){
        // first iteration suppose first item is the smallest
        min_index = i;
        // at every iteration j starts looking at i+1, because
        // the items up to i have already been sorted, and
        // walks through till the end of the array marking
        // the index of the smallest item
        for (int j = i + 1; j < size; j++){
            if (arr[j] < arr[min_index])
                min_index = j;
        }
        // swap the elements with index i and min_index
        swap(&arr[i], &arr[min_index]);
    }
}
