#include<stdio.h>
#include<conio.h>
#include<ctype.h>
#define MAX 100
//initialize the stack as empty with top as -1
float st[MAX];
int top=-1;

//function prototypes
void push(float st[],float val);
float pop(float st[]);
float evaluatePostfixExp(char exp[]);

void  main()
{
 float val;
 char exp[100];
clrscr();
 //Accepting input
 printf("Enter Any Postfix Expression:");
 gets(exp);
 //accepting output in val
 val=evaluatePostfixExp(exp);
 printf("\n Value =%.2f",val);
 getch();
 }


//Function definition :

 float evaluatePostfixExp(char exp[])
 {
    int i=0;
    float op1,op2,value;
    while(exp[i]!='\0')
    { //1. If an opernad is encountered then push it on the stack
      if(isdigit(exp[i]))
      {
      push(st,(float)(exp[i]-'0'));
       }
      else
      { //pop the top 2 elements if operator is encountered
       op2=pop(st);
       op1=pop(st);
       switch(exp[i])
	{
	case '+':value=op1+op2;
	       break;
	case '-':value=op1-op2;
	       break;
	case '/':value=op1/op2;
	       break;
	case '*':value=op1*op2;
	       break;
	case '%':value=(int)op1%(int)op2;
	       break;
	}
    push(st,value);//push obtained value in stack
      }
 i++;
 }
 return(pop(st));//result is in top element of stack
 }


void push(float st[], float val)
{
if(top==MAX-1)
printf("\n STACK OVERFLOW");
else
{
top++;
st[top]=val;// to assign here val we pass stack also in the params
}
}

//Function Definition For pop
float pop(float st[])
{
float val=-1;
if(top==-1)
printf("\n STACK UNDERFLOW");
else
{
val=st[top];
top--;
}
return val;
}
