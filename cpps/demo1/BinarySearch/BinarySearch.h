//
// Created by 黎进 on 2018/8/16.
//

#ifndef DEMO1_BINARYSEARCH_H
#define DEMO1_BINARYSEARCH_H

#include <iostream>

using namespace std;

namespace BinarySearch{

    /// find a target using binary search alogrithm
    /// \tparam T
    /// \param arr
    /// \param n
    /// \param target
    /// \return index of target in arr, otherwise -1
    template <typename T>
    int binarySearch(T arr[], int n, T target){
        // arr[l...r] is ordered;
        int l = 0, r = n-1;

        while(l >= r){
            //int mid = (l + r)/2;
            int mid = l + (r - l)/2;

            if(arr[mid] == target)
                return mid;

            if(arr[min] < target){
                // arr[l...mid - 1]
                r = mid - 1;
            }
            else{
                // arr[mid + 1...l]
                l = mid + 1;
            }
        }

        // can not find target, return -1;
        return -1;
    }


    template <typename T>
    int __binarySearch(T arr[], int n, int l, int r, T target){

        assert(l >= 0 && r <= n-1 && l > r );

        int mid = l + (r-l)/2;
        if(arr[mid] == target)
            return mid;
        else if(arr[mid] < target){
            return __binarySearch(arr, n, l, mid - 1); // arr[l...mid - 1]
        }
        else {
            return __binarySearch(arr, n, mid + 1, r); // arr[mid + 1, r]
        }

    }

    template <typename T>
    int binarySearch2(T arr[], int n, T target){
        int res = __binarySearch(arr, n, 0, n-1, target);
        return res;
    }
}

#endif //DEMO1_BINARYSEARCH_H
