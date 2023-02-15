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

const int INF = 1e9; 
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

// Title: firefly

// Description: find the path through obstacles which are lines in a plane parallell to the y axis.
// the solution is the path which goes through the fewest obstacles. divide and conquer approach in which
// we first sort the obstacles on height and then binary search a height which gives the fewest obstacles hit. 

// Complexity: O(N*log(N))

// Input constraints and expectations: see kattis problem.

int main() {
    //freopen("prog.in", "r", stdin);
    int N{0}, H{0}, temp{0}, k{1};
    vi stag, stac;
    scanf("%d%d ", &N, &H);
    scanf("%d ", &temp);
    stag.push_back(temp);

    while (k < N){
        scanf("%d ", &temp);

        if (k % 2 == 0){
            stag.push_back(temp);
        }

        else{
            stac.push_back(temp);
        }

        ++k;
    }

    sort(stag.begin(), stag.end());
    sort(stac.begin(), stac.end());
    int solutions{0}, stagsHit{0}, stacsHit{0}, minHits{INF};

    for (int h{1}; h <= H; ++h){
        stacsHit = stac.end() - lower_bound(stac.begin(), stac.end(), H-h+1);
        stagsHit = stag.end() - lower_bound(stag.begin(), stag.end(), h);

        if (stacsHit + stagsHit < minHits){
            minHits = stacsHit + stagsHit;
            solutions = 1;
        }

        else if (stacsHit + stagsHit == minHits){
            ++solutions;
        }
    }

    cout << minHits << ' ' << solutions << '\n';
    
    return 0;
}