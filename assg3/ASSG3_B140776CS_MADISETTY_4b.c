#include<stdio.h>
#include<stdlib.h>
struct node{
int data;
struct node*next;
};
struct stack{
struct node*top;
};
int check (float x)
{
int k;
k=x;
if(k==x)
return 0;
else
return 1;
}
void start(struct stack *stk)
{
stk->top=NULL;
}
void push(struct stack *stk,int x)
{
 struct node*temp;
 temp=(struct node*)malloc(sizeof(struct node));
 temp->data=x;
 if(stk->top==NULL)
 {
  stk->top=temp;
  temp->next=NULL;
 }
 else
 {
 temp->next=stk->top;
 stk->top=temp;
 }
}

void pop(struct stack*stk)
{
 struct node*temp;
 temp=stk->top;
 if(temp==NULL)
 printf("Empty\n");
 else
 {
 printf("%d\n",temp->data);
 temp=temp->next;
 stk->top=temp;
 }
}
void print_stack(struct stack *stk)
{
 struct node*temp;
temp=stk->top;
 if(temp==NULL)
 printf("Empty\n");
 else
 {
 while(temp!=NULL)
 {
 printf("%d ",temp->data);
 temp=temp->next;
 }
 printf("\n");}
}
int main()
{
struct stack *stk;
start(stk);
int element,j;
float w;
char ch;
do
{
scanf("%c",&ch);
switch(ch)
{
case 'a':{scanf("%f",&w);
           j=check(w);
           element=w;
           if(j==1||element<0||element>2147483648)
           {
           printf("Invalid Input\n");
           return 0;
           }
          push(stk,element);
          break;}
case 'r':{pop(stk);
          break;}
case 'p':{print_stack(stk);
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


