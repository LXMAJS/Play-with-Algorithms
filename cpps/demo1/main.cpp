#include <iostream>
#include "Sort-Alogrithms/SortAlogrithms.h"
#include "Sort-Alogrithms/SortTestHelper.h"
#include "Sort-Alogrithms/Questions.h"

#include "Heap/MaxHeap.h"

using namespace std;

int main() {

    /* sort alogrithms test codes
//    int n = 10000;
//    int* arr_1 = SortTestHelper::generateRandomArray(n, 0, n);
//    //int* arr_2 = SortTestHelper::copyIntArray(arr_1, n);
//    //int* arr_3 = SortTestHelper::copyIntArray(arr_1, n);
//
//    //SortTestHelper::testSort("Selection Sort", SortAlogrithms::selectionSort, arr_1, n);
//
//    //SortTestHelper::testSort("Insertion Sort", SortAlogrithms::insertionSort, arr_2, n);
//
//    //SortTestHelper::testSort("Bubble Sort", SortAlogrithms::bubbleSort, arr_3, n);
//
//    //SortTestHelper::testSort("Quick Sort", SortAlogrithms::quickSortTribleRoute, arr_1, n);
//    //SortTestHelper::testSort("Quick Sort TribleRoute", SortAlogrithms::quickSortTribleRoute, arr_2, n);
//
//    //SortTestHelper::testSort("Quick Sort", SortAlogrithms::quickSort, arr_2, n);
//    //SortTestHelper::printArray(arr_1, n);
//
//    int num = Questions::getNthItemInArray(arr_1, n, 100);
//    cout << num << endl;
//
//    delete[] arr_1;
//    //delete[] arr_2;
//    //delete[] arr_3;
     */


    MaxHeap::MaxHeap<int> maxheap = MaxHeap::MaxHeap<int>(100);

    srand(time(NULL));
    for( int i = 0 ; i < 50 ; i ++ )
        maxheap.insert( rand()%100 );

    maxheap.printAllItems();
    return 0;
}