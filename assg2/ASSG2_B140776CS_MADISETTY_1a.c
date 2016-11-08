#include<stdio.h>
int iterbinarysearch(float *,int,int,int);
int check(float *a,int n);
int sameocc(float *a,int n);
int main()
{
int n,i,m,l,c,h,d,x,q=0,u,w,v=0;
float y,a[10000],k;
scanf("%f",&y);
u=y*10;
w=u%10;
n=y;
if((n<=0)||(w>0))
printf("Invalid Input\n");
else
{
getchar();
i=0;
do{
scanf("%f",&a[i]);
u=a[i]*10;
w=u%10;
if(w>0)
v++;
if(getchar()==' ')
q++;
i++;}
while(i<n);
if((q>=n)||(v>0))
printf("Invalid Input\n");
else
{
scanf("%f",&k);
u=k*10;
w=u%10;
if(w>0)
printf("Invalid Input\n");
else
{
l=0;
h=n-1;
x=sameocc(a,n);
d=check(a,n);
if((d==1)&&(x==1))
{
c=iterbinarysearch(a,k,l,h);
if(c==1)
printf("\n");
else
printf("Not found\n");
}
else
printf("Invalid Input\n");
}}}
return 0;
}

int iterbinarysearch(float *a,int k,int l,int h)
{
int mid;
while(l<=h)
{
mid=(l+h)/2;
if(k==a[mid])
{
printf("%d",mid+1);
return 1;
}
else if(k<a[mid])
h=mid-1;
else 
l=mid+1;
}
}
int check(float *a,int n)
{
int b[100000],i,j,t,y;
for(i=0;i<n;i++)
b[i]=a[i];
for(i=0;i<n-1;i++)
{
for(j=i+1;j<n;j++)
{
if(b[i]>b[j])
{
t=b[i];
b[i]=b[j];
b[j]=t;
}}}

y=0;
for(i=0;i<n;i++)
{
if(b[i]-a[i]==0)
y++;
}
if(y==n)
return 1;
else
return 0;
}
int sameocc(float *a,int n)
{
int i,j,m=0,k=0;
for(i=0;i<n;i++)
{
for(j=0;j<n;j++)
{
if(a[i]==a[j])
m++;
}
if(m>1)
k++;
m=0;
}
if(k>=1)
return 0;
else
return 1;
}
