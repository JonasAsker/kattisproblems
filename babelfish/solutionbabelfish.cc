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
#include <unordered_map>

using namespace std;

//const int INF = 1e9; 
//const int LLINF = 4e18; 
//const double EPS = 1e-9;
//typedef long long ll; // common data types 
//typedef pair<int, int> ii; // comments that are mixed typedef 
//vector<int> vi; // in with code are placed 
//typedef vector<ii> vii; // on the right side 
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

int main() {
    unordered_map<string, string> dict;
    string key;
    string value;
    string row;
    bool endOfDict{false};
    while(getline(cin, row)){
        istringstream iss{row};
        if (row.empty()){
            endOfDict = true;
        }
        else if (!endOfDict){
            iss >> value >> key;
            dict[key] = value;
        }
        else{
            iss >> key;
            if (dict.count(key) == 0){
                cout << "eh" << "\n";
            }
            else{
                cout << dict[key] << "\n";
            }
        } 
    }
    return 0;
}