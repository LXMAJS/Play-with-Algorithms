//
// Created by 黎进 on 2018/8/20.
//

#ifndef DEMO1_BINARYSEARCHTREE_H
#define DEMO1_BINARYSEARCHTREE_H

#include <iostream>
#include <queue>

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

    public:

        BST(){
            root = NULL;
            count = 0;
        }

        ~BST(){
            destory(root);
        }

        /// size of bst
        int size(){
            return count;
        }

        /// if empty
        bool isEmpty(){
            return root == NULL;
        }

        /// insert a new item, use interation
        void insert(Key k, Value val){
            root = insert(root, k, val);
        }

        /// insert a new item, without interation
//        void insert(Key k, Value val){
//            Node node = root;
//
//            if(node == NULL){
//                node = new Node(k, val);
//                return;
//            }
//
//            while(node != NULL){
//                if(node.key == k){
//                    node.value = val;
//                }
//                else if(node.key < k){
//                    if(node.left == NULL){
//                        node->left = new Node(k, val);
//                        break;
//                    }
//                    node = node->left;
//                }
//                else{
//                    // node.key > k
//                    if(node.right == NULL){
//                        node->right = new Node(k, val);
//                        break;
//                    }
//                    node = node->right;
//                }
//            }
//        }

        /// if bst has a value'key is k
        bool contain(Key k){
            return contain(root, k);
        }

        /// find an value's address when it's key eqaul to k
        Value* search(Key k){
            return search(root, k);
        }


        /// pre order a bst
        void preOrder(){
            preOrder(root);
            cout << endl;
        }

        /// middle order a bst
        void inOrder(){
            inOrder(root);
            cout << endl;
        }

        /// post order a bst
        void postOrder(){
            postOrder(root);
            cout << endl;
        }

        ///
        void levelOrder(Node* node){
            queue<Node*> q;
            q.push(root);

            while(!q.empty()){

                Node* node = q.front();
                q.pop();

                if(node != NULL)
                    cout << node->key;

                if(node->left) // node->left != NULL
                    q.push(node->left);
                if(node->right) // node->right != NULL
                    q.push(node->right);
            }
        }

    private:
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

        ///
        bool contain(Node* node, Key k){
            if(node == NULL)
                return false;

            if(node->key == k)
                return true;
            else if(node->key < k)
                return contain(node->left, k);
            else
                return contain(node->right, k);
        }

        ///
        Value* search(Node* node, Key k){
            if(node == NULL)
                return NULL;

            if(node->key == k)
                return &(node->value);
            else if(node->key < k)
                return search(node->left, k);
            else
                return search(node->right, k);
        }

        ///
        void preOrder(Node* node){
            if(node != NULL) {
                cout << node->value << "-";
                preOrder(node->left);
                preOrder(node->right);
            }
        }

        ///
        void inOrder(Node* node){
            if(node != NULL) {
                inOrder(node->left);
                cout << node->value << "-";
                inOrder(node->right);
            }
        }

        ///
        void postOrder(Node* node){
            if(node != NULL){
                postOrder(node->left);
                postOrder(node->right);
                cout << node->value << "-";
            }
        }

        /// destory a node and release it's memory
        void destory(Node * node){
            if(node != NULL){
                destory(node->left);
                destory(node->right);

                delete node;
                count --;
            }
        }


    };
}
#endif //DEMO1_BINARYSEARCHTREE_H
