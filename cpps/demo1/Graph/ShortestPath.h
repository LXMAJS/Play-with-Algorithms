//
// Created by 黎进 on 2018/9/10.
//

#ifndef DEMO1_SHORTESTPATH_H
#define DEMO1_SHORTESTPATH_H

#include <iostream>
#include <queue>
#include <stack>

using namespace std;

template <typename Graph>
class ShortestPath {
private:
    Graph &G;
    int source;
    bool *visited;
    int *from;
    int *order; // 从source到各个节点的距离

public:
    ///
    /// \param graph
    /// \param s
    ShortestPath(Graph &graph, int s) : G(graph) {

        assert(s >= 0 && s <= graph.V());
        visited = new bool[graph.V()];
        from = new int[graph.V()];
        order = new int[graph.V()];
        for (int i = 0; i < graph.V(); ++i) {
            visited[i] = false;
            from[i] = -1;
            order[i] = -1;
        }
        this->source = s;
        // 辅助数据结构
        queue<int> q;

        q.push(s);
        visited[s] = true;
        order[s] = 0;

        while( !q.empty() ){
            int v = q.front();
            q.pop();

            typename Graph::adjIterator adj(G, v);
            for (int i = adj.begin(); !adj.end() ; i = adj.next() {
                if(!visited[i]){
                    q.push(i);
                    visited[i] = true;
                    from[i] = v;
                    order[i] = order[v] + 1;
                }
            }
        }
    }

    ///
    ~ShortestPath(){
        delete []visited;
        delete []from;
        delete []order;
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

    /// 返回w距离s节点的长度
    /// \param w
    /// \return
    int length(int w){
         assert(w >= 0 && w <= G.V());
         return order[w];
    }
};

#endif //DEMO1_SHORTESTPATH_H
