#include<stdio.h>
#include<stdlib.h>

struct node{
int data;
int rank;
struct node*parent;
};

int c1,c2,c3,c4;

struct node*a[10000],*b[10000],*c[10000],*d[10000];
int makeset1(int x)
{ 
  struct node*temp=(struct node*)malloc(sizeof(struct node));
  if(a[x]->data==-1){
  temp->data=x;
  temp->rank=0;
  temp->parent=temp;
  a[x]=temp;
  return x;}
  else
  return -2;
  
}


int makeset2(int x)
{ 
  struct node*temp=(struct node*)malloc(sizeof(struct node));
  if(b[x]->data==-1){
  temp->data=x;
  temp->parent=temp;
  temp->rank=0;
  b[x]=temp;
  return x;}
  else
  return -2;
  
}
int makeset3(int x)
{ 
  struct node*temp=(struct node*)malloc(sizeof(struct node));
  if(c[x]->data==-1){
  temp->data=x;
  temp->rank=0;
  temp->parent=temp;
  c[x]=temp;
  return x;}
  else
  return -2;
  
}
int makeset4(int x)
{ 
  struct node*temp=(struct node*)malloc(sizeof(struct node));
  if(d[x]->data==-1){
  temp->data=x;
  temp->rank=0;
  temp->parent=temp;
  d[x]=temp;
  return x;}
  else
  return -2;
  
}

int find1(int x)
{
 c1++;
 if(a[x]->data==-1){return -2;}
 if(a[x]->parent==a[x]){
 return x;}
 else{
  return find1(a[x]->parent->data);
 }
}
int find2(int x)
{
 c2++;
 if(b[x]->data==-1){return -2;}
 if(b[x]->parent==b[x]){
 return x;}
 else{
 return find2(b[x]->parent->data);
 }
}

struct node* find3(struct node*z)
{ c3++;
 if(z->data==-1){return NULL;}
 if(z->parent!=z)
 z->parent=find3(z->parent);
 
 return z->parent;
 
}
struct node* find4(struct node*z)
{ 
  c4++;
 if(z->data==-1){return NULL;}
 if(z->parent!=z)
 z->parent=find4(z->parent);
 
 return z->parent;
}



int unionset1(int x,int y)
{
 int c,d;
 c=find1(x);
 
 d=find1(y);
 
 if(c==-2||d==-2){return -3;}
 a[d]->parent=a[c];
 return c;
}

 
 
int unionset2(int x,int y)
{
 int c,d;
 c=find2(x);
 d=find2(y);
 if(c==-2||d==-2){return -3;}
 if(c==d)
 return c;
 else
 {
  if(b[c]->rank<b[d]->rank){
    b[c]->parent=b[d];
    return d;}
  else if(b[c]->rank>b[d]->rank){
    b[d]->parent=b[c];
    return c;}
  else {
    b[d]->parent=b[c];
    b[c]->rank=b[c]->rank+1;
    return c;
    }
 }
}
 

int unionset3(int x,int y)
{
 struct node *q,*w;
 q=find3(c[x]);
 
 w=find3(c[y]);
 
 if(q==NULL||w==NULL){return -3;}
 w->parent=q;
 return q->data;
}
 
int unionset4(int x,int y)
{
 struct node*g,*h;
 g=find4(d[x]);

 h=find4(d[y]);

 if(g==NULL||h==NULL){return -3;}
 if(g==h)
 return g->data;
 else
 {
  if(g->rank<h->rank){
    g->parent=h;
    return h->data;}
  else if(g->rank>h->rank){
    h->parent=g;
    return g->data;}
  else {
    h->parent=g;
    g->rank=g->rank+1;
    return g->data;
    }
 }
}




 
 
 
 
 
 
int main()
{
char t;
int x,y,r,i,p,q,s;
float w,u;
struct node*g,*h;
c1=0;
c2=0;
c3=0;
c4=0;
for(i=0;i<10000;i++){
struct node*temp;
temp=(struct node*)malloc(sizeof(struct node));
temp->data=-1;
a[i]=temp;
b[i]=temp;
c[i]=temp;
d[i]=temp;}
do
 {
scanf("%c",&t);
switch(t)
 {
 case 'm':{ getchar();
            scanf("%f",&w);
            x=w;
            if(x!=w||x<0||x>10000){printf("Invalid Input\n"); return 0;}
            p=makeset1(x);
            q=makeset2(x);
            r=makeset3(x);
            s=makeset4(x);
            
            if(p==-2||q==-2||r==-2||s==-2){
            printf("PRESENT\n"); break;}
            else
            {
            printf("%d\n",r);}
            break;}
            
            
 case 'f':{ getchar();
            scanf("%f",&w);
            x=w;
            if(x!=w||x<0||x>10000){printf("Invalid Input\n"); return 0;}
            p=find1(x);
            q=find2(x);
            g=find3(c[x]);
            h=find4(d[x]);
            if(p==-2||q==-2||g==NULL||h==NULL){printf("NOT FOUND\n"); break;}
            else
            {
            printf("%d ",p);
            printf("%d ",q);
            printf("%d ",g->data);
            printf("%d\n",h->data);
            }
            break;}
 case 'u':{ getchar();
            scanf("%f %f",&u,&w);
            x=u;
            y=w;
            if(x!=u||w!=y||x<0||y<0||x>10000||y>10000){printf("Invalid Input\n"); return 0;}
            p=unionset1(x,y);
            q=unionset2(x,y);
            r=unionset3(x,y);
            s=unionset4(x,y);
            if(p==-3||q==-3||r==-3||s==-3){printf("ERROR\n"); break;}
            else
            {
            printf("%d ",p);
            printf("%d ",q);
            printf("%d ",r);
            printf("%d\n",s);}
            break;}
 case 's':{ printf("%d ",c1);
            printf("%d ",c2);
            printf("%d ",c3);
            printf("%d\n",c4);
            return 0;}
 default: {printf("Invalid Option\n"); return 0;}
 }
 getchar();
 }while(t!='s');
 
return 0;
}
 
 
 
 
 
 
 
 
 
 
