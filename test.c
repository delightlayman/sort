#include "sort.h"

#define arrsize 1000

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
void test_merge(){
    int *arr=GenerateArray(arrsize);
    int begin=clock();
    MergeSort(arr,0,arrsize-1);
    int end=clock();
    //PrintValues(arr,arrsize);
    printf("\n%s time = %d,Ascending order:%d","MergeSort",end-begin,isAscendingOrder(arr,arrsize));
    free(arr);
}

//文件指针检查
void CheckFilePointer(FILE* fp,const char* name){
    if(!fp){
        printf("%s打开失败",name);
        exit(-1);
    }
}

//文件排序合并
void File_SortMerge(FILE* pre,FILE* cur,FILE* mfile){
    if (pre == NULL || cur == NULL || mfile == NULL) {
        fprintf(stderr, "Error: Invalid file pointer.\n");
        return;
    }
    //读取不加空格，输出加空格
    int num1,num2;
    int val1=fscanf(pre,"%d",&num1);
    int val2=fscanf(cur,"%d",&num2);
    while(val1==1&&val2==1){
        if(num1<num2){
            fprintf(mfile,"%d ",num1);
            val1=fscanf(pre,"%d",&num1);
        }
        else{
            fprintf(mfile,"%d ",num2);
            val2=fscanf(cur,"%d",&num2);
        }

    }

    while(val1==1){
        fprintf(mfile,"%d ",num1);
        val1=fscanf(pre,"%d",&num1);
    }
    while(val2==1){
        fprintf(mfile,"%d ",num2);
        val2=fscanf(cur,"%d",num2);

    }

}

int main(){
    // InsertSort(arr,10);
    // SeeleSort(arr,10);
    // PrintValues(arr,10);
    //test_seele();
    //test_insert();
    //test_select();
    //test_heap();
    //test_bubble();
    //test_quick();
    //test_merge();
    int *array=GenerateArray(arrsize);
    FILE* fin=fopen("data.txt","w");
    CheckFilePointer(fin,"data.txt");
    for(int i=0;i<arrsize;i++)
        fprintf(fin,"%d ",array[i]);
    fclose(fin);
    free(array);

    FILE* fout=fopen("data.txt","r");
    int fnum=0;
    char subtitle[20];
    int read_val=0;

    int arr[100];
    int count=0;
    //fscanf返回 正确读取的数量 读到文件尾返回EOF(-1)
    while(fscanf(fout,"%d",&read_val)==1){
        arr[count%100]=read_val;
        if((count+1)%100==0){
            QuickSort(arr,0,99);
            sprintf(subtitle,"sub\\data%d.txt",fnum++);
            FILE* ftmp=fopen(subtitle,"w");
            for(int i=0;i<100;i++)        
                fprintf(ftmp,"%d ",arr[i]);
            fclose(ftmp); 
        }
        count++;      
    }
    fclose(fout);

    char filename[20];
    char mfilename[20];
    //char newname[20];

    //创建mfile
    // strcpy(mfilename,"sub/0.txt");
    // FILE* mfile=fopen(mfilename,"w");
    // CheckFilePointer(mfile,mfilename);
    
    //读取文件
    strcpy(filename,"sub\\data0.txt");
    FILE* pre=fopen(filename,"r");
    CheckFilePointer(pre,filename);

    //文件指针作用域机制和通常指针相同
    for(int i=1;i<10;i++){
        //文件名中的 \0 被误用为字符串结束符
        //sprintf(tempname,"sub\\0_%d.txt",i);
        
        //重命名前需关闭文件
        // fclose(mfile);
        // sprintf(newname,"sub/merge:0-%d.txt",i);
        // rename(mfilename,newname) 成功返回0，否则非0

        sprintf(mfilename,"sub\\merge_0-%d.txt",i);
        FILE* mfile=fopen(mfilename,"w");
        CheckFilePointer(mfile,mfilename);

        //读取当前文件
        sprintf(filename,"sub\\data%d.txt",i);
        FILE* cur=fopen(filename,"r");
        CheckFilePointer(cur,filename);

        File_SortMerge(pre,cur,mfile);

        
        fclose(cur);
        fclose(mfile);
        // 关闭旧的 pre 文件
        fclose(pre);
        //关闭文件指针后，该指针本身仍然存在，但它指向的文件流已被释放，此时直接使用该指针会导致未定义行为（如程序崩溃或数据错误）。
        //但如果在关闭后重新为其赋值新的有效文件指针，则可以继续使用该指针变量。
        pre=fopen(mfilename, "r");
        CheckFilePointer(mfile,mfilename);
    }
    fclose(pre);
    return 0;
}