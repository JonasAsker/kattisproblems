// Author: Jonas Asker Svedberg

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

#include "dijkstra.h"

using namespace std;

//const int INF = 1e9; 
//const int LLINF = 4e18; 
//const double EPS = 1e-9;
//typedef long long ll; // common data types 
//typedef unsigned long ul;
typedef pair<int, int> ii; // comments that are mixed typedef 
typedef vector<int> vi; // in with code are placed 
typedef vector<ii> vii; // on the right side 
//typedef vector<string> VS;  
//typedef vector<vector<string> > VVS;
// memset(memo, -1, sizeof memo); // to init DP memo table 
// vi memo(n, -1); // alternative way 
// memset(arr, 0, sizeof arr); // to clear array of ints
//++i; 
//ans = a ? b : c; 
//ans += val; 
//index = (index+1) % n; 
//index = (index+n-1) % n; 
//int ans = (int)((double)d + 0.5); 
//ans = min(ans, new_computation); 

// Title: Single source shortest path

// Description: Find the shortest path from a single source node
// in a graph with non negative weights. 

// Dijkstras algorithm, a greedy algorithm which evaluates each node 
// and each vertex in a graph once. The algorithm first assumes infinite 
// distance to all other nodes from the start node. It then iteratively 
// replaces these distances with shorter ones as it finds them. If a 
// longer path is discovered it will be discarded and not considered again.
// The start node will be processed once and all its distances to its immediate 
// neighbors will be saved as the shortest path. Then the node labeled as 
// number two will be processed. If the sum of the weights of node 1 to 2 and 2 to 3
// is smaller than the weight of 1 to 3 then the path 1-2-3 will replace the path 
// 1-3.

// Complexity: Each node / vertex is processed once -> O(V+E) where V is the number 
// of vertecies and E is the number of Edges. But, to keep track of of the shortest 
// distances and in which order to handle the nodes we use a priority queue of nodes
// which multiplies each operation with log(V). So O((V+E)*log(V)). 

// Input constraints and expectations: See problem single source shortest path non negative weights.

int main() {
   //freopen("prog.in", "r", stdin);

    while(true){
        int V, E, q, s;
        int k;
        scanf("%d %d %d %d ", &V, &E, &q, &s);
        if (V == 0 && E == 0 && q == 0 && s == 0) break;
        vector<vii> adjacencyList(V, vii());

        while (E--){
            int u, v, w;
            scanf("%d %d %d ", &u, &v, &w);
            adjacencyList[u].emplace_back(v,w);
        }

        Dijkstra Dijkstra(adjacencyList, s);
        vector<vi> path = Dijkstra.shortestPath();

        while (q--){
            scanf("%d ", &k);
            if (path[0][k] == INF) cout << "Impossible\n";
            else cout << path[0][k] << "\n";
        }
    }

    return 0;
}