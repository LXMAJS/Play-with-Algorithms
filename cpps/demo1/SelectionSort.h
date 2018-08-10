//
// Created by 黎进 on 2018/8/10.
//

#ifndef DEMO1_SELECTIONSORT_H
#define DEMO1_SELECTIONSORT_H

#include <iostream>

using namespace std;

namespace SelectionSort {

    // select sort
    void Sort(int arr[], int n){
        for (int i = 0; i < n; i++) {

            int minIndex = i;
            for (int j = i + 1; j < n; j++) {
                if(arr[j] < arr[minIndex])
                    minIndex = j;
            }

            swap(arr[i], arr[minIndex]);
        }
    }
}

#endif //DEMO1_SELECTIONSORT_H
