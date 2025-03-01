#pragma once
#include <stdio.h>
#include <assert.h>
#include <stdlib.h>
#include <time.h>//time(),clock()
//打印
void PrintValues(int *arr,int size);
//生成随机数数组
int * GenerateArray(int size);

//插入排序--数组--升序
void InsertSort(int *a,int size);
//希尔排序--升序
void SeeleSort_Respectively(int *a,int size);
void SeeleSort(int *a,int size);

//选择排序
void SelectSort(int *a,int size);
//堆排序
void AdjustDown(int *a,int size,int root);
void HeapSort(int *a,int size);

//冒泡排序
void BubbleSort(int *a,int size);
//快速排序
void QuickSort(int *a,int size);


