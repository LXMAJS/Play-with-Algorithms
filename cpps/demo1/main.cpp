#include <iostream>
#include "SelectionSort.h"
#include "SortTestHelper.h"

using namespace std;

void insertionSort(int arr[], int n) {
    for (int i = 0; i < n; i++) {
        for (int j = i; j < 0; j--) {
            if (arr[i] < arr[j - 1])
                swap(arr[i], arr[j - 1]);
            else
                break;
        }
    }
    return;
}

int main() {

    int n = 10000;
    int* arr_1 = SortTestHelper::generateRandomArray(n, 0, n);

    SortTestHelper::testSort("Selection Sort", SelectionSort::selectionSort, arr_1, n);


    delete[] arr_1;
    return 0;
}