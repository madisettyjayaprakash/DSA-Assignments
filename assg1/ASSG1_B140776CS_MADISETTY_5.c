#include<stdio.h>
float add(float d,float f)
{
return (d+f);
}
float sub(float d,float f)
{
return (d-f);
}
float mul(float d,float f)
{
return (d*f);
}
float div(float d,float f)
{
return (d/f);
}
int main()
{
float a,b,r;
int c;
float (*p)(float ,float),(*q)(float ,float),(*s)(float ,float),(*t)(float ,float);
printf("Enter the numbers:");
scanf("%f%f",&a,&b);
p=add;
q=sub;
s=mul;
t=div;       
label:
printf("\nMenu:\n1. Add\n2. Subtract\n3. Multiply\n4. Divide\n5. Exit\n");
printf("Enter the choice:");
scanf("%d",&c);
switch(c)
{
case 1:
r=p(a,b);
printf("%f\n",r);
goto label;
case 2:
r=q( a,b);
printf("%f\n",r);
goto label;
case 3:
r=s( a,b);
printf("%f\n",r);
goto label;
case 4:
r=t(a, b);
printf("%f\n",r);
goto label;
case 5:
break;
}
return 0;
}



