//
// Created by 黎进 on 2018/8/24.
//

#ifndef DEMO1_SIMPLEMATHEMATIC_H
#define DEMO1_SIMPLEMATHEMATIC_H


#include <iostream>
using namespace std;


namespace SimpleMathematic{

    /// 交换两个数，不使用额外的空间
    void exchangeTwoNumber(int a, int b){
        a = a + b;
        b = a - b;
        a = a - b;
        return;
    }

    /*
     * 有一个N*N的矩阵，请拟写一个方法，将矩阵进行顺指针旋转90度
     * 例如：[[1, 2], [3, 4]]，旋转后 [[3, 1], [4, 2]]
     */
    void rotate(vector<vector<int>>& matrix){
        int size = matrix.size() - 1;
        for (int i = 0; i < size; i++) {
            for (int j = 0; j < size; j++) {
                swap(matrix[i][j], matrix[j][size - i])；
            }
        }
    }
}
#endif //DEMO1_SIMPLEMATHEMATIC_H
