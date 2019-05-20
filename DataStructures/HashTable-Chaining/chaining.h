// DATA STRUCTURE
struct Node{
	int data;
	struct Node *next;
};

// PROTOTYPES
int Search_ll(struct Node *p, int key);
void Insert_ordered(struct Node **head, int key);
int Hash_modulo10 (int key);
int Search_chaining(struct Node **p, int key);
void Insert_hashtable (struct Node **H, int key);


