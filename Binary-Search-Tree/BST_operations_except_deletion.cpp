#include <bits/stdc++.h>
using namespace std;

class Node
{

public:
    int data;

    Node *left;

    Node *right;

    Node(int d)
    {

        this->data = d;

        this->left = NULL;

        this->right = NULL;
    }
};

void Inorder(Node *root)
{

    if (root == NULL)
        return;

    Inorder(root->left);

    cout << root->data << " ";

    Inorder(root->right);
}

void Inorder_Successor(Node *root, int val, int &successor)
{

    if (root == NULL)
        return;

    if (root->data <= val)
    {

        Inorder_Successor(root->right, val, successor);
    }

       if (root->data > val)
    {

        successor = root->data;

        Inorder_Successor(root->left, val, successor);
    }
}

void Inorder_Predecessor(Node *root, int val, int &predecessor)
{

    if (root == NULL)
        return;

    Inorder_Predecessor(root->left, val, predecessor);

    if (root->data < val)
    {

        predecessor = root->data;
    }

    Inorder_Predecessor(root->right, val, predecessor);
}
void LevelOrderTraversal(Node *root)
{

    queue<Node *> q;

    q.push(root);

    q.push(NULL);

    while (!q.empty())
    {

        Node *frontNode = q.front();

        q.pop();

        if (frontNode == NULL)
        {

            cout << endl;

            if (!q.empty())
            {

                q.push(NULL);
            }
        }

        else
        {

            cout << frontNode->data << " ";

            if (frontNode->left)
                q.push(frontNode->left);

            if (frontNode->right)
                q.push(frontNode->right);
        }
    }
}

Node *CreationOfBST(Node *&root, int data)
{

    if (root == NULL)
    {

        root = new Node(data);

        return root;
    }

    if (data > root->data)
    {

        root->right = CreationOfBST(root->right, data);
    }

    else
    {

        root->left = CreationOfBST(root->left, data);
    }

    return root;
}

void takeInput(Node *&root)
{

    int n;

    cin >> n;

    while (n != -1)
    {

        root = CreationOfBST(root, n);

        cin >> n;
    }
}

int main()
{

    Node *root = NULL;

    cout << "Enter the value : " << endl;

    takeInput(root);

    int predecessor;

    //    Inorder_Predecessor(root , 11 , predecessor);

    //    cout<<predecessor;

    int successor;

    Inorder_Successor(root, 6, successor);

    cout << successor;

    return 0;
}
