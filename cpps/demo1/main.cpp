#include <iostream>
#include "Sort-Alogrithms/SortAlogrithms.h"
#include "Sort-Alogrithms/SortTestHelper.h"
#include "Sort-Alogrithms/Questions.h"

#include "Heap/MaxHeap.h"
#include "Heap/HeapSort.h"

#include "Practice/Sum.h"
#include "Practice/Repetition.h"
#include "Practice/Dynamic.h"
#include "Practice/Tree.h"
#include "Practice/SimpleMathematic.h"

#include "UnionFind/UnionFindTestHelper.h"

#include "Graph/SparseGraph.h"
#include "Graph/DenseGraph.h"
#include "Graph/ReadGraph.h"

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

    /*
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
    */

    /*
//    int n = 20;
//    int* arr_1 = SortTestHelper::generateRandomArray(n, 1, n);
//
//    for (int index = 0; index < n; ++index) {
//        cout << arr_1[index] << " : " <<Dynamic::climbStairs(arr_1[index]) << endl;
//    }
//
//    Tree::TreeNode* n1 = new Tree::TreeNode(1);
//    Tree::TreeNode* n3 = new Tree::TreeNode(3);
//    Tree::TreeNode* n4 = new Tree::TreeNode(4);
//    Tree::TreeNode* n5 = new Tree::TreeNode(5);
//    Tree::TreeNode* n6 = new Tree::TreeNode(6);
//
//    n4->left = n3;
//    n4->right = n6;
//
//    n5->left = n1;
//    n5->right = n4;
//
//    bool t = Tree::isValidBST(n5);

//    int n = 1000000;
//    UnionFindTestHelper::testUF3(n);
//    UnionFindTestHelper::testUF4(n);
//    UnionFindTestHelper::testUF5(n);

//    string s = "sss{wwev[vrv]wervrv}wevrwrvwrv(wvrrv";
//    char[] cc = s.toCharArray();
//    cout << SimpleMathematic::check_pattern(cc) << endl;


//    int n = 6;
//    bool result = SimpleMathematic::check_bin(n);
//
//    cout << endl << result << endl;
*/

    string filename = "../testG1.txt";
    SparseGraph sg(13, false);
    ReadGraph<SparseGraph> readGraph1(sg, filename);
    cout<<"test G1 in Sparse Graph : "<<endl;
    sg.show();

    cout<<endl;

    DenseGraph g2( 13 , false );
    ReadGraph<DenseGraph> readGraph2( g2 , filename );
    cout<<"test G1 in Dense Graph:" << endl;
    g2.show();

    // 使用两种图的存储方式读取testG2.txt文件
    filename = "../testG2.txt";
    SparseGraph g3( 6 , false );
    ReadGraph<SparseGraph> readGraph3( g3 , filename );
    cout<<"test G2 in Sparse Graph:" << endl;
    g3.show();

    cout<<endl;

    DenseGraph g4( 6 , false );
    ReadGraph<DenseGraph> readGraph4( g4 , filename );
    cout<<"test G2 in Dense Graph:" << endl;
    g4.show();


    cout << "finished!"<<endl;
    return 0;
}