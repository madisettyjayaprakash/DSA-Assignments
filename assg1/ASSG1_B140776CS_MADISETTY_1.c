#include<stdio.h>
#include<string.h>
int valid(char *);
char sort(char *);
int main()
{
char a[20],b[20];
int i,j,k,m,n,o,p;
printf("Enter str1:");
scanf("%s",a);
printf("Enter str2:");
scanf("%s",b);
o=valid(a);
p=valid(b);
if((o==1)&&(p==1))
{
k=0;
m=0;
n=0;
*a=sort(a);
*b=sort(b);
if(strlen(a)==strlen(b))
{
for(i=0;i<strlen(a);i++)
{
for(j=0;j<strlen(b);j++)
{
if(a[i]==b[j])
k++;
if(b[i]==a[j])
n++;
}
if(k==n)
m++;
k=0;
n=0;
}
}
if(m==strlen(a))
printf("YES\n");
else
printf("NO\n");
}
else
printf("Invalid input\n");
return 0;
}
int valid(char *x)
{
int v,u,y=0,z=0;
for(u=0;u<strlen(x);u++)
{
for(v='a';v<='z';v++)
{
if(x[u]==v)
y++;
}
if(y==1)
z++;
y=0;
}
if(z==strlen(x))
return 1;
else 
return 0;
}
char sort(char *c)
{
char t;
int i,j;
for(i=0;i<strlen(c);i++){
for(j=0;j<strlen(c);j++){
if(c[i]<c[j])
{
t=c[i];
c[i]=c[j];
c[j]=t;
}
}}
return (*c);
}

