#include<stdio.h>
typedef struct node{
    int data;
    struct node*next;
}no;
int isCircleList(no*head){
    if(head==NULL||head->next==NULL){
        return 0;
    }
    no*fast=head,*slow=head;
    while(fast&&fast->next){
        fast=fast->next->next;
        slow=slow->next;
        if(fast==slow){
            return 1;
        }
    }
    return 0;
}
no* findEntranceOfCircleList(no*head){
    if(isCircleList(head)==0){
        printf("链表无环结构\n");
        return NULL;
    }
    no *fast=head->next,*slow=head;
    while (fast!=slow){
        fast=fast->next->next;
        slow=slow->next;
    }
    no*p=fast->next;
    int count=1;
    while(p!=fast){
        p=p->next;
        count++;
    }
    fast=head,slow=head;
    for(int i=0;i<count;i++){
        fast=fast->next;
    }
    while(fast!=slow){
        fast=fast->next;
        slow=slow->next;
    }
    return slow;
}
int main(int argc, char const *argv[])
{
    
    return 0;
}

