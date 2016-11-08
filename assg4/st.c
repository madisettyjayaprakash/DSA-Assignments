#include<stdio.h>
#include<string.h>
#include<stdlib.h>
struct expt{
char data;
struct expt *right,*left;
}*stack[50],*temp,*root;
int top=-1,max=100,l;
char a[2000];
void pusht(struct expt *p)
{
if(top==max)
printf("Full\n");
else
{
//top=top+1;
stack[++top]=p;
}}
struct expt* popt()
{
if(top==-1)
return NULL;
else
{
return (stack[top--]);
}
}
void inor(struct expt*p)
{
if(p!=NULL)
{
if(!(p->left==NULL&&p->right==NULL))
printf("(");
inor(p->left);
printf("%c",p->data);
inor(p->right);
if(!(p->left==NULL&&p->right==NULL))
printf(")");
}}
void post(struct expt *p)
{
if(p!=NULL)
{
post(p->left);
post(p->right);
printf("%c",p->data);
}}
void pror(struct expt *p)
{
if(p!=NULL)
{
printf("%c",p->data);
pror(p->left);
pror(p->right);
}}
void createtree()
{
int i,x;
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
root=stack[top];
}
int main()
{
int x,c=0,d=0,n;
scanf("%s",a);
for(x=0;x<strlen(a);x++){
if((a[x]<97||a[x]>122)&&(a[x]!='+'&&a[x]!='-'&&a[x]!='*'&&a[x]!='/'&&a[x]!='^')){
printf("Invalid Input\n"); return 0;}
}
for(x=0;x<strlen(a);x++){
if(a[x]=='+'||a[x]=='-'||a[x]=='*'||a[x]=='/'||a[x]=='^')
c++;
else
d++;}
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

