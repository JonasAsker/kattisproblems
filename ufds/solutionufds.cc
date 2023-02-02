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

#include "ufdsClass.h"

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

// Title: Union find

// Description: 
// A problem testing the functionality of the union find 
// disjoint set data structure. the ufds DS implements a forset of trees
// in which each tree describes a disjoint set. the trees roots are all
// representative elements for their respective sets. the idea is that 
// an elements set can be found by just looking at it's representative element.
// this way it's easy to determine if two elements are not part of the same 
// sets. 
// the DS also allows for the unifiction of two disjoint sets.

// Complexity: 
// Amortized O(N). this is because on the main loop reading all the data.
// the DS utilizes path compression which allows it to make faster searches 
// if it has already traversed that part of the tree. it also has a 
// treeheight heurstic which makes it less likely to grow tall trees which 
// would result in slower searches. Each operation on the DS is at worst O(log(n)).

// Input constraints and expectations:
// The first line of input consists of two integers N  and Q, 
// where 1 <= N <= 1000000 is the number of elements in the base set 
// and is 1 <= Q <= 1000000 the number of operations. 
// Then follow lines, one per operation. There are two types of operations:
// “=” a b indicate that the sets containing a and b are joined
// “?” a b is a query asking whether a and b belong to the same set
// In both cases, a and b are distinct integers between 0 and N-1.

int main() {
    //freopen("prog.in", "r", stdin);
    int N{0}, Q{0};
    char symbol;
    int a, b;

    while(scanf("%d %d ", &N, &Q) != EOF){
        Ufds ufds = Ufds(N);

        for (int i{0}; i < Q; ++i){
            scanf("%c%d%d ", &symbol, &a, &b);

            if (symbol == '?'){

                if (ufds.same(a, b)){
                    cout << "yes\n";
                }

                else cout << "no\n";
            }

            else {
                ufds.makeUnion(a, b);
            }

        }

    }
    
    return 0;
}