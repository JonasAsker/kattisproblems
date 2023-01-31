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
#include <unordered_map>

using namespace std;

//const int INF = 1e9; 
//const int LLINF = 4e18; 
//const double EPS = 1e-9;
//typedef long long ll; // common data types 
//typedef pair<int, int> ii; // comments that are mixed typedef 
//typedef vector<int> vi; // in with code are placed 
//typedef vector<ii> vii; // on the right side 
typedef vector<string> VS;  
typedef vector<vector<string> > VVS;
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
typedef unordered_map<string, unordered_set<string>> um;
typedef unordered_map<string, string> umss;

string tempU, tempD, first, second; 
VS upVec , downVec; bool impossible{false};
um dictUpDownKeys, dictDownUpKeys;
umss dictUpDownAlpha, dictDownUpAlpha;

string chainer(string chainKey, bool up){
    um dictKey = dictDownUpKeys; umss dictDownUpAlpha;
    if (up){
        um dictKey = dictUpDownKeys; umss dictUpDownAlpha;
    }
    for (auto [key, value] : dictKey){
        for(auto v: value){
            if (up){
                if (dictDownUpAlpha.count(v) != 0){
                    if (dict)
                }
            }
        }
    }
}

int main() {
    // initialize variables
    int cases; scanf("%d ", &cases);
    // get a pair of lines, a pattern
    while(getline(cin, tempU) && getline(cin, tempD)){
        istringstream issF(tempU); istringstream issS(tempD);
        // split into vectors of strings
        while( issF >> first ) upVec.push_back(first);
        while( issS >> second ) downVec.push_back(second);
        // differnt lengths can't match
        if (upVec.size() != downVec.size()) {
            cout << "-" << '\n';
            continue;
        }
        // create maps which will chain together the mappings of <x> and x
        for (unsigned int i; i < upVec.size(); i++){
            tempU = upVec[i]; tempD = downVec[i];
            if (tempU[0] == '<' and tempD[0] == '<'){
                dictUpDownKeys[tempU].insert(tempD);
                dictUpDownKeys[tempD].insert(tempU); // can probably get rid of one of the dicts
            }                                        // be cause ones keys is the others values
            else if (tempU[0] == '<' and tempD[0] != '<'){ // which means we have all the information
                if (dictUpDownAlpha.count(tempU) == 0){
                    dictUpDownAlpha[tempU] = tempD;
                }
                else if (dictUpDownAlpha[tempU] != tempD ) {impossible = true; break;}       
            }
            else if (tempD[0] == '<' and tempU[0] != '<'){
                if (dictDownUpAlpha.count(tempD) == 0){
                    dictDownUpAlpha[tempD] = tempU;
                    }
                else if (dictDownUpAlpha[tempD] != tempU ) {impossible = true; break;}
            }
        }
        // if we have found a key that has to map to two differnt letters we cant proceed
        if (impossible){
            cout << "-" << '\n';
            dictDownUpAlpha.clear(); dictDownUpKeys.clear();
            dictUpDownAlpha.clear(); dictDownUpKeys.clear();
            impossible = false;
            continue;           
        }

        for (auto i : upVec){
            if (dictUpDownKeys.count(i) == 0){
                cout << i;
            }
            else if (dictUpDownAlpha.count(i) != 0){
                cout << dictUpDownAlpha[i];
            }
            else{
                    chainer(i, true);

                }
            }
        }
        
    return 0;
}