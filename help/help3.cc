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

string tempU, tempD, first, second; 
VS upVec , downVec; bool impossible{false};
VS out; bool updated{false};

void replacer(VS& vec, string key, string value){
    for (int i{0}; i < (int) vec.size(); i ++){
        if (vec[i] == key){
            vec[i] = value;
        }
    }
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
            upVec.clear(); downVec.clear();
            continue;
        }
        do {
            updated = false;
            for (int i{0}; i < (int) upVec.size(); i++){
                tempU = upVec[i]; tempD = downVec[i];

                if(tempU[0] == '<' and tempD[0] != '<'){
                    replacer(upVec, tempU, tempD);
                    updated = true;
                }
            }
            for (int i{0}; i < (int) upVec.size(); i++){
                tempU = upVec[i]; tempD = downVec[i];
                if(tempD[0] == '<' and tempU[0] != '<'){
                    replacer(downVec, tempD, tempU);
                    updated = true;
                }
            }
        }
        while(updated);
        for (int i{0}; i < (int) upVec.size(); i++){
            tempU = upVec[i]; tempD = downVec[i];
            if (tempU[0] == '<') upVec[i] = "x";
            if (tempD[0] == '<') downVec[i] = "x";
        }
        if (upVec != downVec) {cout << "-\n";}
        else {
            for (int i{0}; i < (int) upVec.size(); i++){
                tempU = upVec[i];
                cout << tempU;
                if (i != (int)upVec.size() - 1) cout << " ";
                else cout << "\n";
            }   
        }
        upVec.clear(); downVec.clear();
    }
}