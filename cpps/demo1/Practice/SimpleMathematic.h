//
// Created by 黎进 on 2018/8/24.
//

#ifndef DEMO1_SIMPLEMATHEMATIC_H
#define DEMO1_SIMPLEMATHEMATIC_H


#include <iostream>
#include <stack>

using namespace std;


namespace SimpleMathematic{

    /// 交换两个数，不使用额外的空间
    void exchangeTwoNumber(int a, int b){
        a = a + b;
        b = a - b;
        a = a - b;
        return;
    }

    /*
     * 有一个N*N的矩阵，请拟写一个方法，将矩阵进行顺指针旋转90度
     * 例如：[[1, 2], [3, 4]]，旋转后 [[3, 1], [4, 2]]
     */
    void rotate(vector<vector<int>>& matrix){
        int size = matrix.size() - 1;
        for (int i = 0; i < size; i++) {
            for (int j = 0; j < size; j++) {
                swap(matrix[i][j], matrix[j][size - i])；
            }
        }
    }

    /*
     * 检查一个字符串的括号是否是成对出现的
     */
    bool isPair(char h, char t){
        if((h == '{' && t == '}') || (h == '[' && t == ']') || (h == '(' && t == ')'))
            return true;

        return false;
    }

    bool check_pattern(char* expr){
        if(expr == NULL)
            return false;
        char[] head = {'{', '[', '(' };
        char[] tail = {'}', ']', ')' };

        stack<char> s;
        int i = 0;
        while(expr[i] != '\0'){
            char c = expr[i];
            if(c == '{' || c == '[' || c == '('){
                s.push(c);
            }
            else if(c == '}' || c == ']' || c == ')'){
                char h = s.top();
                s.pop();
                if(!isPair(h, c))
                    return false;
            }
            else
                continue;
        }

        if(!s.empty())
            return false;
        else
            return true;
    }
}
#endif //DEMO1_SIMPLEMATHEMATIC_H
