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

// Title: aircoditioned

// Description: interval cover problem where as few intervals as possible should be picked to
// cover a number of points. sorted the intervals in non decreasing order on the right bound.

// Complexity: O(n*log(n))

// Input constraints and expectations: see kattis problem airconditioned.

struct interval{
    // Struct to represent intervals.
    int l,r; 
};


bool comp(interval i1, interval i2){
    if (i1.r == i2.r) return i1.l < i2.l;
    return i1.r < i2.r;
}


int cover(vector<interval> & minions){
    int covered{minions[0].r};
    int out{1};

    for (size_t i{1}; i < minions.size(); ++i){

        if (minions[i].l > covered){
            ++out;
            covered = minions[i].r;
        }
    }

    return out;
}


int main() {
    freopen("prog.in", "r", stdin);
    int n{0}; interval temp{0,0};
    vector<interval> vecInterval;

    while (scanf("%d ", &n) != EOF) {
        for (int i{0}; i < n; ++i){
            scanf("%d %d", &temp.l, &temp.r);
            vecInterval.push_back(temp);
        }

        sort(vecInterval.begin(), vecInterval.end(), comp);

        int out = cover(vecInterval);
        cout << out << '\n';
    }
    return 0;
}