//
// Created by 黎进 on 2018/9/5.
//

#ifndef DEMO1_PATH_H
#define DEMO1_PATH_H

#include <iostream>
#include <cassert>
#include <stack>

using namespace std;

template <typename Graph>
class Path{
private:
    Graph &G;
    int source; // 源节点
    bool * visited; // 是否被访问过
    int * from; // 存储某个节点的源节点

    /// 深度优先寻路
    /// \param v
    void dfs(int v){
        assert(v >= 0 && v <= G.V());

        visited[v] = true;
        typename Graph::adjIterator adj(G, v);
        for (int i = adj.begin(); !adj.end(); i++) {
            if(!visited[i]){
                from[i] = v;
                dfs(i);
            }
        }
    }


public:
    /// 初始化某个图的某个节点的路径
    /// \param graph
    /// \param s
    Path(Graph &graph, int s) : G(graph){
        assert(s >= 0 && s <= G.V());
        this->source = s;

        visited = new bool[G.V()];
        from = new int[G.V()];

        for (int i = 0; i < G.V(); i++) {
            visited[i] = false;
            from[i] = -1;
        }

        // 深度优先寻路
        dfs(s);
    }

    ///
    ~Path(){
        delete[] visited;
        delete[] from;
    }

    /// 某个节点跟当前节点是否是联通的，理解为有路径
    /// \param w
    /// \return
    bool hasPath(int w){
        return visited[w];
    }

    ///
    /// \param w
    /// \param vec
    void path(int w, vector<int> &vec){
        assert(hasPath(w));

        stack<int> s;

        // 将路径压入栈中
        int p = w;
        while(p != -1){
            s.push(p);
            p = from[p];
        }

        // 填充到向量中
        vec.clear();
        while(!s.empty()){
            vec.push_back(s.top());
            s.pop();
        }
    }

    /// 显示路径
    /// \param w
    void showPath(int w){
        assert(hasPath((w)));

        vector<int> vec;
        path(w, vec);

        for (int i = 0; i < vec.size(); i++) {
            cout<<vec[i];

            if(i == vec.size() -1)
                cout<<endl;
            else
                cout<<" -> ";
        }
    }
};
#endif //DEMO1_PATH_H
