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

// Title: dead fraction

// Description:
// use that c = a/b => a = b*c
// for b use formula (10^n - 1)*10^k 
// where n is the number of digits in periodic part of c
// and k is the number of digits after the dot before the periodic part starts.

// Complexity: the gcd uses euclid's algo which runs in O(log(2n))
// this means that the for loop is dominant if the number is long enough 
// so we have O(n*log(2n)). 

// Input constraints and expectations: see kattis problem

vi solver(string & s, int inx, int length){
    vi out(2, INF);
    int n{length - inx};
    int k{length - (n + 2)};
    string repS = s.substr(0, length);
    string rep = repS.substr(inx);
    
    while (repS.size() < 17) {
        repS += rep;
    }

    double c = stold(repS);
    int b{(int)(pow(10, n) - 1)*(int)pow(10, k)};
    int a{(int)round(b * c)};
    int gcdAB{gcd(a, b)};

    while ( gcdAB != 1 ){
        a /= gcdAB; 
        b /= gcdAB;
        gcdAB = gcd(a,b);
    }

    out[0] = a; out[1] = b;
    return out;
}

int main() {
    //freopen("prog.in", "r", stdin);
    string s;

    while( getline(cin, s) ){
        if (s == "0") break;
        int length{(int)s.size() - 3}, a{INF}, b{INF};
        vi nomDeNom;

        for (int i{2}; i < length; ++i){
            nomDeNom = solver(s, i, length);

            if ( nomDeNom[1] < b){
                b = nomDeNom[1]; a = nomDeNom[0];
            }
        }

        cout << a << "/" << b << '\n';
    }
    
    return 0;
}