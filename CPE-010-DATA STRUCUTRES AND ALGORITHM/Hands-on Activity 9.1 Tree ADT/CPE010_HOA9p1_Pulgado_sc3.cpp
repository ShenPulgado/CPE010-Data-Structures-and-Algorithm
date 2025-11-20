#include <iostream>

struct Node {
    int data;
    Node* left;
    Node* right;

    Node(int val) : data(val), left(nullptr), right(nullptr) {}
};

class BST {
public:
    Node* root;

    BST() : root(nullptr) {}

    Node* insert(Node* node, int value) {
        if (node == nullptr) {
            return new Node(value);
        }
        if (value < node->data) {
            node->left = insert(node->left, value);
        } else if (value > node->data) {
            node->right = insert(node->right, value);
        }
        return node;
    }

    void insert(int value) {
        root = insert(root, value);
    }

    void preorder(Node* node) {
        if (node == nullptr) return;
        std::cout << node->data << " ";
        preorder(node->left);
        preorder(node->right);
    }

    void inorder(Node* node) {
        if (node == nullptr) return;
        inorder(node->left);
        std::cout << node->data << " ";
        inorder(node->right);
    }

    void postorder(Node* node) {
        if (node == nullptr) return;
        postorder(node->left);
        postorder(node->right);
        std::cout << node->data << " ";
    }
};

int main() {
    BST tree;
    int values[] = {2, 3, 9, 18, 0, 1, 4, 5};
    for (int v : values) {
        tree.insert(v);
    }

    std::cout << "Preorder Traversal: ";
    tree.preorder(tree.root);
    std::cout << "\n";

    std::cout << "Inorder Traversal: ";
    tree.inorder(tree.root);
    std::cout << "\n";

    std::cout << "Postorder Traversal: ";
    tree.postorder(tree.root);
    std::cout << "\n";

    return 0;
}
