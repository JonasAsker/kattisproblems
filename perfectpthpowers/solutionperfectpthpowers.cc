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
const double EPS = 1e-9;
typedef long long ll; // common data types 
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

// Title: Perfect pth powers

// Description: Find the greatest exponent e which would satisy x^e = b where b is 
// the given integer and x can be any integer. here one can simply check all integers up
// to the square root and check the logarithm in the base of each investigated integer.

// Complexity: for the majority of integers in the problem range the problem range 
// the logarithm takes just a single instruction O(1). therefore, the loop is 
// dominant and we have linear time.

// Input constraints and expectations: see problem on kattis.

int main() {
    //freopen("prog1.in", "r", stdin);
    ll a{0};
    double c{0};

    while(scanf("%lld ", &a)){
        bool found{false};
        if ( a == 0 ) break;

        else if ( a > 0){

            for (int i{2}; i <= sqrt(a); ++i){
                c = log(a) / log(i);

                if (floor(c) <= c + EPS && floor(c) >= c - EPS){
                    cout << c << '\n';
                    found = true;
                    break;
                }    
            }
        }

        else {
            ll aAbs{abs(a)};

            for (int i{2}; i <= sqrt(aAbs); ++i){
                c = log(aAbs) / log(i);

                if (floor(c) <= c + EPS && floor(c) >= c - EPS
                    && ((int)floor(c) % 2 != 0)){
                    cout << c << '\n';
                    found = true;
                    break;
                }    
            }

        }

        if (!found){
            cout << 1 << '\n';
            found = false;
        }

    }
    return 0;
}