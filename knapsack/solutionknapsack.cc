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
//const double EPS = 1e-9;
//typedef long long ll; // common data types 
typedef pair<int, int> ii; // comments that are mixed
typedef vector<int> vi; // in with code are placed 
typedef vector<ii> vii; // on the right side 
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

// DYNAMIC PROGRAMMING - KNAPSACK PROBLEM
// the states are current weight and index. transitions are to add 
// item i or to not add item i. either one increases the index but only adding
// item increases the current weight. in the DP table, the greatest value 
// found at this weight, index combination is stored. the best value found is 
// stored in a seperate variable and so is it's state. the optimal solution
// is then found by going backwards from the state which had the best value.

// COMPLEXITY
// runs in O(capacity*n) because of the for loops in knapsack().
// each table insertion and look up is O(1). 
// sice both n and capacity <= 2000, this is well within the 100M limit.

// Input constraints and expectations
// The input consists of between 1 and 30 test cases. Each test case begins with an integer 1 <= C <= 2000, 
// giving the capacity of the knapsack, and an integer 1 <= n <= 2000, giving the number of objects. 
// Then follow n lines, each giving the value and weight of the n objects. 
// Both values and weights are integers between 1 and 10000.

int memo[2001][10001]; // one extra row and column to avoid segmentation fault.

vi solConstruct(vii & things, ii & opt, int & optValue){
    // backtrack in the table to print the optimal solution
    vi out;
    int weight{opt.second}, index{opt.first}, value{optValue};
    for (int k{index}; k>=0; --k){
        if (k == 0){
            if (memo[k][weight] == value){
                out.push_back(0);
            }
            break;
        }
        else if (memo[k-1][weight] != value){
            out.push_back(k);
            value -= things[k].first;
            weight -= things[k].second;
        }
        else if (memo[k][weight] == value){
            continue;
        }
        if (weight == 0 && value == 0){
            return out;
        }
    }
    return out;
}

vi knapsack(int & cap, vii & things){
    // go over the table and fill out values bottom up 
    vi out;

    int optValue{things[0].first}; ii opt;
    opt.first = 0; opt.second = things[0].second;

    for (int i{1}; i <= (int) things.size(); ++ i){
        for (int w{0}; w <= cap; ++ w){

            if (memo[i-1][w] != -1){
                
                int cumValue{memo[i-1][w] + things[i].first};
                int cumWeight{w + things[i].second};

                // don't add item i
                if(memo[i][w] < memo[i-1][w]){

                    memo[i][w] = memo[i-1][w];

                    if (optValue < memo[i][w]){
                        optValue = memo[i][w];
                        opt = {i-1, w};
                    }
                }

                // add item i
                if(cumWeight <= cap && memo[i][cumWeight] < cumValue
                    && i != (int) things.size()){
                    memo[i][cumWeight] = cumValue;
                    if (optValue < cumValue){
                        optValue = cumValue;
                        opt = {i, cumWeight};
                    }
                }   
            }
        }
    }
    vi indicies = solConstruct(things, opt, optValue);
    return indicies;
}

int main() {
    int c, n, w, v;
    vii stuff;

    // for debugging. 
    //freopen("prog1.in", "r", stdin);

    while(scanf("%d %d", &c, &n) != EOF){
        memset(memo, -1, sizeof memo);
        stuff.clear();
        for (int i{0}; i < n; ++i){
            scanf("%d %d", &v, &w);
            stuff.push_back({v,w});
            if (w <= c) memo[i][w] = v;
        }

        vi indicies = knapsack(c, stuff);

        if (indicies.size()){
            cout << (int)indicies.size() << '\n';
            for (int i{0}; i < (int)indicies.size(); ++i){
                cout << indicies[i];
                if (i != (int)indicies.size() - 1) cout << " ";
            }
        }

        else cout << 0;

        cout << '\n';

        indicies.clear();
    }
    
    return 0;
}