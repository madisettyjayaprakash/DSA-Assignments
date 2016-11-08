#include<stdio.h>
#include<math.h>
int rnd(float r);
int main()
{
float a[20][20],l,b[20][20];
int i,j,n,p,q,r=0,s,m,t;
char x;
printf("Enter input\n");
do
{
s=0;
do{
scanf("%f%c",&a[r][s],&x);
s++;
}
while(x==' ');
r++;
s--;
}
while(r<=s);
n=r;
if((n<0)||(n>100))
printf("Invalid input");
else
{
if(n==1)
printf("%f\n",a[0][0]);
else
{
for(i=0;i<n;i++){
for(j=0;j<n;j++){

if((i==0)&&(j==0))
b[i][j]=(a[i][j]+a[i][j+1]+a[i+1][j]+a[i+1][j+1])/4;
else if((i==n-1)&&(j==0))
b[i][j]=(a[i][j]+a[i-1][j]+a[i][j+1]+a[i-1][j+1])/4;
else if((i==0)&&(j==n-1))
b[i][j]=(a[i][j]+a[i][j-1]+a[i+1][j]+a[i+1][j-1])/4;
else if((i==n-1)&&(j==n-1))
b[i][j]=(a[i][j]+a[i][j-1]+a[i-1][j]+a[i-1][j-1])/4;
else if(i==0){
for(p=1;p<n-1;p++)
{
b[i][p]=(a[i][p]+a[i][p-1]+a[i][p+1]+a[i+1][p-1]+a[i+1][p]+a[i+1][p+1])/6;
}}
else if(i==n-1){
for(p=1;p<n-1;p++){
b[i][p]=(a[i][p]+a[i][p-1]+a[i-1][p]+a[i-1][p-1]+a[i][p+1]+a[i-1][p+1])/6;}}
else if(j==0){
for(p=1;p<n-1;p++){
b[p][j]=(a[p-1][j]+a[p+1][j]+a[p][j+1]+a[p-1][j+1]+a[p+1][j+1]+a[p][j])/6;}}
else if(j==n-1){
for(p=1;p<n-1;p++){
b[p][j]=(a[p-1][j]+a[p-1][j-1]+a[p][j-1]+a[p+1][j-1]+a[p+1][j]+a[p][j])/6;}}
else 
b[i][j]=(a[i][j]+a[i-1][j-1]+a[i+1][j+1]+a[i][j-1]+a[i][j+1]+a[i-1][j]+a[i-1][j+1]+a[i+1][j-1]+a[i+1][j])/9;
}
}}
for(i=0;i<n;i++){
printf("\n");
for(j=0;j<n;j++){
q=rnd(b[i][j]);
printf("%d ",q);
}}
}

return 0;
}
int rnd(float s)
{
return s+0.5;
}



