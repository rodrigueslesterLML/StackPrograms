#include <stdio.h>
#include <conio.h>
#include <ctype.h>
#include <string.h>
#define MAX 100
//initializing char stack
char st[MAX];
int top=-1;//stack empty currently
//function prototypes
void push(char st[], char);
char pop(char st[]);
void InfixtoPostfix(char source[], char target[]);
int getPriority(char);

void main()
{
char infix[100], postfix[100];
clrscr();
//inputing an infix exp in char infix[100]
printf("\n Enter any infix expression : ");
gets(infix);
strcpy(postfix,"");//making the postfix array empty
//passing both to this function
InfixtoPostfix(infix, postfix);//infix arrray contains the expression and postfix array is empty
printf("\n The corresponding postfix expression is : ");
puts(postfix);//displays answer
getch();

}


void InfixtoPostfix(char source[], char target[])
{
int i=0, j=0;
char temp;
strcpy(target, "");//here the postfix exp will be there

while(source[i]!='\0')//scan until the last infix exp's element
{

// Case: If a ( is encountered push it in the stack
if(source[i]=='(')
{
push(st, source[i]);
i++;// We would move to the next elemnent in the stack
}

// Case: If ) is encountered check:
else if(source[i] == ')')
{
//1.if stack is not empty and until ( is encountered in stack
while((top!=-1) && (st[top]!='(')) //
{

target[j] = pop(st);//we pop from the stack and add it to postfix exp
j++;// Move ahead in postfix exp
}
// if top is empty it means ) is the first element encountered which is not a correct exp form
if(top==-1)
{
printf("\n INCORRECT EXPRESSION");

exit(1);

}
temp = pop(st);//2.remove left parenthesis (discarded)
i++;// We move ahead in source array to discard left (
}
// Case:If opernad Digit or character encountred
else if(isdigit(source[i]) || isalpha(source[i]))
{

target[j] = source[i];// add to postfix exp
j++;// move ahead in target
i++;// move ahead in source
}

//Case:if operator encountred
else if (source[i] == '+' || source[i] == '^' || source[i] == '*' ||
source[i] == '/' || source[i] == '%')
{

//1st condition:top cant be -1 since u cant begin an exp with a operator
//2nd condition;until operator in stack has higher priority than the one in source add it to postfix exp
while( (top!=-1) && (st[top]!= '(') && (getPriority(st[top])
> getPriority(source[i])))
{

target[j] = pop(st);
j++;//move ahead in target

}
push(st, source[i]);//push the operator in the stack
i++; // move ahead in source
}
// if nothing possible then
else

{
printf("\n INCORRECT ELEMENT IN EXPRESSION");
exit(1);
}
}
//pop from stack and add to postfix exp
while((top!=-1) && (st[top]!='('))
{
target[j] = pop(st);
j++;
}
target[j]='\0';
}




//Function Definition for get priority
int getPriority(char op)
{
if(op=='/' || op == '*' || op=='%')
return 1;//Higher preccednece than +-
else if(op=='+' || op=='-')
return 0;

}

//Function definition for push
void push(char st[], char val)
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
char pop(char st[])
{
char val=' ';
if(top==-1)
printf("\n STACK UNDERFLOW");
else
{
val=st[top];
top--;
}
return val;
}
