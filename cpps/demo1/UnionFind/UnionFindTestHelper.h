//
// Created by 黎进 on 2018/8/27.
//

#ifndef DEMO1_UNIONFINDTESTHELPER_H
#define DEMO1_UNIONFINDTESTHELPER_H

#include <iostream>
#include <cassert>

#include "UnionFind1.h"

using namespace std;

namespace UnionFindTestHelper {

    void testUF1(int n){

        srand(time(NULL));
        UF1::UnionFind1 uf1 = UF1::UnionFind1(n);

        time_t startTime = clock();

        // 随机的链接两个元素
        for (int i = 0; i < n; i++) {
            int a = rand()%n;
            int b = rand()%n;
            uf1.unionElements(a, b);
        }

        // 两个元素是否连接
        for (int j = 0; j < n; j++) {
            int p = rand()%n;
            int q = rand()%n;
            uf1.isContected(p, q);
        }

        time_t endTime = clock();

        // 输出时间
        cout << "UF1: " << n << " ops, " << double(endTime - startTime) / CLOCKS_PER_SEC << "s" << endl;
    }
}

#endif //DEMO1_UNIONFINDTESTHELPER_H
