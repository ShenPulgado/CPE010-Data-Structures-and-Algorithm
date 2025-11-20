#include <iostream>
#include <vector>
#include <string>

struct Node {
    std::string data;              
    std::vector<Node*> children;   

    Node(std::string value) {
        data = value;
    }
};

void addChild(Node* parent, Node* child) {
    parent->children.push_back(child);
}

void displayTree(Node* root, int level = 0) {
    if (root == nullptr) return;

    for (int i = 0; i < level; i++)
        std::cout << "   ";
    std::cout << root->data << std::endl;

    for (auto child : root->children) {
        displayTree(child, level + 1);
    }
}

int main() {
    Node* A = new Node("A");
    Node* B = new Node("B");
    Node* C = new Node("C");
    Node* D = new Node("D");
    Node* E = new Node("E");
    Node* F = new Node("F");
    Node* G = new Node("G");
    Node* H = new Node("H");
    Node* I = new Node("I");
    Node* J = new Node("J");
    Node* K = new Node("K");
    Node* L = new Node("L");
    Node* M = new Node("M");
    Node* N = new Node("N");
    Node* P = new Node("P");
    Node* Q = new Node("Q");

    addChild(A, B);
    addChild(A, C);
    addChild(A, D);
    addChild(A, E);
    addChild(A, F);
    addChild(A, G);

    addChild(D, H);

    addChild(E, I);
    addChild(E, J);
    addChild(J, P);
    addChild(J, Q);

    addChild(F, K);
    addChild(F, L);
    addChild(F, M);

    addChild(G, N);

    std::cout << "Tree structure:\n";
    displayTree(A);

    return 0;
}
