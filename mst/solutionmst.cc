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

#include "ufdsClass.h"

using namespace std;

//const int INF = 1e9; 
//const int LLINF = 4e18; 
//const double EPS = 1e-9;
typedef long long ll; // common data types 
//typedef unsigned long ul;
typedef pair<int, int> ii; // comments that are mixed typedef 
typedef vector<int> vi; // in with code are placed 
typedef vector<ii> vii; // on the right side 
typedef tuple<int, int, int> iii;
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

// Title: Minimum spanning tree

// Description: Kruskals algorithm for minimum spanning tree. The code utilizes the 
// ufds datastructure to keep track of connected components. Kruskals is a greedy 
// algorithm which works through sorting the edges in increasing order based on weights.
// Which edges that are kept is decided through simply keeping those with the lowest 
// weight given that the nodes the edge is connecting doesn't already have an edge and 
// that the current edge doesnt close a cycle if kept.

// Complexity: The runtime of the algorithm is O(sort + add edge * unfds)
// = O(Elog(E) + E) = O(Elog(V^2)) = O(Elog(V))

// Input constraints and expectations:

int main() {
    //freopen("prog.in", "r", stdin);
    while (true)
    {
        int V, E, u, v, w;
        scanf("%d %d ", &V, &E);
        if (V == 0 && E == 0) break;
        vector<iii> edgeList(E);
        vii edges;

        for (int i{0}; i < E; i++)
        {
            scanf("%d %d %d ", &u, &v, &w);
            edgeList[i] = {w, u, v};
        }
        
        sort(edgeList.begin(), edgeList.end());

        ll cost{0};
        int edgesTaken{0};
        Ufds ufds = Ufds(V);

        for (int i{0}; i < E; i++){
            auto [w, u, v] = edgeList[i];
            if (ufds.same(u, v)) continue;
            cost += w;
            ufds.makeUnion(u, v);
            edgesTaken++;
            if(u > v) swap(u, v);
            edges.push_back({u,v});
            if (edgesTaken == V-1) break;
        }

        sort(edges.begin(), edges.end());

        if (ufds.getSize() != 1){
            cout <<"Impossible\n";
        }

        else{
            cout << cost << '\n';

            for (auto [u,v]: edges){
                cout << u << " " << v << '\n';
            }
        }
    }
    
    return 0;
}
