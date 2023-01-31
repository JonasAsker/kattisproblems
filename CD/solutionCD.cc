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
    int jacks{0}; 
    int jills{0}; int tempA {0}; int tempB{0}; int readLines{0}; int common{0};
    scanf("%d%d", &jacks, &jills);
    char sep;
    unordered_set<int> jacksCDs;
    while(1){
        scanf("%d%c", &tempA, &sep);
        if (sep != '\n'){
            scanf("%d", &tempB);
            jacks = tempA; jills = tempB;
            cout << common << "\n";
            jacksCDs.clear(); readLines=0; common=0;
            if (jacks == 0 and jills == 0) break;
        }
        else {
            if (readLines ++ < jacks){
                jacksCDs.insert(tempA);
            }
            else if (jacksCDs.count(tempA) != 0) {
                jacksCDs.erase(tempA);
                common ++;
            }
        }
    }
    return 0;
}