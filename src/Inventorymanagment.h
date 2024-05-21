#ifndef INVENTORYMANAGMENT_H
#define INVENTORYMANAGMENT_H
#include <iostream>
#include <fstream>
#include <string>
using namespace std;

struct Item {
    string name;
    int score;

    Item(const string& itemName, int itemScore) : name(itemName), score(itemScore) {}
};

struct Node {
    Item* item;
    Node* left;
    Node* right;
    int height;

    Node(Item* itemPtr) : item(itemPtr), left(nullptr), right(nullptr), height(1) {}
};

class AVLTree {
public:
    AVLTree() : root(nullptr) {}

    int height() {
        return height(root);
    }

    int height(Node* node) {
        if (node == nullptr)
            return 0;
        return node->height;
    }

    int balanceFactor(Node* node) {
        if (node == nullptr)
            return 0;
        return height(node->left) - height(node->right);
    }

    Node* rotateRight(Node* y) {
        Node* x = y->left;
        Node* T2 = x->right;

        x->right = y;
        y->left = T2;

        y->height = 1 + max(height(y->left), height(y->right));
        x->height = 1 + max(height(x->left), height(x->right));

        return x;
    }

    Node* rotateLeft(Node* x) {
        Node* y = x->right;
        Node* T2 = y->left;

        y->left = x;
        x->right = T2;

        x->height = 1 + max(height(x->left), height(x->right));
        y->height = 1 + max(height(y->left), height(y->right));

        return y;
    }

    Node* balance(Node* node) {
        if (node == nullptr)
            return nullptr;

        int bf = balanceFactor(node);

        if (bf > 1) {
            if (balanceFactor(node->left) < 0) {
                node->left = rotateLeft(node->left);
            }
            return rotateRight(node);
        } else if (bf < -1) {
            if (balanceFactor(node->right) > 0) {
                node->right = rotateRight(node->right);
            }
            return rotateLeft(node);
        }

        return node;
    }

    void insert(const string& itemName, int itemScore) {
        Item* item = new Item(itemName, itemScore);
        root = insert(root, item);
    }

    Node* insert(Node* node, Item* item) {
    if (node == nullptr)
        return new Node(item);

    if (item->name < node->item->name)
        node->left = insert(node->left, item);
    else if (item->name > node->item->name)
        node->right = insert(node->right, item);
    else {
        // If item name matches, accumulate the score
        node->item->score += item->score;
        delete item; // Delete the newly created item
        return node; // No need to create a new node
    }

    return balance(node);
}


    void remove(const string& itemName) {
        if (root == nullptr) {
            cout << "Error: Tree is empty." << endl;
            return;
        }
        root = remove(root, itemName);
    }

    Node* remove(Node* node, const string& itemName) {
        if (node == nullptr)
            return node;

        if (itemName < node->item->name)
            node->left = remove(node->left, itemName);
        else if (itemName > node->item->name)
            node->right = remove(node->right, itemName);
        else {
            if ((node->left == nullptr) || (node->right == nullptr)) {
                Node* temp;
                if (node->left != nullptr)
                    temp = node->left;
                else
                    temp = node->right;

                if (temp == nullptr) {
                    temp = node;
                    node = nullptr;
                } else
                    *node = *temp;

                delete temp->item;
                delete temp;
            } else {
                Node* temp = minValueNode(node->right);

                node->item = temp->item;

                node->right = remove(node->right, temp->item->name);
            }
        }

        if (node == nullptr)
            return node;

        return balance(node);
    }

    void insertFromFile(const string& filename) {
    ifstream file(filename);
    if (!file.is_open()) {
        cerr << "Error: Unable to open file " << filename << endl;
        return;
    }

    int score;
    string itemName;

    while (file >> score >> ws && getline(file, itemName)) {
        Item* item = new Item(itemName, score);
        root = insert(root, item);
    }

    file.close();
}


    void display() {
        if (root == nullptr) {
            cout << "Inventory is empty." << endl;
        } else {
            Preorder(root);
        }
    }

private:
    Node* root;

    Node* minValueNode(Node* node) {
        Node* current = node;
        while (current->left != nullptr)
            current = current->left;
        return current;
    }

    void Preorder(Node* node) {
        if (node != nullptr) {
             cout << "Item Name: " << node->item->name << ", Score: " << node->item->score << endl;
            Preorder(node->left);
            Preorder(node->right);
        }
    }
};


#endif // INVENTORYMANAGMENT_H