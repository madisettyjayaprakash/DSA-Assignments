#include<stdio.h>
#include<string.h>
void check (char b[300]);
int main()
{
char a[100][10000],t[100],k,ch,ah;
int i,j,m=0,l=0,x=0,c,p=0,q=0,s,g;
float n;
scanf("%f",&n);
s=n*10.0;
g=s%10;
if((n<=0)||(g>0))
printf("Invalid Input\n");
else
{
if(n==1)
{
scanf("%s",a[0]);
check(a[0]);
}
else
{
getchar();
i=0;
do
{
scanf("%s",a[i]);
if(getchar()==' ')
q++;
i++;}
while(i<n);
if(q>=n)
printf("Invalid Input\n");
else
{
for(i=0;i<n;i++){
if(strlen(a[i])>10)
p++;}
if(p>=1)
printf("Invalid Input\n");
else
{
for(i=0;i<n;i++){
for(k='A';k<='Z';k++){
for(j=0;j!=' ';j++){
if(a[i][j]==k)
m++;
}
}
}
if(m>=1)
printf("Invalid input\n");
else
{
for(i=0;i<n-1;i++){
for(j=i+1;j<n;j++){
if(strcmp(a[i],a[j])>0)
{
strcpy(t,a[i]);
strcpy(a[i],a[j]);
strcpy(a[j],t);
}}}
for(i=0;i<n;i++)
printf("%s ",a[i]);
printf("\n");
}
}
}
}}
return 0;
}
void check(char b[300])
{
int i,j,n,y;
char k;
n=strlen(b);
for(i=0;i<n;i++){
for(k='A';k<='Z';k++){
if(b[i]==k)
y++;
}}
if((y>=1)||(n>10))
printf("Invalid Input\n");
else
printf("%s\n",b);
}
