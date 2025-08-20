#include<stdio.h>
#include<stdlib.h>
#include<math.h>

typedef int elemType;
typedef struct node{
    elemType data;
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
void deleteMiddleNode(no*head){
    //奇数删一个，偶数删两个
    //快慢指针
    if(head==NULL||head->next==NULL){
        return;
    }
    no*fast=head,*slow=head,*slow0=head;
    while(fast&&fast->next){
        fast=fast->next;
        fast=fast->next;
        slow0=slow;
        slow=slow->next;
    }
    if(fast==NULL){
        slow0->next=slow->next;
        free(slow);
    }
    else{
        slow0->next=slow->next;
        free(slow);
        slow=slow0->next;
        slow0->next=slow->next;
        free(slow);       
    }
    return;
}
int reverseList(no*head){
    //反转链表
    if(head==NULL){
        return 0;
    }
    no*first=NULL,*second=head->next;
    if(second==NULL){
        return 0;
    }
    no*third=second->next;
    while(second){
        second->next=first;
        first=second;
        second=third;
        if(third!=NULL){
        third=third->next;}
    }
    head->next=first;
    return 0;
}
int deleteSameNode(no*head){
    //删除绝对值相等的节点
    //空间换时间
    no*r=head->next;
    int length=0;
    while(r){
        r=r->next;
        length++;
    }
    int *p=(int*)malloc(sizeof(int)*(length+1));
    for(int i=0;i<=length;i++){
        p[i]=0;
    }
    no*q=head->next,*q0=head;
    while(q){
        if(p[abs(q->data)]==0){
            p[abs(q->data)]++;
            q=q->next;
            q0=q0->next;
        }
        else{
            q0->next=q->next;
            free(q);
            q=q0->next;
        }
    }
    free(p);
    return 0;

}
int dataFindK(no*head,int k,int *e){
    //快慢指针
    no*fast=head,*slow=fast;
    while(--k){
        if(fast==NULL||k<0){
            printf("查找位置错误\n");
            return 1;
        }
        fast=fast->next;
    }
    while(fast->next){
        fast=fast->next;
        slow=slow->next;
    }
    *e=slow->data;
    return 0;
}
no*initList(){
    no*head=(no*)malloc(sizeof(no));
    head->next=NULL;
    return head;
}
no*get_tail(no*head){
    no*p=head->next;
    if(p==NULL){
        return head;
    }
    while(p->next){
        p=p->next;
    }
    return p;
}
int insertHead(no*head,elemType e){
    no*p=(no*)malloc(sizeof(no));
    p->data=e;
    p->next=head->next;
    head->next=p;
    return 0;
}
no*insertTail(no*tail,elemType e){
    no*p=(no*)malloc(sizeof(no));
    p->data=e;
    tail->next=p;
    p->next=NULL;
    return p;
}
int insertAnywhere(no*head,int po,elemType e){
    no*p=head;
    if(po<=0){
        printf("插入位置错误\n");
        return 1;
    }
    while(--po){
        if(p){
            p=p->next;
        }
        else{
            printf("插入位置错误\n");
            return 1;
        }
    }
    no*q=(no*)malloc(sizeof(no));
    q->data=e;
    q->next=p->next;
    p->next=q;
    return 0;
}
int deleteNode(no*head,int po){
    no*p=head;
    if(po<=0){
        printf("删除位置错误\n");
        return 1;
    }
    while(--po){
        if(p->next){
            p=p->next;
        }
        else{
            printf("删除位置错误\n");
            return 1;
        }
    }
    no*q=p->next;
    p->next=q->next;
    free(q);
    return 0;
}
void listNode(no*head){
    no*p=head->next;
    while(p){
        printf("%d\n",p->data);
        p=p->next;
    }
}
int validNodeLength(no*head){
    no*p=head->next;
    int i=0;
    while(p){
        p=p->next;
        i++;
    }
    return i;
}
void freeNode(no*head){
    no*p=head->next;
    while(p){
        no*q=p->next;
        free(p);
        p=q;
    }
    free(head);
}
int main(int argc, char const *argv[])
{
    no*head=initList();
    insertHead(head,1);
    no*tail=get_tail(head);
    tail=insertTail(tail,2);
    tail=insertTail(tail,3);
    tail=insertTail(tail,4);
    tail=insertTail(tail,5);
    tail=insertTail(tail,6);
    tail=insertTail(tail,7);
    tail=insertTail(tail,8);
    listNode(head);
    printf("有效节点长度：%d\n",validNodeLength(head));
    insertAnywhere(head,4,15);
    listNode(head);
    printf("有效节点长度：%d\n",validNodeLength(head));
    deleteNode(head,6);
    listNode(head);
    printf("有效节点长度：%d\n",validNodeLength(head));
    int e;
    dataFindK(head,3,&e);
    printf("倒数第k(k=3)个数据为：%d\n",e);
    deleteMiddleNode(head);
    listNode(head);

    freeNode(head);   
    return 0;
}