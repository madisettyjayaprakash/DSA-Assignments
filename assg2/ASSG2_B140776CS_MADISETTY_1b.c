#include<stdio.h>
int recbinsearch(float *,int,int,int);
int check(float *,int);
int sameocc(float *,int);
int main()
{
int n,l,h,c,i,d,e,q=0,u,v,w=0,k;
float y,a[1000],x;
scanf("%f",&y);
u=y*10;
v=u%10;
if((y<=0)||(v>0))
printf("Invalid Input\n");
else
{
n=y;
getchar();
i=0;
do{
scanf("%f",&a[i]);
u=a[i]*10;
v=u%10;
if(v>0)
w++;
if(getchar()==' ')
q++;
i++;}
while(i<n);
if((q>=n)||(w>0))
printf("Invalid Input\n");
else
{
scanf("%f",&x);
u=x*10;
v=u%10;
if(v>0)
printf("Invalid Input\n");
else
{
k=x;
l=0;
h=n-1;
e=sameocc(a,n);
d=check(a,n);
if((d==1)&&(e==1))
{
c=recbinsearch(a,k,l,h);
if(c==1)
printf("\n");
else
printf("Not Found\n");
}
else
printf("Invalid Input\n");
}}}
return 0;
}

int recbinsearch(float *a,int k,int l,int h)
{
int mid;
if(l<=h)
{
mid=(l+h)/2;
if(k==a[mid])
{
printf("%d",mid+1);
return 1;
}
else if(k<a[mid])
recbinsearch(a,k,l,mid-1);
else 
recbinsearch(a,k,mid+1,h);
}
else
return 0;
}
int check(float *a,int n)
{
int b[100],i,j,t,y=0;
for(i=0;i<n;i++)
b[i]=a[i];
for(i=0;i<n-1;i++)
{
for(j=i+1;j<n;j++)
{
if(a[i]>a[j])
{
t=a[i];
a[i]=a[j];
a[j]=t;
}}}
for(i=0;i<n;i++)
{
if(a[i]==b[i])
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
