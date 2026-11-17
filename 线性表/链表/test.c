#include<stdlib.h>
#include<stdio.h>

typedef int ElemType;

typedef struct node
{
    ElemType data;
    struct node* next;
} Node;

Node* initList()
{
    Node *head = (Node*)malloc(sizeof(Node));
    head->data = 0;
    head->next = NULL;
    return head;
}

void headinsert(Node *L, ElemType e)
{
    Node* p = (Node*)malloc(sizeof(Node));
    p->data = e;
    p->next = L->next;
    L->next = p;
}

Node* get_tail(Node *L)
{
    Node *p = L;
    while (p->next != NULL)
    {
        p = p->next;
    }
    return p;
}

Node* tailinsert(Node *tail, ElemType e)
{
    Node *p = (Node*)malloc(sizeof(Node));
    p->data = e;
    tail->next = p;
    p->next = NULL;
    return p;
}

void insertNode(Node* L, int pos, ElemType e)
{
    Node *p = L;
    for(int i = 0; i < pos - 1; i++)
    {
        p = p->next;
        if(p == NULL)
        {
            return;
        }
    }

    Node* q = (Node*)malloc(sizeof(Node));
    q->data = e;
    q->next = p->next;
    p->next = q;
}

void deleteNode(Node* L, int pos)
{
    Node* p = L;
    for(int i = 0; i < pos - 1; i++)
    {
        p = p->next;
        if(p == NULL)
        {
            return;
        }
    }

    if(p->next == NULL)
    {
        return;
    }
    Node* q = p->next;
    p->next = q->next;
    free(q);
}

int getNodelenth(Node* L)
{
    Node *p = L->next;
    int len = 0;
    while(p != NULL)
    {
        len++;
        p = p->next;
    }
    return len;
}

void freeList(Node* L)
{
    Node *p = L->next;
    Node *q;

    while(p != NULL)
    {
        q = p->next;
        free(p);
        p = q;
    }
    L->next = NULL;
}

void listNode(Node* L)
{
    Node *p = L->next;
    while(p != NULL)
    {
        printf("%d ",p->data);
        p = p->next;
    }
}

int main()
{
    Node *list = initList();
    headinsert(list,10);
    headinsert(list,20);
    Node *tail = get_tail(list);
    tail = tailinsert(tail, 30); 
    tail = tailinsert(tail, 40);
    listNode(list);
    insertNode(list, 2, 15);
    listNode(list);
    deleteNode(list,2);
    listNode(list);
    printf("%d\n",getNodelenth(list));
    freeList(list);
    printf("%d\n",getNodelenth(list));
    return 0;
}