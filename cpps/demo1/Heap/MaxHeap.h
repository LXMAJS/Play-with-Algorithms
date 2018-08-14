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

        ///
        void shiftDown(int k){

            int leftChild = k*2;
            while( leftChild <= count ){ // if has child

                // choose the max child
                int maxChild = data[k*2] > data[k*2 + 1] ? k*2 : k*2 + 1;

                if(data[k] >= data[maxChild]) break;

                swap(data[maxChild], data[k]);

                k = maxChild;
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
        MaxHeap(Item arr[], int n){

            data = new Item[n + 1];
            capacity = n;

            for (int index = 0; index < n; ++index) {
                data[index + 1] = arr[index];
            }
            count = n;

            for (int i = count / 2; i >= 1; i--) {
                shiftDown(i);
            }
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


        Item extractMaxItem(){
            assert( count > 0);

            Item res = data[1];

            swap(data[count], data[1]);
            count --;
            shiftDown(1);

            return res;
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
