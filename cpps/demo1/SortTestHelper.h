//
// Created by 黎进 on 2018/8/10.
//

#ifndef DEMO1_SORTTESTHELPER_H
#define DEMO1_SORTTESTHELPER_H


#include <iostream>
#include <ctime>
#include <algorithm>
#include <cassert>
#include <string>

using namespace std;

namespace SortTestHelper {

    //
    // return a array with n items, which range from rangeL to rangeR
    //
    int* generateRandomArray(int n, int rangeL, int rangeR) {

        assert(rangeL <= rangeR);

        int * arr = new int[n];

        // init time clock
        srand( time(NULL));
        for (int i = 0; i < n; i++) {
            arr[i] = rand() % (rangeR - rangeL + 1) + rangeL;
        }

        return arr;
    }


    //
    // if a array is sorted
    //
    template <typename T>
    bool isSorted(T * arr, int n){

        for (int i = 0; i < n - 1; i++) {
            if(arr[i] > arr[i + 1])
                return false;
        }

        return true;
    }


    //
    // print an array
    //
    template <typename T>
    void printArray(T * arr, int n){

        for (int i = 0; i < n; i++) {
            cout << arr[i] << " ";
        }
        cout << endl;
    }


    //
    // test sort alog
    //
    template <typename T>
    void testSort(string sortName, void(*sort(T arr[], int n)), T arr[], int n){

        // count times when sorting
        clock_t  startTime = clock();
        sort(arr, n);
        clock_t  endTime = clock();

        assert(isSorted(arr, n));

        cout << sortName << " : " << double(endTime - startTime) / CLOCKS_PER_SEC << " s" << endl;

        return;
    }
}

#endif //DEMO1_SORTTESTHELPER_H
