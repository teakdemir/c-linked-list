#include <iostream>
#include <cassert>

template <classT>
struct node{
 T data; //HOLDS THE VALUE İN THE NODE
 node<T> *right_node; // POINTER TO THE RIGHT CHILD NODE
 node<T> *left_node; // POINTER TO THE LEFT CHILD NODE

};

template <class T>

class BinaryTree{

protected:
node<T> *root;

private:
void destroyT(node<T> *);
 void inorderT(node<T> *);
 void preorderT(node<T> *);
 void postorderT(node<T> *);
 void copyT(node<T> *);
 void heightT(node<T> *);
 int maxT(node<T> *);
 int nodeCountT(node<T> *);
 int leavesCountT(node<T> *);

 public:
    BinaryTree() { root = NULL; }  // Yapıcı: Ağacı boş olarak başlatır
    ~BinaryTree() { destroyT(root); }  // Yıkıcı: Ağacı yok eder

    bool isEmpty() { return root == NULL; } // Ağaç boş mu?

    // Kullanıcıya sunulan gezinme metotları:
    void inorder() { inorderT(root); }
    void preorder() { preorderT(root); }
    void postorder() { postorderT(root); }

    // Ağaç bilgilerini döndüren metotlar:
    int treeHeight() { return heightT(root); }
    int nodeCount() { return nodeCountT(root); }
    int leavesCount() { return leavesCountT(root); }
};

template<class T>
void BinaryTree<T>::destroyT(node<T>*)
{
}

template <class T>
void BinaryTree<T>::  inorderT(node<T> *p){
if (p != NULL) {
        inorderT(p->left_node);  // Sol alt ağacı ziyaret et
        cout << p->data;         // Kök düğümü işle
        inorderT(p->right_node); // Sağ alt ağacı ziyaret et
    }

}

template <class T>
void BinaryTree<T>:: postordert(node<T> *p)
{
if(p !=NULL)
{
postorderT(p->left_node);
postorderT(p->right_node);
cout<<p->data;

}
}

template <class T>
void BinaryTree<T>:: preorderT(node<T> *p)
{
    if(p !=NULL){
        cout<<p->data;
postorderT(p->left_node);
postorderT(p->right_node);
    }

}
template <class T>
int BinaryTree<T>::maxT(int x, int y) {
    if (x >= y)
        return x;
    else
        return y;
}


template <class T>
int BinaryTree<T>::heightT(node<T> *p){
if(p != NULL){

    return(0);//boş tree
}
else {

    return 1+maxT(heigthT(p->left_node),heigthT(p->right_node)); 
}



}