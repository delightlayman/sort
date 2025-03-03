#pragma once
#include <stdio.h>
#include <assert.h>
#include <stdlib.h>
#include <time.h>//time(),clock()
#include <stdbool.h>
//打印
void PrintValues(int *arr,int size);
//生成随机数数组
int * GenerateArray(int size);
//交换
void swap(int* a,int* b);
//顺序判定---升序 ascending order 降序descending order
bool isAscendingOrder(int *arr,int size);

//插入排序--数组--升序
void InsertSort(int *a,int size);
//希尔排序--升序
void SeeleSort_Respectively(int *a,int size);
void SeeleSort(int *a,int size);

//选择排序
void SelectSort(int *a,int size);
//堆排序
void AdjustDown(int *a,int size,int root);
void HeapBuilt(int *a,int size);
void HeapSort(int *a,int size);

//冒泡排序
void BubbleSort(int *a,int size);
//三数取中
int GetMidIndex(int *a,int begin,int end); 

//注意返回 分界值下标
//左右指针法
int QPartSort_LR(int *a,int begin,int end);
//挖坑法
int QPartSort_Pit_Swap(int *a,int begin,int end);
int QPartSort_Pit_Assign(int *a,int begin,int end);
//前后指针法
int QPartSort_FB(int *a,int begin,int end);
//快速排序---递归
void QuickSort_REC(int *a,int begin,int end);
//快速排序---非递归
void QuickSort(int *a,int begin,int end);



//计数排序
void CountSort(int *a,int size);
//基数排序
void BaseSort(int *a,int size);
//桶排序
void BocketSort(int *a,int size);


