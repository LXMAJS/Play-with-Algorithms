//
// Created by 黎进 on 2018/8/25.
//

#ifndef DEMO1_TREE_H
#define DEMO1_TREE_H

#include <iostream>
#include <queue>

using namespace std;

namespace Tree{

    /*
     * 给定一个二叉树，找出其最大深度。
     * 二叉树的深度为根节点到最远叶子节点的最长路径上的节点数。
     * 说明: 叶子节点是指没有子节点的节点。
     * 示例：
     * 给定二叉树 [3,9,20,null,null,15,7]，
     */

    struct TreeNode {
        int val;
        TreeNode *left;
        TreeNode *right;

        TreeNode(int x) : val(x), left(NULL), right(NULL) {}
    };

    int maxDepth(TreeNode * root) {
        if(root == NULL)
            return 0;

        int leftDept = maxDepth(root->left);
        int rightDept = maxDepth(root->right);

        return (rightDept > leftDept ? rightDept : leftDept) + 1;
    }


    /*
     * 给定一个二叉树，判断其是否是一个有效的二叉搜索树。
     * 假设一个二叉搜索树具有如下特征：
     *  节点的左子树只包含小于当前节点的数。
     *  节点的右子树只包含大于当前节点的数。
     *  所有左子树和右子树自身必须也是二叉搜索树。
     *
     */

    void __inOrder(TreeNode* node, queue<int>& q){
        if(node != NULL){
            __inOrder(node->left, q);
            q.push(node->val);
            __inOrder(node->right, q);
        }
    }

    bool isValidBST(TreeNode* root) {
        queue<int> q;

        __inOrder(root, q);

        int* arr = new int[q.size()];
        int i = 0;
        cout << q.size() << endl;
        while (!q.empty()) {
            arr[i] = q.front();
            q.pop();
            cout << arr[i] << " - ";
            i++;
        }

        for (int j = 1; j < i; j++) {
            if(arr[j-1] >= arr[j])
                return false;
        }
        return true;
    }
}
#endif //DEMO1_TREE_H
