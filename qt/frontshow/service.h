#ifndef SERVICE_H
#define SERVICE_H

#include <algorithm>
#include <random>
#include "global.h"
#include "oneSearchInfo.h"

class Service
{
public:
    Service();

public:
    static void quicksort(std::vector<oneSearchInfo> &a, SortKey key);

private:
    static void _sort(std::vector<oneSearchInfo> &a, int lo, int hi, SortKey key);
    static void shuffle(std::vector<oneSearchInfo> &a);
    static int partition(std::vector<oneSearchInfo> &a, int lo, int hi, SortKey key);
    static void exch(std::vector<oneSearchInfo> &a, int i, int j);
    static void show(std::vector<oneSearchInfo> &a);
    static int myCompare(const oneSearchInfo & a, const oneSearchInfo & b, SortKey key);
};

#endif // SERVICE_H
