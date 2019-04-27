#include "functions.h"

/**********************************************************
 * FUNCTION: HEAP_HEAPSORT
 *
 * Sort a given array by using the heapsort algorithm.
 *
 *********************************************************/
void Heap_heapsort(struct heap *h){
    int temp = h->index; // keep the original size of the heap
    int *n; // pointer to the index of the heap
    n = &h->index;

    // Enforcing the Max heap structure on the array
    Heap_build_heap(h);

    for (int i = *n; i > 0; i--){
        // At every cycle we remove the root of the heap (Max
        // value) and move it at the back of the array.As the
        // root is the largest value, by moving it at the last
        // position of the array it is in the correct (sorted)
        // position.
        Heap_swap(h, 0, i);
        // Then we decrease the index of the array, so we only
        // consider the elements on the left side of the sorted
        // number(s), and call heapify.
        *n = *n - 1;
        Heap_heapify(h, 0);
        //Heap_print(h); // Debugging purposes (2 lines)
        //printf("Index is %d\n\n", *n);
    }
    // Set heap's index back to original value
    *n = temp;
}


/**********************************************************
 * FUNCTION: HEAP_INIT
 *
 * Initializes a heap by setting the index to -1;
 *
 *********************************************************/
void Heap_init(struct heap *h){
    h->index = -1;
}

/**********************************************************
 * FUNCTION: HEAP_HEAPIFY
 *
 * Appies the heap structure to as given node. Gives for
 * granted that the nodes below respect the heap structure.
 *
 *********************************************************/
void Heap_heapify(struct heap *h, int node){

    int max = node;
    // Set left and right children to -1 until validated
    int left = -1;
    int right = -1;

    // Checking if left and right children are valid nodes
    // (within the array's boundary)
    if (2*node + 1 <= h->index)
        left = 2*node + 1;
    if (2*node + 2 <= h->index)
        right = 2*node + 2;

    // If a child is not valid it takes the vlue of the
    // sibling
    // If neither the left nor the right child are valid
    // it returns
    if (left < 0 && right < 0)
        return;
    if (left < 0)
        left = right;
    if (right < 0)
        right = left;

    // Assign the maximum value:
    if (h->arr[left] > h->arr[node])
        max = left;
    if (h->arr[right] > h->arr[max])
        max = right;

    // If the parent node is not the maximum the two
    // are swapped and the function is called again
    // on the child node
    if (max != node){
        Heap_swap(h, node, max);
        Heap_heapify(h, max);
    }


}
///***********************************************************
// * FUNCTION: HEAP_MAX
// *
// * Given a heap and the indexes of three of its elements
// * returns the index associated with the largest value.
// *
// **********************************************************/
//int Heap_max(struct heap *h, int a, int b, int c){
//    int max, max_index, node, left, right;
//
//    node = h->arr[a];
//    left = h->arr[b];
//    right = h->arr[c];
//
//    max = node;
//    max_index = a;
//
//    // Case 1: the node has only one child (left)
//    if (c > h->index){
//        if (left > node){
//            max = left;
//            max_index = b;
//        }
//    }
//    // Case 2: The node has 2 children: left and right
//    else {
//        if (left > node){
//            max = left;
//            max_index = b;
//        }
//        if (right > max){
//            max = right;
//            max_index = c;
//        }
//    }
//    return max_index;
//
//}

/**********************************************************
 * FUNCTION: HEAP_SWAP
 *
 * Given a heap and two indexes swaps the two elements
 * associated with the indexes.
 *
 *********************************************************/
void Heap_swap (struct heap *h, int a, int b){

    int temp;
    temp = h->arr[a];
    //printf("a: %d, b: %d temp: %d\n", a, b, temp);
    h->arr[a] = h->arr[b];
    h->arr[b] = temp;
}

/**********************************************************
 * FUNCTION: BUILD_HEAP
 *
 * Forces the heap property on the given heap structure
 * converting the array to a max heap.
 *
 *********************************************************/
void Heap_build_heap(struct heap *h){
    int halfway_index = (h->index);
    for (int i = halfway_index/2; i >= 0; i--){
        Heap_heapify(h, i);
        //Heap_print(h); //For debugging purposes only
    }
}

/**********************************************************
 * FUNCTION: HEAP_PRINT
 *
 * Prints the elements of the heap as they are positioned
 * in the array.
 * Function's first parameter declared constant as the
 * function doesn't need to modify the heap.
 *
 *********************************************************/
void Heap_print(const struct heap *h){
    if (h->index == -1){
        printf("%s\n", "Heap is Empty, nothing to print");
    }
    else {
        for (int i = 0; i <= h->index; i++){
            printf("Array Index %3d: %3d\n", i, h->arr[i]);
        }
    }
}

/**********************************************************
 * FUNCTION: HEAP_CREATE_RANDOM
 *
 * Fills in all the elements of the heap's array with
 * random numbers up to 50.
 * utility function to test the Heap_build_heap function
 * in the main function.
 *
 *********************************************************/
void Heap_create_random(struct heap *h){
    srand(time(NULL));

    for (int i = 0; i < MAX_SIZE; i++){
        h->index++;
        h->arr[i] = rand() % 50;

    }
}

/**********************************************************
 * FUNCTION: HEAP_INSERT_TAIL
 *
 * It insert a given number at the tail of the current
 * heap.
 * It doesn't respect the heap property, it's a utility
 * function used for testing purposes only.
 *
 *********************************************************/
void Heap_insert_tail(struct heap *h, int value){
    if (h->index >= MAX_SIZE-1)
        printf("%s\n", "ERROR: FULL");
    else {
        h->index++;
        h->arr[h->index] = value;
        //printf("Index: %d, Value: %d\n", h->index, h->arr[h->index]);


    }
}

/**********************************************************
 * FUNCTION: HEAP_EXTRACT_MAX
 *
 * It removes and returns the maximum number of the heap.
 *
 * Output: Returns the largest number of the heap.
 *
 *********************************************************/
int Heap_extract_max( struct heap *h){
    // If heap is empty, print an error msg and exit
    // the function
    if (h->index == -1){
        printf("%s\n", "ERROR: Underflow");
        return EXIT_FAILURE; // there may be a  better way
    }

    int max = h->arr[0];

    h->arr[0] = h->arr[h->index];
    h->index--;
    Heap_heapify(h, 0);

    return max;
}

/**********************************************************
 * FUNCTION: HEAP_INSERT
 *
 * Inserts a given number in the current heap. Complies
 * with the heap property (max heap).
 *
 *********************************************************/
void Heap_insert (struct heap *h, int value){
    if (h->index >= MAX_SIZE-1)
        printf("%s\n", "ERROR: FULL");
    else {
        h->index++;
        int i = h->index;

        while (i > 0 && (h->arr[Heap_parent_node(i)] < value)){
            h->arr[i] = h->arr[Heap_parent_node(i)];
            i = Heap_parent_node(i);
        }
        h->arr[i] = value;
    }
}

/**********************************************************
 * FUNCTION: HEAP_PARENT_NODE
 *
 * Given a node index, it returns the index of its parent
 * node.
 * Utility function, used within Heap_insert.
 *
 * Output: Returns the index of the parent node.
 *
 *********************************************************/
int Heap_parent_node(int node){
    return (node-1)/2;
}

