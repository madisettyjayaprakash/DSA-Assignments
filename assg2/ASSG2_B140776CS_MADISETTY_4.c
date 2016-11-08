#include<stdio.h>
int main()
{
int i,j,n,q;
double a[10000],t;
scanf("%d",&n);
if(n<=0)
printf("Invalid Input\n");
else
{
getchar();
i=0;
do{
scanf("%lf",&a[i]);
if(getchar()==' ')
q++;
i++;}
while(i<n);
if(q==n)
printf("Invalid Input\n");
else
{
for(i=0;i<n-1;i++)
{
for(j=0;j<n-i-1;j++)
{
if(a[j]>a[j+1])
{
t=a[j];
a[j]=a[j+1];
a[j+1]=t;
}}}
for(i=0;i<n;i++)
printf("%lf ",a[i]);
printf("\n");
}}
return 0;
}
