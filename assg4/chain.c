#include<stdio.h>
#include<stdlib.h>
struct node{
int data;
struct node*next;
};
struct hash{
struct node*head;
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
int m,tot=0;
void insert(struct hash*h,int x)
{
int k;
if(x<0)
k=(x%m)+m;
else
k=x%m;
struct node*new=(struct node*)malloc(sizeof(struct node));
new->data=x;
new->next=NULL;
if(h[k].head==NULL){
h[k].head=new;
printf("%d\n",k);
}
else
{
new->next=h[k].head;
h[k].head=new;
printf("%d\n",k);
}
return;
}
void search(struct hash*h,int y)
{
int a,b=0;
if(y<0)
a=(y%m)+m;
else
a=y%m;
struct node *node1;
node1=h[a].head;
if(node1==NULL)
{printf("%d ",a);
printf("NOT FOUND\n"); return ;}
while(node1!=NULL)
{
  if(node1->data==y){
      printf("%d ",a);
      printf("FOUND\n");
      b=1;
      break;
       }
    node1=node1->next;
}
if(b==0){
printf("%d ",a);
printf("NOT FOUND\n");}
return ;
}
int main()
{
char ch;
int i,key,j;
float c;
scanf("%f",&c);
m=c;
j=check(c);
if(j==1||m<=0){printf("Invalid Input\n"); return 0;}
struct hash *h=(struct hash*)calloc(m,sizeof(struct hash)); 
getchar();
do
{
scanf("%c",&ch);
{
switch(ch)
{
case 'i':{ getchar();
            scanf("%f",&c);
            j=check(c);
            key=c;
            if(j==1){printf("Invalid Input\n"); return 0;}
            insert(h,key);
            break;}
case 'f':{getchar();
            scanf("%f",&c);
            j=check(c);
            key=c;
            if(j==1){printf("Invalid Input\n"); return 0;}
           search(h,key);
           break;
           }
case 's':{return 0;}
default: {printf("Invalid option\n");
           return 0;}
 }
 } 
 getchar();}
 while(ch!='s');
 return 0;
 }
           
