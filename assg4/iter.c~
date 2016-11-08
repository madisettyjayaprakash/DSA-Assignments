#include<stdio.h>
#include<string.h>
#include<stdlib.h>
struct expt{
char data;
struct expt *right,*left;
}*s1[50],*temp,*root,*s2[50];
int t1=-1,max=100,l,t2=-1;
char a[2000];
void pusht(struct expt *p)
{
if(t1==max)
printf("Full\n");
else
{
s1[++t1]=p;
}}
struct expt* popt()
{
if(t1==-1)
return NULL;
else
{
return (s1[t1--]);
}
}
void push(struct expt *p)
{
if(t2==max)
printf("Full\n");
else
s2[++t2]=p;
}
struct expt *pop()
{
if(t2==-1)
return NULL;
else
return (s2[t2--]);
}
void pror(struct expt*p)
{
if(p!=NULL)
push(p);
struct expt*temp;
while(t2!=-1)
{
     temp=pop();
     printf("%c",temp->data);
    if(temp->right!=NULL)
     push(temp->right);
    if(temp->left!=NULL)
    push(temp->left);
}}

void post(struct expt *p)
{
if(p==NULL)
return;
do
{
while(p!=NULL)
{
   if(p->right!=NULL)
    push(p->right);
push(p);
p=p->left;
}
p=pop();

if(p->right!=NULL&&s2[t2]==p->right)
{
   pop(p->right);
   push(p);
   p=p->right;
}
else
{
printf("%c",p->data);
p=NULL;
}}
while(t2!=-1); 
}

void inor(struct expt *p)
{
int k=0,i=0;
struct expt*temp2=NULL;
temp=p;
while(t2!=-1||temp!=NULL){
if(temp!=NULL){
push(temp);
temp=temp->left;
}
else{
temp=s2[t2];
pop();
printf("%c",temp->data);
temp=temp->right;
}
}
}

void createtree()
{
int i;
l=strlen(a);
i=l-1;
while(i>=0)
{
if(a[i]=='+'||a[i]=='-'||a[i]=='*'||a[i]=='/'||a[i]=='^')
{
temp=(struct expt*)malloc(sizeof(struct expt));
temp->data=a[i];
temp->left=popt();
temp->right=popt();
pusht(temp);
i--;}
else 
{
temp=(struct expt*)malloc(sizeof(struct expt));
temp->data=a[i];
temp->right=NULL;
temp->left=NULL;
pusht(temp);
i--;}
}
root=s1[t1];
}


int main()
{
int x,i,c=0,d=0,n;
scanf("%s",a);
for(i=0;i<strlen(a);i++){
if((a[i]<97||a[i]>122)&&(a[i]!='+'&&a[i]!='-'&&a[i]!='*'&&a[i]!='/'&&a[i]!='^')){
printf("Invalid Input\n"); return 0;}
}
for(x=0;x<strlen(a);x++){
if(a[x]=='+'||a[x]=='-'||a[x]=='*'||a[x]=='/'||a[x]=='^')
c++;
else
d++;
}
if(d-c!=1){printf("Invalid Input\n"); return 0;}
n=strlen(a);
if((a[n-1]=='+'||a[n-1]=='-'||a[n-1]=='*'||a[n-1]=='/'||a[n-1]=='^')||(a[n-2]=='+'||a[n-2]=='-'||a[n-2]=='*'||a[n-2]=='/'||a[n-2]=='^')){
printf("Invalid Input\n"); return 0;}



createtree();
printf("Inorder:");
inor(root);
printf("\n");
printf("Preorder:");
pror(root);
printf("\n");
printf("Postorder:");
post(root);
printf("\n");
return 0;
}

