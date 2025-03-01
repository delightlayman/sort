#include "sort.h"
//打印
void PrintValues(int *arr,int size){
    for(int i=0;i<size;i++){
        printf("%d ",arr[i]);
    }

}
//生成随机数数组
int * GenerateArray(int size){
    srand(time(0));
    int *arr=(int *)malloc(sizeof(int)*size);
    for(int i=0;i<size;i++){
        arr[i]=rand();
    }
    return arr;
}
//插入排序--数组--升序
// void InsertSort(int *a,int size){
//     for(int i=0;i<size-1;i++){
//         int srt=a[i+1];
//         for(int j=i;j>=0;){
//             int cmp=a[j];
//             if(cmp>srt){
//                 a[j+1]=cmp;
//                 j--;
//             }
//             else{
//                 a[j+1]=srt;
//                 break;
//             }    
//             if(j<0)
//                 a[j+1]=srt;
//         }
//     }
// }

void InsertSort(int *a,int size){
    assert(a);
    for(int i=0;i<size-1;i++){
        int cmp=i;
        int temp=a[cmp+1];
        while(cmp>=0){
            if(a[cmp]>temp){
                a[cmp+1]=a[cmp];
                cmp--;
            }
            else{
                break;
            }
        }
        a[cmp+1]=temp;  
    }
}

//希尔排序--升序
//gap越大，大数越快到后面，小数越快到前面
//gap越大，越无序，越小，越有序
//gap==1 即为插入排序


//各组分别排序
void SeeleSort_Respectively(int *a,int size){

    int gap=3;
    int groups=gap;//组数等于间隔值
    for(int i=0;i<groups;i++){
        for(int j=i;j<=size-1-gap;j+=gap){
            int end=j;
            int temp=a[end+gap];
            //i属于[0,gap-1]，故而i-gap<0,这里取end>=0即可
            while(end>=i){//大于等于起始下标
                if(a[end]>temp){
                    a[end+gap]=a[end];
                    end-=gap;
                }
                else
                    break;
            }
            a[end+gap]=temp;
        }
    }
    InsertSort(a,size);
}

//多组并排--各组交替进行排序
void SeeleSort(int *a,int size){
    int gap=size;
    while(gap>1){
        //取/3 相对最优
        gap=gap/3+1;//+1保证最后一次gap==1,相当于进行一次插入排序

        for(int i=0;i<size-gap;i++){//i可以取到size-1-gap
            int end=i;
            int temp=a[end+gap];
            //各组起始位置q属于[0,gap-1]，故而q-gap<0,这里取end>=0即可
            while(end>=0){
                if(temp<a[end]){
                    a[end+1]=a[end];
                    end-=gap;
                }
                else
                    break;
            }
            a[end+1]=temp;
        }
    }
}

