#include<stdio.h>
#include<stdlib.h>
#include<string.h>


struct node{
int data;
struct node*next;
};
int R=-1,F=-1,arr[10000];
int n,v[10000],v1[10000];
struct node*a[10000];



void createlist(int i,int y)
{
 struct node*p,*q;
 p=(struct node*)malloc(sizeof(struct node));
 p->data=y;
 p->next=NULL;
 if(a[i]==NULL)
 a[i]=p;
 else
 {
  q=a[i];
  while(q->next!=NULL)
  q=q->next;
  q->next=p;
  }
  
}

void dfs(int e,int f)
{
struct node*w,*r;
printf("%d ",e);
w=a[e];
r=a[f];
v[e]=1;
while(w!=r&&w!=NULL)
{
e=w->data;
if(v[e]==0)
dfs(e,f);
if(e==f){return;}
w=w->next;
}
}

int empty()
{
if(R==-1)
return 1;
else
return 0;
}
int full()
{
if(R==n-1)
return 1;
else
return 0;
}
void enqueue(int x)
{
if(R==-1)
{
R=0;
F=0;
arr[R]=x;
}
else
{
R=R+1;
arr[R]=x;
}
}
int dequeue()
{
int x;
x=arr[F];
if(R==F)
{
 R=-1;
 F=-1;
}
else
F=F+1;
return x;
}

void bfs(int e,int f)
{
int i,j,l;

struct node*p,*r;
r=a[f];
for(i=0;i<10000;i++)
v1[i]=0;
printf("%d ",e);
enqueue(e);

v1[e]=1;
while(!empty())
{
e=dequeue();
for(p=a[e];p!=r&&p!=NULL;p=p->next)
{
 j=p->data;
 if(j==f){printf("%d ",j);return; }
 if(v1[j]==0)
 {
   enqueue(j);
   v1[j]=1;
   printf("%d ",j);
  }
  
}
}
return;
}

int main()
{
char c[10],l[1000],u;
int g,h,i,d,k,y;
float w,s;

scanf("%f",&w);
n=w;
if(n!=w||n<=0||n>10000){printf("Invalid Input\n");}
getchar();
for(i=0;i<10000;i++)
a[i]=NULL;

for(i=0;i<n;i++)
{
  int j=0;
  u=' ';
  for(;u!='\n';)
  {
   scanf("%c",&u);
   if(u=='\n'&& j==0)
   {
    a[i]=NULL;
    break;
   }
   else if(u!=' '&&u!='\n')
   {
    l[j]=u;
    j++;
    l[j]='\0';
   }
    else
   {
     j=0;
     y=atoi(l);
     if(y<0||y>n-1){printf("Invalid Input\n");return 0;}
     createlist(i,y);
    }
 }
}

 
do
{
scanf("%s",c);
{
if(strcmp("dfs",c)==0)
  {
 
   scanf("%f",&w);
   scanf("%f",&s);
   g=w;
   h=s;
   if(g>=n||h>=n||g!=w||h!=s||g<0||h<0){printf("Invalid Input\n");return 0;}
   for(i=0;i<10000;i++)
    v[i]=0;
   dfs(g,h);
   printf("\n");
   getchar();
  }
else if(strcmp("bfs",c)==0)
   {
   
   scanf("%f %f",&w,&s);
   g=w;
   h=s;
   if(g>=n||h>=n||g!=w||h!=s||g<0||h<0){printf("Invalid Input\n");return 0;}
   while(!empty())
   dequeue();
   bfs(g,h);
   printf("\n");
   getchar();
   }
else if(strcmp("stp",c)==0)
  {
  return 0;
  }
else
  {
  printf("Invalid Option\n");
  return 0;
  }
}
}while(1);

return 0;
}













