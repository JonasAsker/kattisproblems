// Author: Jonas Asker Svedberg

#ifndef BELLMANFORD_H
#define BELLMANFORD_H

#include <algorithm>
#include <cassert>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <functional>
#include <iomanip>
#include <iostream>
#include <sstream>
#include <map>
#include <set>
#include <queue>
#include <stack>
#include <string>
#include <utility>
#include <vector>
#include <unordered_set>
#include <cstring>
#include <numeric>

using namespace std;

const int INF = 1e9; 
typedef pair<int, int> ii; // comments that are mixed typedef 
typedef vector<int> vi; // in with code are placed 
typedef vector<ii> vii; // on the right side 

class BellmanFord{
    
    private:
        vector<vii> adjacencyList;
        int sn;

    public:
        BellmanFord(vector<vii> Al, int startNode){
            adjacencyList = Al;
            sn = startNode;
        }

        vector<vi> shortestPath(){
            int V = adjacencyList.size();
            vector<vi> out(2, vi(V, INF)); // {{distances},{parents}}
            out[0][sn] = 0;

            for (int i = 0; i < V-1; ++i){
                for (int u = 0; u < V; ++u){
                    for (auto &[v,w]: adjacencyList[u]){
                        if (out[0][u] + w >= out[0][v] || out[0][u] == INF) continue; // no improvement
                        out[0][v] = out[0][u] + w;
                        out[1][v] = u;
                    }
                }
            }

            for (int i = 0; i < V; ++i) {
                for (int u = 0; u < V; ++u){
                    if (out[0][u] != INF){
                        for (auto &[v,w] : adjacencyList[u]){
                            if ((out[0][v] > out[0][u] + w)){ // negative cycle if edge decreases the total distance
                                out[0][v] = -INF;
                            }
                        }
                    }
                }
            }

            return out;
        }

        vector<vi> reconstructPath(){
            vector<vi> path = shortestPath();
            vector<vi> out(adjacencyList.size());

            for (int i = 0; i < path[0].size(); i++){
                int parent = path[1][i];
                while (parent != sn && parent != INF){
                    out[i].push_back(parent);
                    parent = path[1][parent];
                }
            }

            return out;
        }
};

#endif