#include <stdio.h>
#include <stdlib.h>
#include <math.h>

/*
Reverse Linked List in groups
*/
struct Node
{
	int data;
	struct Node *next;
};
struct Node* insert(struct Node * head , int data) // insert at tail
{
	struct Node *new = (struct Node *)malloc(sizeof(struct Node));

	struct Node *head2 = head;

	new->data = data;
	new->next = NULL;

	if(head2 == NULL)	
		return new;
	while(head2->next != NULL) // upper condition important ..if head2 = NULL then
	{						// head2->next will result in segmentation fault;
		head2 = head2->next;
	}
	head2->next = new;
	return head;
}

void print(struct Node  *head)
{
	while(head != NULL) // not head->next != null..
	{
		printf("%d\n",head->data);
		head = head->next;
	}
}

struct Node *revK (struct Node *head, int k)
{
	struct Node * prev = (struct Node*)malloc(sizeof(struct Node));
	prev = NULL;
	struct Node * temp = (struct Node*)malloc(sizeof(struct Node));
	struct Node * head1 = (struct Node*)malloc(sizeof(struct Node));
	head1 = head;
	int t = 0;
	while(t < k && head1!= NULL)	// 1->2->2->4->5 6 7 8 ..head at 1
	{
		temp = head1->next;
		head1->next = prev;
		prev = head1;
		head1 = temp;
		t++;
	}						// 1<-2<-2<-4 5->6 7 8 head at 1
							// 5678 rev 8765 1->next = 5 
	if(head1 != NULL)
		head->next = revK(head1,k);

	return prev;

}
int main(int argc, char const *argv[])
{
	struct Node *head = NULL; //originally
	//struct Node *head =(struct Node *)malloc(sizeof(struct Node));
	
//1 2 2 4 5 6 7 8
	head = insert(head,1);
	head = insert(head,2);
	head = insert(head,2);
	head = insert(head,4);
	head = insert(head,5);
	head = insert(head,6);
	head = insert(head,7);
	head = insert(head,8);
	head = revK(head,4);
	print(head);

	return 0;
}