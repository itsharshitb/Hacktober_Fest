//Simple Stack Implementation using Singly-Linked Lists made in C

#include <stdio.h>
#include <stdlib.h>

//structure of node
struct node{
	int data;
	struct node* next;
};

//Initializing the node 'top'
struct node* top = NULL;


//Subroutines for push,pop and display operations
void push(int);
void pop();
void display();

int main(){
	//A while loop for displaying stack operations to choose from
	while(1){
		printf("\n");
		printf("1. Push\n");
		printf("2. Pop\n");
		printf("3. Display\n");
		printf("4. Exit\n");
		printf("Enter your choice: ");
		int ch;
		scanf("%d",&ch);

		switch(ch){
			case 1:{
				printf("Enter element: ");
				int num;
				scanf("%d",&num);
				push(num);
				break;
			}
			case 2:{
				pop();
				break;
			}
			case 3: display();
			break;
			case 4: exit(0);
		}
	}

}

//Definitions of subroutines
void push(int n){
	struct node* p = (struct node*)malloc(sizeof(struct node));
	p->data = n;
	if(top==NULL){
		top = p;
		p->next=NULL;
	}
	else{
	p->next = top;
	top = p;
	}
}

void pop(){
	if(top==NULL){
		printf("Stack underflow. Can't pop elements.\n");
		return;
	}
	//instead of returning popped element as int, it is displayed via a print statment
	printf("\nPopped element: %d\n",top->data);
	struct node* temp = top;
	top = top->next;
	free(temp);
}

void display(){
	if(top==NULL){
		printf("Stack underflow.\n");
		return;
	}
	struct node* temp = top;
	while(temp!=NULL){
		printf("%d ---> ",temp->data);
		temp = temp->next;
	}
}