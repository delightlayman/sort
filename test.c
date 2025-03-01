#include "sort.h"

#define arrsize 100000

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

int main(){
    // InsertSort(arr,10);
    // SeeleSort(arr,10);
    // PrintValues(arr,10);
    test_seele();
    test_insert();
}