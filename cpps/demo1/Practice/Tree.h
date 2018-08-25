//
// Created by 黎进 on 2018/8/25.
//

#ifndef DEMO1_TREE_H
#define DEMO1_TREE_H

#include <iostream>

using namespace std;

namespace Tree{


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
}
#endif //DEMO1_TREE_H
