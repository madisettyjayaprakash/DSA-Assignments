#include<stdio.h>
struct array{
int data;
int pro;
};
int check (float x)
{
int k;
k=x;
if(k==x)
return 0;
else
return 1;
}
int h;
int parent(int x)
{
return(x/2);
}

void insert(struct array *pq,int x,int y)
{
int k;
struct array temp;
if(h==0)
{
h=h+1;
pq[h].data=x;
pq[h].pro=y;
}
else
{
h=h+1;
pq[h].data=x;
pq[h].pro=y;
k=h;
while(k>1 && pq[parent(k)].pro > pq[k].pro)
{
temp=pq[parent(k)];
pq[parent(k)]=pq[k];
pq[k]=temp;
k=parent(k);
}
}}


void minheapify(struct array *pq,int i)
{
int small;
struct array temp;
int l,r;
l=2*i;
r=2*i+1;
if(l<=h && pq[l].pro<pq[i].pro)
   small=l;
else
   small=i;
if(r<=h && pq[r].pro<pq[small].pro)
   small=r;
   
if(small!=i)
{
temp=pq[i];
pq[i]=pq[small];
pq[small]=temp;
minheapify(pq,small);
}
}
 
 
 
void extract_min(struct array *pq)
{
if(h<=0)
printf("Empty\n");
else
{
struct array min;
min=pq[1];
printf("%d ",min.data);
printf("(%d)\n",min.pro);
pq[1]=pq[h];
h=h-1;
minheapify(pq,1);
}}

void get_min(struct array *pq)
{
if(h==0)
printf("Empty\n");
else
{
printf("%d ",pq[1].data);
printf("(%d)\n",pq[1].pro);
}
}


void decrease_priority(struct array *pq,int x,int y)
{
int i,n;
struct array temp;
for(i=1;i<=h;i++)
{
if(pq[i].data==x)
{
pq[i].pro=y;
if(pq[i].pro<=pq[1].pro)
{
temp=pq[i];
pq[i]=pq[1];
pq[1]=temp;
}
return;
}}
printf("Data could not be found\n");
}


int main()
{
struct array pq[1000];
int pr,elem,newelem,newpr,i,j;
float w,y;
char c;
h=0;
do
{
scanf("%c",&c);
switch(c)
{
case 'a':{scanf("%f",&w);
          scanf("%f",&y);
          i=check(w);
          j=check(y);
          elem=w;
          pr=y;
          if(i==1||j==1||elem<0||elem>1073741824||pr<=0||pr>1073741824)
          {
          printf("Invalid Input\n");
          return 0;
          }
          insert(pq,elem,pr);
          break;}
case 'e':{extract_min(pq);
          break;}
case 'g':{get_min(pq);
          break;}
case 'd':{scanf("%f",&w);
          scanf("%f",&y);
          i=check(w);
          j=check(y);
          elem=w;
          newpr=y;
          if(i==1||j==1||elem<0||elem>1073741824||newpr<=0||newpr>1073741824)
          {
          printf("Invalid Input\n");
          return 0;
          }
          decrease_priority(pq,elem,newpr);
          break;}
case 's':{break;}
}
}
while(c!='s');
return 0;
}
          
