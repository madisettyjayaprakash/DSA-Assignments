#include<stdio.h>
#include<string.h>
#include<stdlib.h>
struct std{
char r[20];
char f[30];
int m;
};
int power(int,int);
void fun(struct std *student,int n);
void rad(struct std *student,int n,int s);
int main()
{
struct std student[100];
int i,n,l,h,q=0,s,t,u;
scanf("%d",&n);
if(n<=0)
printf("Invalid Input\n");
else
{
for(i=0;i<n;i++)
{
scanf("%s",student[i].r);
scanf("%s",student[i].f);
scanf("%d",&student[i].m);
}
for(i=0;i<n;i++)
{
s=atoi(&student[i].r[0]);
t=atoi(&student[i].r[7]);
u=atoi(&student[i].r[8]);
if((strlen(student[i].r)!=9)||(student[i].m<0)||(student[i].m>100)||(s!=0)||(t!=0)||(u!=0))
q++;
}
if(q>=1)
printf("Invalid Input\n");
else
fun(student,n);
}
return 0;
}
void rad(struct std *student,int n,int s)
{

struct std b[1000];
int i,j,k=0,r,q,l,d=0,c=10,e;
while(s!=0){
for(i=0;i<10;i++){
for(j=0;j<n;j++){
q=atoi(&student[j].r[1]);
e=power(c,d);
q=q/e;
if(q%10==i)
{
b[k]=student[j];
k++;
}
}
}
for(i=0;i<n;i++)
{
student[i]=b[i];
}
k=0;
s--;
d++;
}
for(i=0;i<n;i++)
{
printf("%s ",student[i].r);
printf("%s ",student[i].f);
printf("%d\n",student[i].m);
}
}
void fun(struct std *student,int n)
{
int i,j,q[1000],max=0,c=0;
for(i=0;i<n;i++)
q[i]=atoi(&student[i].r[1]);
for(i=0;i<n;i++){
if(q[i]>max){
max=q[i];
}}
while(max!=0){
max=max/10;
c++;}
rad(student,n,c);
}
int power(int a,int b)
{

if(b<0)
return 1;
else if(b==0)
return 1;
else
return a*power(a,b-1);
}


