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
typedef unsigned long long ll; // common data types 
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

int main() {
    //freopen("prog.in", "r", stdin);
    ll l{0}, d{0};
    int n{0};
    scanf("%lld%lld%d ", &l, &d, &n);
    l -= 12;
    ll temp{0};
    vector<ll> lengths;
    vector<ll> birds;
    ll prevLength{0};
    ll tempLength{0};
    ll out{0};
    ll lastBird{0};

    if (l < 0){
        cout << 0 << '\n';
    }

    else{

        while(n--){
            scanf("%lld ", &temp);
            birds.push_back(temp - 6);
        }

        sort(birds.begin(), birds.end());

        for (int i{0}; i < (int) birds.size(); ++i){

            if (i != 0){
                tempLength = birds[i] - prevLength;
                prevLength = birds[i] + d;
                lengths.push_back(tempLength);
            }

            if (i == 0){
                prevLength = birds[0] + d;
                lengths.push_back(birds[0]);
            }

            if (i == (int) birds.size() - 1){
                lastBird = birds[i];
            }
        }

        if (birds.size() != 0){
            ll offset{lastBird};
            if (offset < l){
                lengths.push_back(l - (lastBird));
            }

            for (auto l: lengths){
                if ( l > 0){
                    out += l / d;   
                }
            }
        }

        else{
            out += l / d;
            ++out;
        }

        cout << out << '\n';
        int Bp{0};

    }
    
    return 0;
}