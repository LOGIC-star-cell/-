#include<stdlib.h>

#define MAXSIZE 100
typedef int EleType;

//顺序表定义
typedef struct 
{
    EleType *data; //指针，用来指向一块动态开辟的数组空间
    int length;
} Seqlist;

//顺序表的初始化 - 动态分配内存
Seqlist* initList()
{
    //1.开辟结构体本身的内存
    Seqlist* L = (Seqlist*)malloc(sizeof(Seqlist));
    if(L == NULL)
    {
        return NULL;
    }
    //2.开辟存放数据的数组内存，大小MAXSIZE个EleType
    L->data = (EleType*)malloc(sizeof(EleType) * MAXSIZE);
    L->length = 0;
    //length是结构体里面自带的成员，其内存包含在第一次malloc的结构体内存里面，不用单独开
    //只有data仅仅是一个指针，它指向的数组不在结构体里面，所以要二次malloc
    return L;
}

int main()
{
    //声明一个线性表并初始化
    Seqlist* list = initList();

    //释放内存空间，防止内存泄漏
    free(list->data); //先释放数据数组
    free(list); //再释放结构体本身

    return 0;
}