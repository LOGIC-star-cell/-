#include<stdio.h>

#define MAXSIZE 100
typedef int ElemType;

typedef struct
{
    ElemType data[MAXSIZE];
    int length;
} Seqlist;

void initList(Seqlist *L)
{
    L->length = 0;
}

//尾部添加元素
int appendElem(Seqlist *L, ElemType e)
{
    if(L->length >= MAXSIZE)
    {
        printf("顺序表已满\n");
        return 0;
    }
    L->data[L->length]  = e;
    L->length++;
    return 1;
}

//插入元素
int insertElem(Seqlist *L, int pos, ElemType e)
{
    if(L->length >= pos)
    {
        for(int i = L->length - 1; i >= pos - 1; i--)
        {
            L->data[i + 1] = L->data[i];
        }
        L->data[pos - 1] = e;
        L->length++;
    }
    return 1;
}

//删除元素
int deleteElem(Seqlist *L, int pos, ElemType *e)
{
    if(L->length == 0)
    {
        printf("空表\n");
        return 0;
    }

    if(pos < 1 || pos > L->length)
    {
        printf("删除的数据位置有误\n");
        return 0;
    }

    *e = L->data[pos - 1];
    if(pos < L->length)
    {
        for(int i = pos; i < L->length; i++)
        {
            L->data[i - 1] = L->data[i];
        }
    }
    L->length--;
    return 1;
}

//查找
int findElem(Seqlist *L, ElemType e)
{
    if(L->length == 0)
    {
        printf("空表\n");
        return 0;
    }
    for(int i = 0; i < L->length; i++)
    {
        if(L->data[i] == e)
        {
            return i + 1;
        }
    }
    return 0;
}

//遍历
void listElem(Seqlist *L)
{
    for(int i = 0; i < L->length; i++)
    {
        printf("%d ",L->data[i]);
    }
    printf("\n");
}

int main()
{
    Seqlist list;
    initList(&list);
    appendElem(&list,88);
    appendElem(&list,67);
    appendElem(&list,40);
    appendElem(&list,8);
    appendElem(&list,23);
    listElem(&list);

    insertElem(&list,2,56);
    listElem(&list);

    ElemType delete_Data;
    deleteElem(&list,2,&delete_Data);
    printf("被删除的数据:%d\n",delete_Data);
    listElem(&list);

    printf("该元素在顺序表的第%d个位置\n",findElem(&list, 40));

    return 0;
}