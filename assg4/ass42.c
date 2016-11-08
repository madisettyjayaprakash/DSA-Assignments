#include<stdio.h>
#include<string.h>
#include<stdlib.h>
struct node{
int key;
struct node*left,*right;
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
struct node*insert(struct node*tree,int x)
{
struct node*temp;
temp=(struct node*)malloc(sizeof(struct node));
         temp->key=x;
         temp->left=NULL;
         temp->right=NULL;
     if(tree==NULL)
     return(temp);
     if(x<= tree->key)
     tree->left=insert(tree->left,x);
     else if(x> tree->key)
     tree->right=insert(tree->right,x);

}
struct node*search(struct node*temp,int y)
{
if(tree==NULL||tree->key==y)
 return tree;
 if(y< tree->key)
 return search(tree->left,y); 
 else
 return search(tree->right,y);
}

struct node* findMin(struct node*tree)
{
struct node*temp=tree;
if(temp==NULL){
return NULL;
}
else
{
while(temp->left!=NULL){
temp=temp->left;}
return temp;
}}
struct node*findMax(struct node*tree)
{
struct node*temp=tree;
if(temp==NULL)
return NULL;
else
{
while(temp->right!=NULL){
temp=temp->right;}
return temp;
}}
void inorder(struct node*temp)
{
if(temp==NULL)
return;
else
{
    inorder(temp->left);
    printf("%d ",temp->key);
    inorder(temp->right);
}
}  
void preorder(struct node*temp)
{
if(temp==NULL)
return ;
else {
    printf("%d ",temp->key);
    preorder(temp->left);
    preorder(temp->right);
}
}
void postorder(struct node*temp)
{
if(temp==NULL)
return;
else
{
    postorder(temp->left);
    postorder(temp->right);
    printf("%d ",temp->key);
}
}

struct node*successor(struct node*tree,int x)
{
  //search the node
  struct node*curr=search(tree,x);
  if(curr==NULL) 
  return NULL;
  if(curr->right!=NULL){   //node has right sub-tree
       return findMin(curr->right);
}
  else            //No right sub-tree
  {
      struct node*succ=NULL;
      struct node*ance=tree;
       while(ance!=curr){
          if(curr->key < ance->key){
             succ=ance; //so far this is the deepest node for which the current node is the left
             ance=ance->left;
             }
           else
           ance=ance->right;
         }
       return succ;
  }
}
struct node*predecessor(struct node*tree,int x)
{
struct node*curr=search(tree,x); 
if(curr==NULL)
return NULL;                 
if(curr->left!=NULL) //node has left sub-tree
  return findMax(curr->left);
else          //case node has no left sub-tree
{
   struct node*pred=NULL;
   struct node*ance=tree;
   while(ance!=curr){
      if(curr->key > ance->key)
      {
          pred=ance;
          ance=ance->right;
      }
      else
      ance=ance->left;
    }
    return pred;
}}
struct node*delete(struct node*tree,int x)
{
struct node*temp,*q;
q=search(tree,x);
if(q==NULL){
printf("element not present\n"); return tree;}
else{
  if(tree==NULL)
        return tree;
  else if(x< tree->key)
              tree->left=delete(tree->left,x);
  else if(x> tree->key)
              tree->right=delete(tree->right,x);
  else
  { 
          if(tree->left==NULL&&tree->right==NULL)
          {
             free(tree);
             tree=NULL;
             return tree;
          }
          if(tree->left==NULL)
          {
            temp=tree;
            tree=tree->right;
            free(temp);
            return tree;
          }
          if(tree->right==NULL)
          {
             temp=tree;
             tree=tree->left;
             free(temp);
              return tree;
          }
          else
          {
            temp=findMin(tree->right);
            tree->key=temp->key;
            tree->right=delete(tree->right,temp->key);
           }
 }return tree;}}
int main()
{
struct node*tree=NULL,*t;
char a[20];
int element,key,r,j;
float w;
do
{
scanf("%s",a);
{
   if(strcmp("insr",a)==0)
      {
      scanf("%f",&w);
      element=w;
      j=check(w);
      if(j==1||w<0){
      printf("Invalid Input\n"); return 0;}
      else
      tree=insert(tree,element);
      }
   else if(strcmp("srch",a)==0)
      {  getchar();
        scanf("%d",&key);
        
        t=search(tree,key);
        if(t!=NULL)
        printf("FOUND\n");
        else
        printf("NOT FOUND\n");
        
      }
    else if(strcmp("minm",a)==0)
    {
       t=findMin(tree);
       if(t==NULL)
       printf("NIL\n");
       else
       printf("%d\n",t->key);
    }
    else if(strcmp("maxm",a)==0)
    {
       t=findMax(tree);
       if(t==NULL)
       printf("NIL\n");
       else
       printf("%d\n",t->key);
     }
   else if(strcmp("pred",a)==0)
    {
    scanf("%f",&w);
    j=check(w);
    element=w;
    if(j==1||w<0){
    printf("Invalid Input\n"); return 0;}
    else
    {
    t=predecessor(tree,element);
    if(t==NULL)
    printf("NIL\n");
    else
    printf("%d\n",t->key);
    }
    }
    else if(strcmp("succ",a)==0)
    {
    scanf("%f",&w);
    j=check(w);
    element=w;
    if(j==1||w<0){
    printf("Invalid Input\n"); return 0;}
    else
    {
    t=successor(tree,element);
    if(t==NULL)
    printf("NIL\n");
    else
    printf("%d\n",t->key);
    }
    }
    else if(strcmp("delt",a)==0)
    {
    scanf("%f",&w);
    j=check(w);
    element=w;
    if(j==1||w<0){
    printf("Invalid Input\n"); return 0;}
    else
    tree=delete(tree,element);
    }
    else if(strcmp("inor",a)==0)
   {
       if(tree==NULL)
       printf("No elements\n");
       else
       {
       inorder(tree);
       printf("\n");
       }
    }
    else if(strcmp("prer",a)==0)
    {
       if(tree==NULL)
       printf("No elements\n");
       else
       {
       preorder(tree);
       printf("\n");
       }
     }
    else if(strcmp("post",a)==0)
    {
       if(tree==NULL)
       printf("No elements\n");
       else
       {
       postorder(tree);
       printf("\n");
       }
    }
    else if(strcmp("stop",a)==0)
            return 0;
    else
           { printf("Invalid\n"); return 0;}
}}
while(strcmp("stop",a)!=0);
return 0;
}


