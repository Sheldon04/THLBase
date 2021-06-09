#ifndef HUFFTREE_H_
#define HUFFTREE_H_
#include <map>
#include <string>
#include <queue>
using namespace std;
using uchar = unsigned char;

struct Node { // 树中的节点
    uchar c;  // 字符
    int freq; // 频数
    Node* left; // 左孩子
    Node* right; // 右孩子
    Node(uchar _c, int f, Node* l = nullptr, Node* r = nullptr)
        : c(_c), freq(f), left(l), right(r) {}
    bool operator<(const Node& node) const { //重载，优先队列的底层数据结构std::heap是最大堆
        return freq > node.freq;
    }
};

class huffTree {
private:
    std::priority_queue<Node> q; // 优先队列
public:
    huffTree(const std::map<uchar, int>& afMap) { // 构造器
        for (auto i : afMap) { // 对于 map<unsigned char, int> 存有字符及其频数 中的每一元素
            Node n(i.first, i.second); // 用字符及其频数 创出节点 并将其加入优先队列
            q.push(n);
        }
        _makehuffTree(); // 形成 huffman 树
    }

    ~huffTree() { // 析构函数
        Node node = q.top();
        _deleteTree(node.left);
        _deleteTree(node.right);
    }

    // huffman编码
    void huffmanCode(std::map<uchar, std::string>& codeMap) {
        Node node = q.top();
        string prefix;
        _huffmanCode(&node, prefix, codeMap);
    }

    Node getHuffTree() {
        return q.top();
    }

private:
    static bool _isLeaf(Node* n) {
        return n->left == nullptr && n->right == nullptr;
    }

    void _deleteTree(Node* n) { // 迭代删除指定根的树
        if (!n) return;
        _deleteTree(n->left);
        _deleteTree(n->right);
        delete n;
    }

    static void _printNode(Node* n) {
        if (!n) {
            printf("%c:%d\n", n->c, n->freq);
        }
    }

    // 循环生成huffman树
    void _makehuffTree() {
        while (q.size() != 1) { // 直到队列中只剩下一个节点 即根节点
            Node* left = new Node(q.top()); q.pop(); // 优先队列 出队列 将其转化成动态内存分配
            Node* right = new Node(q.top()); q.pop(); // 优先队列 出队列 将其转化成动态内存分配
            Node node('R', left->freq + right->freq, left, right); // 形成新的节点
            q.push(node); // 优先队列进队列
        }
    }

    // 获得 Huffman 编码和 prefix    传入根节点  prefix 和 codeMap 的引用
    void _huffmanCode(Node* root, std::string& prefix,
        std::map<uchar, std::string>& codeMap) {
        std::string tmp = prefix;
        if (root->left != nullptr) {
            prefix += '0';
            if (_isLeaf(root->left)) {
                codeMap[root->left->c] = prefix;
            }
            else {
                _huffmanCode(root->left, prefix, codeMap);
            }
        }
        if (root->right != nullptr) {
            prefix = tmp;
            prefix += '1';
            if (_isLeaf(root->right)) {
                codeMap[root->right->c] = prefix;
            }
            else {
                _huffmanCode(root->right, prefix, codeMap);
            }
        }
    }

};


#endif

