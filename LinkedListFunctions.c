#include <stdio.h>
#include <stdlib.h>

struct Node
{
	int data;
	struct Node *next;
};
struct Node* insertTail(struct Node * head , int data) // insert at tail
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
struct Node * insertHead(struct Node* head, int data)
{
	struct Node * new = (struct Node *)malloc(sizeof(struct Node));
	new->next = head;
	new->data = data;
	return new;
}
struct Node * insertPosition(struct Node * head, int position, int data)
{
	struct Node * new = (struct Node *)malloc(sizeof(struct Node));
	new -> data = data;

	if(head == NULL)
		return new;
	else if(position == 0)
		return insertHead(head,0);

	struct Node * head2 = head;
	position --;
	while(--position > 0) // not position--
	{
		head = head->next;
	}

	struct Node * temp = head -> next;
	head->next = new;
	new->next = temp;
	return head2;
}
struct Node * deletePosition(struct Node * head , int position)
{
	if(head == NULL)
		return head;
	if(position == 0)
	{
		head = head->next;
		return head;
	}

	struct Node * head2 = (struct Node*)malloc(sizeof(struct Node));
	while(--position > 0)
	{
		head = head->next;
	}
	head->next = (head->next)->next;
	return head2;
}

struct Node * reverse(struct Node * head)
{
   if(head == NULL || head->next == NULL) // if 0 or 1 element..or in end
       return head;

   struct Node* newHead = reverse(head->next); 

   head->next->next = head; 

   head->next = NULL; 

   return newHead; 

}
struct Node * rev(struct Node * head)
{
	if(head == NULL || head->next == NULL)
		return head;
	struct Node * old = NULL; // previous of head
	struct Node * temp = NULL; // just temp
	
	while(head->next != NULL) // 2 pointers 1 at head and one before head
	{							// one temp
		temp = head->next;		// store value of next node after head in temp	
		head->next = old;		//reverse the linking of head
		old = head;				// previous pointer moves forward
		head = temp;			// head moves forward
	}
	head->next = old;
	return head;
} 
void sort(struct Node * head) // Selection Sort kind of..
{ 	// compare 1st value to all the values..step by step replace by that
	// value which is greater than 1st one

	// in Selection sort..we find min value and replace that with ith value

	// so its worse than even Selection Sort..LOL ;) O(n^2) , w(n^2) , 8(n^2)			
	struct Node * head2 = (struct Node *)malloc(sizeof(struct Node));
	int temp;
	for(;head->next!=NULL ; head = head->next)
	{
		for(head2 = head->next;head2!=NULL;head2 = head2->next)
		{
			if(head->data > head2->data)
			{
				temp = head->data;
				head->data = head2->data;
				head2->data = temp;
			}
		}
	}
}
void print(struct Node  *head)
{
	while(head != NULL) // not head->next != null..
	{
		printf("%d\n",head->data);
		head = head->next;
	}
}
int main(int argc, char const *argv[])
{
	struct Node *head = NULL; //originally
	//struct Node *head =(struct Node *)malloc(sizeof(struct Node));
	//head->data = 55;
	int i = 2;
	for(;i < 6 ; i++)
	{
		if(i != 3)
			head = insertTail(head,i);
	}
	i = 0;
	head = insertHead(head,1);
	head = insertPosition(head,3,3);
	head = insertPosition(head,0,0);
	head = insertTail(head,6);
	print(head);
	//deletePosition(head,4);  do later...errors in deleting 0th and last element
	//deletePosition(head,0);
	printf(" ******************************************\n");
	
	//head = reverse(head);
	//print(head);
	//sort(head);

	head = rev(head);
	print(head);

	return 0;
}