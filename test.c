#include "sort.h"

#define arrsize 10000000

void test_seele(){
    int *arr=GenerateArray(arrsize);
    int begin=clock();
    SeeleSort(arr,arrsize);
    int end=clock();
    //PrintValues(arr,arrsize);
    printf("\n%s time = %d","SeeleSort",end-begin);
}

void test_insert(){
    int *arr=GenerateArray(arrsize);

    int begin=clock();
    InsertSort(arr,arrsize);
    int end=clock();
    //PrintValues(arr,arrsize);
    printf("\n%s time = %d","InsertSort",end-begin);
}

void test_select(){
    int *arr=GenerateArray(arrsize);
    int begin=clock();
    SelectSort(arr,arrsize);
    int end=clock();
    //PrintValues(arr,arrsize);
    printf("\n%s time = %d","SelectSort",end-begin);
}

void test_heap(){
    int *arr=GenerateArray(arrsize);
    int begin=clock();
    HeapSort(arr,arrsize);
    int end=clock();
    //PrintValues(arr,arrsize);
    printf("\n%s time = %d","HeaSort",end-begin);
}


int main(){
    // InsertSort(arr,10);
    // SeeleSort(arr,10);
    // PrintValues(arr,10);
    test_seele();
    test_insert();
    test_select();
    test_heap();
}