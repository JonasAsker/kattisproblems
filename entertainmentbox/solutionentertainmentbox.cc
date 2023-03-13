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

// Title:

// Description:

// Complexity:

// Input constraints and expectations:

struct program{
    ll start;
    ll end;
};

bool comp(program p1, program p2){
    
    if (p1.end == p2.end){
        return p1.start < p2.start;
    }

    return p1.end < p2.end;
}

int main() {
    //freopen("prog.in", "r", stdin);
    ll n{0}, k{0};
    scanf("%lld%lld ", &n, &k);
    program temp;
    vector<program> schedule;
    multiset<ll> recordings;

    for (int i{0}; i < k; ++i){
        recordings.insert(0);
    }

    while(n--){
        scanf("%lld%lld", &temp.start, &temp.end);
        schedule.push_back(temp);
    }

    sort(schedule.begin(), schedule.end(), comp);
    int out{0};

    for (auto i: schedule){
        auto c = recordings.lower_bound(-i.start);

        if (c != recordings.end()){
            recordings.insert(-i.end);
            recordings.erase(c);
            ++out;
        }
    }

    cout << out << '\n';

    return 0;
}