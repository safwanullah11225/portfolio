#include <iostream>
using namespace std;


struct Node {
    int data;
    Node* left;
    Node* right;
};


Node* createNode(int value) {
    Node* newNode = new Node();
    newNode->data = value;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}


Node* insert(Node* root, int value) {
    if (root == NULL) return createNode(value);  
    if (value < root->data) root->left = insert(root->left, value);  
    else root->right = insert(root->right, value);  
    return root;
}


void inorder(Node* root) {
    if (root != NULL) {
        inorder(root->left);
        cout << root->data << " ";
        inorder(root->right);
    }
}


bool search(Node* root, int value) {
    if (root == NULL) return false;  
    if (root->data == value) return true;  
    if (value < root->data) return search(root->left, value); 
    return search(root->right, value);  
}

int main() {
    Node* root = NULL;

    
    root = insert(root, 50);
    insert(root, 30);
    insert(root, 20);
    insert(root, 40);
    insert(root, 70);
    insert(root, 60);
    insert(root, 80);

    
    cout << "Inorder Traversal: ";
    inorder(root);
    cout << endl;

    
    int searchValue = 40;
    cout << "Search " << searchValue << ": " 
         << (search(root, searchValue) ? "Found" : "Not Found") << endl;

    return 0;
}

