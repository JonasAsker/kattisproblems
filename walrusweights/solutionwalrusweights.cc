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

//const int INF = 1e9; 
//const int LLINF = 4e18; 
//const double EPS = 1e-9;
//typedef long long ll; // common data types 
//typedef unsigned long ul;
typedef pair<int, int> ii; // comments that are mixed typedef 
typedef vector<int> vi; // in with code are placed 
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

// Title: walrus weights

// Description: similar to knapsack problem
// pick or dont pick but no weight limit
// the items only have values no weights
// solved with top down but bottom up is probably viable aswell.

// Complexity: very large search space but overlapping subproblems which makes
// it reducable through memoization. worst possible is aroud 2000000 operations

// Input constraints and expectations: see kattis problem 

// memotables keeps track of visited weights and deviances from 1000.

const int MAXWEIGHT{2000};
int memo[1001][MAXWEIGHT];
int visited[1001][MAXWEIGHT];

ii bestWeight(ii & add, ii & noAdd){

    if (abs(add.first) < abs(noAdd.first)){
        return add;
    }

    if (abs(add.first) == abs(noAdd.first)){
        
        if (add.second > noAdd.second){
            return add;
        }
    }

    return noAdd;
}

ii walrus(vi & things, int i, int w){
    ii add{MAXWEIGHT,0}, noAdd{0,0};
    visited[i][w] = 1;
    memo[i][w] = 1000 - w;

    if (i == (int) things.size()){
        return {1000 - w, w};
    }

    if (visited[i+1][w] == -1){
        noAdd = walrus(things, i+1, w);
    }

    else {
        noAdd = {memo[i+1][w], w};
    }

    if (w+things[i] < MAXWEIGHT){

        if (visited[i+1][w+things[i]] == -1){
            add = walrus(things, i+1, w+things[i]);
        }

        else {
            add = {memo[i+1][w+things[i]], w+things[i]};
        }
    }

    ii out = bestWeight(add, noAdd);
    return out;
}

int main() {
    int n, w;
    vi stuff;
    // for debugging. 
    //freopen("prog.in", "r", stdin);

    while(scanf("%d ", &n) != EOF){
        memset(visited, -1, sizeof visited);
        for (int i{0}; i < n; ++i){
            scanf("%d ", &w);
            stuff.push_back(w);
        }

        ii opt = walrus(stuff, 0, 0);
        int out = opt.second;

        cout << out << '\n';
    }
    
    return 0;
}