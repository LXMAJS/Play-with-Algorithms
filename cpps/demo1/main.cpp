#include <iostream>
#include "SortAlogrithms.h"
#include "SortTestHelper.h"

using namespace std;

int main() {

    int n = 1000000;
    int* arr_1 = SortTestHelper::generateNearlyOrderArray(n, 100);
    int* arr_2 = SortTestHelper::copyIntArray(arr_1, n);
    //int* arr_3 = SortTestHelper::copyIntArray(arr_1, n);

    //SortTestHelper::testSort("Selection Sort", SortAlogrithms::selectionSort, arr_1, n);

    //SortTestHelper::testSort("Insertion Sort", SortAlogrithms::insertionSort, arr_2, n);

    //SortTestHelper::testSort("Bubble Sort", SortAlogrithms::bubbleSort, arr_3, n);

    SortTestHelper::testSort("Quick Sort", SortAlogrithms::quickSort, arr_1, n);
    SortTestHelper::testSort("Quick Sort DoubleROute", SortAlogrithms::quickSortDoubleRoute, arr_2, n);

    //SortTestHelper::testSort("Quick Sort", SortAlogrithms::quickSort, arr_2, n);
    //SortTestHelper::printArray(arr_1, n);

    delete[] arr_1;
    delete[] arr_2;
    //delete[] arr_3;
    return 0;
}