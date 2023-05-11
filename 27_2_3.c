#include<stdio.h>
#include<stdlib.h>

typedef struct node{
    struct node* prev;
    int info;
    struct node* next;
}node;
node* insert_at_end(node* ,int );
node* insert_at_front(node* ,int );
node* insert_after(node* ,int ,int);
node* insert_before(node* ,int ,int );
node* insert_after_k(node* ,int ,int );
node* insert_before_k(node* ,int ,int );
node* create(node* ,int );
void print(node* );
node* reverse(node* );
node* delete_first(node* );
node* delete_last(node* );
node* delete_first_occurrence(node* ,int );
node* delete_k(node* ,int );
node* delete_before_k(node* ,int );
node* delete_after_k(node* ,int );

int main(){

	int choice,k,size,info,skey;
        node *head1,*head2;
        head1=NULL;  
	do{
   	printf("Enter\n1>To create a list.\n2>To print the list.\n3>To insert an element in the front.\n4>To insert an element at the end.\n5>To insert a node after k th node.\n6>To insert a node after given value.\n7>To insert a node before k th node.\n8>To insert a node before given value.\n9>To delete the first node.\n10>To delete the last node.\n11>To delete after k the node.\n12>To delete before k the node.\n13>To delete the k th node.\n14>To delete a node by value.\n15>To reverse the list.\n16>To EXIT.\n");
        
	    printf("Enter Your choice:- ");
        scanf("%d",&choice);
        switch(choice){
            case 1:
                printf("Enter the initial size:- ");
                scanf("%d",&size);
                printf("Enter the elements:- ");	
                head1 = create(head1,size);
                break;
            case 2:
                print(head1);
                break;
            case 3:
                printf("Enter the value of data of the inserted node:- ");
                scanf("%d",&info);
                head1=insert_at_front(head1,info);
                break;
            case 4:
                printf("Enter the value of data of the inserted node:- ");
                scanf("%d",&info);
                head1=insert_at_end(head1,info);
                break;
            case 5:
                printf("Enter the value of k:- ");
                scanf("%d",&k);
                printf("Enter the value of data of the inserted node:- ");
                scanf("%d",&info);
                head1 = insert_after_k(head1,info,k);
                break;	
            case 6:
                printf("Enter the value of data of the inserted node:- ");
                scanf("%d",&info);
                printf("Enter the value after which the node will be inserted:- ");
                scanf("%d",&skey);
                head1=insert_after(head1,info,skey);
                break;
            case 7:
                printf("Enter the value of k:- ");
                scanf("%d",&k);
                printf("Enter the value of data of the inserted node:- ");
                scanf("%d",&info);
                head1 = insert_before_k(head1,info,k);
                break;
            case 8:
                printf("Enter the value of data of the inserted node:- ");
                scanf("%d",&info);
                printf("Enter the value after which the node will be inserted:- ");
                scanf("%d",&skey);
                head1=insert_before(head1,info,skey);
                break;
            case 9:
                head1=delete_first(head1);
                break;
            case 10:
                head1=delete_last(head1);
                break;
            case 11:
                printf("Enter the value of k:- ");
                scanf("%d",&k);
                head1=delete_after_k(head1,k);
                break;	
            case 12:
                printf("Enter the value of k:- ");
                scanf("%d",&k);
                head1 = delete_before_k(head1,k);
                break;
            case 13:
                printf("Enter the value of k:- ");
                scanf("%d",&k);
                head1=delete_k(head1,k);
                break;
            case 14:
                printf("Enter the value of of the node to be deleted:- ");
                scanf("%d",&info);
                head1=delete_first_occurrence(head1,info);
                break;
            case 15:
                head1 = reverse(head1);
                break;
            case 16:
                break;			
            default:
                printf("Wrong Choice.\n");	
        }
	}while(choice!=21); 
    return 0;
}




node* insert_at_end(node* head,int data){
    node* temp=(node *)malloc(sizeof(node));
    temp->info=data;
    temp->next=NULL;
    if(head==NULL){
        temp->prev=NULL;
        head=temp;
        return head;
    }
    node* ptr=head;
    while(ptr->next!=NULL){
        ptr=ptr->next;
    }
    ptr->next=temp;
    temp->prev=ptr;
    return head;
}

node* insert_at_front(node* head,int data){
    node* temp=(node *)malloc(sizeof(node));
    temp->info=data;
    temp->prev=NULL;
    temp->next=head;
    if(head!=NULL)
        head->prev=temp;
    head=temp;
    return head;
}

node* insert_after(node* head,int skey,int data){
    node *ptr,*temp;
    ptr=head;
    while(ptr!=NULL){
        if(ptr->info==skey){
            temp=(node *)malloc(sizeof(node));
            temp->info=data;
            temp->next=ptr->next;
            temp->prev=ptr;
            if(ptr->next!=NULL)
                ptr->next->prev=temp;
            ptr->next=temp;    
            return head;
        }
        ptr=ptr->next;
    }
    return head;
}
node* insert_before(node* head,int skey,int data){
    node *ptr,*temp;
    ptr=head;
    while(ptr!=NULL){
        if(ptr->info==skey){
            if(ptr==head){
                return insert_at_front(head,data);
            }
            temp=(node *)malloc(sizeof(node));
            temp->info=data;
            temp->next=ptr;
            temp->prev=ptr->prev;
            if(ptr->prev!=NULL)
                ptr->prev->next=temp;
            ptr->prev=temp;    
            return head;
        }
        ptr=ptr->next;
    }
    return head;
}

node* insert_after_k(node* head,int data,int k){
    node *ptr,*temp;
    ptr=head;
    for(int i=0;i<k-1;i++){
        ptr=ptr->next;
    }
    temp=(node *)malloc(sizeof(node));
    temp->info=data;
    temp->next=ptr->next;
    temp->prev=ptr;
    if(ptr->next!=NULL)
        ptr->next->prev=temp;
    ptr->next=temp;    
    return head;
}

node* insert_before_k(node* head,int data,int k){
    node *ptr,*temp;
    ptr=head;
    if(k==1){
        return insert_at_front(head,data);
    }
    return insert_after_k(head,k-1,data);
}

node* create(node* head,int size){
    int data;
    for(int i=0;i<size;i++){

        scanf("%d",&data);
        head=insert_at_end(head,data);
    }
    return head;
}


void print(node* head){
    node *ptr=head;
    while(ptr!=NULL){
        printf("%d ",ptr->info);
        ptr=ptr->next;
    }
    printf("\n");
}

node* reverse(node* head){
    node *prev,*ptr,*next;
    ptr=head;
    prev=NULL;
    while(ptr!=NULL){
        next=ptr->next;
        ptr->next=prev;
        ptr->prev=next;
        prev=ptr;
        ptr=next;
    }
    return prev;
}

node* delete_first(node* head){
    if(head==NULL){
        return head;
    }
    node* temp=head;
    if(temp->next!=NULL)
        temp->next->prev=NULL;
    head=temp->next;
    free(temp);
    return head;
}

node* delete_last(node* head){
    if(head==NULL){
        return head;
    }
    node* ptr=head;
    while(ptr->next!=NULL){
        ptr=ptr->next;
    }
    if(ptr==head){
        head=NULL;
    }else{
        ptr->prev->next=NULL;
    }
    return head;
}

node* delete_first_occurrence(node* head,int val){
    node *ptr,*temp;
    ptr=head;
    while(ptr!=NULL){
        if(ptr->info==val){
            temp=ptr;
            if(ptr==head){
                ptr->next->prev=NULL;
                head=ptr->next;
            }else{
                ptr->prev->next=ptr->next;
                ptr->next->prev=ptr->prev;
            }
            free(temp);
            return head;
        }
        ptr=ptr->next;
    }
    return head;
}

node* delete_k(node* head,int k){
 	node* ptr=head;
    for(int i=0;i<k-1;i++){
        ptr=ptr->next;
    }
    if(ptr==head){
        return delete_first(head);
    }
    ptr->prev->next=ptr->next;
    if(ptr->next!=NULL)
        ptr->next->prev=ptr->prev;
    free(ptr);
    return head;
}

node* delete_before_k(node* head,int k){
 	return delete_k(head,k-1);
}
node* delete_after_k(node* head,int k){
 	return delete_k(head,k+1);
}
