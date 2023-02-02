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

typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;

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