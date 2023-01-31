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
typedef vector<int> vi; // in with code are placed
typedef long long llint; 
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

int main() {
    // initalize variables, 2*10^9 fits in 32 bits
    int children{0}, candies{0}, wish{0};
    // use long for those who might grow large
    llint totalDesire{0}, rage{0}, sub{0};
    vi wishes;
    scanf("%d %d", &candies, &children);
    // make vector of desires
    while(true){
        scanf("%d", &wish);
        if (feof(stdin)) break; // test EOF
        totalDesire += wish;
        wishes.push_back(wish);
    }
    // instead of handing out candy, hand out lack of candy. 
    // look at the problem backwards as Halim puts it.
    llint missing{totalDesire - candies};
    // the total missing candy is a fixed sum
    // the rage is the sum of the squared terms of that sum
    // this problem is minimized when all terms are equal
    // they are equal when selected as the missing candy split 
    // between the children.
    // since this is a greedy problem we minimize first the 
    // sum with all children taken into account, then one fewer, then two etc.
    llint average{missing/children};
    if (average == 0) average = 1;
    // we are bounded by the child wanting the fewest candies as we 
    // might not be able to give it the average lack of candy, take 
    // as much as possible from that child. 
    // we want to start with the least hungry child so we sort the vector.
    sort(wishes.begin(), wishes.end());
    // sort in O(nlog(n)), quicksort
    while (missing){
        // do the procedure described above, one loop -> linear O(n)
        for (auto &i : wishes){
            if (i >= average){
                sub = average;
            }
            else{
                sub = i;
            }
            i -= sub;
            missing -= sub;
            --children;
            rage += (sub * sub);
            if (children == 0) {missing = 0; break;}
            average = missing/children;
        }
    }
    // O(n) + O(nlog(n)) = O(nlog(n)), N <= 100000 OK
    cout << rage << '\n';
    return 0;
}