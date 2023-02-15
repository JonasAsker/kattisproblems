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

// Title: bank

// Description: greedy problem about choosing customers from a bank queue who can wait different amount of time 
// and want to deposit different amount of money. goal is to maximize the amount of money depsited before the bank
// closes. 

// Complexity: O(n*log(n))

// Input constraints and expectations: see kattis problem.

int times[47];

struct customer{
    int money;
    int time;
};

bool comp(customer & c1, customer & c2){

    if (c1.time == c2.time){
        return c1.money > c2.money;
    }

    return c1.time < c2.time;
}

void replaceInLine(customer & c, int T){
    int time = min(c.time, T);
    int money = c.money;
    bool foundBetter{false};
    customer replace{money, 0};

    for (int i{0}; i <= time; ++i){
        if (replace.money > times[i]){
            replace.money = times[i];
            replace.time = i;
            foundBetter = true;
        }
    }

    if (foundBetter){
        times[replace.time] = money;
    }       
}

int main() {
    //freopen("prog.in", "r", stdin);
    int N{0}, T{0};
    ll money{0};
    scanf("%d%d ", &N, &T);
    vector<customer> line;
    customer a;

    while(N--){
        scanf("%d%d ", &a.money, &a.time);
        line.push_back(a);
    }

    sort(line.begin(), line.end(), comp);
    size_t inx{0};

    for (auto c: line){
        int bp{0};
        replaceInLine(c, T);
    }

    for (auto i: times){
        money += i;
    }

    cout << money << '\n';
    
    return 0;
}