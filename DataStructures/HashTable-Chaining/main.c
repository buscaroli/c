/* HASH TABLES
 * IMPLEMENTATION OF OPEN ADDRESSING : CHAINING
 *
 * The chained keys are kept ordered to speed up the search of
 * the elements, as usually hash tables are used when the main
 * focus is search speed
 *
 * Matteo Buscaroli
 *
 * TODO : IMPPLEMENTNG A DISPLAY FUNCTIONS
 *        MAYBE A DELETE FUNCTION
 */

#include <stdio.h>
#include <stdlib.h>
#include "chaining.h"

// MAIN

int main()
{
    struct Node *HT[10];


    // Initializing all nodes of the hash table to NULL
    // to be able to recognise unused nodes
    for (int i = 0; i < 10; i++){
        HT[i] = NULL;
    }

    Insert_hashtable(HT, 6);
    Insert_hashtable(HT, 15);
    Insert_hashtable(HT, 25);
    Insert_hashtable(HT, 35);
    Insert_hashtable(HT, 14);

    return 0;
}
