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
typedef unordered_map<string, string> umss;
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

string tempU, tempD, first, second; 
VS upVec , downVec; bool impossible{false};
umss dictUpAlpha, dictDownAlpha;
VS out;
//(int)upVec.size()-1
bool chainer(VS vec1, VS vec2){
    for (int i{0}; i < (int)upVec.size(); i++){
            tempU = vec1[i]; tempD = vec2[i];
            // tempU is the upper word and tempD is the lower
            if (tempU[0] == '<' and tempD[0] != '<'){
                // we find a key-value pair to insert, check if we've
                // already found a value for this key
                if (dictUpAlpha.count(tempU) == 0){
                    // we have no value so assign this one
                    dictUpAlpha[tempU] = tempD;
                }
                else if (dictUpAlpha[tempU] != tempD ) {
                    return false;
                    }
            }
            else if (tempU[0] != '<' and tempD[0] == '<'){
                // we find a key-value pair to insert, check if we've
                // already found a value for this key
                if (dictDownAlpha.count(tempD) == 0){
                    // we have no value so assign this one
                    dictDownAlpha[tempD] = tempU;
                }
                else if (dictDownAlpha[tempD] != tempU ) {
                    return false;
                    }
            }
            else if (tempU[0] == '<' and tempD[0] == '<'){
                // here we have established that we are looking 
                // at a key-key pair -> check if any of them
                // has a value associated to it.
                if (dictUpAlpha.count(tempU) != 0 &&
                    dictDownAlpha.count(tempD) != 0){
                    // here we know that both of them has a value, 
                    // make sure that the value is the same for both
                    if (dictDownAlpha[tempD] != dictUpAlpha[tempU]){
                        // if they dont have the same value we stop and print -
                        return false;
                    }
                    // otherwise we're good, keep going
                    else{continue;}
                }
                else if(dictUpAlpha.count(tempU) != 0 &&
                        dictDownAlpha.count(tempD) == 0){
                    // here we find that the upper one has a value
                    // but the lower one doesnt -> we associate the 
                    // lower key's value to be the same as the upper ones
                    dictDownAlpha[tempD] = dictUpAlpha[tempU];
                    }
                else if(dictUpAlpha.count(tempU) == 0 &&
                        dictDownAlpha.count(tempD) != 0){
                    // analogous to above but reversed    
                    dictUpAlpha[tempU] = dictDownAlpha[tempD];
                    }
                //else if(dictUpAlpha.count(tempU) == 0 &&
                //        dictDownAlpha.count(tempD) == 0){
                //    // last case, a key-key pair where neither
                //    // of them has a value -> assign x to both of them    
                //    dictUpAlpha[tempU] = "A";
                //    dictDownAlpha[tempD] = "A";
                //    }     
            }
            else if (tempU[0] != '<' and tempD[0] != '<'){
                if (tempU[0] != tempD[0]) return false;
            }
    }
    // if we get here, everyone has an association and we can start printing
    return true;                               
}

int main() {
    // initialize variables
    //freopen("prog2.in", "r", stdin);
    //freopen("prog.out", "w", stdout);
    string cases; getline(cin, cases);
    // get a pair of lines, a pattern
    while(getline(cin, tempU) && getline(cin, tempD)){
        istringstream issF(tempU); istringstream issS(tempD);
        // split into vectors of strings
        while( issF >> first ) upVec.push_back(first);
        while( issS >> second ) downVec.push_back(second);
        // differnt lengths can't match
        if (upVec.size() != downVec.size()) {
            cout << "-" << '\n';
            dictUpAlpha.clear(); dictDownAlpha.clear();
            upVec.clear(); downVec.clear();
            continue;
        }
        // build dicts with key value relation where the key is <x> and value is x
        // one dict for the upper row and one for the lower

        VS upVecR{upVec}; VS downVecR{downVec};
        reverse(upVecR.begin(), upVecR.end());
        reverse(downVecR.begin(), downVecR.end());

        // print - if we have established that it is impossible
        if (impossible){
            cout << "-" << '\n';
            dictUpAlpha.clear(); dictDownAlpha.clear();
            upVec.clear(); downVec.clear();
            impossible = false;
            continue;           
        }
        // link together keys and values with chainer, if we find
        // that to be impossilbe, print -
        if (! chainer(upVecR, downVecR)){
            cout << "-" << '\n';
            dictUpAlpha.clear(); dictDownAlpha.clear();
            upVec.clear(); downVec.clear();
            impossible = false;
            continue;
        }
        if (! chainer(upVec, downVec)){
            cout << "-" << '\n';
            dictUpAlpha.clear(); dictDownAlpha.clear();
            upVec.clear(); downVec.clear();
            impossible = false;
            continue;
        }
        // the printing routine
        unsigned int j{0};
        for(auto i : upVec){
            if (dictUpAlpha.count(i) != 0){
                cout << dictUpAlpha[i];
            }
            else if (i[0] == '<') cout << "x";
            else cout << i;
            if (j != upVec.size()-1) cout << " ";
            j++;
        }
        dictUpAlpha.clear(); dictDownAlpha.clear(); j=0;
        upVec.clear(); downVec.clear();
        cout << '\n';
    }
}