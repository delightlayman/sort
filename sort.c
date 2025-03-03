#include "sort.h"
#include "stack.h"
//打印
void PrintValues(int *arr,int size){
    for(int i=0;i<size;i++){
        if(i%10==0)
            printf("\n");
        printf("%-6d ",arr[i]);
    }
    if(size%10!=0)
        printf("\n");
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


//交换
void swap(int* a,int* b){
    int temp=*a;
    *a=*b;
    *b=temp;
}


//顺序判定---升序 ascending order 降序descending order
bool isAscendingOrder(int *arr,int size){
    bool check=1;
    for(int i=0;i<size-1;i++){
        if(arr[i]>arr[i+1]){
            check=0;
            break;
        }
    }
    return check;

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
                    a[end+gap]=a[end];
                    end-=gap;
                }
                else
                    break;
            }
            a[end+gap]=temp;
        }
    }
}



//选择排序---升序
//可以一次排一个最值，也可以是两个
//遍历选出最值，交换到合适位置
void SelectSort(int *a,int size){
    int begin=0;
    int end=size-1;
    while(begin<end){
        int maxi=begin,mini=begin;//最值下标,设置在每次循环的起始位置
        for(int i=begin;i<=end;i++){
            if(a[maxi]<a[i])
                maxi=i;
            
            if(a[mini]>a[i])
                mini=i;
        }
        //小优化---maxi==end&&mini==begin时 不用交换
        swap(&a[begin],&a[mini]);//最小值换到开头
        if(maxi==begin)//确保最大值交换到末尾
            maxi=mini;
        swap(&a[end],&a[maxi]);
        begin++;
        --end;

    }

}
//堆排序--升序--建大堆
void AdjustDown(int *a,int size,int root){
    int parent=root;
    int child=2*parent+1;
    while(child<size){
        //选大孩子
        if(child+1<size&&a[child+1]>a[child])
            ++child;
        //大者向上调整
        if(a[child]>a[parent]){
            swap(&a[child],&a[parent]);
            parent=child;
            child=2*parent+1;
        }
        else{
            break;
        }    
    }
}
void HeapBuilt(int *a,int size){
    for(int i=(size-1-1)/2;i>=0;i--){
        AdjustDown(a,size,i);
    }
}

void HeapSort(int *a,int size){
    HeapBuilt(a,size);
    for(int i=size-1;i>0;i--){
        swap(&a[0],&a[i]);
        AdjustDown(a,i,0);
    }
}

//冒泡排序--升序
//相邻两数，交换大者到后方，遍历数值，循环操作，直至最大值换至最后
void BubbleSort(int *a,int size){
    for(int pos=size-1;pos>0;pos--){
        //优化
        int check=0;
        for(int i=1;i<=pos;i++){
            if(a[i-1]>a[i]){
                swap(&a[i],&a[i-1]);
                check=1;  
            }                
        }
        if(!check)//check==0说明未发生交换，原数组本身就有序
            break;
    }
}
//三数取中---优化：避免取到最值，提高效率
int GetMidIndex(int *a,int begin,int end){
    int mid=(begin+end)/2;
    if(a[begin]<a[end]){
        if(a[begin]>a[mid])
            return begin;
        else if(a[mid]<a[end])
            return mid;
        else        
            return end;
    }
    else{//a[begin]>=a[end])
        if(a[end]>a[mid])
            return end;
        else if(a[mid]<a[begin])
            return mid;    
        else    
            return begin;
    }
}

//左右指针法
int QPartSort_LR(int *a,int begin,int end){
    int key=GetMidIndex(a,begin,end);
    swap(&a[end],&a[key]);
    key=end;//确保最后大值换到末尾
    while(begin<end){
        //begin找大--
        while(begin<end&&a[begin]<=a[key]){begin++;}
        //end找小
        while(begin<end&&a[end]>=a[key]){end--;}
        swap(&a[begin],&a[end]);
    }
    //begin==end
    swap(&a[begin],&a[key]);
    return begin;
}
//挖坑法--交换
int QPartSort_Pit_Swap(int *a,int begin,int end){
    int key=GetMidIndex(a,begin,end);
    swap(&a[key],&a[end]);
    key=end;
    while(begin<end){
        while(begin<end&&a[begin]<=a[key]){begin++;}
        swap(&a[begin],&a[key]);
        key=begin;
        while(begin<end&&a[end]>=a[key]){end--;}
        swap(&a[end],&a[key]);
        key=end;
    }
    return begin; 
}
//挖坑法--赋值
int QPartSort_Pit_Assign(int *a,int begin,int end){
    int key=GetMidIndex(a,begin,end);
    swap(&a[end],&a[key]);
    int pit=a[key];
    while(begin<end){
        while(begin<end&&a[begin]<=pit){begin++;}
            a[end]=a[begin];
        while(begin<end&&a[end]>=pit){end--;}
            a[begin]=a[end];
    } 
    a[begin]=pit;
    return begin;
}

//前后指针法
int QPartSort_FB(int *a,int begin,int end){
    int key=GetMidIndex(a,begin,end);
    swap(&a[key],&a[end]);
    int cur=begin;
    int pre=cur-1;
    while(cur<end){ //end位用于比较，遍历到end前
        if(a[cur]<a[end]&&++pre!=cur){ 
            swap(&a[cur],&a[pre]);    
        }
        cur++;
    }
    swap(&a[cur],&a[++pre]);
    return pre;    
}
//快速排序---递归升序
void QuickSort_REC(int *a,int begin,int end){
    if(begin>=end)
        return;
    //int div=QPartSort_LR(a,begin,end);
    //int div=QPartSort_Pit_Swap(a,begin,end);
    //int div=QPartSort_Pit_Assign(a,begin,end);
    int div=QPartSort_FB(a,begin,end);

    QuickSort(a,begin,div-1);
    QuickSort(a,div+1,end);
}
void QuickSort(int *a,int begin,int end){
    Stack s;
    StackInit(&s);
    
    if(begin>=end)
        return;
    //int div=QPartSort_LR(a,begin,end);
    //int div=QPartSort_Pit_Swap(a,begin,end);
    //int div=QPartSort_Pit_Assign(a,begin,end);
    int div=QPartSort_FB(a,begin,end);

    QuickSort(a,begin,div-1);
    QuickSort(a,div+1,end);
}


//计数排序
void CountSort(int *a,int size);
//基数排序
void BaseSort(int *a,int size);
//桶排序
void BocketSort(int *a,int size);