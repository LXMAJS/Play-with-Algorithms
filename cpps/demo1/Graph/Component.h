//
// Created by 黎进 on 2018/9/5.
//

#ifndef DEMO1_COMPONENT_H
#define DEMO1_COMPONENT_H

#include <iostream>
#include <cassert>

using namespace std;

template <typename Graph>
class Component{
private:
    Graph &G;
    bool * visited; // 存储深度优先遍历时，每个节点是否被遍历到
    int ccount; // 联通分量
    int * id; // 存储联通的节点之间相同的id号

    void dfs(int v){
        assert(v >= 0 && v <= G.V());

        visited[v] = true;
        id[v] = ccount;
        typename Graph::adjIterator adj(G, v);
        for (int i = adj.begin(); !adj.end(); i++) {
            if(!visited[i]){
                dfs(i);
            }
        }
    }

public:
    Component(Graph & graph) : G(graph) {
        visited = new bool[G.V()];
        id = new int[G.V()];
        ccount = 0;

        for (int i = 0; i < G.V(); ++i) {
            visited[i] = false;
            id[i] = -1;
        }

        /*
         * 深度优先遍历
         */
        for (int j = 0; j < G.V(); ++j) {
            if(!visited[j]){
                dfs(j);
                ccount ++;
            }
        }
    }

    ~Component(){
        delete[] visited;
        delete[] id;
    }

    int count(){
        return ccount;
    }
};

#endif //DEMO1_COMPONENT_H
