#include <iostream>
using namespace std;

// Düğüm yapısı
template <class T>
struct node {
    T data;
    node* left_node;
    node* right_node;
};

// BST sınıfı
template <class T>
class BSearchTree {
private:
    node<T>* root;

    // Yardımcı Fonksiyonlar
    void inorderTraversal(node<T>* p) {
        if (p != NULL) {
            inorderTraversal(p->left_node);
            cout << p->data << " ";
            inorderTraversal(p->right_node);
        }
    }

    bool deleteFromTree(node<T>*& p) {
        node<T>* temp;
        if (p == NULL) return true;  // Silinecek düğüm yok

        // Yaprak düğüm
        if (p->left_node == NULL && p->right_node == NULL) {
            temp = p;
            p = NULL;
            delete temp;
        }
        // Tek çocuklu düğüm (sağ çocuk)
        else if (p->left_node == NULL) {
            temp = p;
            p = temp->right_node;
            delete temp;
        }
        // Tek çocuklu düğüm (sol çocuk)
        else if (p->right_node == NULL) {
            temp = p;
            p = temp->left_node;
            delete temp;
        }
        // İki çocuklu düğüm
        else {
            node<T>* c = p->left_node;
            node<T>* prev = NULL;

            // Inorder predecessor bul
            while (c->right_node != NULL) {
                prev = c;
                c = c->right_node;
            }
            p->data = c->data;  // Inorder predecessor değerini kopyala

            if (prev == NULL)
                p->left_node = c->left_node;
            else
                prev->right_node = c->left_node;

            delete c;
        }
        return false;
    }

public:
    BSearchTree() { root = NULL; }

    // Ekleme
    bool insertB(T& key) {
        node<T>* newNode = new node<T>;
        newNode->data = key;
        newNode->left_node = NULL;
        newNode->right_node = NULL;

        if (root == NULL) {
            root = newNode;
            return true;
        }

        node<T>* p = root;
        node<T>* q = NULL;

        while (p != NULL) {
            q = p;
            if (key < p->data)
                p = p->left_node;
            else
                p = p->right_node;
        }

        if (key < q->data)
            q->left_node = newNode;
        else
            q->right_node = newNode;

        return true;
    }

    // Silme
    bool deleteB(T& data) {
        node<T>* p = searchBST(data);
        if (!p) return false;  // Veri bulunamadı
        return deleteFromTree(p);
    }

    // Arama
    node<T>* searchBST(T& key) {
        node<T>* p = root;
        while (p != NULL) {
            if (p->data == key)
                return p;
            else if (key < p->data)
                p = p->left_node;
            else
                p = p->right_node;
        }
        return NULL;
    }

    // Inorder Traversal
    void inorder() { inorderTraversal(root); }
};

// Ana fonksiyon
int main() {
    BSearchTree<int> bst;

    // Değerler ekle
    int values[] = {15, 10, 20, 8, 12, 17, 25};
    for (int val : values)
        bst.insertB(val);

    // Inorder Traversal
    cout << "Inorder Traversal: ";
    bst.inorder();
    cout << endl;

    // Silme
    int deleteKey = 10;
    bst.deleteB(deleteKey);
    cout << "10 Silindikten Sonra Inorder Traversal: ";
    bst.inorder();
    cout << endl;

    return 0;
}
