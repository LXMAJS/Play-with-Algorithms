//
// Created by 黎进 on 2018/9/19.
//

#ifndef DEMO1_SHORTESTPATH_EDGE_H
#define DEMO1_SHORTESTPATH_EDGE_H

#include <iostream>
#include <cassert>
#include <vector>

using namespace std;

namespace ShortestPath {

    ///
    /// \tparam Weight
    template<typename Weight>
    class Edge {

    private:
        int a, b; // two vertex, from a to b
        Weight weight; // vertex's weight


    public:
        ///
        /// \param a
        /// \param b
        /// \param weight
        Edge(int a, int b, Weight weight) {
            this->a = a;
            this->b = b;
            this->weight = weight;
        }

        ///
        Edge() {
            // do nothing
        }

        ///
        ~Edge() {}

        ///
        /// \return
        int v() {
            return a;
        }

        ///
        /// \return
        int w() {
            return b;
        }

        ///
        /// \return
        Weight wt() {
            return weight;
        }

        ///
        /// \param x
        /// \return
        int other(int x) {
            assert(x == a || x == b);
            return x == a ? b : a;
        }

        ///
        /// \param os
        /// \param e
        /// \return
        friend ostream &operator<<(ostream &os, const Edge &e) {
            os << e.a << "-" << e.b << " : " << e.wt();
            return os;
        }

        bool operator<(Edge<Weight> &e) {
            return weight < e.wt();
        }

        bool operator>(Edge<Weight> &e) {
            return weight > e.wt();
        }

        bool operator<=(Edge<Weight> &e) {
            return weight <= e.wt();
        }

        bool operator>=(Edge<Weight> &e) {
            return weight >= e.wt();
        }

        bool operator==(Edge<Weight> &e) {
            return weight == e.wt();
        }
    };
}

#endif //DEMO1_SHORTESTPATH_EDGE_H
