#include<stdio.h>
#include<stdlib.h>

typedef struct node{
    struct node* prev;
    int data;
    struct node* next;
}node; 

void show(node* head){
printf("The people in the circle is:---");
    node* ptr=head;
    do{
        printf("%d ",ptr->data);
        ptr=ptr->next;
    }while(ptr!=head);
    printf("\n");
}

node* execute(node *head,node *ptr,int k,int ch){
    int t=k;
    show(head);
    
    node* temp;
    if(head==NULL || head->next==head){
        return head;
    }
    if(ch)
    {
    k--;
    while(--k){
        ptr=ptr->next;
    }
    temp=ptr->next;
    ptr->next=temp->next;
    temp->next->prev=ptr;
    if(head==temp){
        head = ptr->next;
    }
    printf("%d is freed\n",temp->data);
    free(temp);
    return execute(head,ptr->next,t,ch);}
    else
    {k--;
    while(--k){
        ptr=ptr->prev;
    }
    temp=ptr->prev;
    ptr->prev=temp->prev;
    temp->prev->next=ptr;
    if(head==temp){
        head = ptr->prev;
    }
    printf("%d is freed\n",temp->data);
    free(temp);
    return execute(head,ptr->prev,t,ch);}
}

node* insertLast(node* head,int info){
    node* temp = (node *)malloc(sizeof(node));
    temp->data=info;
    if(head==NULL){
        temp->next=temp;
        temp->prev=temp;
        head = temp;
        return head;
    }
    node* ptr = head;
    while(ptr->next!=head)
        ptr = ptr->next;
    ptr->next->prev = temp;
    temp->next=ptr->next;
    ptr->next=temp;
    temp->prev=ptr;
    return head;
}

node* createCircle(node* head,int number){
    int people_id=1;
    while(number--){
        
        head = insertLast(head,people_id++);
    }
    return head;
}

int main(){
    node *head = NULL;
    printf("Enter the  number of people \n");
    int number;
    scanf("%d",&number);
    head = createCircle(head,number);
    node* ptr = head;
     printf("enter the specified number of people\n");
    int k;
    scanf("%d",&k);
    int choice ;
    printf("Enter 1 for clockwise and 0 for anti clockwise\n");
    scanf("%d",&choice);
    head = execute(head,ptr,k,choice);
     printf("The last person to freed is ---");
     printf("%d\n",head->data);
    return 0;
}

