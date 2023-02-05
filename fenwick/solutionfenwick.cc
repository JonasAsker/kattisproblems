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

#include "fenwick.h"

using namespace std;

//const int INF = 1e9; 
//const int LLINF = 4e18; 
//const double EPS = 1e-9;
//typedef long long ll; // common data types 
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

// Title: Fenwick tree

// Description:
// implementation of the fenwick tree DS for range sum queries and updating.
// keeps track of the frequency array aswell as the cumulative frequency
// array.
// uses the least significant one bit manipulation to map indicies from
// frequency array to cumulative frequency array and back.

// Complexity: the operations on the fenwick tree are known to take O(log(N))
// time where N is the size of the underlying array.

// Input constraints and expectations: 
//The first line of input contains two integers N, Q, 
//where 1<=N<=5000000 is the length of the array and 1<=Q<=5000000 is the number of operations. 
//Then follow Q lines giving the operations. There are two types of operations:
//“+ i delta” indicates that a[i] is incremented by delta, where 0<=i<N and -10^9<=delta<=10^9 (both are integers)
//“i ?” is a query for the range sum up to i, where 0<=i<N (for i=0 this is interpreted as an empty sum)
//You should assume that every array entry is initially 0.

int main() {
    //freopen("prog.in", "r", stdin);
    int N{0}, Q{0};
    char symbol;
    ll a, b;

    while(scanf("%d %d ", &N, &Q) != EOF){
        Fenwick fenwick = Fenwick(N);

        for (int i{0}; i < Q; ++i){
            scanf("%c", &symbol);

            if (symbol == '?'){
                scanf("%lld ", &a);
                ll rsq = fenwick.rsq(a);
                cout << rsq << '\n';
            }

            else {
                scanf("%lld%lld ", &a, &b);
                fenwick.update(a, b);
            }

        }

    }
    return 0;
}