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
#include <unordered_map>
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

// Title: Introspective caching

// Description: 
// Simulate a chache in a computer which predicts the future.
// This means it can keep track of how long it is until an item is needed
// again. Therefore, we have the ability to keep the stack filled with only
// the items we need soonest, by doing so we minimize cache read ins.

// Complexity:
// for loop of length a with O(log(n)) opertions inside.
// total time is O(a*log(n)), manageable since a and n <= 100000.

// Input constraints and expectations: see kattis problem.

int main() {

    //freopen("prog.in", "r", stdin);
    int c, a, n, temp;    
    scanf("%d %d %d ", &c, &n, &a);

    vi objects; 
    map<int, int> cacheTimes;
    unordered_set<int> cached;
    vector<queue<int>> accessTimes(n);
    int cacheAccesses{0};

    for (int i{0}; i < a; ++i){
        scanf("%d ", &temp);
        objects.push_back(temp);
        accessTimes[temp].push(i);
    }

    for (int i{0}; i < a; ++i){

        if (!cached.count(objects[i])){
            ++ cacheAccesses;

            if ((int)cached.size() >= c){
                cached.erase( cacheTimes.rbegin()->second );
                cacheTimes.erase( cacheTimes.rbegin()->first);
            }

            // pop off current
            accessTimes[objects[i]].pop();

            // won't need it in the future, don't add to cache
            if (accessTimes[objects[i]].empty()) continue;
            
            // add next time item's needed
            int nextAccess{accessTimes[objects[i]].front()};
            cached.insert(objects[i]);
            cacheTimes[nextAccess] = objects[i];
        }

        else {
            accessTimes[objects[i]].pop();

            cacheTimes.erase(cacheTimes.begin()->first);

            if (accessTimes[objects[i]].empty()){
                cached.erase(objects[i]);
                continue;
            }

            int nextAccess{accessTimes[objects[i]].front()};
            cacheTimes[nextAccess] = objects[i];
        }

    }
    cout << cacheAccesses << '\n';
    return 0;
}