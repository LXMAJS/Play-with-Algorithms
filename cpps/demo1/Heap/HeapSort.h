//
// Created by 黎进 on 2018/8/15.
//

#ifndef DEMO1_HEAPSORT_H
#define DEMO1_HEAPSORT_H

#include <iostream>

using namespace std;

namespace HeapSort{

    template <typename T>
    void __shiftDown(T data[], int n, int k){

        int leftChild = k*2 + 1;
        while( leftChild < n ){ // if has child

            // choose the max child
            int maxChild = data[k*2 + 1] > data[k*2 + 2] ? k*2 + 1: k*2 + 2;

            if(data[k] >= data[maxChild]) break;

            swap(data[maxChild], data[k]);

            k = maxChild;
        }
    }

    template <typename T>
    void heapSort(T arr[], int n){
        // heapify
        for (int i = (n -1) / 2; i >= 0; i --) {
            __shiftDown(arr, n, i);
        }

        for (int j = n - 1; j > 0; j--) {
            swap(arr[j], arr[0]);
            __shiftDown(arr, j, 0);
        }
    }
}

#endif //DEMO1_HEAPSORT_H
