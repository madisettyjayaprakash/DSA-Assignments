#include<stdio.h>
#include<stdlib.h>
#include<math.h>
int m;
int check (float x)
{
int k;
k=x;
if(k==x)
return 0;
else
return 1;
}
float flor(float q)
{
int x;
x=q;
if(q<0){
x=x-1;
return q-x;}
else
return q-x;}
int calc(int x,int y)
{
int z,s,r,q,w;
double C,u,e;
if(x<0)
z=(x%m)+m;
if(x>=0)
z=x%m;
C=x*0.6180339887;                    //h1(k)=k%m
u=flor(C);                           //h2(k)=m*(kA mod 1) 
r=(m*u); 
q=y*r;
return ((z+q)%m);                    //h(k,i)=(h1(k)+i*h2(k))mod m
}
void insert(float *h,int x)
{
int a,b;
b=0;
a=calc(x,b);
while(h[a]!=-10.5&&b<m)
{
printf("%d ",a);
b=b+1;
a=calc(x,b);}
if(b>=m)
printf("Cannot insert\n");
else{
h[a]=x;
printf("%d\n",a);}
return;
}
void search(float *h,int y)
{
int a,b;
b=0;
a=calc(y,b);
while(h[a]!=y&&h[a]!=-10.5&&b<m)
{
printf("%d ",a);
b=b+1;
a=calc(y,b);
}
if(h[a]==y){
printf("%d ",a);
printf("FOUND\n");}
else
{
printf("%d ",a);
printf("NOT FOUND\n");
}
}
int main()
{
float c;
char ch;
int i,key,j;
scanf("%f",&c);
j=check(c);
m=c;
if(j==1||m<=0){printf("Invalid Input\n"); return 0;}
float *h=(float *)calloc(m,sizeof(float));
for(i=0;i<m;i++){
h[i]=-10.5;}
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
case 'f':{  getchar();
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

