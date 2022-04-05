#include <bits/stdc++.h>
using namespace std;
class Node
{
public:
    int data;
    Node *left;
    Node *right;
    Node(int _d)
    {
        data = _d;
        left = NULL;
        right = NULL;
    }
};
class List
{
public:
    void insertion(Node **head, Node **last, int data)
    {
        Node *newnode = new Node(data);
        if (*head == NULL)
        {
            *head = newnode;
            *last = newnode;
            return;
        }
        else
        {
            (*last)->right = newnode;
            newnode->left = *last;
            *last = newnode;
        }
    }
    void Print(Node *head)
    {
        while (head)
        {
            cout << head->data << " ";
            head = head->right;
        }
        cout << "\n";
    }
    void Reverse(Node **head, Node **last)
    {
        Node *fowd, *pre, *curr = *head;
        while (curr)
        {
            fowd = curr->right;
            pre = curr->left;
            curr->left = curr->right;
            curr->right = pre;
            curr = fowd;
        }
        *head = *last;
    }
};
int main()
{
    Node *head = NULL, *Last = NULL;
    List l1;
    l1.insertion(&head, &Last, 2);
    l1.insertion(&head, &Last, 1);
    l1.insertion(&head, &Last, 3);
    l1.insertion(&head, &Last, 4);
    l1.insertion(&head, &Last, 5);
    l1.Print(head);
    l1.Reverse(&head,&Last);
    l1.Print(head);
}