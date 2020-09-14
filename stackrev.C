/* Reverse an Array using Stack */
#include<stdio.h>
#include<conio.h>
#define MAX 10
//initializing stack and its size
int stack[MAX];
int top=-1;
//Function definition for pop
int pop()
{
  return (stack[top--]);
 // We check for Underflow condition when our pop attempts are more than the elements
 //here pop attempts are equal to the number of elements
 //therefore non need to check underflow condititon
  }
//Function Definition for push
void push(int val)
{//Here We dont need to check for overflow condition since the for loop in the main pushes elements = the size of the array only
{  stack[++top]=val;}
}
void main()
{
  int val,n,i;
  int arr[100];
  clrscr();

  printf("Enter the number of elemnets in the array:");
  scanf("%d",&n);

  printf("Enter the elements in the array:");
  for(i=0;i<n;i++)
  {
   scanf("%d",&arr[i]);
  }

   for(i=0;i<n;i++)
  {
   push(arr[i]);//pushing eleements in the stack in the seq entered by the user
  }
for(i=0;i<n;i++)
{
  val=pop();//popping the top element
  arr[i]=val;//inserting the top elment in the start of the array
}
printf("\n the reversed array is :");
for(i=0;i<n;i++)
{printf("\n %d",arr[i]); //output
}
 getch();
 }
