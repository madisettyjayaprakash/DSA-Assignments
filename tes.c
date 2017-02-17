#include <stdio.h>
#include<stdlib.h> 
 
struct node {
    long long int v;
    long long int f;
    struct node*next;
    
};
struct node*a[50000];
long long int b[50000];
long long int c[50000];
 
 void insert(struct node*head,struct node*newnode){
     struct node*current;
     printf("Hi");
    if(head->next->f <= newnode->f||head->next==NULL){
        newnode->next=head->next;
         head->next=newnode;
         printf("%lld ",head->next->f); 
         
     }
     else{
         current=head;
          while(current->next!=NULL&&current->next->f > newnode->f){
              current=current->next;
          }
          newnode->next=current->next;
          current->next=newnode;
          
         
         
     }
     
     
 }


int main(void) {
	long long int t,i,j,k,n,p,x,m,r,m1,r1;
	
	scanf("%lld",&t);
	while(t--){
	    scanf("%lld",&n);
	    for(i=1;i<=n;i++){
	    scanf("%lld",&b[i]);
	    c[i]=i;
	    a[i]=(struct node*)malloc(sizeof(struct node));
	    a[i]->next=NULL;
	    }
	    p=n-1;
	   
	    while(p--){
	   
	        scanf("%lld %lld",&m,&r);
	    
	       printf("Hi");
	        struct node *newnode; 
	         newnode=(struct node*)malloc(sizeof(struct node));

	         newnode->v=m;
	         newnode->f=b[m];
	         newnode->next=NULL;
	         
           insert(a[m],newnode);
                 
            newnode=(struct node*)malloc(sizeof(struct node));
	         newnode->v=r;
	         newnode->f=b[r];
            newnode->next=NULL;
           insert(a[r],newnode);
	        
	   
	    }
	  /* for(i=1;i<=n;i++){
	       for(j=i+1;j<=n;j++){
	           if(b[i]<b[j]){
	               k=b[i];
	               b[i]=b[j];
	               b[j]=k;
	               k=c[i];
	               c[i]=c[j];
	               c[j]=k;
	           }
	       }
	   }*/
	  
	struct node*gh;
	
	 for(i=1;i<=n;i++){
	     gh=a[i]->next;
	     while(gh!=NULL){
	         printf("%lld ",gh->f);
	         gh=gh->next;
	     }
	     printf("\n");
	 }
	   
	   
	   
	    
	  /*  for(i=1;i<=n;i++){
	      
	         
	             for(j=1;j<=n;j++){
	                 k=0;
	                struct node*gh=a[i];
	                  while(gh!=NULL){
	                   if(gh->v==c[j]){
	                     k=1;    
	                     break;
	                  }
	                  gh=gh->next;
	             }
	             if(k==0){
	                 k=c[j];
	              break;
	              
	             }
	              
	          }
	         printf("%lld ",k);
	          
	           }
	    printf("\n");
	    */
	    
	    
	    
	    
	}
	
	return 0;
}
