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

using namespace std;

//const int INF = 1e9; 
//const int LLINF = 4e18; 
//const double EPS = 1e-9;
//typedef long long ll; // common data types 
//typedef pair<int, int> ii; // comments that are mixed typedef 
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

// Title: Chopping wood.

// Description: 
// Create an edge list when given the prufer code of a tree.
// First find the missing node numbers in the prufer sequence. 
// These are the leaves. Calulate the degrees of the others, a node 
// cannot be printed until it has degree zero. keep track of which 
// nodes are to be printed with a priority queue and add nodes to the 
// queue when their degree becomes zero. the prufer codes must end with the
// highest numbered node.

// Complexity:
// the heap operations are done in log(n) time. there are several for loops
// of length n so the complexity is O(n).

// Input constraints and expectations:

int main() {
    //freopen("prog.in", "r", stdin);
    ios_base::sync_with_stdio(false);
    int n, temp;
    scanf("%d ", &n);
    vi nums(n, 0), degrees(n+2, 0);
    // low numbered nodes should be printed first
    priority_queue<int, vi, greater<int>> out;
    for (int i{0}; i < n; ++i){
        scanf("%d ", &temp);
        nums[i] = temp;
    }
    if (*nums.rbegin() != n+1) cout << "Error" << '\n';
    else{
        for (auto i: nums){
            ++degrees[i];
        }
        for (int i{1}; i <= n+1; ++i){
            if (!degrees[i]){
                out.push(i);
            }
        }
        for (auto i: nums){
            cout << out.top() << '\n';
            out.pop();
            if(! --degrees[i]){
                out.push(i);
            }
        }
    }

    return 0;
}