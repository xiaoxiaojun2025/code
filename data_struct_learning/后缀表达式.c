#include<stdio.h>
#include<stdlib.h>
typedef struct stack{
    int data;
    struct stack*next;
}st;
typedef enum judgment{
    NUM,ADD,SUB,MUL,DIV,REM,ERROR
}ju;
ju judge(char e){
if(e>='0'&&e<='9'){
    return NUM;
}
else if(e=='+'){
    return ADD;
}
else if(e=='-'){
    return SUB;
}
else if(e=='*'){
    return MUL;
}
else if(e=='/'){
    return DIV;
}
else if(e=='%'){
    return REM;
}
else{
    return ERROR;
}
}
st*init(){
    st*head=(st*)malloc(sizeof(st));
    head->next=NULL;
    return head;
}
int appendStack(st*head,int e){
    st*p=(st*)malloc(sizeof(st));
    if(p==NULL){
        return 0;
    }
    p->data=e;
    p->next=head->next;
    head->next=p;
    return 1;
}
int outOfStack1(st*head){
    if(head->next==NULL){
        printf("No data on the top of stack.\n");
        return -1;
    }
    st*p=head->next;
    int e=p->data;
    head->next=p->next;
    free(p);
    return e;
}
int free_stack(st*head){
    st*p=head,*q=p->next;
    while(q!=NULL){
        p->next=q->next;
        free(q);
        q=p->next;
    }
    free(p);
    return 1;
}
int arithmetic_unit(st*head,char*p){
    int num1,num2;
    while(*p!='\0'){
        switch (judge(*p))
        {
        case NUM:
            appendStack(head,*p-'0');
            break;
        case ADD:
            num2=outOfStack1(head);
            num1=outOfStack1(head);
            appendStack(head,num1+num2);
            break;
        case SUB:
            num2=outOfStack1(head);
            num1=outOfStack1(head);
            appendStack(head,num1-num2);
            break;
        case MUL:
            num2=outOfStack1(head);
            num1=outOfStack1(head);
            appendStack(head,num1*num2);
            break;
        case DIV:
            num2=outOfStack1(head);
            num1=outOfStack1(head);
            if(num2==0){
                printf("error\n");
                return -1;
                break;
            }
            appendStack(head,num1/num2);
            break;
        case REM:
            num2=outOfStack1(head);
            num1=outOfStack1(head);
            if(num2==0){
                printf("error\n");
                return -1;
            }
            appendStack(head,num1%num2);
            break;                    
        default:
            printf("error.\n");
            return -1;
            break;
        }
        p++;
    }
int result=outOfStack1(head);
if(head->next==NULL){
    return result;
}
printf("error.\n");
return -1;
}
int main(int argc, char const *argv[])
{
    st*head=init();
    char a[100];
    scanf("%s",a);
    printf("The result of %s is %d.\n",a,arithmetic_unit(head,a));
    free_stack(head);
    return 0;
}
