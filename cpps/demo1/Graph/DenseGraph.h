//
// Created by 黎进 on 2018/8/31.
//

#ifndef DEMO1_DENSEGRAPH_H
#define DEMO1_DENSEGRAPH_H

#include <iostream>
#include <vector>

using namespace std;

/*
 * advince vector
 */
class DenseGraph{
private:
    int n; // count of vectrix
    int m; // count of edge
    bool directed; // if directed
    vector<vector<bool>> g; // graph

public:
    /// construction
    /// \param n
    /// \param directed
    DenseGraph(int n, bool directed){
        this->n = n;
        this->m = 0;
        this->directed = directed;

        for (int i = 0; i < n; i++) {
            g.push_back( vector<bool>(n, false) ); //TODO: can't understand now
        }
    }

    ~DenseGraph(){
        // Do nothing
    }

    int V(){ return n; }
    int E(){ return m; }

    /// confirm two v has e
    /// \param v
    /// \param w
    /// \return
    bool hasEdge(int v, int w){
        assert(v >= 0 && v <= n);
        assert(w >= 0 && w <= n);

        return g[v][w];
    }

    ///  add edge
    /// \param v
    /// \param w
    void addEdge(int v, int w) {
        assert(v >= 0 && v <= n);
        assert(w >= 0 && w <= n);

        // 去掉了平行边的概念
        if (hasEdge(v, w)) {
            return;
        }

        g[v][w] = true;
        if(!directed){
            g[w][v] = true;
        }
        m++;
        return;
    }

    /// show a dense graph
    void show(){
        for (int i = 0; i < V(); i++) {
            for (int j = 0; j < V(); j++) {
                cout<<g[i][j]<<" ";
            }
            cout<<endl;
        }
    }


    /*
     *
     */
    class adjIterator{
    private:
        DenseGraph &G;
        int v; // current vertex
        int index;

    public:
        adjIterator(DenseGraph graph, int v) : G(graph) {
            this->v = v;
            this->index = -1; // 数组的下标从0开始，因此初始值可设置为 -1;
        }

        ///
        /// \return
        int begin(){
            index = -1;
            return next(); // 将index设置为-1，然后返回第一个next即可
        }

        ///
        /// \return
        int next(){
            index += 1;
            for ( ; index < G.V() ; index++) {
                if(G.g[v][index])
                    return index; // 返回值为true的图的index
            }
            return -1;
        }

        bool end(){
            return index >= G.V();
        }
    };
};


#endif //DEMO1_DENSEGRAPH_H
