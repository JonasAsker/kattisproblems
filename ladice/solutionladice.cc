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

// Title: ladice

// Description: containers which can only contain one item.
// each item can be in one of two containers. 
// trick is to realize that we don't need to keep track of where we put 
// the items. what we do need to keep track of is the chains in which we can
// move items around from one container to another. theses chains are represented
// by UFDS. to containers are joined together if an item can be in either of them
// the size of the set is decreased for each item put in it. 
// using arrays is infeasible as the number of instructions and boxes <= 300000.

// Complexity: ufds is ~ O(1) so in total O(N).

// Input constraints and expectations: see kattis

int main() {
    //freopen("prog.in", "r", stdin);
    int N{0}, L{0}, group1{0}, group2{0};
    scanf("%d%d ", &N, &L);
    Ufds boxes = Ufds(L+1);

    while(N--){
        scanf("%d%d ", &group1, &group2);

        if (boxes.getSize(group1) != 0){
            boxes.decreaseSize(group1);
            boxes.makeUnion(group1, group2);
            cout << "LADICA" << '\n';
        }

        else if (boxes.getSize(group2) != 0){
            boxes.decreaseSize(group2);
            boxes.makeUnion(group1, group2);
            cout << "LADICA" << '\n';
        }

        else {
            cout << "SMECE" << '\n';
        }
    }

    return 0;
}