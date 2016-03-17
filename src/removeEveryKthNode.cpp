/*
OVERVIEW: Given a single linked list, remove every Kth node in the linked list.
E.g.: 1->2->3->4->5 and K 2, output is 1->3->5.

INPUTS: A linked list and Value of K.

OUTPUT: Remove every Kth node in the linked list.

ERROR CASES: Return NULL for error cases.

NOTES:
*/

#include <stdio.h>

struct node {
	int num;
	struct node *next;
};

struct node * removeEveryKthNode(struct node *head, int K) {
	int save;
	struct node* iter = head,*iter2;
	if (iter == NULL || K<=1)	return NULL;
	while (iter != NULL){
		iter2 = iter->next;
		save = K;
		while (save-- > 2){
			iter2 = iter2->next;
			iter = iter->next;
			if (iter2 == NULL)
				break;
		}
		if (iter2 == NULL)
			break;
		iter->next = iter2->next;
		iter = iter->next;
	}
	return head;
}