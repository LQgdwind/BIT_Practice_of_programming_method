/* PRESET CODE BEGIN - NEVER TOUCH CODE BELOW */

#include <iostream>

using namespace std;

typedef int ElemType;
typedef struct node
{
    ElemType    data;
    struct node* next;
} NODE;
typedef NODE* LinkList;

void output(LinkList);
void change(int, int, NODE*);
LinkList createList(ElemType);
void inverse(LinkList);

LinkList createList(ElemType finish)	//finish�����ݽ������ 
{
    ElemType x;
    NODE* newNode;
    LinkList first = new NODE;   // ����ͷ���
    first->next = NULL;
    first->data = finish;
    cin >> x;	      			// Լ����finish������������
    while (x != finish)
    {
        newNode = new NODE;      // �����½��
        newNode->data = x;
        newNode->next = first->next; // ��
        first->next = newNode;       // ��
        cin >> x;
    }
    return first;
}

void output(LinkList head)
{
    cout << "List:";
    while (head->next != NULL)
    {
        cout << head->next->data << ",";
        head = head->next;
    }
    cout << endl;
}

int main(int argc, char** argv)
{
    LinkList head;

    head = createList(-1);
    output(head);
    inverse(head);
    output(head);
    return 0;
}

void inverse(LinkList head)
{
    LinkList prev = NULL;
    LinkList p = head;
    while (head!= NULL)
    {
        p = head->next;
        head->next = prev;
        prev = head;
        head = p;
    }
    head  = prev;
}
