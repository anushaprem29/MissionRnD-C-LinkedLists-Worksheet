/*
OVERVIEW:  Given a single linked list of 0s 1s and 2s ,Sort the SLL such that zeroes 
will be followed by ones and then twos.


INPUTS:  SLL head pointer

OUTPUT: Sorted SLL ,Head should Finally point to an sll of sorted 0,1,2


ERROR CASES:

NOTES: Only 0,1,2, will be in sll nodes
*/

#include <stdio.h>
#include <malloc.h>

struct node {
	int data;
	struct node *next;
};

//Insert values into list.
void push(struct node * head,int value){
	struct node *newNode, *iter;

	iter = head;
	newNode = (struct node *)malloc(sizeof(struct node));
	newNode->next = NULL;
	newNode->data = value;
	if (head == NULL)
		head = newNode;
	else{
		while (iter->next != NULL){
			iter = iter->next;
		}
		iter->next = newNode;
	}
}

//Function to sort the linked list into 0,1 and 2
void sort012(struct node *head){
	struct node *iter = head;
	int value[3] = { 0, 0, 0 }, count = 0;
	if (iter == NULL)	return;
	while (iter != NULL){
		value[iter->data]++;
		iter = iter->next;
	}
	if (head != NULL){
		while (count < 3){
			if (value[count]){
				head->data = count;
				head->next = NULL;
				value[count]--;
				break;
			}
			count++;
		}
	}
	//head = NULL;
	count = 0;
	while (count<3){
		while (value[count]--)
			push(head,count);
		count++;
	}
}
void sll_012_sort(struct node *head){
	sort012(head);
}