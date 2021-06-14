#include "service.h"

Service::Service()
{

}

void Service::quicksort(std::vector<oneSearchInfo> &a, SortKey key)
{
    Service::shuffle(a);
    _sort(a, 0, a.size() - 1, key);
}

void Service::_sort(std::vector<oneSearchInfo> &a, int lo, int hi, SortKey key)
{
    if (lo >= hi) return;
    // 该操作后pos左边的数都比它小，右边的数都比它大
    int pos = partition(a, lo, hi, key);
    // 递归调用
    _sort(a, lo, pos - 1, key);
    _sort(a, pos + 1, hi, key);
}

void Service::shuffle(std::vector<oneSearchInfo> &a)
{
    std::random_device rd;
    std::mt19937 rng(rd());
    std::shuffle(a.begin(), a.end(), rng);
}

int Service::partition(std::vector<oneSearchInfo> &a, int lo, int hi, SortKey key)
{
    int i = lo, j = hi + 1;
    while (true)
    {
        // 在左边找比a[lo]大的数
        while (myCompare(a[++i], a[lo], key) < 0)
            if (i == hi) break;
        // 在右边找比a[lo]小的数
        while (myCompare(a[--j], a[lo], key) > 0)
            if (j == lo) break;
        // 结束
        if (i >= j) break;
        // 把比a[lo]小的数字移到左边，比a[lo]大的数移动右边
        exch(a, i, j);
    }
    // j指向所有比a[lo]小的数中最右边的数的位置
    exch(a, j, lo);
    return j;
}



void Service::exch(std::vector<oneSearchInfo> &a, int i, int j)
{
    oneSearchInfo temp = a[i];
    a[i] = a[j];
    a[j] = temp;
}

int Service::myCompare(const oneSearchInfo &a, const oneSearchInfo &b, SortKey key)
{
    int ret = 0;
    switch (key) {
    case ID:
        return a.miR_index.toInt() - b.miR_index.toInt();
    case CG:
        return a.CG.toDouble() - b.CG.toDouble();
    case DG:
        return a.dG.toDouble() - b.dG.toDouble();
    case MIR_NAME:
        return a.miR_name.compare(b.miR_name);
    }
    qDebug() <<"Unknow error in myCompare" << endl;
    return ret;
}
