#include <stdlib.h>
#include <stdio.h>

struct node {
	int value;
	struct node* next;
	struct node* prev;
};

typedef struct node node_t;

void printList(node_t* startIndex, int numOfRead) {
	node_t* temp = startIndex;
	for (int i = 0; i < numOfRead; i++)
	{
		printf("%d\t: %d\n", i ,temp->value);
		temp = temp->next;
	}
}

node_t* init_node(int value) {
	node_t* result = malloc(sizeof(node_t));
	result->value = value;
	result->next = result;
	result->prev = result;
	return result;
}

void create_new_node(int value, node_t *tail) {
	node_t* result = malloc(sizeof(node_t));
	result -> value = value;
	result->next = tail->next;
	tail->next = result;
	result->prev = tail;
}

int main() {
	node_t *circularBuffer;

	circularBuffer =init_node(10);
	create_new_node(11, circularBuffer);
	create_new_node(12, circularBuffer);
	
	printList(circularBuffer,10);

	return 0;
}