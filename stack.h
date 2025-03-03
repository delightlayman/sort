#pragma once
#include <stdio.h>
#include <stdbool.h>
#include <assert.h>
#include <stdlib.h>
#include <time.h>
typedef int (*SDataType)[2];
typedef struct stack{
    SDataType* arr;
    int size;
    int capacity;
}Stack;

//打印
void Printval(Stack* s);

//初始化与摧毁
void StackInit(Stack* s);
void StackDEst(Stack* s);
//增删  用不上查改
void StackPush(Stack* s,SDataType val);
void StackPop(Stack* s);
// int StackFind(Stack* s,int val);
// int StackModi(Stack* s,int pos,int val);

//空？
bool isEmptyStack(Stack* s);
//满？
bool isFullStack(Stack* s);

//栈顶值
SDataType StackTop(Stack* s);

//栈大小
int StackSize(Stack* s);
