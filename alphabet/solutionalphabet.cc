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

#include "lis.h"

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

// Title: alphabet

// Description: variant of longest increasing subsequence where you have to parser letters to
// their ascii codes. 

// Complexity: O(n*log(n))

// Input constraints and expectations: see kattis problem

int main() {
    //freopen("prog.in", "r", stdin);
    int temp{0};
    vector<ll> letters;
    string l;
    getline(cin, l);

    for (char a: l){
        temp = (int) a;
        letters.push_back((ll)a);
    }

    int len{(int)letters.size()};
    vi subseq = lis(letters, len);
    int out{26 - (int)subseq.size()};
    cout << out << '\n';
    
    return 0;
}