#ifndef AVLTREE_H
#define AVLTREE_H

#include "global.h"

struct AVLNode {
    QString name;
    int idx;
    int height;
    AVLNode *lchild;
    AVLNode *rchild;

    AVLNode(QString _name, int _idx, AVLNode *l, AVLNode *r) :
        name(_name), idx(_idx), height(1), lchild(l), rchild(r) {}
};

class AVLTree
{
public:
    AVLTree();

    ~AVLTree() {destroy();}

    int height();

    void insert(QString name, int idx);

    int search(QString name);

    void destroy();

    void preOrder();

    int cnt = 0;

private:
    void preOrder(AVLNode *tree);

    int height(AVLNode *tree);

    int max(int a, int b) { return a > b ? a : b; }

    AVLNode * search(AVLNode *x, QString key);

    AVLNode *LLRotation(AVLNode *k2);

    AVLNode *RRROtation(AVLNode *k1);

    AVLNode *LRRoatation(AVLNode *k3);

    AVLNode *RLRoatation(AVLNode *k1);

    AVLNode * insert(AVLNode * &tree, QString name, int idx);

    void destroy(AVLNode *tree);

private:
    AVLNode *root;
};

#endif // AVLTREE_H
