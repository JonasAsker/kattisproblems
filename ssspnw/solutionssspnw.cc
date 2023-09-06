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

#include "BellmanFord.h"

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

// Title: Single source shortest path with negative weights

// Description: Bellman Ford algorithm to solve the ssspnw problem. Dijkstra is 
// faster but will get stuck in a negative loop. Bellman Ford investigates every 
// edge V-1 times. Each path from the start node to the other nodes is tried and 
// relaxed if a shorter path is found. However, the shortest path for a certain node
// will also be found several times. But, the perk is that the algorithm will not
// get stuck in a negative cycle. 

// Complexity: For every node we consider every edge so the total complexity is O(VE).

// Input constraints and expectations: See problem Single source shortest path, negative weights

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

        BellmanFord BellmanFord(adjacencyList, s);
        vector<vi> path = BellmanFord.shortestPath();

        while (q--){
            scanf("%d ", &k);
            if (path[0][k] == INF) cout << "Impossible\n";
            else if (path[0][k] == -INF) cout << "-Infinity\n";
            else cout << path[0][k] << "\n";
        }
    }
    
    return 0;
}
