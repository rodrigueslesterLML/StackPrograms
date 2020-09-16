/*     Stack ADT Of books using Array*/
#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#define size 5
typedef struct
{
 char name[50];
 int pages;
 float price;
 }book;

 book stack[size];/*Declaration of Stack Array to store Books*/
 int top=-1;


 book getbookdetails();/*Use: Input  Details of a new book and return it */
 void push(book b);/*Use: Add a book b to the top of the stack*/
 book *pop();/* Function's Work:Remove the book at the top of the stack */
 void peep();/* Function's Work:  Show the book at the top of the stack
	      */
 void display();/* Function's Work: Display Stack Contents */
 void show(book b);/* Function's Work: Display Details of the book b*/

 void  main()
 {
 int choice;
 book b;
 book *bp;

 clrscr();

 while(1)
 {
 printf("\nMenu Options:  1.Push 2.Pop 3.Peek 4.Display 5.exit\n");/* Peek meaning Peep */
 printf("Enter your choice: ");
 scanf("%d",&choice);

 switch(choice)
 {
 case  1:
	    if (top==size-1)
	    {
	    printf("\n Stack is full\n");
	    }
	    else{
	    printf("Enter the details: \n");
	    b= getbookdetails();
	    push(b);
	    }
	    break;
  case 2: bp=pop();
	  if(bp!= NULL)
	  {
	   printf("\n Book Removed Is:");
	   show(*bp);

	  }
	  break;
  case 3: peep();
	  break;
  case 4:display();
	 break;
 case 5: return;
 default:printf("Please Refer the Menu and enter correct choice");
 }
}
}
 void push(book b)
 {
 if (top==size-1)
 printf("\n Stack is full !!!\n");
 else{  top++;
       stack[top]=b;
       }

}

  book getbookdetails( )
{
   book b;
   float x;
   printf("Enter book's name: ");
   flushall();
   gets(b.name);
   printf("Enter no of pages: ");
   scanf("%d",&b.pages);
   printf("Enter the price: ");
   scanf("%f",&x);
   b.price=x;
   return b;
  }
 void show (book b)
  {
    printf("\nName=%s\nPages=%d\nPrice=%f\n",b.name,b.pages,b.price);


 }


book * pop()
{
  if(top==-1)
  {
  printf("\n Stack is Empty!!\n");
  return NULL;
  }
  else
  {
    top--;
    return(&stack[top+1]);
  }
     return;
  }

void peep()
{
  int val;
  if (top==-1)
  {printf("\n Stack is Empty!!\n");
  }
  else
  {
    printf("\n Book At the top of the stack is:\n");
    show( stack[top]);

  }
}
void display()
{  int i;
if (top==-1)
{ printf("\n Stack is Empty !!!\n");
}
else
{  printf("\n Stack Contents are:\n");
for(i=top;i>=0;i--)
{ printf(" Book at position: %d",i);
  show (stack[i]);
  }
  }
  }
