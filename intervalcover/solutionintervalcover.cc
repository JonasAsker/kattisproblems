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

using namespace std;

const int INF = 1e9; 
//const int LLINF = 4e18; 
//const double EPS = 1e-6;
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


// Title: Interval cover. 

// Description:
// Known to be solved with a greedy algorithm. Lowest feasible complexity is O(n*log(n))
// cannot try all possible combinations as this is a very large number 2^20000.
// Instead sort the intervals in decreasing order of coverage and at each point select
// the one that covers the most of the remaining target interval.

// Complexity:
// The below algorithm runs in O(n*log(n)). The sorting is done in O(n*log(n)) and the 
// selection is done in O(n), O(n) + O(n*log(n)) = O(n*log(n)).

// Input constraints and expectations:
// The input consists of up to 30 test cases. 
// Each test case begins with two real numbers A <= B, indicating that [A,B] is the interval to be covered . 
// Then follows an integer 1 <= n <= 20000, giving the number of intervals available. 
// After this follow n lines, the i’th of which contains two real numbers a <= b, 
// indicating that the i’th interval is [a, b]. 
// All real numbers have at most digits 6 after the decimal point.

struct interval{
    // Struct to represent intervals. Saves index for easy printing.
    double l,r; 
    int index;
};

interval targetInterval;
vector<interval> vecInterval;

bool comp(interval i1, interval i2){
    // sort in nondecreasing order on the left bound. greatest right is a tie breaker.
    if (i1.l == i2.l) return i1.r < i2.r;
    return i1.l < i2.l;
}

vi cover(vector<interval> intervals, interval target){
    // indicies are saved in out. greatestMin is the upper bound for the lower
    // end of the interval to add
    interval bounds{-INF, target.l, 0}; 
    vi out;
    for (int i{0}; i < (int)intervals.size(); ++i){
        // greedily pick intervals which cover as much of the remaining 
        // interval as possible. keep track of the interval covered with bounds.
        // bounds.l is the largest smallest value covered and bounds.r is 
        // the greatest value covered.
        if (intervals[i].l <= bounds.l && intervals[i].r >= bounds.r){
            if(!out.empty()){
                out.pop_back();
            }
            bounds.r = intervals[i].r;
            out.push_back(intervals[i].index);
        }
        else if (intervals[i].l <= bounds.r && intervals[i].r >= bounds.r){
            bounds.l = bounds.r;
            bounds.r = intervals[i].r;
            out.push_back(intervals[i].index);
        } 
        if (bounds.r >= target.r && !out.empty()) break;
    }
    if (bounds.r < target.r) out.clear();
    return out;
}


int main() {
    // uncomment for debugging
    // freopen("prog4.in", "r", stdin);
    int n; interval temp;

    while (scanf("%lf %lf", &targetInterval.l, &targetInterval.r) != EOF) {
        scanf("%d ", &n);
        for (int i{0}; i < n; ++i){
            scanf("%lf %lf", &temp.l, &temp.r);
            temp.index = i;
            vecInterval.push_back(temp);
        }

        sort(vecInterval.begin(), vecInterval.end(), comp);

        vi indicies = cover(vecInterval, targetInterval);

        if (indicies.empty()) cout << "impossible";

        else {
            cout << (int)indicies.size() << '\n';
            for (auto i : indicies){
                cout << i;
                if (i != *indicies.rbegin()) cout << " ";
            }
        }
        cout << '\n';
        vecInterval.clear(); 
    }
    return 0;
}