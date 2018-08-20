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


    /*
     * 给定两个非空链表来表示两个非负整数。位数按照逆序方式存储，它们的每个节点只存储单个数字。将两数相加返回一个新的链表。
     * 你可以假设除了数字 0 之外，这两个数字都不会以零开头。
     * 示例：
     * 输入：(2 -> 4 -> 3) + (5 -> 6 -> 4)
     * 输出：7 -> 0 -> 8
     * 原因：342 + 465 = 807
     */
    struct ListNode {
        int val;
        ListNode *next;

        ListNode(int x) : val(x), next(NULL) {}
    };

    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        if(l1 == NULL && l2 == NULL)
            return NULL;

        int sum = (l1 != NULL ? l1->val : 0) + (l2 != NULL ? l2->val : 0);

        ListNode* node = new ListNode(sum % 10);
        node->next = new ListNode(0);
        if(sum >= 10){
            if(l1 != NULL && l1->next != NULL) {
                l1->next->val += 10;
            }
            else if(l2 != NULL && l2->next != NULL){
                l2->next->val += 10;
            }
        }
        if(l1 != NULL && l2 != NULL && (l1->next != NULL || l2->next != NULL)) {
            node->next = addTwoNumbers(l1->next, l2->next);
        }
        return node;
    }

};

#endif //DEMO1_SUM_H
