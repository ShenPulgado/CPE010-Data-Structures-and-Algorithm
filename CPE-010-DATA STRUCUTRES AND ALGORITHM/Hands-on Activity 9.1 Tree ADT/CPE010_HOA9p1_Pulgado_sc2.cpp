#include <iostream>
#include <string>

struct Node {
    char data;
    Node* left;
    Node* right;

    Node(char val) : data(val), left(nullptr), right(nullptr) {}
};

void preorder(Node* root) {
    if (root == nullptr) return;
    std::cout << root->data << " ";
    preorder(root->left);
    preorder(root->right);
}

void postorder(Node* root) {
    if (root == nullptr) return;
    postorder(root->left);
    postorder(root->right);
    std::cout << root->data << " ";
}

void inorder(Node* root) {
    if (root == nullptr) return;
    inorder(root->left);
    std::cout << root->data << " ";
    inorder(root->right);
}

bool preorderFind(Node* root, char key) {
    if (root == nullptr) return false;
    if (root->data == key) {
        std::cout << key << " was found!\n";
        return true;
    }
    if (preorderFind(root->left, key)) return true;
    if (preorderFind(root->right, key)) return true;
    return false;
}

bool inorderFind(Node* root, char key) {
    if (root == nullptr) return false;
    if (inorderFind(root->left, key)) return true;
    if (root->data == key) {
        std::cout << key << " was found!\n";
        return true;
    }
    if (inorderFind(root->right, key)) return true;
    return false;
}

bool postorderFind(Node* root, char key) {
    if (root == nullptr) return false;
    if (postorderFind(root->left, key)) return true;
    if (postorderFind(root->right, key)) return true;
    if (root->data == key) {
        std::cout << key << " was found!\n";
        return true;
    }
    return false;
}

void findData(Node* root, const std::string& choice, char key) {
    if (choice == "PRE") {
        preorderFind(root, key);
    } else if (choice == "IN") {
        inorderFind(root, key);
    } else if (choice == "POST") {
        postorderFind(root, key);
    }
}

int main() {
    Node* A = new Node('A');
    Node* B = new Node('B');
    Node* C = new Node('C');
    Node* D = new Node('D');
    Node* E = new Node('E');
    Node* F = new Node('F');
    Node* G = new Node('G');
    Node* H = new Node('H');
    Node* I = new Node('I');
    Node* J = new Node('J');
    Node* K = new Node('K');
    Node* L = new Node('L');
    Node* M = new Node('M');
    Node* N = new Node('N');
    Node* O = new Node('O');
    Node* P = new Node('P');
    Node* Q = new Node('Q');

    A->left = B;
    B->right = C;
    C->right = D;
    D->right = E;
    E->right = F;
    F->right = G;

    D->left = H;

    E->left = I;
    I->right = J;

    J->left = P;
    P->right = Q;

    F->left = K;
    K->right = L;
    L->right = M;

    G->left = N;
    N->right = O;

    std::cout << "Preorder Traversal: ";
    preorder(A);
    std::cout << "\n";

    std::cout << "Postorder Traversal: ";
    postorder(A);
    std::cout << "\n";

    std::cout << "Inorder Traversal: ";
    inorder(A);
    std::cout << "\n\n";

    findData(A, "PRE", 'O');   // search with preorder
    findData(A, "IN", 'O');    // not found
    findData(A, "POST", 'O');  // search with postorder

    return 0;
}
