#include<stdio.h>
#include<stdlib.h>
typedef struct queueNode{
    int data;
    struct queueNode *next;
}queueNode;
typedef struct queue{
    queueNode*front;
    queueNode*rear;
}queue;
queueNode*initQueue(queue*s){
    queueNode*head=(queueNode*)malloc(sizeof(queueNode));
    queue*p=(queue*)malloc(sizeof(queue));
    head->next=NULL;
    p->front=head;
    p->rear=head;
    s=p;
    return head;
}
int appendQueue(queueNode*head,queue*s,int e){
    queueNode*p=(queueNode*)malloc(sizeof(queueNode));
    p->data=e;
    s->rear->next=p;
    p->next=NULL;
    s->rear=s->rear->next;
    return 1;
}
int outOfQueue(queueNode*head,queue*s){
    if(s->front==s->rear){
        printf("队列是空的\n");
        return 0;
    }
    queueNode*p=head->next;
    if(p==s->rear){
        s->rear=s->front;
    }
    head->next=p->next;
    free(p);
    return 1;
}
int main(int argc, char const *argv[])
{
    
    return 0;
}
