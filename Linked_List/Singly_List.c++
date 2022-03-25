#include <bits/stdc++.h>
using namespace std;
class Node
{
public:
    int data;
    Node *next;
    Node(int d)
    {
        data = d;
        next = NULL;
    }
};
class Linked_List
{
public:
    void Push(Node **head, Node **Last, int data)
    {
        Node *new_node = new Node(data);

        if (*head == NULL)
        {
            *head = new_node;
            *Last = new_node;
        }
        else
        {
            (*Last)->next = new_node;
            *Last = new_node;
        }
    }
    void Print(Node *temp)
    {
        while (temp)
        {
            cout << temp->data << " ";
            temp = temp->next;
        }
        cout << "\n";
    }
    void Del_Pos(Node *head, int pos)
    {
        Node *temp = head, *pre;
        for (int i = 0; i < pos - 1; i++)
        {
            pre = temp;
            temp = temp->next;
        }
        pre->next = temp->next;
        delete (temp);
    }
    void Del_Key(Node *head, int key)
    {
        Node *pre;
        while (head)
        {
            if (head->data == key)
            {
                break;
            }
            pre = head;
            head = head->next;
        }
        pre->next = head->next;
        delete (head);
    }
    void Reverse(Node **head)
    {
        Node *curr = *head, *fow, *pre = NULL;
        while (curr)
        {
            fow = curr->next;
            curr->next = pre;
            pre = curr;
            curr = fow;
        }
        *head = pre;
    }
    void Insertion_pos(Node *head, int pos, int data)
    {
        Node *newnode = new Node(data), *temp = head;
        for (int i = 1; i < pos - 1; i++)
        {
            temp = temp->next;
        }
        newnode->next = temp->next;
        temp->next = newnode;
    }
};
int main()
{
    Node *head = NULL, *Last = NULL;
    Linked_List List;
    int data;
    for (int i = 0; i < 5; i++)
    {
        cin >> data;
        List.Push(&head, &Last, data);
    }
    List.Print(head);
    List.Del_Pos(head, 3);
    List.Print(head);
    List.Del_Key(head, 2);
    List.Print(head);
    List.Reverse(&head);
    List.Print(head);
    List.Insertion_pos(head, 2, 2);
    List.Print(head);
    List.Insertion_pos(head, 3, 3);
    List.Print(head);
    List.Reverse(&head);
    List.Print(head);
}