#include<stdio.h>
int main()
{
int i,j,k,m=0,q,c,d,l=0;
float a[100000],n;
scanf("%f",&n);
c=n*10.0;
d=c%10;
if((n<=0)||(d>0))
printf("Invalid Input\n");
else
{
getchar();
i=0;
do{
scanf("%f",&a[i]);
c=a[i]*10.0;
d=c%10;
if(d>0)
l++;
if(getchar()==' ')
q++;
i++;}
while(i<n);
if((q==n)||(l>0))
printf("Invalid Input\n");
else
{

for(i=0;i<n;i++)
{
if(a[i]<0)
m++;
}
if(m>0)
printf("Invalid Input\n");
else
{
for(i=1;i<=n-1;i++)
{
j=i;
k=a[i];
while((j>=0)&&(k<a[j-1]))
{
a[j]=a[j-1];
j=j-1;
}
a[j]=k;
}
for(i=0;i<n;i++)
printf("%5.0f ",a[i]);
printf("\n");
}
}}
return 0;
}

