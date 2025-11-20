#include <iostream>
#include <queue>

struct Node {
    char data;
    Node* left;
    Node* right;
    Node(char val) : data(val), left(nullptr), right(nullptr) {}
};
void preorder(Node* root) {
    if (!root) return;
    std::cout << root->data << " ";
    preorder(root->left);
    preorder(root->right);
}
void inorder(Node* root) {
    if (!root) return;
    inorder(root->left);
    std::cout << root->data << " ";
    inorder(root->right);
}
void postorder(Node* root) {
    if (!root) return;
    postorder(root->left);
    postorder(root->right);
    std::cout << root->data << " ";
}
void bfs(Node* root) {
    if (!root) return;
    std::queue<Node*> q;             
    q.push(root);
    while (!q.empty()) {
        Node* cur = q.front();
        q.pop();
        std::cout << cur->data << " ";
        if (cur->left) q.push(cur->left);
        if (cur->right) q.push(cur->right);
    }
}

int main() {
    Node* root = new Node('A');
    root->left = new Node('B');
    root->right = new Node('C');
    root->left->left = new Node('D');
    root->left->right = new Node('E');
    root->right->right = new Node('F');

    std::cout << "Preorder (DFS): ";
    preorder(root);
    std::cout << "\nInorder (DFS): ";
    inorder(root);
    std::cout << "\nPostorder (DFS): ";
    postorder(root);
    std::cout << "\nLevel-order (BFS): ";
    bfs(root);

    return 0;
}
