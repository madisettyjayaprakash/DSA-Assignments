#include<stdio.h>
#include<string.h>
#include<stdlib.h>
struct std{
char r[50];
char f[50];
int m;
};
void sortq(struct std *student,int l,int h);
int part(struct std *student,int x,int y);
int main()
{
struct std student[1000];
int i,n,l,h,q=0,s,t,u;
scanf("%d",&n);
if(n<=0)
printf("Invalid Input\n");
else
{
for(i=0;i<n;i++)
{
scanf("%s",student[i].r);
scanf("%s",student[i].f);
scanf("%d",&student[i].m);
}
/*for(i=0;i<n;i++)
{
s=atoi(&student[i].r[0]);
t=atoi(&student[i].r[7]);
u=atoi(&student[i].r[8]);
if((strlen(student[i].r)!=9)||(student[i].m<0)||(student[i].m>100)||(s!=0)||(t!=0)||(u!=0))
q++;
}*/
if(q>=1)
printf("Invalid Input\n");
else
{
l=0;
h=n-1;
sortq(student,l,h);
for(i=0;i<n;i++)
{
printf("%s ",student[i].r);
printf("%s ",student[i].f);
printf("%d\n",student[i].m);
}
}
}
return 0;
}

void sortq(struct std *student,int l,int h)
{
int pi;
if(l<=h)
{
pi=part(student,l,h);
sortq(student,l,pi-1);
sortq(student,pi+1,h);
}
}
int part(struct std *student,int x,int y)
{
int i,j,k,n;
struct std t,l;
k=student[y].m;
i=x;
for(n=x;n<y;n++)
{
if(student[n].m>k)
{
t=student[n];
student[n]=student[i];
student[i]=t;
i++;
}
}

l=student[y];
student[y]=student[i];
student[i]=l;
return i;
}

