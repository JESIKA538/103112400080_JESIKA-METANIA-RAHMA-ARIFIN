#ifndef BST_H
#define BST_H

#include "Node.h"

class BST {
public:
    Node* root;

    BST() {
        root = NULL;
    }

    bool isEmpty() {
        return root == NULL;
    }

    Node* newNode(string nama, float berat, string tier) {
        Node* temp = new Node;
        temp->namaMember = nama;
        temp->beratBadan = berat;
        temp->tierMember = tier;
        temp->left = NULL;
        temp->right = NULL;
        return temp;
    }

    void insertNode(Node* newData) {
        root = insert(root, newData);
    }

    Node* insert(Node* current, Node* newData) {
        if (current == NULL)
            return newData;

        if (newData->beratBadan < current->beratBadan)
            current->left = insert(current->left, newData);
        else
            current->right = insert(current->right, newData);

        return current;
    }

    // ================= SEARCH DENGAN PARENT =================
    Node* searchWithParent(Node* current, Node* parent, float berat, Node*& parentOut) {
        if (current == NULL) return NULL;

        if (current->beratBadan == berat) {
            parentOut = parent;
            return current;
        }

        if (berat < current->beratBadan)
            return searchWithParent(current->left, current, berat, parentOut);
        else
            return searchWithParent(current->right, current, berat, parentOut);
    }

    Node* searchByBeratBadan(float berat, Node*& parentOut) {
        parentOut = NULL;
        return searchWithParent(root, NULL, berat, parentOut);
    }

    // ================= MOST LEFT & RIGHT =================
    Node* mostLeft() {
        if (root == NULL) return NULL;
        Node* current = root;
        while (current->left != NULL)
            current = current->left;
        return current;
    }

    Node* mostRight() {
        if (root == NULL) return NULL;
        Node* current = root;
        while (current->right != NULL)
            current = current->right;
        return current;
    }

    // ================= INORDER =================
    void inOrder() {
        inOrderTraversal(root);
    }

    void inOrderTraversal(Node* current) {
        if (current != NULL) {
            inOrderTraversal(current->left);
            cout << current->beratBadan << " - ";
            inOrderTraversal(current->right);
        }
    }
};

#endif
