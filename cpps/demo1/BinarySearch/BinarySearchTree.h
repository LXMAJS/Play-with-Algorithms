//
// Created by 黎进 on 2018/8/20.
//

#ifndef DEMO1_BINARYSEARCHTREE_H
#define DEMO1_BINARYSEARCHTREE_H

#include <iostream>

using namespace std;

namespace BinarySearchTree{

    template <typename Key, typename Value>
    class BST{
    private:
        struct Node{
            Key key;
            Value value;
            Node* left;
            Node* right;

            Node(Key k, Value val){
                this->key = k;
                this->value = val;
                this->left = this->right = NULL;
            }
        };

        Node * root; // root node
        int count; // tree node's count

        /// insert a new item, private function
        Node insert(Node node, Key k, Value val){

            if(node == NULL){
                count ++;
                return new Node(k, val);
            }

            if(node.key == k){
                node.value = val;
            }
            else if(node.key < k){
                node.left = insert(node.left, k, val);
            }
            else {// node.key > k
                node.right = insert(node.right, k, val);
            }
        }

    public:

        BST(){
            root = NULL;
            count = 0;
        }

        ~BST(){
            // TODO:
        }

        /// size of bst
        int size(){
            return count;
        }

        /// if empty
        bool isEmpty(){
            return root == NULL;
        }

//        /// insert a new item, use interation
//        void insert(Key k, Value val){
//            root = insert(root, k, val);
//        }

        /// insert a new item, without interation
        void insert(Key k, Value val){
            Node node = root;
            
            if(node == NULL){
                node = new Node(k, val);
                return;
            }

            while(node != NULL){
                if(node.key == k){
                    node.value = val;
                }
                else if(node.key < k){
                    if(node.left == NULL){
                        node.left = new Node(k, val);
                        break;
                    }
                    node = node.left;
                }
                else{
                    // node.key > k
                    if(node.right == NULL){
                        node.right = new Node(k, val);
                        break;
                    }
                    node = node.right;
                }
            }
        }
    };
}
#endif //DEMO1_BINARYSEARCHTREE_H
