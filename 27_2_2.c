#include<stdio.h>
#include<stdlib.h>

typedef struct node{
    int coeff;
    int exp;
    struct node* next;
}node;

node* add(node*,node* );
node* sub(node*,node* );
node* multiply(node*,node* );
void show(node*);
node* create(int);
node* insert(node *,int c,int );


int main()

{
    int choice,size,flag=1;
    node *poly1,*poly2,*result;
    do{
printf("\n1> enter 1 for creating  polynomials.\n2>enter 2 for showing the polynomials.\n3>Enter 3 for adding polynomials.\n4>enter 4 for subtracting polynomials.\n5>Enter 5 for multiplying polynomials.\nAny other key to exit.\n");
        printf("Enter Your choice:- ");
        scanf("%d",&choice);
        switch(choice){
            case 1:
                printf("Enter the size of the First polynomial:- ");
                scanf("%d",&size);
                poly1=create(size);
                printf("Enter the size of the Second polynomial:- ");
                scanf("%d",&size);
                poly2=create(size);
                break;
            case 2:
                printf("The first polynomial is -\n");
                show(poly1);
                printf("The second polynomial is -\n");
                show(poly2);
                break;
            case 3:
                result=add(poly1,poly2);
                printf("After addition the result is -\n");
                show(result);
                break;
            case 4:
                result=sub(poly1,poly2);
                printf("After subtraction the result is -\n");
                show(result);
                break;
            case 5:
                result=multiply(poly1,poly2);
                printf("After multiplication the result is -\n");
                show(result);
                break;
            default:
                flag=0;
        }
    }while(flag);
    return 0;
}


node* insert(node *head,int coeff,int exp)
{
    node *temp,*ptr;
    ptr = head;
    temp=(node *)malloc(sizeof(node));
    temp->coeff = coeff;
    temp->exp = exp;
    temp->next = NULL;
    if(ptr==NULL){
        head = temp;
    }else{
        while(ptr->next!=NULL){
            ptr=ptr->next;
        }
        ptr->next=temp;
    }
    return head;
}


node* add(node* p1,node* p2){
    node *ptr1,*ptr2,*temp,*p3;
    ptr1 = p1;
    ptr2 = p2;
    p3=NULL;
    while(ptr1!=NULL && ptr2!=NULL){
        if(ptr1->exp > ptr2->exp){
            p3 = insert(p3,ptr1->coeff,ptr1->exp);
            ptr1 = ptr1->next;
        }else if(ptr2->exp > ptr1->exp){
            p3 = insert(p3,ptr2->coeff,ptr2->exp);
            ptr2 = ptr2->next;
        }else{
            p3 = insert(p3,ptr1->coeff+ptr2->coeff,ptr1->exp);
            ptr1 = ptr1->next;
            ptr2 = ptr2->next;
        }
    }
    while(ptr1!=NULL){
        p3 = insert(p3,ptr1->coeff,ptr1->exp);
        ptr1 = ptr1->next;
    }
    while(ptr2!=NULL){
        p3 = insert(p3,ptr2->coeff,ptr2->exp);
        ptr2 = ptr2->next;
    }
    return p3;
}

node* sub(node* p1,node* p2){
    node *ptr1,*ptr2,*temp,*p3;
    ptr1 = p1;
    ptr2 = p2;
    p3=NULL;
    while(ptr1!=NULL && ptr2!=NULL){
        if(ptr1->exp > ptr2->exp){
            p3 = insert(p3,ptr1->coeff,ptr1->exp);
            ptr1 = ptr1->next;
        }else if(ptr2->exp > ptr1->exp){
            p3 = insert(p3,-ptr2->coeff,ptr2->exp);
            ptr2 = ptr2->next;
        }else{
            p3 = insert(p3,ptr1->coeff-ptr2->coeff,ptr1->exp);
            ptr1 = ptr1->next;
            ptr2 = ptr2->next;
        }
    }
    while(ptr1!=NULL){
        p3 = insert(p3,ptr1->coeff,ptr1->exp);
        ptr1 = ptr1->next;
    }
    while(ptr2!=NULL){
        p3 = insert(p3,ptr2->coeff,ptr2->exp);
        ptr2 = ptr2->next;
    }
    return p3;
}

node* multiply(node* p1,node* p2){
    node *p3,*ptr1,*ptr2,*temp;
    ptr1 = p1;
    p3=NULL;
    while(ptr1!=NULL){
        ptr2 = p2;
        while(ptr2!=NULL){
            temp=(node *)malloc(sizeof(node));
            temp->coeff = ptr1->coeff * ptr2->coeff;
            temp->exp = ptr1->exp + ptr2->exp;
            temp->next = NULL;
            p3 = add(p3,temp);
            ptr2=ptr2->next;
        }
        ptr1=ptr1->next;
    }
    return p3;
}

void show(node *head){
   node *ptr = head;
   printf("%dX^%d ",ptr->coeff,ptr->exp);
   ptr = ptr->next;
   while (ptr)
   {    
        if(ptr->coeff<0)
            printf("%dX^%d ",ptr->coeff,ptr->exp);
        else if(ptr->coeff>0)
            printf("+%dX^%d ",ptr->coeff,ptr->exp);
        ptr = ptr->next;
   }
    printf("\n");
}

node* create(int size){
    int coeff,exp;
    node* head=NULL;
    for(int i=0;i<size;i++){
        printf("Enter the Coefficient :- ");
        scanf("%d",&coeff);
        printf("Enter the exponent :- ");
        scanf("%d",&exp);
        head = insert(head,coeff,exp);
    }
    return head;
}


