//
// Created by 黎进 on 2018/9/19.
//

#ifndef DEMO1_SHORTESTPATH_READGRAPH_H
#define DEMO1_SHORTESTPATH_READGRAPH_H

#include <iostream>
#include <cassert>
#include <vector>
#include <fstream>
#include <sstream>

using namespace std;

namespace ShortestPath {

    ///
    /// \tparam Graph
    /// \tparam Weight
    template<typename Graph, typename Weight>
    class ReadGraph {

    public:
        /// read a graph from file
        /// \param graph
        /// \param filename
        ReadGraph(Graph &graph, const string filename) {

            ifstream file(filename); // file
            string line; // one line from file
            int V, E; // vertex and edge

            assert(file.is_open());

            // 从文件中读取第一行，读取出边和点的数量
            assert(getline(file, line));
            stringstream ss(line);
            ss >> V >> E;

            assert(V == graph.V());

            // 读取每一条边的数
            for (int i = 0; i < E; i++) {
                assert(getline(file, line));
                stringstream ss(line);
                int a, b;
                Weight weight;
                ss >> a >> b >> weight;
                assert(a >= 0 && a <= V);
                assert(b >= 0 && b <= V);
                // 将边加到图中
                graph.addEdge(a, b, weight);
            }
        }
    };

}


#endif //DEMO1_SHORTESTPATH_READGRAPH_H
