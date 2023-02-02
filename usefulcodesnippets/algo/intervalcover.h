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
typedef vector<int> vi;


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
