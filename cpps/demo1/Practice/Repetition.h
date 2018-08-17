//
// Created by 黎进 on 2018/8/17.
// 这里汇总我写过的关于 重复问题 的代码
//

#ifndef DEMO1_REPETITION_H
#define DEMO1_REPETITION_H

using namespace  std;

namespace Practice_Repetition {
    /*
     * 给定一个排序数组，你需要在原地删除重复出现的元素，使得每个元素只出现一次，返回移除后数组的新长度。
     * 不要使用额外的数组空间，你必须在原地修改输入数组并在使用 O(1) 额外空间的条件下完成。
     */
    int deleteRepeatItem(int arr[], int n){

        int j = 0; // 表示当前新数组的下标
        for (int i = 1; i < n; ++i) {
            if(arr[i] != arr[j]){
                arr[++j] = arr[i];
            }
        }
        return j + 1; // 返回的是数组的长度
    }
}
#endif //DEMO1_REPETITION_H
