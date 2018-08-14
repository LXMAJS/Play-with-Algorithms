//
// Created by 黎进 on 2018/8/14.
//

#ifndef DEMO1_MAXHEAP_H
#define DEMO1_MAXHEAP_H

#include <iostream>

using namespace std;


namespace MaxHeap{

    // max heap
    template <typename Item>
    class MaxHeap{

    private:
        Item * data;
        int count;
        int capacity;

        ///
        void shiftUp(int k){

            // if parent is little then child, swich two item's value
            while( k > 1 && data[k/2] < data[k] ){
                swap( data[k/2] , data[k] );
                k /= 2;
            }
        }
    public:
        ///
        MaxHeap(int capacity){
            data = new Item[capacity + 1]; // root item's index is 1(one), not 0(zero);
            count = 0;
            this->capacity = capacity;
        }

        ///
        ~MaxHeap(){
            delete [] data;
            count = 0;
            capacity = 0;
        }

        ///
        int size(){
            return count;
        }

        ///
        bool isEmpty(){
            return count == 0;
        }

        /// add new item
        /// \param newItem
        void insert( Item newItem ){
            assert( count + 1 <= capacity );

            data[count + 1] = newItem;
            count ++;
            shiftUp(count);
        }


        ///
        void printAllItems(){
            cout << "Max Heap's Items: " << endl;
            for (int i = 1; i < count - 1; ++i) {
                cout << data[i] << " ";
            }
            cout << endl;
        }
    };
}

#endif //DEMO1_MAXHEAP_H
