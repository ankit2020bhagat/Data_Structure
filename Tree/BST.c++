#include <bits/stdc++.h>
#include <queue>
using namespace std;
class Node
{
public:
    int data;
    Node *left;
    Node *right;
};
class Tree
{
public:
    Node *GetNode(int data)
    {
        Node *newnode = new Node();
        newnode->data = data;
        newnode->left = NULL;
        newnode->right = NULL;
        return newnode;
    }
    Node *Insert(Node *root, int data)
    {
        Node *newnode;
        if (root == NULL)
        {
            root = GetNode(data);
        }
        else if (data < root->data)
        {
            root->left = Insert(root->left, data);
        }
        else
        {
            root->right = Insert(root->right, data);
        }
        return root;
    }
    void Preorder(Node *root)
    {
        if (root == NULL)
        {
            return;
        }
        cout << root->data << " ";
        Preorder(root->left);
        Preorder(root->right);
    }
    int FindHeight(Node *root)
    {
        if (root == NULL)
        {
            return -1;
        }
        return max(FindHeight(root->left), FindHeight(root->right)) + 1;
    }
    void Labelorder_traversal(Node *root)
    {
        queue<Node *> q1;
        q1.push(root);
        while (!q1.empty())
        {
            Node *curr = q1.front();
            cout << curr->data << " ";
            if (curr->left)
            {
                q1.push(curr->left);
            }
            if (curr->right)
            {
                q1.push(curr->right);
            }
            q1.pop();
        }
    }
};
int main()
{
    Node *root = NULL;
    Tree T1;
    int data;
    for (int i = 0; i < 7; i++)
    {
        cin >> data;
        root = T1.Insert(root, data);
    }
    T1.Preorder(root);
    cout << "\n";
    cout << T1.FindHeight(root);
    cout << "\n";
    T1.Labelorder_traversal(root);
}