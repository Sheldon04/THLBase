#include "avltree.h"

AVLTree::AVLTree()
{
    this->root = nullptr;
}

int AVLTree::height()
{
    return height(this->root);
}

void AVLTree::insert(QString name, int idx)
{
    insert(this->root, name, idx);
}

int AVLTree::search(QString name)
{
    AVLNode *ret = search(this->root, name);
    return ret == nullptr ? -1 : ret->idx;
}

void AVLTree::destroy()
{
    destroy(this->root);
    this->root = nullptr;
}

void AVLTree::preOrder()
{
    preOrder(this->root);
}

void AVLTree::preOrder(AVLNode *tree)
{
    if (tree == nullptr) return;
    qDebug() << tree->name << endl;
    cnt++;
    preOrder(tree->lchild);
    preOrder(tree->rchild);
}

// 避免空指针出现的问题
int AVLTree::height(AVLNode *tree)
{
    if (tree == nullptr) return 0;
    return tree->height;
}

AVLNode *AVLTree::search(AVLNode *x, QString key)
{
    while ((x != nullptr) && x->name.compare(key) != 0)
    {
        if (key.compare(x->name) < 0)
            x = x->lchild;
        else
            x = x->rchild;
    }
    return x;
}

AVLNode *AVLTree::LLRotation(AVLNode *k2)
{
    AVLNode *k1 = k2->lchild;
    k2->lchild = k1->rchild;
    k1->rchild = k2;

    k2->height = max(height(k2->lchild), height(k2->rchild)) + 1;
    k1->height = max(height(k1->lchild), k2->height) + 1;

    return k1;
}

AVLNode *AVLTree::RRROtation(AVLNode *k1)
{
    AVLNode *k2 = k1->rchild;
    k1->rchild = k2->lchild;
    k2->lchild = k1;

    k1->height = max(height(k1->lchild), height(k1->rchild)) + 1;
    k2->height = max(height(k2->rchild), k1->height) + 1;

    return k2;
}

AVLNode *AVLTree::LRRoatation(AVLNode *k3)
{
    k3->lchild = RRROtation(k3->lchild);
    return LLRotation(k3);
}

AVLNode *AVLTree::RLRoatation(AVLNode *k1)
{
    k1->rchild = LLRotation(k1->rchild);
    return RRROtation(k1);
}

AVLNode *AVLTree::insert(AVLNode * &tree, QString name, int idx)
{
    if (tree == nullptr)
    {
        tree = new AVLNode(name, idx, nullptr, nullptr);
        if (tree == nullptr)
        {
//            qDebug() << "内存不足插入失败" << endl;
            return nullptr;
        }
//        qDebug() << ">>>新节点: " << tree->name << " 左子树高度: " << height(tree->lchild) << " 右子树高度: " << height(tree->rchild) << endl;
    }
    else if (name.compare(tree->name) < 0)
    {
//        qDebug() << tree->name << "向左" << endl;
        tree->lchild = insert(tree->lchild, name, idx);
//        qDebug() << "节点: " << tree->name << " 左子树高度: " << height(tree->lchild) << " 右子树高度: " << height(tree->rchild) << endl;
        if (height(tree->lchild) - height(tree->rchild) >= 2)
        {
//            qDebug() << "rotate" << endl;
            if (name.compare(tree->lchild->name) < 0)
            {
//                qDebug() << "LL" << endl;
                tree = LLRotation(tree);
            }
            else
            {
//                qDebug() << "LR" << endl;
                tree = LRRoatation(tree);
            }
        }
    }
    else if (name.compare(tree->name) > 0)
    {
//        qDebug() << tree->name << "向右" << endl;
        tree->rchild = insert(tree->rchild, name, idx);
//        qDebug() << "节点: " << tree->name << " 左子树高度: " << height(tree->lchild) << " 右子树高度: " << height(tree->rchild) << endl;
        if (height(tree->rchild) - height(tree->lchild) >= 2)
        {
//            qDebug() << "rotate" << endl;
            if (name.compare(tree->rchild->name) > 0)
            {
//                qDebug() << "RR" << endl;
                tree = RRROtation(tree);
            }
            else
            {
//                qDebug() << "RL" << endl;
                tree = RLRoatation(tree);
            }

//            qDebug() << "rotate" << endl;
        }
    }
    else if (name.compare(tree->name) == 0)
    {

    }

    tree->height = max(height(tree->lchild), height(tree->rchild)) + 1;

    return tree;
}

void AVLTree::destroy(AVLNode *tree)
{
    if (tree == nullptr) return;

    if (tree->lchild != nullptr)
        destroy(tree->lchild);
    else if (tree->rchild != nullptr)
        destroy(tree->rchild);

    delete tree;
}


