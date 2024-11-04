#include <iostream>
using namespace std;

// Node structure for a Binary Search Tree
class Node
{
public:
    int data;
    Node *left;
    Node *right;

    Node(int data)
    {
        this->data = data;
        this->left = NULL;
        this->right = NULL;
    }
};

class BST
{
public:
    Node *root;
    BST()
    {
        root = NULL;
    }

    void inorderTraversal(Node *root)
    {
        if (root != NULL)
        {
            inorderTraversal(root->left);
            cout << root->data << " ";
            inorderTraversal(root->right);
        }
    }

    Node *insertNode(Node *root, int data)
    {
        if (root == NULL)
        { // TREE IS EMPTY, CREATE A NEW NODE
            return new Node(data);
        }
        if (data < root->data)
        {
            root->left = insertNode(root->left, data);
        }
        else if (data >= root->data)
        {
            root->right = insertNode(root->right, data);
        }
        return root;
    }

    // Find successor
    Node *minValueNode(Node *node)
    {
        Node *current = node;
        // Loop down to find the leftmost leaf
        while (current && current->left != NULL)
        {
            current = current->left;
        }
        return current;
    }

    // Function to delete a node
    Node *deleteNode(Node *root, int data)
    {
        if (root == NULL)
            return root;

        // Data is less than root (go left)
        if (data < root->data)
        {
            root->left = deleteNode(root->left, data);
        }
        // Data is greater than root (go right)
        else if (data > root->data)
        {
            root->right = deleteNode(root->right, data);
        }
        // Equal data
        else
        {
            // Node with only one child or no child
            if (root->left == NULL)
            {
                Node *temp = root->right;
                delete root;
                return temp;
            }
            else if (root->right == NULL)
            {
                Node *temp = root->left;
                delete root;
                return temp;
            }

            // Node with two children: Get the inorder successor
            Node *temp = minValueNode(root->right);

            root->data = temp->data;
            root->right = deleteNode(root->right, temp->data);
        }
        return root;
    }
};

// Function to do in-order traversal of BST
int main()
{
    BST bstsd;
    // Create a BST
    bstsd.root = bstsd.insertNode(bstsd.root, 50);
    bstsd.root = bstsd.insertNode(bstsd.root, 30);
    bstsd.root = bstsd.insertNode(bstsd.root, 20);
    bstsd.root = bstsd.insertNode(bstsd.root, 40);
    bstsd.root = bstsd.insertNode(bstsd.root, 70);
    bstsd.root = bstsd.insertNode(bstsd.root, 60);
    bstsd.root = bstsd.insertNode(bstsd.root, 80);

    // Print the inorder traversal of a BST
    cout << "Inorder traversal of the given Binary Search Tree is: ";
    bstsd.inorderTraversal(bstsd.root);
    cout << endl;

    // Delete a node in BST
    bstsd.root = bstsd.deleteNode(bstsd.root, 50);
    cout << "After deletion of 50: ";
    bstsd.inorderTraversal(bstsd.root);
    cout << endl;

    // Insert a node in BST
    bstsd.root = bstsd.insertNode(bstsd.root, 25);
    cout << "After insertion of 25: ";
    bstsd.inorderTraversal(bstsd.root);
    cout << endl;

    return 0;
}
