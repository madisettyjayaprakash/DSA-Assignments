#include<stdio.h>
#include<stdlib.h>
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
int calc(int x,int y)
{
int z;
if(x%m==0)
return ((y*y)%m);
if(x<0)
z=(x%m)+m;
else
z=x%m;                            //h1(k)=k%m
return ((z+(y*y))%m);}           //Hq(k,i)=(h1(k)+ci+d(i*i))%m  c=0 ,d=1
void insert(int *h,int x)
{
int a,b;
b=0;
a=calc(x,b);
while(h[a]!=-100000&&b<m)
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
void search(int *h,int y)
{
int a,b;
b=0;
a=calc(y,b);
while(h[a]!=y&&h[a]!=-100000&&b<m)
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
char ch;
int i,key,j;
float c;
scanf("%f",&c);
j=check(c);
m=c;
if(j==1||m<=0){printf("Invalid Input\n"); return 0;}
int *h=(int *)calloc(m,sizeof(int));
for(i=0;i<m;i++){
h[i]=-100000;}
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
            if(j==1){printf("Invalid Input\n"); break;}
            insert(h,key);
            break;}
case 'f':{ getchar();
            scanf("%f",&c);
            j=check(c);
            key=c;
            if(j==1){printf("Invalid Input\n"); break;}
           search(h,key);
           break;
           }
case 's':{return 0;}
default: {printf("Invalid option\n");
           break;}
 }
 } 
 getchar();}
 while(ch!='s');
 return 0;
 }

