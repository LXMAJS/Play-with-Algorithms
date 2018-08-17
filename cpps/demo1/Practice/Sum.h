//
// Created by 黎进 on 2018/8/16.
//

#ifndef DEMO1_SUM_H
#define DEMO1_SUM_H

#include <iostream>
#include "../BinarySearch/BinarySearch.h"
#include "../Sort-Alogrithms/SortAlogrithms.h"

using namespace  std;

namespace Practice_Sum {

    /// 求数组中两个数之和是某个数，返回这个数
    int* twoSum(int arr[], int n, int target){
        int* res = new int[2];

        // 首先使用快速排序将整个数组排序
        SortAlogrithms::quickSortTribleRoute(arr, n);
//
//        for (int i = 0; i < n; i ++) {
//            int firstNum = arr[i];
//            int secondNum = target - firstNum;
//            if(secondNum <= 0)
//                return res;
//
//            // 使用二分查找法找到第二个数，如果有，就直接返回这两个数
//            secondNum = BinarySearch::binarySearch(arr, n, secondNum);
//            if(secondNum >= -1){
//                res[0] = firstNum;
//                res[1] = secondNum;
//                return res;
//            }
//        }

        for (int index = 0; index < n; index ++) {
            int targetNum = target - arr[index];
            if(targetNum < 0)
                return NULL;

            for (int jndex = index + 1; jndex < n; jndex ++) {
                if(arr[jndex] == targetNum){
                    res[0] = arr[index];
                    res[1] = targetNum;
                    return res;
                }
            }
        }
    }
};

#endif //DEMO1_SUM_H
