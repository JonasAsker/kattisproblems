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
//typedef pair<int, int> ii; // comments that are mixed typedef 
typedef pair<float, float> ff; // comments that are mixed typedef 
typedef vector<int> vi; // in with code are placed 
typedef tuple<float, int, int> fii;
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

// Title:

// Description:

// Complexity:

// Input constraints and expectations:

double distance(ff n1, ff n2) {
    double d = sqrt(pow((n1.first-n2.first), 2) + pow((n1.second-n2.second), 2));
    return d;
}

int main() {
    //freopen("prog.in", "r", stdin);
    int C;
    scanf("%d ", &C);
    while (C--)
    {
        int V, E;
        float x, y;
        scanf("%d ", &V);
        vector<ff> coordinates(V, ff());

        for (int i{0}; i < V; i++){
            scanf("%f %f ", &x, &y);
            coordinates[i] = {x, y};
        }

        vector<fii> edgeList;
        set<ff> taken;

        for (int i{0}; i < V; i++){
            for (int j{0}; j < V; j++){
                if (taken.find({i,j}) == taken.end()){
                    edgeList.push_back({distance(coordinates[i], coordinates[j]), i, j});
                    E++;
                }
                taken.insert({i,j});
            }
        }
        
        sort(edgeList.begin(), edgeList.end());

        float cost{0};
        int edgesTaken{0};
        Ufds ufds = Ufds(V);

        for (int i{0}; i < E; i++){
            auto [w, u, v] = edgeList[i];
            if (ufds.same(u, v)) continue;
            cost += w;
            ufds.makeUnion(u, v);
            edgesTaken++;
            if(u > v) swap(u, v);
            if (edgesTaken == V-1) break;
        }
        
        cout << fixed << setprecision(4) << cost << '\n';
    }
    return 0;
}
