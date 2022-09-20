
#include <bits/stdc++.h>
using namespace std;

class Node
{
public:
    int data;
    Node *next;

    Node(int val, Node *nextaddress)
    {
        data = val;
        next = nextaddress;
    }
    Node(){};
};

//traversal
void traversal(Node *ptr)
{
    while (ptr != NULL)
    {
        cout << ptr->data << " ";
        ptr = ptr->next;
    }
    cout << endl;
}

void deleteHead(Node *&head)
{
    Node *ptr = head;
    head = head->next;
    free(ptr);

    traversal(head);
}
void deleteAtIndex(Node *&head, int index)
{
    Node *p = head;
    Node *q = head->next;
    for (int i = 0; i < index - 1; i++)
    {
        p = p->next;
        q = q->next;
    }

    p->next = q->next;
    free(q);

    traversal(head);
}

void deleteLast(Node *&head)
{
    Node *p = head;
    Node *q = head->next;
    while (q->next != NULL)
    {
        p = p->next;
        q = q->next;
    }
    p->next = NULL;
    free(q);

    traversal(head);
}

void deleteValue(Node *&head, int data)
{
    Node *p = head;
    Node *q = head->next;
    while (q->data != data && q->next != NULL)
    {
        p = p->next;
        q = q->next;
    }

    if (q->data == data)
    {
        p->next = q->next;
        free(q);
    }

    traversal(head);
}

int main()
{
    Node *sixth = new Node(60, NULL);
    Node *fifth = new Node(50, sixth);
    Node *fourth = new Node(40, fifth);
    Node *third = new Node(30, fourth);
    Node *second = new Node(20, third);
    Node *head = new Node(10, second);

    traversal(head);

    deleteValue(head, 30);

    deleteHead(head);

    deleteAtIndex(head, 3);

    deleteLast(head);

    return 0;
}
