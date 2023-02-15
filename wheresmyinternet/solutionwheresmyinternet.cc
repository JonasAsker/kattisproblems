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

// Title: wheresmyinternet

// Description: find connected components in a graph. easily done with ufds. 
// the rule is "if not connected to one => donsnt have internet"

// Complexity: ufds operations is roughly O(1) so O(N)

// Input constraints and expectations: see kattis problem.

int main() {
    //freopen("prog.in", "r", stdin);
    int N{0}, M{0}, temp1{0}, temp2{0};
    int parent{0}, child{0};
    bool connected {true};
    scanf("%d%d ", &N, &M);
    Ufds houses(N+1);

    while (M--){
        scanf("%d%d ", &temp1, &temp2);
        houses.makeUnion(temp1, temp2);
    }

    for (int k{1}; k <= N; ++k){

        if (houses.getParent(k) != 1){
            cout << k << '\n';
            connected = false;
        }
    }

    if (connected){
        cout << "CONNECTED\n";
    }
    
    return 0;
}