#ifndef BASEENCODE_H_
#define BASEENCODE_H_

#include <iostream>
#include <map>
#include <fstream>
#include "huffTree.h"
#include <QObject>
#include <QString>

//得到index位的值，若index位为0，则GET_BYTE值为假，否则为真
#define GET_BYTE(vbyte, index) (((vbyte) & (1 << ((index) ^ 7))) != 0)
//index位置1
#define SET_BYTE(vbyte, index) ((vbyte) |= (1 << ((index) ^ 7)))
//index位置0
#define CLR_BYTE(vbyte, index) ((vbyte) &= (~(1 << ((index) ^ 7))))

using namespace std;


struct fileHead {
    char flag[4]; // 压缩二进制文件头部标志
    short alphaVariety;  // 字符种类
    unsigned char lastValidBit;   // 最后一个字符的有效位数
    char fileName[50];    // 存储文件名
};



struct alphaFreq {
    unsigned char alpha;   // 字符，考虑到有汉字 使用unsigned char
    int freq;     // 字符出现的频率
    alphaFreq() {

    }

    alphaFreq(const std::pair<char, int>& x)
        : alpha(x.first), freq(x.second) {

    }
};

class huffEncode {
private:
    std::map<unsigned char, int> _afMap; // 字符及其频数
    std::map<unsigned char, std::string> _codeMap; // 字符及其 Haffman 编码

public:
    bool encode(const char* srcFilename, const char* destFilename) {
        if (!_getAlphaFreq(srcFilename)) return false;
        huffTree htree(_afMap);
        htree.huffmanCode(_codeMap);
        return _encode(srcFilename, destFilename);
    }
private:
    int _getLastValidBit() { // 最后字符的有效位数
        int sum = 0;
        for (auto it : _codeMap) {
            sum += it.second.size() * _afMap.at(it.first);
            sum &= 0xFF;
        }
        sum &= 0x7;
        return sum == 0 ? 8 : sum;
    }

    bool _getAlphaFreq(const char* filename) { // 获得指定文件的字符频数
        unsigned char ch;
        std::ifstream is(filename, std::ios::binary);
        if (!is.is_open()) { // 打开文件失败
            printf("read file failed! filename: %s", filename);
            return false;
        }
        is.read((char*)&ch, sizeof(unsigned char));
        while (!is.eof()) {
            _afMap[ch]++; // 频数加一
            is.read((char*)&ch, sizeof(unsigned char));
        }
        is.close();
        return true;
    }

    bool _encode(const char* srcFilename, const char* destFilename);

};


class huffDecode{
private:
    fileHead* _fileHead;
    huffTree* _htree;
    std::map<uchar, int> _afMap;
    std::map<uchar, std::string> _codeMap;
    std::map<std::string, uchar> _decodeMap;

public:
    huffDecode() : _fileHead(nullptr), _htree(nullptr) {
        _fileHead = new fileHead();
    }
    ~huffDecode() {
        if (!_fileHead) delete _fileHead;
        if (!_htree) delete _htree;
    }

private:
    static bool _isLeaf(Node* n) { // 判断是否是叶子节点
        return n->left == nullptr && n->right == nullptr;
    }

    long long _getFileSize(const char* strFileName) { // 获得文件大小
        std::ifstream in(strFileName);
        if (!in.is_open()) return 0;

        in.seekg(0, std::ios_base::end);
        std::streampos sp = in.tellg();
        in.close();
        return sp;
    }

    bool _getAlphaFreq(const char* filename) { // 读取头：字符及其频率
        std::ifstream is(filename, std::ios::binary);
        if (!is) {
            printf("read file failed! filename: %s", filename);
            return false;
        }

        is.read((char*)_fileHead, sizeof(fileHead)); // 读取文件头
        if (!(_fileHead->flag[0] == 'e' &&
            _fileHead->flag[1] == 'v' &&
            _fileHead->flag[2] == 'e' &&
            _fileHead->flag[3] == 'n')) {
            printf("not support this file format! filename: %s\n", filename);
            return false;
        }


        for (int i = 0; i < static_cast<int>(_fileHead->alphaVariety); ++i) {
            alphaFreq af;
            is.read((char*)&af, sizeof(af));
            _afMap.insert(std::pair<char, int>(af.alpha, af.freq));
        }
        is.close();
        return true;
    }

    bool _decode(const char* srcFilename, const char* destFolder) {
        string destFilename(destFolder);
        destFilename += '/';
        destFilename += string(_fileHead->fileName);

        long long fileSize = _getFileSize(srcFilename);  // 获取文件大小

        std::ifstream is(srcFilename, std::ios::binary);
        if (!is) {
            printf("read file failed! filename: %s", srcFilename);
            return false;
        }
        is.seekg(sizeof(fileHead) + sizeof(alphaFreq) * _fileHead->alphaVariety); // 到达文件头后部

        Node node = _htree->getHuffTree();
        Node* pNode = &node;

        std::ofstream io(destFilename, std::ios::binary);
        if (!io) {
            cout << "create file failed! filename: " << destFilename << endl;
            return false;
        }

        uchar value; // 一个字节
        std::string code; // 霍夫曼编码
        int index = 0;
        long long curLocation = is.tellg();
        is.read((char*)&value, sizeof(uchar));
        while (1) {
            if (_isLeaf(pNode)) { // 当前节点是叶子节点
                uchar alpha = _decodeMap[code]; // 译码 霍夫曼编码 -> 字节
                io.write((char*)&alpha, sizeof(uchar)); // 写入文件
                if ( (curLocation >= fileSize && index >= _fileHead->lastValidBit) || (curLocation == -1)) { // 循环退出条件
                    break;
                }
                code.clear();  // 霍夫曼编码清空
                pNode = &node; // 重置指针
            }

            // 当前节点不是叶子节点  if-else 霍夫曼编码生成
            if (GET_BYTE(value, index)) {
                code += '1';
                pNode = pNode->right;
            }
            else {
                pNode = pNode->left;
                code += '0';
            }
            if (++index >= 8) { // 读8位读完value 再从文件中读取8位(霍夫曼编码位)
                index = 0;
                is.read((char*)&value, sizeof(uchar));
                curLocation = is.tellg();
            }
        }

        is.close();
        io.close();
        return true;
    }
public:
    bool decode(const char* srcFilename, const char* destFilename) {
        if (!_getAlphaFreq(srcFilename)) return false;
        _htree = new huffTree(_afMap);
        _htree->huffmanCode(_codeMap);

        for (auto it : _codeMap) {
            _decodeMap.insert(std::pair<std::string, uchar>(it.second, it.first));
        }

        return _decode(srcFilename, destFilename);
    }
};


#endif

