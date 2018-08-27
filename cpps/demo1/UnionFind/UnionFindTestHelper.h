//
// Created by 黎进 on 2018/8/27.
//

#ifndef DEMO1_UNIONFINDTESTHELPER_H
#define DEMO1_UNIONFINDTESTHELPER_H

#include <iostream>
#include <cassert>

#include "UnionFind1.h"
#include "UnionFind2.h"
#include "UnionFind3.h"

using namespace std;

namespace UnionFindTestHelper {

    ///
    /// \param n
    void testUF1(int n){

        srand(time(NULL));
        UF1::UnionFind uf1 = UF1::UnionFind(n);

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
            uf1.isConnected(p, q);
        }

        time_t endTime = clock();

        // 输出时间
        cout << "UF1: " << n << " ops, " << double(endTime - startTime) / CLOCKS_PER_SEC << "s" << endl;
    }

    ///
    /// \param n
    void testUF2(int n){

        srand(time(NULL));
        UF2::UnionFind uf = UF2::UnionFind(n);

        time_t startTime = clock();

        // 随机的链接两个元素
        for (int i = 0; i < n; i++) {
            int a = rand()%n;
            int b = rand()%n;
            uf.unionElements(a, b);
        }

        // 两个元素是否连接
        for (int j = 0; j < n; j++) {
            int p = rand()%n;
            int q = rand()%n;
            uf.isConnected(p, q);
        }

        time_t endTime = clock();

        // 输出时间
        cout << "UF1: " << 2*n << " ops, " << double(endTime - startTime) / CLOCKS_PER_SEC << "s" << endl;
    }

    ///
    /// \param n
    void testUF3(int n){

        srand(time(NULL));
        UF3::UnionFind uf = UF3::UnionFind(n);

        time_t startTime = clock();

        // 随机的链接两个元素
        for (int i = 0; i < n; i++) {
            int a = rand()%n;
            int b = rand()%n;
            uf.unionElements(a, b);
        }

        // 两个元素是否连接
        for (int j = 0; j < n; j++) {
            int p = rand()%n;
            int q = rand()%n;
            uf.isConnected(p, q);
        }

        time_t endTime = clock();

        // 输出时间
        cout << "UF1: " << 2*n << " ops, " << double(endTime - startTime) / CLOCKS_PER_SEC << "s" << endl;
    }
}

#endif //DEMO1_UNIONFINDTESTHELPER_H
