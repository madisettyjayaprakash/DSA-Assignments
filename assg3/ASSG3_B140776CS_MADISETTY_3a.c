#include<stdio.h>
#include<stdlib.h>
int n,f=0,r=0;
int check (float x)
{
int k;
k=x;
if(k==x)
return 0;
else
return 1;
}
int isfull(){
if(f==0&&r==n-1)
return 1;
else if(r!=n-1&&f-r==1)
return 1;
else
return 0;
}
int isempty(){
if(f==r)
return 1;
else
return 0;}

void enqueue(int *q,int x)
{
if(isfull())
printf("Overflow\n");
else
{
q[r]=x;
if(r==n-1)
r=0;
else
r++;
}}

void dequeue(int *q)
{
int y;
if(isempty())
printf("Empty\n");
else{
y=q[f];
if(f==n-1){
f=0;
printf("%d\n",y);
}
else
{f++;
printf("%d\n",y);}
}}
void print_queue(int *q)
{
int i;
if(isempty())
 printf("Empty\n");
else
{
 if(f<r){
 for(i=f;i<r;i++)
 printf("%d ",q[i]);}
 else
 {
 for(i=f;i<=n-1;i++)
 printf("%d ",q[i]);
 for(i=0;i<r;i++)
 printf("%d ",q[i]);
 }
printf("\n");
}
}
int main()
{
float w;
int i,q[500],element,j;
char c,l;
scanf("%f",&w);
j=check(w);
n=w;
if(j==1||n<=0||n>=100){printf("Invalid Input\n"); return 0;}
scanf("%c",&c);
do
{
scanf("%c",&c);
switch(c)
{
case 'e':{getchar();
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
          {
          dequeue(q);
          break;}
case 'p':
          {
          print_queue(q);
          break;}
case 's':
          {return 0;}
default: {printf("Invalid option\n");
          break;}         
}
getchar();
}
while(c!='s');
return 0;
}
