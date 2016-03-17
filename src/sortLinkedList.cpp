/*
OVERVIEW: Given an unsorted single linked list, sort the linked list without using extra array or linked list.
E.g.: 4->2->1->5->3, output is 1->2->3->4->5.

INPUTS: An unsorted single linked list.

OUTPUT: Sort the linked list.

ERROR CASES: Return NULL for error cases.

NOTES: Without using extra array or linked list.
*/

#include <stdio.h>

struct node {
	int num;
	struct node *next;
};
/*
struct node * lastNode(struct node *current){
	while (current != NULL && current->next != NULL)
		current = current->next;
	return current;
}

struct node *partition(struct node *head, struct node *end, struct node **newHead, struct node **newEnd){
	struct node *pivot = end, *prev = NULL, *cur = head, *tail = pivot, *tmp = NULL;
	while (cur != pivot){
		if (cur->next<pivot->next){
			if ((*newHead) == NULL)
				*newHead = cur;
			prev = cur;
			cur = cur->next;
		}
		else{
			if (prev)
				prev->next = cur->next;
			tmp = cur->next;
			cur->next = NULL;
			tail->next = cur;
			tail = cur;
			cur = tmp;
		}
	}
	if (*newHead == NULL)
		(*newHead) = pivot;
	(*newEnd) = tail;
	return pivot;
}

struct node *quickSortRecur(struct node *head, struct node *end){
	struct node *newHead, *newEnd, *pivot, *tmp;
	if (!head || head == end)
		return head;
	newHead = NULL;
	newEnd = NULL;
	pivot = (struct node *) partition(head, end, &newHead, &newEnd);
	if (newHead != pivot){
		tmp = newHead;
		while (tmp->next != pivot)
			tmp = tmp->next;
		tmp->next = NULL;
		newHead = quickSortRecur(newHead, tmp);
		tmp = lastNode(newHead);
		tmp->next = pivot;
	}
	pivot->next = quickSortRecur(pivot->next, newEnd);
	return newHead;
}

void quickSort(struct node **headRef){
	*headRef = quickSortRecur(*headRef, lastNode(*headRef));
	return;
}
*/
struct node * sortLinkedList(struct node *head) {
	if (head==NULL || head->next==NULL)
		return head;
	struct node *iter,*iter1,*min;
	for (iter = head; iter != NULL; iter = iter->next){
		min = iter;
		for (iter1 = iter->next; iter1 != NULL; iter1 = iter1->next){
			if (iter1->num < min->num){
				min = iter1;
			}
		}
	}
	return head;
}