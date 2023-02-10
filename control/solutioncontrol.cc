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

#include "ufdsClass.h"

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

// Title: associatoin for control over minds

// Description: union find ds where the sets are cauldrons for potion cooking with a set of ingredients 
// with only one of each. use ufds to keep track of the cauldrons and simulate the pouring of one 
// into anonther. also helps to check if one legally can make a potion, that is whether or not 
// a subset of one set is a complete set already found.

// Complexity: all ufds operations tend to O(1). so we have O(N*setof(M)) where 1<= M but sum(M) over N <= 500000.
// the worst case is around O(2M), well below 100M.

// Input constraints and expectations: see kattis problem control

const int MAXINGREDIENT{500001};
int overlap[MAXINGREDIENT];

int main() {
    //freopen("prog.in", "r", stdin);
    int r{0}, rLen{0}, temp{0};
    scanf("%d ", &r);
    Ufds cauldrons = Ufds(MAXINGREDIENT);
    bool possible{true};
    int numPotions{0};

    while (r--){
        scanf("%d", &rLen);
        vi recipie;

        for (int i{0}; i < rLen; ++i){
            scanf("%d", &temp);
            recipie.push_back(temp);
            ++overlap[cauldrons.getParent(temp)];
        }

        for (int i: recipie){

            if (cauldrons.getSize(i) != overlap[cauldrons.getParent(i)]) {
                possible = false;
                break;
            }
        }

        for (int i: recipie){
            overlap[cauldrons.getParent(i)] = 0;
        }

        if (possible){
            ++numPotions;

            for (size_t i{0}; i < recipie.size() - 1; ++i){
                cauldrons.makeUnion(recipie[i], recipie[i+1]);
            }
        }

        possible = true;
    }

    cout << numPotions << '\n';

    return 0;
}