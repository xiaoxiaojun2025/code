#include<stdio.h>
#include<stdlib.h>
typedef struct node{
    struct node *prev,*next;
    int data;
}no;
void insertHead(no*head,int e){
    no*p=(no*)malloc(sizeof(no));
    p->data=e;
    p->prev=head;
    p->next=head->next;
    if(head->next!=NULL){
        head->next->prev=p;
        head->next=p;
    }
    return;
}
no* insertTail(no*tail,int e){
    no*p=(no*)malloc(sizeof(no));
    p->data=e;
    tail->next=p;
    p->prev=tail;
    p->next=NULL;
    return p;
}