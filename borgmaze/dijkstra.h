// Author: Jonas Asker Svedberg

#ifndef DIJKSTRA_H
#define DIJKSTRA_H

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

class Dijkstra{
    
    private:
        vector<vii> adjacencyList;
        int sn;

    public:
        Dijkstra(vector<vii> Al, int startNode){
            adjacencyList = Al;
            sn = startNode;
        }

        vector<vi> shortestPath(){
            vector<vi> out(2, vi(adjacencyList.size(), INF)); // {{distances},{parents}}
            out[0][sn] = 0;
            set<ii> pq;

            for (int u = 0; u < adjacencyList.size(); ++u){
                pq.insert({out[0][u], u});
            }

            while(!pq.empty()){
                auto [d,u] = *pq.begin(); // u is the current node
                pq.erase(pq.begin());

                for (auto &[v,w] : adjacencyList[u]){ // handle us neighbors one at a time
                
                    if (out[0][u]+w >= out[0][v]){ // we know a better way
                        continue;
                    }

                    pq.erase(pq.find({out[0][v], v}));
                    out[0][v] = out[0][u] + w;
                    out[1][v] = u;
                    pq.insert({out[0][v], v}); // update with new best way
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