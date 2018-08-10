//
// Created by 黎进 on 2018/8/10.
//

#ifndef DEMO1_SORTALOGRITHMS_H
#define DEMO1_SORTALOGRITHMS_H

#include <iostream>

using namespace std;

namespace SortAlogrithms {

    // select sort
    template <typename T>
    void selectionSort(T arr[], int n){

        for (int i = 0; i < n; i++) {

            int minIndex = i;
            for (int j = i + 1; j < n; j++) {
                if(arr[j] < arr[minIndex])
                    minIndex = j;
            }

            swap(arr[i], arr[minIndex]);
        }
    }


    // insertion sort
    template <typename T>
    void insertionSort(T arr[], int n){
        for (int i = 0; i < n; i++) {
            for (int j = i; j > 0; j--) {
                if (arr[i] < arr[j - 1])
                    swap(arr[i], arr[j - 1]);
                else
                    break;
            }
        }
    }

    // insertion sort plus
    template <typename T>
    void insertionSortPlus(T arr[], int n){
        for (int i = 0; i < n; i++) {
            T tempValue = arr[i];
            int j;
            for (j = i; j > 0 && tempValue < arr[j -1]; j--) {
                arr[j] = arr[j -1];
            }
            arr[j] = tempValue;
        }
    }
    
    template <typename T>
    void bubbleSort(T arr[], int n){

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n - (i + 1); j++) {
                if(arr[j] > arr[j + 1])
                    swap(arr[j], arr[j + 1]);
            }
        }
    }
}

#endif //DEMO1_SORTALOGRITHMS_H
