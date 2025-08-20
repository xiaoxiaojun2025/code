#include<stdio.h>
#include<stdlib.h>
#define MAX 100
typedef struct stack{
    int *data;
    int top;
}st;
typedef struct stack1{
    int data;
    struct stack1*next;
}st1;
st1*initStack1(){
    st1*head=(st1*)malloc(sizeof(st1));
    head->next=NULL;
    return head;
}
int appendStack1(st1*head,int e){
    st1*p=(st1*)malloc(sizeof(st1));
    if(p==NULL){
        return 0;
    }
    p->data=e;
    p->next=head->next;
    head->next=p;
    return 1;
}
int OutOfStack1(st1*head){
    if(head->next==NULL){
        printf("栈顶无元素\n");
        return 0;
    }
    st1*p=head->next;
    head->next=p->next;
    free(p);
    return 1;
}
int peekStack(st1*head){
    if(head->next==NULL){
        printf("栈顶无元素\n");
        return 0;
    }
    printf("%d\n",head->next->data);
    return 1;
}
st* initStack(){
    st*s=(st*)malloc(sizeof(st));
    s->data=(int*)malloc(sizeof(int)*MAX);
    s->top=-1;
    return s;
}
void appendStack(st*s,int e){
    if(s->top>=MAX-1){
        printf("栈满了\n");
        return;
    }
    s->top++;
    s->data[s->top]=e;
}
void outOfStack(st*s){
    if(s->top==-1){
        printf("栈是空的\n");
        return;
    }
    s->top--;
}
void freeStack(st*s){
    free(s->data);
    free(s);
}
void findTopOfStack(st*s){
    if(s->top==-1){
        printf("栈是空的\n");
        return ;
    }
    printf("%d\n",s->data[s->top]);
    return;
}

int main(int argc, char const *argv[])
{
    st*s=initStack();
    appendStack(s,10);
    appendStack(s,20);
    appendStack(s,30);
    appendStack(s,40);
    appendStack(s,50);
    findTopOfStack(s);
    outOfStack(s);
    findTopOfStack(s);
    freeStack(s);
    return 0;
}
