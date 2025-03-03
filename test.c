#include "sort.h"

#define arrsize 1000000

void test_seele(){
    int *arr=GenerateArray(arrsize);
    int begin=clock();
    SeeleSort(arr,arrsize);
    int end=clock();
    //PrintValues(arr,arrsize);
    printf("\n%s time = %d","SeeleSort",end-begin);
    free(arr);
}

void test_insert(){
    int *arr=GenerateArray(arrsize);

    int begin=clock();
    InsertSort(arr,arrsize);
    int end=clock();
    //PrintValues(arr,arrsize);
    printf("\n%s time = %d","InsertSort",end-begin);
    free(arr);

}

void test_select(){
    int *arr=GenerateArray(arrsize);
    int begin=clock();
    SelectSort(arr,arrsize);
    int end=clock();
    //PrintValues(arr,arrsize);
    printf("\n%s time = %d","SelectSort",end-begin);
    free(arr);

}

void test_heap(){
    int *arr=GenerateArray(arrsize);
    int begin=clock();
    HeapSort(arr,arrsize);
    int end=clock();
    //PrintValues(arr,arrsize);
    printf("\n%s time = %d","HeapSort",end-begin);
    free(arr);

}
void test_bubble(){
    int *arr=GenerateArray(arrsize);
    int begin=clock();
    BubbleSort(arr,arrsize);
    int end=clock();
    //PrintValues(arr,arrsize);
    printf("\n%s time = %d","BubbleSort",end-begin);
    free(arr);

}

void test_quick(){
    int *arr=GenerateArray(arrsize);
    int begin=clock();
    QuickSort_REC(arr,0,arrsize-1);
    int end=clock();
    //PrintValues(arr,arrsize);
    printf("\n%s time = %d,Ascending order:%d","QuickSort",end-begin,isAscendingOrder(arr,arrsize));
    free(arr);
}

int main(){
    // InsertSort(arr,10);
    // SeeleSort(arr,10);
    // PrintValues(arr,10);
    test_seele();
    //test_insert();
    //test_select();
    test_heap();
    //test_bubble();
    test_quick();
}