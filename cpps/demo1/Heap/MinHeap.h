//
// Created by 黎进 on 2018/8/14.
//

#ifndef DEMO1_MINHEAP_H
#define DEMO1_MINHEAP_H

#include <iostream>

using namespace std;


namespace MinHeap{

    // min heap
    template <typename Item>
    class MinHeap{

    private:
        Item * data;
        int count;
        int capacity;

        ///
        void shiftUp(int k){

            // if parent is little then child, swich two item's value
            while( k > 1 && data[k/2] > data[k] ){
                swap( data[k/2] , data[k] );
                k /= 2;
            }
        }

        ///
        void shiftDown(int k){

            int leftChild = k*2;
            while( leftChild <= count ){ // if has child

                // choose the max child
                int minChild = data[k*2] < data[k*2 + 1] ? k*2 : k*2 + 1;

                if(data[k] <= data[minChild]) break;

                swap(data[minChild], data[k]);

                k = minChild;
            }
        }


    public:
        ///
        MinHeap(int capacity){
            data = new Item[capacity + 1]; // root item's index is 1(one), not 0(zero);
            count = 0;
            this->capacity = capacity;
        }

        ///
        MinHeap(Item arr[], int n){

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
        ~MinHeap(){
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


        Item extractMinItem(){
            assert( count > 0);

            Item res = data[1];

            swap(data[count], data[1]);
            count --;
            shiftDown(1);

            return res;
        }


        ///
        void printAllItems(){
            cout << "Min Heap's Items: " << endl;
            for (int i = 1; i < count - 1; ++i) {
                cout << data[i] << " ";
            }
            cout << endl;
        }

        // get top of minheap
        Item getMin(){
            assert( count > 0 );
            return data[1];
        }
    };
}

#endif //DEMO1_MINHEAP_H
