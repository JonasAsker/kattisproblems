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

using namespace std;

const int INF = 1e9; 
//const int LLINF = 4e18; 
//const double EPS = 1e-9;
//typedef long long ll; // common data types 
//typedef unsigned long ul;
//typedef pair<int, int> ii; // comments that are mixed typedef 
//typedef vector<int> vi; // in with code are placed 
//typedef vector<ii> vii; // on the right side 
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

// Title: All pairs shortest path

// Description: Find the shortest path between all nodes in a graph. The Floyd Warshall algorithm solves
// this problem for a graph that is small enough. Because of the three loops, each running as many times
// as there are nodes V, its complexity is O(V^3). FW uses a dynamic programming approach to solve the 
// problem. The problem is divided into small subproblems which are solved and then constructed into
// the final solution. The idea is to first check direct conections between nodes and the expand to 
// longer and longer paths, checking if a subpath can be part of a path that is shorter than the
// current shortest one. This approach is why the outermost loop is necessary.

// Complexity: O(V^3)

// Input constraints and expectations:

int main() {
    //freopen("prog.in", "r", stdin);
    int adjacencyMatrix[200][200];
    int V, E, q, r, c, w;
    while (true){
        scanf("%d %d %d ", &V, &E, &q); 
        if (V == 0 && E == 0 && q == 0) break;

        for (int i = 0; i < 200; i++){
            for (int j = 0; j < 200; j++){
                adjacencyMatrix[i][j] = INF;
            }
            adjacencyMatrix[i][i] = 0;
        }

        for (int i = 0; i < E; i++){
            scanf("%d %d %d ", &r, &c, &w);
            adjacencyMatrix[r][c] = min(adjacencyMatrix[r][c], w); // can be a multigraph so always save the
                                                                   // edge with the smallest weight
        }

        for (int i = 0; i < V; i++) {
            for (int u = 0; u < V; u++) {
                for (int v = 0; v < V; v++) {
                    if (adjacencyMatrix[u][i] < INF && adjacencyMatrix[i][v] < INF){
                        adjacencyMatrix[u][v] = min(adjacencyMatrix[u][v], 
                                                    adjacencyMatrix[u][i]+adjacencyMatrix[i][v]);
                    }
                }
            }
        }

        for (int u = 0; u < V; u++) {
            for (int v = 0; v < V; v++) {
                for (int i = 0; i < V; i++) {
                    if (adjacencyMatrix[i][i] < 0) {
                        if (adjacencyMatrix[u][i] != INF && adjacencyMatrix[i][v] != INF) {
                            adjacencyMatrix[u][v] = -INF;
                        }
                    }
                }
            }
        }

        while (q--){
            scanf("%d %d ", &r, &c);
            if (adjacencyMatrix[r][c] == INF) cout << "Impossible\n";
            else if (adjacencyMatrix[r][c] == -INF) cout << "-Infinity\n";
            else cout << adjacencyMatrix[r][c] << "\n";
        }

        cout << "\n";
    }
    return 0;
}
