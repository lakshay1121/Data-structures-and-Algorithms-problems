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

Node *maxiVal(Node *root)
{

    Node *temp = root;

    if (root == NULL)
    {

        return temp;
    }

    if (temp->data < root->data)
    {

        temp->data = root->data;
    }

    maxiVal(root->right);
}

Node *DeleteFromBST(Node *&root, int val)
{

    if (root == NULL)
        return root;

    if (root->data == val)
    {

        // 0 child

        if (root->left == NULL && root->right == NULL)
        {

            delete root;

            return NULL;
        }

        // 1 child

        // left child.

        if (root->left != NULL && root->right == NULL)
        {

            Node *temp = root->left;

            delete root;

            return temp;
        }

        // right child.

        if (root->left == NULL && root->right != NULL)
        {

            Node *temp = root->right;

            delete root;

            return temp;
        }

        // 2 child

        if (root->left != NULL && root->right != NULL)
        {

            int maxi = maxiVal(root->left)->data;

            root->data = maxi;

            root->left = DeleteFromBST(root->left, maxi);

            return root;
        }
    }

    else if (root->data < val)
    {

        root->right = DeleteFromBST(root->right, val);

        return root;
    }

    else
    {

        root->left = DeleteFromBST(root->left, val);

        return root;
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

void inorder(Node *root)
{

    if (root == NULL)
        return;

    inorder(root->left);

    cout << root->data << " ";

    inorder(root->right);
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

    cout << "deletion of leaf node:" << endl;

    DeleteFromBST(root, 11);

    inorder(root);

    cout << endl;

    cout << "deletion of node with one child:" << endl;

    DeleteFromBST(root, 3);

    inorder(root);

    cout << endl;

    cout << "deletion of node with two child:" << endl;

    DeleteFromBST(root, 2);

    inorder(root);

    return 0;
}
