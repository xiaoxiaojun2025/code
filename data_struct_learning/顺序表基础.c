#include<stdio.h>
#include<stdlib.h>
#define MAX 100
typedef int elemType;
typedef struct{
    elemType*data;
    int length;
}seqlist;
seqlist* initList(){
    seqlist*l=(seqlist*)malloc(sizeof(seqlist));
    if(l==NULL){
        printf("初始化失败\n");
        free(l);
        return NULL;
    }
    l->data=(elemType*)malloc(sizeof(elemType)*MAX);
    if(l->data==NULL){
        printf("初始化失败\n");
        free(l->data);
        return NULL;
    }
    l->length=0;
    return l;
}
int append(seqlist*l,elemType e){
    l->data[l->length]=e;
    l->length++;
    return 0;
}
int listElem(seqlist*l){
    for(int i=0;i<l->length;i++){
        printf("%d ",l->data[i]);
    }
    printf("\n");
    return 0;
}
int insertElem(seqlist*l,int po,elemType e){
    if(po>0&&po<=l->length+1){
        for(int i=l->length;i>=po;i--){
            l->data[i]=l->data[i-1];
        }
        l->data[po-1]=e;
        l->length++;
        return 0;
    }
    printf("插入位置错误\n");
    return 1;
}
int deleteElem(seqlist*l,int po,elemType*e){
    if(po>0&&po<=l->length){
        *e=l->data[po-1];
        for(int i=po-1;i<l->length;i++){
            l->data[i]=l->data[i+1];

        }
        l->length--;
        return 0;
    }
    printf("删除位置错误\n");
    return 1;
}
int findElem(seqlist*l,elemType e,int *po){
    for(int i=0;i<l->length;i++){
        if(l->data[i]==e){
            *po=i+1;
            return 0;
        }
    }
    printf("未查找到对应元素\n");
    return 1;
}
void freeList(seqlist*l){
    free(l->data);
    free(l);
}
  
int main(int argc, char const *argv[]){
    seqlist*L=initList();
    append(L,20);append(L,78);append(L,3278);append(L,38);append(L,13);append(L,9);
    int deleteData,findData;
    insertElem(L,3,77);
    deleteElem(L,4,&deleteData);
    findElem(L,13,&findData);
    listElem(L);
    printf("当前数据内存块字节数%d\n当前顺序表长度%d\n删除数据为:%d\n查找元素序号为%d\n",sizeof(elemType)*MAX,
            L->length,deleteData,findData);
    freeList(L);
}