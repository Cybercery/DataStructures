#include <iostream>
using namespace std;

// Node class for the binary tree
class Node
{
public:
    int value;
    Node *left;
    Node *right;

    Node(int val)
    {
        value = val;
        left = nullptr;
        right = nullptr;
    }
};

// Binary Tree class
class BinaryTree
{
public:
    Node *root;

    BinaryTree(int rootValue)
    {
        root = new Node(rootValue);
    }

    // Preorder Traversal (Root, Left, Right)
    void preorderTraversal(Node *node)
    {
        if (node != nullptr)
        {
            cout << node->value << " ";     // Visit root
            preorderTraversal(node->left);  // Traverse left subtree
            preorderTraversal(node->right); // Traverse right subtree
        }
    }

    // Inorder Traversal (Left, Root, Right)
    void inorderTraversal(Node *node)
    {
        if (node != nullptr)
        {
            inorderTraversal(node->left);  // Traverse left subtree
            cout << node->value << " ";    // Visit root
            inorderTraversal(node->right); // Traverse right subtree
        }
    }

    // Postorder Traversal (Left, Right, Root)
    void postorderTraversal(Node *node)
    {
        if (node != nullptr)
        {
            postorderTraversal(node->left);  // Traverse left subtree
            postorderTraversal(node->right); // Traverse right subtree
            cout << node->value << " ";      // Visit root
        }
    }
};

// Example usage
int main()
{
    // Creating a binary tree
    BinaryTree bt(1);
    bt.root->left = new Node(2);
    bt.root->right = new Node(3);
    bt.root->left->left = new Node(4);
    bt.root->left->right = new Node(5);

    cout << "Preorder Traversal: ";
    bt.preorderTraversal(bt.root); // Output: 1 2 4 5 3
    cout << endl;

    cout << "Inorder Traversal: ";
    bt.inorderTraversal(bt.root); // Output: 4 2 5 1 3
    cout << endl;

    cout << "Postorder Traversal: ";
    bt.postorderTraversal(bt.root); // Output: 4 5 2 3 1
    cout << endl;

    return 0;
}
