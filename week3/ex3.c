//Indexes starts from 1
#include <stdio.h>
#include <stdlib.h>

struct node{
	int data;
	struct node * next;
};

struct node *head = NULL;

void printList(struct node *i){
	while(i != NULL){
		printf("%d ", i->data);
		i = i -> next;
	}
	printf("\n");
}

//insert value-val, after position-pos
void insert_node(struct node ** head, int pos, int val){
	struct node *nw = (struct node*) malloc(sizeof(struct node));;
	nw->data = val;

	if(pos == 0){
		nw->next = (*head);
		(*head) = nw;
		return ;
	}

	struct node *i = (*head);
	pos --;
	while(pos > 0 && i != NULL){
		pos--;
		i = i->next;
	}
	if(i == NULL){
		printf("out of list\n");
		return ;
	}

	nw->next = i->next;
	i->next = nw;
}

//delete element at position-pos
void delete_node(struct node ** head, int pos){

	if(pos == 1){
		(*head) = (*head)->next;
		return ;
	}

	struct node *i = (*head), *j;
	pos --;
	while(pos > 0 && i != NULL){
		pos--;
		j = i;
		i = i->next;
	}
	if(i == NULL){
		printf("out of list\n");
		return ;
	}

	j->next = i->next;
}

int main(){
	insert_node(&head, 0, 5);
	printList(head);
	insert_node(&head, 1, 4);
	printList(head);
	insert_node(&head, 2, 3);
	insert_node(&head, 3, 2);
	printList(head);
	delete_node(&head, 2);
	printList(head);
	delete_node(&head, 1);
	printList(head);
}