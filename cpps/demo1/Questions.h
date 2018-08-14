//
// Created by 黎进 on 2018/8/14.
//

#ifndef DEMO1_QUESTIONS_H
#define DEMO1_QUESTIONS_H

#include <iostream>

using namespace std;

namespace Questions{

    // 求数组中第n大元素的值
    // 被理解为 排好序后，第n个索引位置的元素的值
    // 使用三路快排的思想

    template <typename T>
    T __getNthItemInArray(T arr[], int l, int r, int n){

        // 如果取值范围已经不包含n了，就直接返回n
        if(l > r || n > r || n < 0)
            return NULL;

        swap(arr[l], arr[rand()%(r - l + 1) + l]);

        T tempValue = arr[l];
        int lt = l; // arr[l + 1, lt] < v
        int gt = r; // arr[gt, r] > v
        int i = l + 1; // arr[lt + 1, i) == v

        while(i > gt){

            if(arr[i] < tempValue){
                swap(arr[lt + 1], arr[i]);
                i ++;
                lt ++;
            }
            else if(arr[i] > tempValue){
                swap(arr[gt], arr[i]);
                gt ++;
            }
            else{
                i ++;
            }
        }

        swap(arr[l], arr[lt]);

        T res = NULL;
        if(lt <= n && n <= gt){
            res = arr[n];
        }
        else if(l < n && n < lt){
            res = __getNthItemInArray(arr, l, lt - 1);
        }
        else if(gt < n && n < r){
            res = __getNthItemInArray(arr, gt,r);
        }
        return res;
    }


    // 获得数组中第n大的元素
    template <typename T>
    T getNthItemInArray(T arr[], int length, int n){
        srand(time(NULL));
        int index = __getNthItemInArray(arr, 0, length -1, n);
        if(index > length)
            return NULL;
        T item = arr[index];
        return item;
    }

}

#endif //DEMO1_QUESTIONS_H
