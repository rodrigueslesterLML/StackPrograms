#include<stdio.h>
#include<stdlib.h>
#include<conio.h>
//structure to define a node:
typedef struct node
{
    int data;
    struct node *next;
}node;

void display(node *);//Function's Use: To Display the  stack
node *push(node *);  //Function's Use: To Push an element into the top of the stack
node *pop(node *);   //Function's Use: To Pop an element from the top of the stack
void peep(node *);   //Function's Use: To Peep into the stack and return the top element  of the stack

int main()
{
  int i;
  struct node *top=NULL;
  int ch;
  clrscr();
  while(1)
  {
       printf("\nMenu: 1.Push 2.Pop 3.Peep 4.Display 5.Exit");
       printf("\nEnter your choice:");
       scanf("%d",&ch);
       switch(ch)
       {
	  case 1:top=push(top);
		 break;
	  case 2:top=pop(top);
		 break;
	  case 3:peep(top);
		 break;
	  case 4:display(top);
		 break;
	  case 5:exit(0);

	  default:printf("You have entered wrong choice");
       }
  }
  getch();
}
//Function definiton for displaying stack
void display(node *top)
{
    node *ptr;
    ptr=top;
    if(ptr==NULL)
    {
	printf("Stack is Empty");
	return;
    }
    else
    {
       printf("\nElements of the stack are:\n");
       while(ptr!=NULL)
       {
	 printf("%d ",ptr->data);
	 ptr=ptr->next;
       }
    }
}
// Function Definition for pushing an element into the top of the stack
node *push(node *top)
{
   node *newnode=malloc(sizeof(node));
   printf("Enter data to be pushed into the stack:");
   scanf("%d",&newnode->data);
   newnode->next=top;
   top=newnode;
   return top;
}
// Function Definition for poping the top element from the stack
node *pop(node *top)
{
   node *ptr;
   if(top==NULL)
       {
       printf("Stack is empty!! Cant delete");
       }
   else
   {
      ptr=top;
      top=top->next;
      printf("Element popped is=%d",ptr->data);
      free(ptr);
   }
   return top;
}

// Function Definition for peeping  into the stack
void peep(node *top)
{
  if(top==NULL)
      {
      printf("Stack Is Empty !!");
      }
  else
  {
     printf("Element at top is=%d",top->data);
  }
}
