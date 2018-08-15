//
// Created by 黎进 on 2018/8/14.
//

#ifndef DEMO1_MAXHEAP_H
#define DEMO1_MAXHEAP_H

#include <iostream>

using namespace std;


namespace IndexMaxHeap{

    // max heap
    template <typename Item>
    class IndexMaxHeap{

    private:
        Item * data;
        int * indexes;
        int count;
        int capacity;

        ///
        void shiftUp(int k){

            // if parent is little then child, swich two item's value
            while( k > 1 && data[indexes[k/2]] < data[indexes[k]] ){
                swap( indexes[k/2] , indexes[k] );
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
            indexes = new int[capacity + 1];
            count = 0;
            this->capacity = capacity;
        }

        ///
        ~MaxHeap(){
            delete [] data;
            delete [] indexes;
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
        void insert( int i, Item newItem ){


            assert( count + 1 <= capacity );
            assert( i >= 0 && i + 1 <= capacity);

            i ++; // make sure that index started with 1(one)

            indexes[count + 1] = i;
            data[i] = newItem;
            count ++;
            shiftUp(count);
        }

        ///
        Item extractMaxItem(){
            assert( count > 0);

            Item res = data[indexes[1]];

            swap(indexes[count], indexes[1]);
            count --;
            shiftDown(1);

            return res;
        }

        ///
        int extracMaxIndex(){
            assert( count > 0);

            int res = indexes[1] -1; // makesure that return index start witb 0(zero)

            swap(indexes[count], indexes[1]);
            count --;
            shiftDown(1);

            return res;
        }

        ///
        Item getItem( int index ){
            assert( i + 1 >= 1 && i + 1 <= capacity );
            return data[index + 1];
        }


        /// change i th item's value
        void change(int i, Item newItem){

            assert(i >= 0 && i + 1 <= capacity);
            i ++;

            data[i] = newItem;

            // heapify indexes
            for (int j = 1; j <= count; j ++) {
                if(indexes[j] == i){
                    shiftDown(j);
                    shiftUp(j);
                    return;
                }
            }
        }
    };
}

#endif //DEMO1_MAXHEAP_H
