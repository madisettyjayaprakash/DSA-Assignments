#include<stdio.h>
int n,top;
int check (float x)
{
int k;
k=x;
if(k==x)
return 0;
else
return 1;
}


void push(int *stk,int x)
{
if(top==n-1)
printf("Overflow\n");
else
{
top=top+1;
stk[top]=x;
}
}

void pop(int *stk)
{
if(top==-1)
printf("Empty\n");
else
{
printf("%d\n",stk[top]);
top=top-1;
}}

void print_stack(int *stk)
{
if(top==-1)
printf("Empty\n");
else
{
int i;
for(i=top;i>=0;i--){
printf("%d ",stk[i]);}
printf("\n");
}}
int main()
{
int element,stk[1200],j,i;
float w;
char ch;
top=-1;
scanf("%f",&w);
j=check(w);
n=w;
if(j==1||n<=0||n>2147483648)
{
printf("Invalid Input\n"); return 0;}
scanf("%c",&ch);
do
{
scanf("%c",&ch);
switch(ch)
{
case 'a':{getchar();
          scanf("%f",&w);
          j=check(w);
          element=w;
          if(j==1||element<0||element>2147483648)
          {
          printf("Invalid Input\n");
          return 0;}
          push(stk,element);
          break;}
case 'r':{ pop(stk);
          break;}
case 'p':{ print_stack(stk);
          break;}
case 's':{return 0;}
default: {printf("Invalid option\n");
          break;}
}
scanf("%c",&ch);
}
while(ch!='s');
return 0;
}        
