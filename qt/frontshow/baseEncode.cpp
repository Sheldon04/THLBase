#include "baseEncode.h"
#include <sstream>
#include <cstring>

using namespace std;

string getFileNameFromThePath(string path) {
    stringstream sstrm; sstrm.str("");
    for (size_t i = 0; i < path.length(); i++) {
        if (path[i] == '/') sstrm.str("");
        else {
            sstrm << path[i];
        }
    }
    return sstrm.str();
}

bool huffEncode::_encode(const char* srcFilename, const char* destFilename) {
    unsigned char ch;
    unsigned char value = 0x11;
    int bitIndex = 0;

    fileHead filehead;
    filehead.flag[0] = 'e';
    filehead.flag[1] = 'v';
    filehead.flag[2] = 'e';
    filehead.flag[3] = 'n';
    filehead.alphaVariety = (short)_afMap.size();
    filehead.lastValidBit = _getLastValidBit();
    strcpy(filehead.fileName, getFileNameFromThePath(srcFilename).c_str()); // 添加文件名

    std::ifstream is(srcFilename, std::ios::binary); // 读取文件

    if (!is.is_open()) {
        printf("read file failed! filename: %s", srcFilename);
        return false;
    }
    std::ofstream io(destFilename, std::ios::binary); // 输出文件
    if (!io.is_open()) {
        printf("read file failed! filename: %s", destFilename);
        return false;
    }

    io.write((char*)&filehead, sizeof(fileHead)); // 将fileHead写入输出文件
    for (auto i : _afMap) { // 将各个字符及其频率写入文件
        alphaFreq af(i);
        io.write((char*)&af, sizeof(alphaFreq));
    }

    // 循环写入霍夫曼编码
    is.read((char*)&ch, sizeof(unsigned char));
    while (!is.eof()) {
        std::string code = _codeMap.at(ch);
        for (auto c : code) {
            if ('0' == c) {
                CLR_BYTE(value, bitIndex);
            }
            else {
                SET_BYTE(value, bitIndex);
            }
            ++bitIndex;
            if (bitIndex >= 8) {
                bitIndex = 0;
                io.write((char*)&value, sizeof(unsigned char));
            }
        }
        is.read((char*)&ch, sizeof(unsigned char));
    }

    if (bitIndex) { // 如果剩下的不足一个字节 那么写入一个字节
        io.write((char*)&value, sizeof(unsigned char));
    }

    is.close();
    io.close();

    return true;
}















