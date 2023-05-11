#include<stdio.h>
#include<stdlib.h>

typedef struct node{
    int data;
    struct node* next;
}node; 

void show(node* last){
   printf("The people in the circle is:---");
    node* ptr=last->next;
    do{
        printf("%d ",ptr->data);
        ptr=ptr->next;
    }while(ptr!=last->next);
    printf("\n");
}

node* execute(node *last,node *ptr,int k){
    int t=k;
    show(last);
    node* temp;
    if(last==NULL || last->next==last){
        return last;
    }
    k--;
    while(--k){
        ptr=ptr->next;
    }
    if(ptr->next==last){
        last=ptr;
    }
    temp=ptr->next;
    printf("%d is freed\n",temp->data);
    ptr->next=temp->next;
    free(temp);
    return execute(last,ptr->next,t);
}

node* insertLast(node* last,int info){
    node* temp = (node *)malloc(sizeof(node));
    temp->data=info;
    if(last!=NULL){
        temp->next = last->next;
        last->next =temp;
        last = last->next;
    }else{
        temp->next=temp;
        last=temp;
    }
    return last;
}

node* createCircle(node* last,int number){
   //printf("enter the positions\n");
    //int people_id;
    int i=1;
    while(number--){
       // scanf("%d",&people_id);
        last = insertLast(last,i++);
    }
    return last;
}

void reverseList( node **head) 
{
    // Temporary helper variables
     node *prev, *cur, *next, *last;

    // Cannot reverse empty list
    if (*head == NULL)
    {
        printf("Cannot reverse empty list.\n");
        return;
    }


    // Head is going to be our last node after reversing list
    last = *head;

    prev  = *head;
    cur   = (*head)->next;
    *head = (*head)->next;

    // Iterate till you reach the initial node in circular list
    while (*head != last)
    {
        *head = (*head)->next;
        cur->next = prev;

        prev = cur;
        cur  = *head;
    }

    cur->next = prev;
    *head = prev;       // Make last node as head
}


int main(){
    node *last = NULL;
    printf("Enter the  number of people \n");
    int number;
    scanf("%d",&number);
    last = createCircle(last,number);
    printf("enter the specified number of people\n");
    int k;
    scanf("%d",&k);
    int choice ;
    printf("Enter 1 for clockwise and 0 for anti clockwise\n");
    scanf("%d",&choice);
    //reverseList(&last);
    if(choice)
    last = execute(last,last->next,k);
    else 
       last = execute(last,last->next,number-k);
    printf("The last person to freed is ---");
    printf("%d\n",last->data);
    return 0;
}

