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

// Title: shopaholic
 
// Description: simply sort and pick every third item

// Complexity: O(n*log(n))

// Input constraints and expectations: see kattis problem

int main() {
    //freopen("prog.in", "r", stdin);
    int n{0}, temp{0}, read{0};
    ll discount{0};
    vi things;
    scanf("%d ", &n);
    read = n - n%3;

    while (n--){
        scanf("%d", &temp);
        things.push_back(temp);
    }

    sort(things.begin(), things.end(), greater<int>());

    for (int i{0}; i < read - 2; i += 3){
        discount += things[i+2];
    }   

    cout << discount << '\n';
    
    return 0;
}