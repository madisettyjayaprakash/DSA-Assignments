#include<stdio.h>
int main()
{
int i,j,y=0,m,n,g,h,s,t,x=0,z;
float a[10][1000],e,f,k;
scanf("%f %f",&e,&f);
g=e*10;
s=g%10;
h=f*10;
t=h%10;
if((e<=0)||(f<=0)||(s>0)||(t>0))
printf("Invalid Input\n");
else
{
n=e;
m=f;
for(i=0;i<n;i++){
for(j=0;j<m;j++){
scanf("%f",&a[i][j]);
s=((a[i][j])*10);
t=s%10;
if(t>0)
x++;
}}
scanf("%f",&k);
s=k*10;
t=s%10;
if((t>0)||(x>0))
printf("Invalid Input\n");
else
{
z=k;
for(i=0;i<n;i++){
for(j=0;j<m;j++){
if(k==a[i][j])
{
printf("%d %d\n",i+1,j+1);
}
else
y++;
}}
if(y==(n*m))
printf("NOT FOUND\n");
}}
return 0;
}
