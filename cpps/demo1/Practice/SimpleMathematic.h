//
// Created by 黎进 on 2018/8/24.
//

#ifndef DEMO1_SIMPLEMATHEMATIC_H
#define DEMO1_SIMPLEMATHEMATIC_H


#include <iostream>
using namespace std;


namespace SimpleMathematic{

    /// 交换两个数，不使用额外的空间
    void exchangeTwoNumber(int a, int b){
        a = a + b;
        b = a - b;
        a = a - b;
        return;
    }
}
#endif //DEMO1_SIMPLEMATHEMATIC_H
