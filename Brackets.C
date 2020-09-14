#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#define MAX 10
int top=-1;//top of the stack as -1 when empty
int stack[MAX]; //stack of size 10 initialized globally
//Function Definition for push
void push (char c)
{
  if(top==(MAX-1))//if stack full top ==size-1
  printf("Stack OVERFLOW");
  else
  {   top=top+1; //else increment top and fill
      stack[top]=c;
      }
 }
 char pop()
 {
 if(top==-1)
 {
  printf("Stack Underflow");//if top==-1 stack is empty
  return(0);
 }
 else {
 return(stack[top--]);//else we return top and decrement it
 }
 }
void main()
{
  char exp[MAX],temp;
  int i,flag=1;//assuming a expression without brackets is well formed therefore flag=1
  clrscr();
  printf("Enter a Expression:");
  gets(exp);
  for(i=0;i<strlen(exp);i++)//for loop traversing the expression
  {

    if(exp[i]=='('||exp[i]=='{'||exp[i]=='[')//left bracket is pushed into the stack
    {
      push(exp[i]);
    }
    if(exp[i]==')'||exp[i]=='}'||exp[i]==']')//if right bracket is encounterd
    {  if(top==-1)// left bracket not encountered i.e stack is empty therefore not well formed
	flag=0;
       else
       {
	 temp=pop();
	 if(exp[i]==')'&&(temp=='{'||temp=='[')) //not matching

	  flag=0;

	 if(exp[i]=='}'&&(temp=='('||temp=='[') )//not matching

	  flag=0;

	  if(exp[i]==']'&&(temp=='('||temp=='{'))//not matching

	  flag=0;

       }
 }
} if (top>=0)//stack contains something
 {
   flag=0;
 }
 if(flag==1)
 {
 printf("Well Formed");
 }
 else {
 printf("not well formed Expresiion");
 }

 getch();
 }
