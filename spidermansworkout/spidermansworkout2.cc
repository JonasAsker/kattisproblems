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

using namespace std;

const int INF = 1e9; 
//const int LLINF = 4e18; 
//const double EPS = 1e-9;
//typedef long long ll; // common data types 
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


// Bottom up DP with predecessor information in memo table.


int cases{0}, numOfExcercises{0}, temp{0};

const int maxSteps{101};
const int maxSum{1000};

// below stores the smallest largest height found on the way to 
// a certain (index, height). Initialize with inf.


int main() {
    //freopen("prog.in", "r", stdin);
    //freopen("prog.out", "w", stdout);
    scanf("%d ", &cases);
    while(cases--){
        scanf("%d", &numOfExcercises);
        int i{numOfExcercises}; int sum{0};
        vi vecExcercises;
        while(i--){
            scanf("%d", &temp); sum += temp; 
            vecExcercises.push_back(temp);
        }
        vector<vi> bestHeightTable(maxSteps, vi(maxSum, INF));
        // below keeps track of which conbinations of index and height are reachable
        // the first element is set to one if reachable, the two others store 
        // from where we came 
        vector<vector<vi>> reachable(numOfExcercises, vector<vi>(sum + 1, vi(3,0)));

        // initialize the first reachable state
        // the only reachable state from the ground is to take the first step up

        reachable[0][vecExcercises[0]][0] = 1;
        bestHeightTable[0][vecExcercises[0]] = vecExcercises[0];

        for (int i{1}; i < numOfExcercises ; ++i){ // loop the steps
            for (int h{0}; h <= sum; ++h){
                // loop over all heights and go up and down from each one
                // we can only go up or down from heights that are reachable
                if (!reachable[i-1][h][0]) continue;
                
                int up{h + vecExcercises[i]}, down{h-vecExcercises[i]};

                // try going down
                if ( down >= 0 ){ // cant go underground
                    // don't bother if we came from a higher point than the highest point we 
                    // saw last time we were here
                    if ( bestHeightTable[i][down] > bestHeightTable[i-1][h] ){
                        reachable[i][down] = {1,i-1,h};
                        bestHeightTable[i][down] = bestHeightTable[i-1][h];
                    }
                }

                // try going up
                int obs {bestHeightTable[i][up]};
                if ( up <= bestHeightTable[i][up] ) { // can we do better than recorded value
                    int update = max(up, bestHeightTable[i-1][h]); // update with largest value found up until this point
                    if (update <= bestHeightTable[i][up] ){
                        reachable[i][up] = {1,i-1,h};
                        bestHeightTable[i][up] = update;
                    }
                }
            }
        }

        // we have to make m moves and end up at height zero
        if (!reachable[numOfExcercises-1][0][0]) cout << "IMPOSSIBLE";

        else {
            string out{""}; int currHeight{0}, prevHeight{0};
            for (int i{numOfExcercises-1}; i >= 0; --i){
                prevHeight = reachable[i][currHeight][2];
                if (prevHeight > currHeight) out += 'D';
                else out += 'U';
                currHeight = prevHeight;
            }

            for (int s{numOfExcercises - 1};  s>=0; --s){
                cout << out[s];
            } 
        }


        cout << '\n';
    }
    return 0;
}