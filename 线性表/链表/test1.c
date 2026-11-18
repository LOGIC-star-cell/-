#include<stdio.h>
#include<stdlib.h>

typedef int ElemType;

//定义节点结构
typedef struct node
{
    ElemType data;
    struct node *next;
}Node;

//初始化链表(造头节点)
Node* initList()
{
    Node *head = (Node*)malloc(sizeof(Node));
    head->data = 0;
    head->next = NULL;
    return head;
}

//头插法
int insertHead(Node* L, ElemType e)
{
    //1.造新节点
    Node *p = (Node*)malloc(sizeof(Node));
    //2.填入数据
    p->data = e;
    //3.新节点先连后面
    p->next = L->next;
    //4.头节点再连新节点
    L->next = p;
    return 1;
}

//获取尾节点的地址
Node* get_tail(Node *L)
{
    Node *p = L;
    while(p->next != NULL)
    {
        p = p->next;
    }
    return p;
}

//尾插法
Node* insertTail(Node* tail, ElemType e)
{
    Node *p = (Node*)malloc(sizeof(Node));
    p->data = e;
    tail->next = p;
    p->next = NULL;
    return p;
}

//尾插法（节点）
Node* insertTailWithNode(Node* tail, Node* node)
{
    tail->next = node;
    node->next = NULL;
    return node;
}

//在指定位置插入数据
int insertNode(Node* L, int pos, ElemType e)
{
    //用来保存插入位置的前驱节点
    Node *p = L;
    //遍历链表找到插入位置的前驱节点
    for(int i = 0; i < pos - 1; i++)
    {
        p = p->next;
        //防越界判断：如果还没走到pos-1步,p就变成了NULL
        if(p == NULL)
        {
            return 0;//插入位置错误
        }
    }

    //要插入的新节点
    Node *q = (Node*)malloc(sizeof(Node));
    q->data = e;
    q->next = p->next;
    p->next = q;
    return 1;
}

//删除节点
int deleteNode(Node* L, int pos)
{
    //要删除节点的前驱
    Node *p = L;
    //遍历链表找到要删除节点的前驱
    for(int i = 0; i < pos - 1; i++)
    {
        p = p->next; 
        if(p == NULL)
        {
            return 0;
        }
    }
    if(p->next == NULL)
    {
        printf("要删除的位置错误\n");
        return 0;
    }
    //q指向要删除的节点
    Node *q = p->next;
    //让要删除节点的前驱指向要删除节点的后继
    p->next = q->next;
    //释放要删除节点的内存空间
    free(q);
    return 1;
}

//获取链表长度
int listLength(Node* L)
{
    Node* p = L->next;
    int len = 0;
    while(p != NULL)
    {
        p = p->next;
        len++;
    }
    return len;
}

//释放链表（保留头节点） 
void freeList(Node *L)
{
    Node* p = L->next;
    //定义一个临时指针q，用来暂存下一个节点的地址
    Node* q;

    while(p != NULL)
    {
        q = p->next;//先保存下一节点的地址
        free(p);//释放当前节点
        p = q;//p跳到下一节点
    }
    L->next = NULL;//头节点置空，防止野指针
}

//使用双指针找到倒数第k个元素
Node* findNodeFS(Node* L, int k)
{
    Node* fast = L->next;
    Node* slow = L->next;
    for(int i = 0; i < k; k++)
    {
        fast = fast->next;
    }
    while(fast != NULL)
    {
        fast = fast->next;
        slow = slow->next;
    }
    printf("倒数第%d个节点值为：&d\n", k, slow->data);
}

//遍历
void listNode(Node *L)
{
    //1.定义一个指针p，从头节点的下一个节点(第一个真实数据)开始
    Node *p = L->next;
    //2.只要p不是空指针，就一直往后找
    while(p != NULL)
    {
        printf("%d\n",p->data);//访问当前节点的数据
        p = p->next;//指针移到下一个节点
    }
    printf("\n");
}

int main()
{
    Node *list = initList();

    //插入10
    insertHead(list, 10);
    //插入20
    insertHead(list, 20);

    Node *tail = get_tail(list);
    tail = insertTail(tail, 10);
    tail = insertTail(tail, 20);
    tail = insertTail(tail ,30);
    listNode(list);
    insertNode(list, 2, 15);
    listNode(list);

    deleteNode(list, 2);
    listNode(list);

    printf("%d\n",listLength(list));

    freeList(list);
    printf("%d\n",listLength(list));

    findNodeFS(list, 3);

    return 0;
}