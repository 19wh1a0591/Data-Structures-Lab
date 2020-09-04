#include<stdio.h>
#include<stdlib.h>
struct node
{
	int data;
	struct node * link;
};
struct node* head=NULL,*tail=NULL,*cur,*prev,*next;
void create()
{
	int n,i;
	scanf("%d",&n);
	for(i=1;i<=n;i++)
	{
		cur = (struct node*)malloc(sizeof(struct node));
		scanf("%d",&(cur->data));
		cur -> link = NULL;
		if(head == NULL)
			head = tail = cur;
		else
		{
			tail -> link = cur;
			tail = cur;
		}
	}
}	

void insert_at_begin()
{
	cur = (struct node*)malloc(sizeof(struct node));
	scanf("%d",(&cur->data));
	cur->link = head;
	head = cur;
}
void insert_at_pos()
{
	int pos,c=1;
	cur = (struct node*)malloc(sizeof(struct node));
	scanf("%d",&(cur->data));
	scanf("%d",&pos);
	next = head;
	while(c<pos)
	{
		prev = next;
		next = next->link;
		c++;
	}
	prev->link = cur;
	cur->link = next;
}
void insert_at_end()
{
	cur = (struct node*)malloc(sizeof(struct node));
	scanf("%d",&(cur->data));
	cur->link = NULL;
	tail->link = cur;
	tail = cur;
}
void insert_before_pos()
{
	int value;
	cur = (struct node*)malloc(sizeof(struct node));
	scanf("%d",&(cur->data));
	printf("Enter before which node we need to perform insertion\n");
	scanf("%d",&value);
	next = head;
	while(next->data != value && next != NULL)
	{
		prev = next;
		next = next ->link;
	}
	prev -> link = cur;
	cur -> link = next;
}
void insert_after_pos()
{
	int value;
	cur = (struct node*)malloc(sizeof(struct node));
	scanf("%d",&(cur->data));
	printf("Enter after which node we need to perform insertion\n");
	scanf("%d",&value);
	next = head;
	while(next->data != value && next != value)
	{
		next = next->link;
	}
	cur->link = next->link;
	next->link = cur;
}
void delete_at_begin()
{
	cur = head;
	head = cur->link;
	cur->link= NULL;
	printf("Deleted elementis %d\n",cur->data);
	free (cur);
}
void delete_at_end()
{
	cur = head;
	while(cur->link != tail)
	{
		cur = cur->link;
	}
	cur ->link = NULL;
	next = tail;
	printf("deleted element is %d",next->data);
	free(next);
	tail = cur;
}
void delete_at_pos()
{
	int pos,c=1;
	printf("Enter position of deletion");
	scanf("%d",&pos);
	while(c<pos)
	{
		prev = next;
		next = next->link;
		c++;
	}
	prev->link = next->link;
	printf("deleted element is at %d ",next->data);
	next->link = NULL;
	free(next);
}
void delete_before_node()	
{
	int value;
	printf("Enter before which node we need to delete");
	scanf("%d",&value);
	next = head;
	while(next->link->data!=value)
	{
		prev = next;
		next = next->link;
	}
	prev->link = next->link;
	printf("deleted element is at %d ",next->data);
	next->link = NULL;
	free(next);
}
void delete_after_node()	
{
	int value;
	printf("Enter after which node we need to delete");
	scanf("%d",&value);
	next = head;
	while(next->data!=value)
	{
		prev = next;
		next = next->link;
	}
	prev = next->link;
	next->link = prev->link ;
	printf("deleted element is at %d ",prev->data);
	prev->link = NULL;
	free(prev);
}
void traversal()
{
	if(head == NULL)
		printf("list is empty");
	else
	{
		next = head;
		while(next!=NULL)
		{
			printf("%d->",next->data);
			next = next->link;
		}
	}
}
void reverse(struct node* head)
{
	if(head!=NULL)
	{
		reverse(head->link);
		printf("%d->",head->data);
	}
}
void search()
{
	int value,flag = 0,c=0;
	scanf("%d",&value);
	next = head;
	if(head == NULL)
	{
		printf("List is empty\n");
	}
	else
	{
		while(next != NULL)
		{
			if(next->data == value)
			{
				flag = 1;
				break;
			}
			next = next->link;
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
	struct node *p1,*p2,*t;
	p1=head;
	int i,c=0;
	while(p1!=NULL)
	{
		c++;
		p1=p1->link;
	}
	for(i=0;i<c;i++)
	{
		p2 = head;
		while(p2->link != NULL)
		{
			if(p2->data > p2->link->data)
			{
				t = p2->data;
				p2->data = p2->link->data;
				p2->link->data=t;
			}
			p2 = p2->link;
		}
	}
}

int main()
{
	int ch;
	while(1)
	{
		printf("program for single linked list\n");
		printf("1-create\n2-insert at begin\n3-insert at pos\n4-insert at end\n5-insert before pos\n");
		printf("6-insert after pos\n7-delete at begin\n8-delete at end\n9-delete at pos\n10-delete before node\n");
		printf("11-delete after node\n12-traversal\n13-reverse\n14-search\n15-sorting\n");
		printf("Enter your choice");
		scanf("%d",&ch);
		switch(ch)
		{
			case 1: create();
				break;
			case 2: insert_at_begin();
				break;
			case 3: insert_at_pos();
				break;
			case 4: insert_at_end();
				break;
			case 5: insert_before_pos();
				break;
			case 6: insert_after_pos();
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
			case 12: traversal();
				break;
			case 13: reverse(head);
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