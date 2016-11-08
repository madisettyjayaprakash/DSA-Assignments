#include<stdio.h>
#include<stdlib.h>
void merg(float *b,float *c,int x,int y,float *a);
void mersort(float *a,int n);
int main()
{
int i,j,m,l,u,v,x=0;
float a[10500];
char ch[10500];
FILE *p,*q;
p=fopen("NUMBERS","r");
q=fopen("OUTPUTS","w");
if(p==NULL){
printf("No contents to read\n");
}
else
{
{
i=0;
j=0;
while(fscanf(p,"%f%c",&a[i],&ch[j])!=EOF)
{
u=a[i]*10;
v=u%10;
if(v>0)
x++;
i++;
j++;}
}
if((x>0)||(j>10000))
printf("Invalid Input\n");
else
{
mersort(a,j);
for(i=0;i<j;i++)
fprintf(q,"%5.0f\n",a[i]);
fclose(p);
fclose(q);
}}
return 0;
}
void mersort(float *a,int n)
{
float b[10000],c[10000];
int x,y,z,i,j;
if(n<2)
return;
else
{
x=n/2;
for(i=0;i<=x-1;i++)
b[i]=a[i];
for(j=x;j<=n-1;j++)
c[j-x]=a[j];
mersort(b,i);
mersort(c,j-x);
merg(b,c,i,j-x,a);
}

}
void merg(float *b,float *c,int x,int y,float *a)
{
int i=0,j=0,k=0;
while((i<x)&&(j<y))
{
if(b[i]<=c[j]){
a[k]=b[i];
i++;
k++;
}
else
{
a[k]=c[j];
k++;
j++;
}
}
while(i<x){
a[k]=b[i];
k++;
i++;
}
while(j<y){
a[k]=c[j];
k++;
j++;
}
}

