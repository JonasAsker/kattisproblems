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
typedef long long ll; // common data types 
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

// Title: classrooms

// Description: interval scheduling problem. several different containers to put intervals in. 
// sort by ascending end time. greedily pick intervals from the sorted list. keep a multiset with 
// which represents the classrooms. each classroom is an element in the set. set the element to the end
// time on the activity it was latest given. to minimize dead time we want to put an acitivity in the 
// classroom whos activity ends the latest but still allows for the new activity. allows in the sense 
// that the end time of the previous activity doesnt overlap with the start time of the new one.

// Complexity: O(N*log(N))

// Input constraints and expectations: see kattis problem.

struct lesson{
    ll start;
    ll end;
};

bool comp(lesson l1, lesson l2){
    
    if (l1.end == l2.end){
        return l1.start < l2.start;
    }

    return l1.end < l2.end;
}

int main() {
    //freopen("prog.in", "r", stdin);
    int N{0}, K{0};
    scanf("%d%d ", &N, &K);
    lesson temp;
    vector<lesson> schedule;
    // use multiset to keep it sorted
    multiset<int> classrooms;

    for (int i{0}; i < K; ++i){
        classrooms.insert(0);
    }

    while(N--){
        scanf("%lld%lld ", &temp.start, &temp.end);
        schedule.push_back(temp);
    }

    sort(schedule.begin(), schedule.end(), comp);
    int activities{0};

    for (auto i: schedule){
        // negative to make sure that impossible activites end up last.
        auto c = classrooms.upper_bound(-i.start);

        if (c != classrooms.end()){
            classrooms.insert(-i.end);
            classrooms.erase(c);
            ++activities;
        }
    }

    cout << activities << '\n';

    return 0;
}