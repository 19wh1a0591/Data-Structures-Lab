#include<stdio.h>
#include<stdlib.h>
struct node
{
	float data;
	struct node *prev;
	struct node *next;
};
struct node *head = NULL,*tail=NULL,*cur,*t1,*t2;
void create()
{
	int n,i;
	scanf("%d",&n);
	for(i=1;i<=n;i++)
	{
		cur = (struct node*)malloc(sizeof(struct node));
		printf("Enter data");
		scanf("%f",&(cur->data));
		cur -> prev = NULL;
		cur->next = NULL;
		if(head == NULL)
			head = tail = cur;
		else
		{
			tail -> next = cur;
			cur -> prev = tail;
			tail = cur;
		}
	}
}
void insert_at_begin()
{
	cur = (struct node*)malloc(sizeof(struct node));
	scanf("%f",(&cur->data));
	cur->prev = NULL;
	cur->next = head;
	head->prev = cur;
	head = cur;
}
void insert_at_end()
{
	cur = (struct node*)malloc(sizeof(struct node));
	scanf("%f",(&cur->data));
	cur->next = NULL;
	cur->prev = tail;
	tail->next = cur;
	tail = cur;
}
void insert_at_pos()
{
	int pos,c=1;
	cur = (struct node*)malloc(sizeof(struct node));
	printf("Enter the current node data\n");
	scanf("%f",&(cur->data));
	printf("Enter the pos where the data is to be inserted\n");
	scanf("%d",&pos);
	t1 = head;
	while(c<pos && t1 != NULL)
	{
		t2 = t1;
		t1 = t1->next;
		c++;
	}
	t2 -> next = cur;
	cur -> prev = t2;
	cur -> next = t1;
	t1 -> prev = cur;
}
void insert_before_node()
{
	float value;
	cur = (struct node*)malloc(sizeof(struct node));
	printf("Enter the current node data\n");
	scanf("%f",&(cur->data));
	printf("Enter the node before which data is to be inserted\n");
	scanf("%f",&value);
	t1 = head;
	while(t1->data != value && t1 != NULL)
	{
		t2 = t1;
		t1 = t1->next;
	}
	t2 -> next = cur;
	cur -> prev = t2;
	cur -> next = t1;
	t1 -> prev = cur;
}
void insert_after_node()
{
	float value;
	cur = (struct node*)malloc(sizeof(struct node));
	printf("Enter the current node data\n");
	scanf("%f",&(cur->data));
	printf("Enter the node after which data is to be inserted\n");
	scanf("%f",&value);
	t1 = head;
	while(t1->data != value && t1 != NULL)
	{
		t1 = t1->next;
	}
	cur -> next = t1 -> next;
	t1 -> next -> prev = cur;
	t1 -> next = cur;
	cur -> prev = t1;
}
void delete_at_begin()
{
	cur = head;
	head = head -> next;
	head -> prev = NULL;
	cur->next= NULL;
	printf("Deleted elementis %f\n",cur->data);
	free (cur);
}
void delete_at_end()
{
	cur = tail;
	tail = tail -> prev;
	tail-> next = NULL;
	cur->prev= NULL;
	printf("Deleted elementis %f\n",cur->data);
	free (cur);
}
void delete_at_pos()
{
	int pos,c=1;
	printf("Enter position of deletion");
	scanf("%d",&pos);
	t1 = head;
	while(c<pos && t1 != NULL)
	{
		t2 = t1;
		t1 = t1 ->next;
		c++;
	}
	t2->next = t1 -> next;
	t1 -> next -> prev = t2;
	printf("deleted element is %f ",t1->data);
	free(t1);
}
void delete_before_node()
{
	float value;
	printf("Enter before which node the data is to be deleted");
	scanf("%f",&value);
	while(t1->next->data != value && t1->next != NULL)
	{
		t2 = t1;
		t1 = t1 ->next;
	}
	t2->next = t1 -> next;
	t1 -> next -> prev = t2;
	printf("deleted element is %f\n",t1->data);
	t1->prev = t1->next = NULL;
	free(t1);
}
void delete_after_node()
{
	float value;
	printf("Enter after which node the data is to be deleted");
	scanf("%f",&value);
	while(t1->data != value && t1 != NULL)
	{
		t1 = t1 ->next;
	}
	t2 = t1 -> next;
	t1->next = t2 -> next;
	t2 -> next -> prev = t1;
	printf("deleted element is %f\n",t2->data);
	t2->prev = t2->next = NULL;
	free(t2);
}
void Display()
{
	if(head == NULL)
		printf("Double linked list is empty");
	else
	{
		cur = head;
		while(cur!=NULL)
		{
			printf("%f<->",cur->data);
			cur = cur->next;
		}
	}
}
void Display_reverse()
{
	if(head == NULL)
		printf("Double linked list is empty");
	else
	{
		cur = tail;
		while(cur!=NULL)
		{
			printf("%f<->",cur->data);
			cur = cur->prev;
		}
	}
}
void search()
{
	int flag = 0;
	float value;
	scanf("%f",&value);
	int c = 1;
	t1 = head;
	if(t1 == NULL)
	{
		printf("List is empty\n");
	}
	else
	{
		while(t1 != NULL)
		{
			if(t1->data == value)
			{
				flag = 1;
				break;
			}
			t1 = t1->next;
			c++;
		}
		if(flag == 1)
		{
			printf("Element present in the list at %d position",c);
		}
		else
		{
			printf("Element not present in the list");
		}
	}
}
void sorting()
{
	struct node *p1,*p2,*last = NULL;
	p1=head;
	int i,c,t;
	p1 = head;
	while(p1->next!=NULL)
	{
		c++;
		p1=p1->next;
	}
	for(i=0;i<c;i++)
	{
		p2 = head;
		while(p2->next!=NULL)
		{
			if(p2->data > p2->next->data)
			{
				t = p2->data;
				p2->data = p2->next->data;
				p2->next->data=t;
			}
			p2 = p2->next;
		}
	}
}
int main()
{
	int ch;
	while(1)
	{
		printf("program for double linked list\n");
		printf("1-create\n2-insert at begin\n3-insert at end\n4-insert at pos\n5-insert before pos\n");
		printf("6-insert after pos\n7-delete at begin\n8-delete at end\n9-delete at pos\n10-delete before node\n");
		printf("11-delete after node\n12-Display\n13-Display reverse\n14-search\n15-sorting\n");
		printf("Enter your choice");
		scanf("%d",&ch);
		switch(ch)
		{
			case 1: create();
				break;
			case 2: insert_at_begin();
				break;
			case 3: insert_at_end();
				break;
			case 4: insert_at_pos();
				break;
			case 5: insert_before_node();
				break;
			case 6: insert_after_node();
				break;
			case 7: delete_at_begin();
				break;
			case 8: delete_at_end();
				break;
			case 9: delete_at_pos();
				break;
			case 10: delete_before_node();
				break;
			case 11: delete_after_node();
				break;
			case 12: Display();
				break;
			case 13: Display_reverse(head);
				break;
			case 14: search();
				break;
			case 15: sorting();
				break;
			case 16: exit (0);
				break;
		}	
	}
}
			