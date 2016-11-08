#include<stdio.h>
#include<stdlib.h>
struct node{
int data;
struct node* next;
};
struct que{
struct node *qf,*qr;
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
void start(struct que *q)
{
q->qf=NULL;
q->qr=NULL;
}

void enqueue(struct que*q,int x)
{
struct node*temp,*temp1;
temp=(struct node*) malloc(sizeof(struct node));
    temp->data=x;
    temp->next=NULL;
if(q->qf==NULL)
  {
     q->qf=temp;
     q->qr=temp;
     return;
  }
  else
  {
  temp1=q->qr;
  temp1->next=temp;
  q->qr=temp;
  }
}
void dequeue(struct que*q)
{
struct node*temp;
if(q->qf==NULL)
{ 
  printf("Empty\n");
  return;
}
if(q->qf==q->qr)
{
  temp=q->qf;
  printf("%d\n",temp->data);
  q->qf=NULL;
  q->qr=NULL;
  free(temp);
}
else
 {
  temp=q->qf;
  q->qf=temp->next;
  printf("%d\n",temp->data);
  free(temp);
 }
 
} 
void print_queue(struct que*q)
{
  struct node*temp;
  if(q->qf==NULL)
  {
  printf("Empty\n");
  }
  else
  {
  temp=q->qf;
  while(temp!=NULL){
  printf("%d ",temp->data);
  temp=temp->next;
  }
  printf("\n");
  }
}


int main()
{
struct que *q;
start(q);
int element,i,j;
float w;
char c;
do
{
scanf("%c",&c);
switch(c)
{
case 'e': 
         {getchar();
         scanf("%f",&w);
         j=check(w);
         element=w;
         if(j==1||element<0||element>2147483648)
         {
         printf("Invalid Input\n");
         return 0;
         }
         enqueue(q,element);
          break;}
case 'd':       
          {dequeue(q);
          break;}
case 'p':
          {print_queue(q);
          break;}
case 's': {return 0;}
default: {printf("Invalid option\n");
         break;}
}
scanf("%c",&c);
}
while(c!='s');
return 0;
}
