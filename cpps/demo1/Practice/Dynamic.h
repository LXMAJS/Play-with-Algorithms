//
// Created by 黎进 on 2018/8/24.
//

#ifndef DEMO1_DYNAMIC_H
#define DEMO1_DYNAMIC_H

#include <iostream>

using namespace std;

namespace Dynamic{

    /*
     * 假设你正在爬楼梯。需要 n 阶你才能到达楼顶。
     * 每次你可以爬 1 或 2 个台阶。你有多少种不同的方法可以爬到楼顶呢？
     *
     * 第 n 个台阶，有以下两种走法：
     * 1、 n-1 + 1
     * 2、 n-2 + 2
     *
     * 因此，n个台阶的走法，就有 climbStairs(n-1) + climbStairs(n-2) 种
     */

    int climbStairs(int n){

        int* arr = new int[n + 1];

        arr[0] = 0;
        arr[1] = 1;
        arr[2] = 2;

        for (int i = 3; i <= n; ++i) {
            arr[i] = arr[i - 1] + arr[i - 2];
        }

        return arr[n];
    }


    /*
     * 给定一个整数数组 nums ，找到一个具有最大和的连续子数组（子数组最少包含一个元素），返回其最大和。
     * 示例:
     * 输入: [-2,1,-3,4,-1,2,1,-5,4],
     * 输出: 6
     * 解释: 连续子数组 [4,-1,2,1] 的和最大，为 6。
     *
     * fun(i) = fun(i - 1) + arr[i]
     */
    int maxSum(int* arr){
         return 0;
    }


}
#endif //DEMO1_DYNAMIC_H
