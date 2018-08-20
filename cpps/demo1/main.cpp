#include <iostream>
#include "Sort-Alogrithms/SortAlogrithms.h"
#include "Sort-Alogrithms/SortTestHelper.h"
#include "Sort-Alogrithms/Questions.h"

#include "Heap/MaxHeap.h"
#include "Heap/HeapSort.h"

#include "Practice/Sum.h"
#include "Practice/Repetition.h"

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


    /*
    MaxHeap::MaxHeap<int> maxheap = MaxHeap::MaxHeap<int>(100);

    srand(time(NULL));
    for( int i = 0 ; i < 50 ; i ++ )
        maxheap.insert( rand()%100 );


    cout << "Max Heap's Items: " << endl;
    while( !maxheap.isEmpty() ) {
        cout << maxheap.extractMaxItem() << " ";
    }
    cout << endl;
    */


//    int n = 10000;
//    int* arr_1 = SortTestHelper::generateRandomArray(n, 0, n);
//
//    SortTestHelper::testSort("Quick Sort", HeapSort::heapSort, arr_1, n);
//
//    delete [] arr_1;

//    int arr[] = {0,0,1,1,1,2,2,3,3,4};
//
//    int res = Practice_Repetition::deleteRepeatItem(arr, 10);
//
//    for (int i = 0; i < res; ++i) {
//        cout << arr[i] << " ";
//    }

    //Practice_Sum::ListNode* n1 = new Practice_Sum::ListNode(2);

    cout << "finished!"<<endl;
    return 0;
}