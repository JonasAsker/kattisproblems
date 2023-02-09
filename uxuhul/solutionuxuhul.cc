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
typedef vector<string> VS;  
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

// Title: the uxuhul voting system

// Description: top down dynamic programming with bit toggling.
// pretty much a recursive complete search but with a memo table because the
// overlap between subproblems is very big.

// Complexity: 3^numOfPriests without the memotable. with the memotable it's much
// more manageable.

// Input constraints and expectations: see problem description.

int numOfPriests{0};
int memo[101][9];
vector<vi> steps(8, vi(3, 0));
VS answers {"NNN", "NNY", "NYN", "NYY", "YNN", "YNY", "YYN", "YYY"};

int bestChoice(vi & pref, vi & possible){
    int best{10};
    int outcome;

    for (auto i : possible){

        if (pref[i] < best){
            best = pref[i];
            outcome = i;
        }
    }

    return outcome;
}


void stoneFlip(int stones){
    int flippedStones{0};

    for (int i{0}; i < 3; ++i){
        flippedStones = stones;
        flippedStones ^= (1<<i);
        steps[stones][i] = flippedStones; 
    }
}


int solver(vector<vi> & prefs, int priest, int currentVote){
    vi reachable = steps[currentVote];
    vi outcomes;

    if (priest == numOfPriests - 1){
        int vote = bestChoice(prefs[priest], reachable);
        memo[priest][currentVote] = vote;
        return vote;
    }

    for (auto i : reachable){
        int outcome{0};

        if (memo[priest][i] != -1){
            outcome = memo[priest][i];
            outcomes.push_back(outcome);
        }

        else {
            outcome = solver(prefs, priest + 1, i);
            memo[priest][i] = outcome;
            outcomes.push_back(outcome);
        }
    }

    int vote = bestChoice(prefs[priest], outcomes);
    return vote;
}


int main() {
    //freopen("prog1.in", "r", stdin);
    int tc{0};
    scanf("%d ", &tc);

    for(int i{0}; i < 8; ++i){
        stoneFlip(i);
    }

    while (tc--){
        scanf("%d ", &numOfPriests);
        vector<vi> prefs(numOfPriests, vi(8,0));
        memset(memo, -1, sizeof memo);
 
        for (int k{0}; k < numOfPriests; ++k){
            int temp{0};

            for(int i{0}; i < 8; ++i){
                scanf("%d", &temp);
                prefs[k][i] = temp;
            }
        }

        int vote = solver(prefs, 0, 0);
        cout << answers[vote] << '\n';
    }
    
    return 0;
}