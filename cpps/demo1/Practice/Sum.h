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

    ListNode addTwoNumbers(ListNode l1, ListNode l2) {
        ListNode p = l1;
        ListNode q = l2;
        ListNode result = new ListNode(0);
        ListNode temp = result;
        int bonus = 0;
        int sum = 0;

        while(p != NULL || q != NULL){
            sum = (p != NULL ? p->val : 0) + (q != NULL ? q->val : 0) + bonus;
            temp.next = new ListNode(sum % 10);
            temp = temp.next;

            if(sum > 10)
                bonus = 1;

            if(p != NULL) p = p.next;
            if(q != NULL) q = q.next;
        }


        if(bonus > 0)
            temp.next = new ListNode(bonus);

        return result.next;
    }

};

#endif //DEMO1_SUM_H
