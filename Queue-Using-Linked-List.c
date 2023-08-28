#include<stdio.h>
#include<stdlib.h>

struct Node {
	int data;
	struct Node* next;
	struct Node* front;
	struct Node* rear;
};

struct Node* head = NULL;
struct Node* front = NULL;
struct Node* rear = NULL;

void enQueue(int data)
{
	struct Node*  newNode = (struct Node*) malloc (sizeof(struct Node));
	
	if(newNode == NULL)
	{
		printf("Memory not allocated\n");
		return;
	}
	
	newNode->data = data;
	if(front==NULL && rear==NULL)
	{
		newNode->next = NULL;
		front = newNode;
		rear = newNode;
	}
	else
	{
		rear->next = newNode;
		rear = newNode;
		rear->next = NULL;
	}
	
	printf("Element Inserted\n");
	
}

void deQueue()
{
	struct Node* temp = front;
	
	if(front==NULL)
	{
		printf("Queue is empty\n");
		return;
	}
	
	int popped = temp->data;
	
	front = front->next;
	free(temp);
	
	printf("Element popped\n");
}
void display()
{
	struct Node* temp = front;
	if(front==NULL)
	{
		printf("Queue is empty\n");
		return;
	}
	
	while(temp!=NULL)
	{
		printf("%d ", temp->data);
		temp = temp->next;
	}
	printf("\n");
	
}
int main()
{
	
	int choice, data;
	while(1)
	{
		printf("--------------QUEUE USING LINKED LIST MENU--------------\n");
		printf("1. ENQUEUE\n");
		printf("2. DEQUEUE\n");
		printf("3. DISPLAY\n");
		printf("4. EXIT\n");
		printf("-----------------------------------------------\n");
		printf("Enter your choice: ");
		scanf("%d", &choice);
		
		switch(choice)
		{
			case 1:
				printf("Enter the data: ");
				scanf("%d", &data);
				enQueue(data);
				break;
				
			case 2:
				deQueue();
				break;
				
			case 3:
				display();
				break;
			
			case 4:
				exit(0);
				
			default:
				printf("Invalid Choice\n");
		}
	}
}
