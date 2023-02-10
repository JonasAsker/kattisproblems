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

#include "fenwick.h"

using namespace std;

//const int INF = 1e9; 
//const int LLINF = 4e18; 
//const double EPS = 1e-9;
typedef long long ll; // common data types 
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

// Title: supercomputers

// Description: fenwick tree problem with slight modification, makeing it
// necessary to also keep track of the underlying array.

// Complexity: all fenwick operations are done in O(log(n)) where n is the 
// array size, there is a loop of length K so we have O(k*log(n))
 
// Input constraints and expectations: see problem on kattis

int main() {
    //freopen("prog.in", "r", stdin);
    int N{0}, K{0}, temp{0}, temp2{0};
    scanf("%d%d ", &N, &K);
    Fenwick fen(N);
    char letter;

    while(K--){
        scanf("%c", &letter);

        if (letter == 'F'){
            scanf("%d ", &temp);
            fen.update(temp);
        }

        else {
            ll upper{0}, lower{0};
            scanf("%d%d ", &temp, &temp2);
            upper = fen.rsq(temp2);
            lower = fen.rsq(temp-1);
            ll rsq{upper - lower};
            cout << rsq << '\n';
        }
    }
    
    return 0;
}