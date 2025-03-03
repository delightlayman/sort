#include "stack.h"
//打印
void Printval(Stack* s){
    if(isEmptyStack(s)){
        printf("stack无存储");
        return;
    }
        
    for(int i=0;i<s->size;i++){
        printf("%d ",s->arr[i]);
        if(i&&i%10==0)
            printf("\n");    
    }

    printf("\n");
}

//初始化与摧毁
void StackInit(Stack* s){
    assert(s);
    s->arr=(SDataType*)malloc(sizeof(SDataType)*10);
    s->size=0;
    s->capacity=10;
}
void StackDEst(Stack* s){
    assert(s);
    free(s->arr);
    s->size=0;
    s->capacity=0;
}
//增删
void StackPush(Stack* s,SDataType val){
    assert(s);
    if(isFullStack(s)){
        s->capacity*=2;
        SDataType* temp=(SDataType*)realloc(s->arr,sizeof(SDataType)*s->capacity);
        s->arr=temp;
    }
    s->arr[s->size++]=val;
}
void StackPop(Stack* s){
    assert(s);
    s->size--;
}


//空？
bool isEmptyStack(Stack* s){
    assert(s);
    return s->size==0;
}
//满？
bool isFullStack(Stack* s){
    assert(s);
    return s->size==s->capacity;
}

//栈顶值
SDataType StackTop(Stack* s){
    assert(s);
    return s->arr[s->size-1];
}

//栈大小
int StackSize(Stack* s){
    assert(s);
    return s->size;
}