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
            for( int j = i ; j > 0 && arr[j] < arr[j-1] ; j -- )
                swap( arr[j] , arr[j-1] );
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

    // insertion sort, can sort range from left to right
    template <typename T>
    void insertionSortPlus(T arr[], int leftPos, int rightPos){

        if(leftPos > rightPos)
            return;

        for (int i = leftPos; i < rightPos; ++i) {
            T tempValue = arr[i];
            int j;
            for (j = i; j > leftPos && tempValue < arr[j - 1]; j --) {
                arr[j] = arr[j - 1];
            }
            arr[j] = tempValue;
        }
    }
    // bubble sort
    template <typename T>
    void bubbleSort(T arr[], int n){

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n - (i + 1); j++) {
                if(arr[j] > arr[j + 1])
                    swap(arr[j], arr[j + 1]);
            }
        }
    }





    template <typename T>
    void __mergeArray(T arr[], int leftPos, int middlePos, int rightPos) {
        int n = rightPos - leftPos + 1;
        int * newArray = new T[n];

        int pos1 = leftPos;
        int pos2 = middlePos + 1;
        for (int i = 0; i < n; i++) {

            if(pos1 > middlePos) {
                newArray[i] = arr[pos2];
                pos2 ++;
            }
            else if(pos2 > rightPos) {
                newArray[i] = arr[pos1];
                pos1 ++;
            }
            else if(arr[pos1] < arr[pos2]) {
                newArray[i] = arr[pos1];
                pos1++;
            }
            else {
                newArray[i] = arr[pos2];
                pos2++;
            }
        }

        for (int j = 0; j < n; j ++) {
            arr[leftPos + j] = newArray[j];
        }
    }

    // merge sort private function
    template <typename T>
    void __mergeSort(T arr[], int leftPos, int rigthPos) {

        //if(leftPos >= rigthPos)
        //   return;

        // use insertion sort when number in range less then 15, the "15" is any other number you like
        if(rigthPos - leftPos <= 15){
            insertionSortPlus(arr, leftPos, rigthPos);
            return;
        }

        //warn!!! dangerous of memory overflow
        int middlePos = (rigthPos + leftPos)/2;

        __mergeSort(arr, leftPos, middlePos);
        __mergeSort(arr, middlePos + 1, rigthPos);

        // merge when left part of array has any items bigger then right part of array
        if(arr[middlePos] > arr[middlePos + 1])
            __mergeArray(arr, leftPos, middlePos, rigthPos);
    }

    // merge sort public function
    template <typename T>
    void mergeSort(T arr[], int n){
        __mergeSort(arr, 0, n-1);
    }
}

#endif //DEMO1_SORTALOGRITHMS_H
