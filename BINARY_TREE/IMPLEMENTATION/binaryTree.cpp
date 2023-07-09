#include <bits/stdc++.h>

using namespace std;

class Node
{
public:
    int data;
    Node *leftChild;
    Node *rightChild;

    Node(int data)
    {
        this->data = data;
        this->leftChild = NULL;
        this->rightChild = NULL;
    }
};

// 1 3 5 7 11 17
Node *buildTree(Node *root)
{
    cout << "Enter the data : " << endl;
    int data;
    cin >> data;

    if (data == -1)
        return NULL;

    root = new Node(data);

    cout << "Enter data for leftChild of " << data << endl;
    root->leftChild = buildTree(root->leftChild);

    cout << "Enter data for rightChild of " << data << endl;
    root->rightChild = buildTree(root->rightChild);

    return root;
}

void inOrder(Node *root)
{
    if (root == NULL)
        return;

    inOrder(root->leftChild);
    cout << root->data << " ";
    inOrder(root->rightChild);
}

void preOrder(Node *root)
{
    if (root == NULL)
        return;

    cout << root->data << " ";
    preOrder(root->leftChild);
    preOrder(root->rightChild);
}

void postOrder(Node *root)
{
    if (root == NULL)
        return;

    postOrder(root->leftChild);
    postOrder(root->rightChild);
    cout << root->data << " ";
}

int main()
{
    Node *root = NULL;

    root = buildTree(root);

    cout << "Inorder traversal is : " << endl;
    inOrder(root);
    cout << endl;

    cout << "Preorder traversal is : " << endl;
    preOrder(root);
    cout << endl;

    cout << "Postorder traversal is : " << endl;
    postOrder(root);
    cout << endl;

    return 0;
}

// 1 3 7 -1 -1 11 -1 -1 5 13 -1 -1 -1