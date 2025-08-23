#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int strcatc(char*s,char c){
    int len=strlen(s);
    s[len]=c;
    s[len+1]='\0';
    return 1;
}
typedef struct stack{
    char data;
    struct stack*next;
}st;
typedef enum{
    ADD=0,SUB,MUL,DIV,MOD,
    LEFT_BRACKET,
    RIGHT_BRACKET,
    NUM,
    SPACE,
    ERROR,
}judge;
int priority_in_stack[]={1,1,2,2,2,0};
int priority_out_of_stack[]={1,1,2,2,2,4};
st*init(){
    st*head=(st*)malloc(sizeof(st));
    head->next=NULL;
    return head;
}
char pop(st*head){
    if(head->next==NULL){
        return '!';
    }
    st*p=head->next;
    char e=p->data;
    head->next=p->next;
    free(p);
    return e;
}
char peek(st*head){
    if(head==NULL||head->next==NULL){
        return '!';
    }
    return head->next->data;
}
int push(st*head,char e){
    st*p=(st*)malloc(sizeof(st));
    if(p==NULL){
        return 0;
    }
    p->data=e;
    p->next=head->next;
    head->next=p;
    return 1;
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
judge judgement(char e){
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
    return MOD;
}
else if (e=='(')
{
    return LEFT_BRACKET;
}
else if(e==')'){
    return RIGHT_BRACKET;
}
else if(e==' '){
    return SPACE;
}
else{
    return  ERROR;

}
}
int arithmetic_unit(st*head,char*p,char*s){
    strcpy(s,"");

    while(*p!='\0'){
        judge m=judgement(*p);
        switch (m)
        {
        case NUM:
            {
                char str[20]="";
                while(1){
                if(judgement(*p)!=NUM){
                    strcatc(str,' ');
                    strcat(s,str);
                    break;
                }
                else{
                    strcatc(str,*p);
                }
                p++;
            }
            p--;
            break;}
        case SPACE:
            break;
        case ADD:
        case SUB:
        case MUL:
        case DIV:
        case MOD:
        case LEFT_BRACKET:
            while(1){
                judge n=judgement(peek(head));
                if(peek(head)!='!'&& priority_out_of_stack[m]<=priority_in_stack[n]){
                    strcatc(s,pop(head));
                }
                else{
                    push(head,*p);
                    break;
                }
            }
            break;
        case RIGHT_BRACKET:
            while(1){
                if(peek(head)!='('){
                    strcatc(s,pop(head));
                }
                if(peek(head)=='('){
                    pop(head);
                    break;
                }
                if(peek(head)=='!'){
                    printf("input error.\n");
                    return 0;
                    break;
                }
            }
            break;
        default:
            printf("error.\n");
            return 0;
            break;
        }
    p++;
    }
    while(peek(head)!='!'){
        strcatc(s,pop(head));
    }
    return 1;
}

int main(void)
{
    char a[100],s[100]="";
    if (fgets(a, sizeof(a), stdin) == NULL) {
    printf("Input error\n");
    return 1;
}
    a[strcspn(a, "\n")] = '\0';
    st*head=init();

    arithmetic_unit(head,a,s);
    printf("%s\n",s);
    free_stack(head);
    return 0;
}
