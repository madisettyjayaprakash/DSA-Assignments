#include<stdio.h>
#include<stdlib.h>
struct node{
int index;
int data;
struct node* next;
};
struct node*head;
int i=1;
int check (float x)
{
int k;
k=x;
if(k==x)
return 0;
else
return 1;
}
void insert(int d)
{
struct node*temp,*temp1;
temp=(struct node*)malloc(sizeof(struct node));
if(head==NULL)
{
head=temp;
temp->data=d;
temp->index=i;
temp->next=NULL;
}
else
{
temp1=head;
while(temp1->next!=NULL)
{
temp1=temp1->next;
}
temp1->next=temp;
temp->data=d;
temp->index=++i;
temp->next=NULL;
}}

int k_last(struct node*head,int k)
{
struct node*temp1,*temp2;
int l=0,x;
temp1=head;
while(temp1!=NULL)
{
temp1=temp1->next;
l++;
}

//counting total nodes 
x=l-k;
temp2=head;
while(x!=0)
{
temp2=temp2->next;
x--;
}
return (temp2->data);
}
int main()
{
head=NULL;
float w;
int n,k,d,v,x,j;
scanf("%f",&w);
n=w;
x=n;
j=check(w);
if(j==1||n<=0||n>2147483648)
{
printf("Invalid Input\n");
return 0;
}
while(n!=0)
{
scanf("%f",&w);
d=w;
j=check(w);
if(j==1||w<=-1073741824||w>=1073741824)
{
printf("Invalid Input\n");
return 0;
}
insert(d);
n--;
}
scanf("%f",&w);
k=w;
j=check(w);
if(j==1||w<1||w>x)
{
printf("Invalid Input\n");
return 0;
}
v=k_last(head,k);
printf("%d\n",v);
return 0;
}
