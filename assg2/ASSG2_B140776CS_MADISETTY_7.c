#include<stdio.h>
void hpsort(float *a,int );
void bldheap(float *a,int );
void heapfy(float *a,int);
int main()
{
int n,i=1,t=0,u,v,q=0;
float x,y,a[10000];
scanf("%f",&x);
u=x*10;
v=u%10;
if((x<=0)||(v>0))
printf("Invalid Input\n");
else
{
n=x;
getchar();
do{
scanf("%f",&a[i]);
u=a[i]*10;
v=u%10;
if(v>0)
q++;
if(getchar()==' ')
t++;
i++;}
while(i<=n);
if((t>=n)||(q>0))
printf("Invalid Input\n");
else
{
hpsort(a,n);
for(i=1;i<=n;i++)
printf("%5.0f ",a[i]);
printf("\n");
}
}
return 0;
}
int z;
void hpsort(float *a,int n)
{
int i,x;
bldheap(a,n);
for(i=n;i>=2;i--){
x=a[1];
a[1]=a[i];
a[i]=x;
z=z-1;
heapfy(a,1);
}}
void bldheap(float *a,int n)
{
int i;
z=n;
for(i=n/2;i>=1;i--){
heapfy(a,i);
}}
void heapfy(float *a,int m)
{
int l,r,q,t;
l=2*m;
r=(2*m)+1;
if((l<=z)&&(a[l]>a[m]))
q=l;
else
q=m;
if((r<=z)&&(a[r]>a[q]))
q=r;
if(q!=m)
{
t=a[m];
a[m]=a[q];
a[q]=t;
heapfy(a,q);
}
}
