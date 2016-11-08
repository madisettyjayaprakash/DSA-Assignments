#include<stdio.h>
#include<math.h>
int binary(long int a);
int main()
{
long int n;
int c;
printf("Enter a positive decimal number:");
scanf("%ld",&n);
if((n<0)||n>pow(2,31))
printf("Invalid input\n");
else
{
c=binary(n);
printf("The binary representation of %ld contains %d 1s.\n",n,c);
return 0;
}
}
int binary(long int a)
{
int b=0;
while(a!=0)
{
if(a%2==1)
{
b++;
a=a/2;
binary(a);
}
else
{
a=a/2;
binary(a);
}
}
return (b);

}
