#include<stdio.h>
#include<stdlib.h>
#include<conio.h>
#define size 50
int stack[size];
int top=-1;
void pushstack(int val)
{
  if(top==size-1)
  {
  printf(" Stack is Full!!\n");
  }
 else  {
	   top++;
	   stack[top]=val;
       }
}

void popstack()
{
   int val;
   if (top==-1)
   {
    printf("Stack is Empty !!\n");
   }
   else
   {
    printf("Element at top=%d",stack[top]);
    top--;
    }
}
void peepstack()
{
   int val;
   if (top==-1)
   {
    printf("Stack is Empty !!\n");
   }
   else
   {
    printf("Element at top=%d",stack[top]);

    }

}

void display()
{
   int i;
   if(top==-1)
   {
    printf(" Stack is Empty !!\n");
   }
   else
   {
     printf("\n Stack Elements:\n " );
     for(i=top;i>=0;i--)
     {
     printf("%d\n",stack[i]);
     }
   }
}
void main ()
{
  int choice;int val;
  clrscr();
  while(1)
  {
    printf("\n 1.Push 2.Pop 3.Peep 4. Display 5.Exit\n  Enter your  choice :");
    scanf("%d",&choice);
    switch(choice)
    {    case 1: printf("Enter Value to be pushed");
		 scanf("%d",&val);
		 pushstack(val);
		 break;
	 case 2: popstack();
		 break;
	 case 3: peepstack();
		 break;
	 case 4: display();
		 break;
	 case 5: exit(0);
	 default:printf("Enter Valid Choice!!\n");
    }
  }

}
