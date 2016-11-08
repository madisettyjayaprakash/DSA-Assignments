#include<stdio.h>
#include<stdlib.h>
struct node
{
int val;
struct node* next;
};
struct node* head;
struct node*t1;
int check (float x)
{
int k;
k=x;
if(k==x)
return 0;
else
return 1;
}
void insert(int x)
{
struct node *temp1;
struct node *temp=(struct node*) malloc(sizeof(struct node));
//allocates a block for temp
temp->val=x;
temp->next=NULL;

if(head==NULL)
{
head=temp;
}
else
{
temp1=head;
while(temp1->next!=NULL)
{
temp1=temp1->next;
}
temp1->next=temp;
}
}
void printlist()
{
if(t1==NULL)
printf("\n");
else
{
while(t1!=NULL)
{
printf("%d ",t1->val);
t1=t1->next;
}
printf("\n");
}
}
void swap(struct node* head,int x,int y)
{
t1=head;
if(x==y)
{
return ;
}
struct node *px=NULL,*cx,*py=NULL,*cy;
cx=t1;
cy=t1;
while(cx!=NULL&&cx->val!=x)
{
px=cx;
cx=cx->next;
}
while(cy!=NULL&&cy->val!=y)
{
 py=cy;
 cy=cy->next;
}
if(cx==NULL)
{ printf("%d Not Found",x);
  t1=NULL;
  return ;
}
if(cy==NULL)
{ printf("%d Not Found",y);
  t1=NULL;
  return ;
}

if(px!=NULL)
  px->next=cy;
else
  t1=cy;
if(py!=NULL)
  py->next=cx;
else
   t1=cx;
   
  
struct node* temp=cy->next;
cy->next=cx->next;
cx->next=temp;
}
int main()
{
head=NULL;
int n,v,l,x,y,i,j,s;
float w,z;
scanf("%f",&w);
j=check(w);
n=w;
if(n<=0||j==1){printf("Invalid Input\n");return 0;}

for(i=1;i<=n;i++)
{
scanf("%f",&w);
j=check(w);
v=w;
if((w<-1073741824)||(w>1073741824)||(j==1)){printf("Invalid Input\n"); return 0;}
insert(v);
}
scanf("%f",&w);
scanf("%f",&z);
x=w;
y=z;
s=check(w);
j=check(z);
if(j==1||s==1||x<-1073741824||x>1073741824||y<-1073741824||y>1073741824)
{
printf("Invalid Input\n"); return 0;}
swap(head,x,y);
printlist();
return 0;
}



