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

//const int INF = 1e9; 
//const int LLINF = 4e18; 
//const double EPS = 1e-9;
//typedef long long ll; // common data types 
typedef pair<int, int> ii; // comments that are mixed typedef 
typedef vector<int> vi; // in with code are placed 
typedef vector<ii> vii; // on the right side 
//memset(memo, -1, sizeof memo); // to init DP memo table 
//vi memo(n, -1); // alternative way 
//memset(arr, 0, sizeof arr); // to clear array of ints
//++i; 
//ans = a ? b : c; 
//ans += val; 
//index = (index+1) % n; 
//index = (index+n-1) % n; 
//int ans = (int)((double)d + 0.5); 
//ans = min(ans, new_computation); 

// in comes n (1 < n <= 1000) -> next n lines are distinct integers
// next up (after n distinct integers) comes m (0<m<25) -> next m lines are query integers
// find a pair of numbers from the n which is closest to m

// when counting time complexity, what matters is the size of n, m, etc. The fact that there
// are several test cases is unimportant.

int main() {
    string row;
    int n{-1}; int m{-1}; int c{1};
    vi ns; set<int> nSums;
    set<int> ms;
    while(getline(cin, row)){
        if (n == -1) {n = stoi(row); cout << "Case " << c << ":" << "\n";}
        else if(n > 0) {ns.push_back(stoi(row)); --n;}
        else if (n == 0 && m == -1) {
            m = stoi(row);
            for(int i{0}; i<ns.size();  i++){
                for (int j{i+1}; j < ns.size(); j++){
                    nSums.insert(ns[i] + ns[j]);
                }
            }
        }
        else if (m>=0){
            int q{stoi(row)};
            auto closestI = nSums.lower_bound(q); int closest{*closestI};
            auto p = prev(closestI);
            if (closestI == nSums.end()){
                cout << "Closest sum to " << q << " is " << *nSums.rbegin() << "." << "\n";    
            }
            else if (abs(q - *p) < abs(closest - q) and closestI != nSums.begin()){
                cout << "Closest sum to " << q << " is " << *p << "." << "\n";
            }
            else {
                cout << "Closest sum to " << q << " is " << closest << "." << "\n";
            } 
            m--;
        }
        if (m == 0 and n == 0) {
            m = -1; nSums.clear(); ns.clear();
            n = -1; 
            c++;}
    }
    return 0;
}