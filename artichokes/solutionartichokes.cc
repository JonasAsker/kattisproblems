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

// Title: artichokes

// Description: find the largest decrease in a number sequence. note that it's not the same as
// the greatest difference beteween two numbers.

// Complexity: O(N)

// Input constraints and expectations: see kattis problem.

int main() {
    //freopen("prog.in", "r", stdin);
    cout << fixed;
    cout << setprecision(7);
    int p{0}, a{0}, b{0}, c{0}, d{0}, n{0};
    scanf("%d%d%d%d%d%d", &p, &a, &b, &c, &d, &n);
    double price{0};
    double initPrice{p*(sin(a*1+b) + cos(c*1+d) + 2)}; 
    double minPrice{initPrice}, maxPrice{initPrice}, decrease{0};

    for(int k{2}; k <= n; ++k){
        price = p*(sin(a*k+b) + cos(c*k+d) + 2);
        
        if (price > maxPrice){
            maxPrice = price;
            minPrice = price;
        }

        else if (price < minPrice){
            minPrice = price;
            decrease = max(decrease, maxPrice - minPrice);
        }
    }

    if (minPrice == initPrice){
        cout << 0 << '\n';
    }

    else{
        cout << decrease << '\n';
    }
    
    return 0;
}