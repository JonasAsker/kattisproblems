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

//const int INF = 1e9; 
//const double EPS = 1e-9;
typedef long long ll; // common data types 
const ll LLINF = 4e18; 
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

// Title: Longest increasing subsequence

// Description:
// find the longest increasing subsequence in an array.
// goal is to make it run in O(n*log(n)) trough binary search and 
// dynamic programming. integers between -2^31 and 2^31 so ints are not enough!
// the solution is found by keeping a sorted list of the smallest possible
// end values of increasing sequences of lengths up to longest possible 
// increasing subsequence length. on this list binary search is performed
// with elements from the given sequence. if the current element in the 
// sequence can be used to replace an end value of a subsequence, that 
// element is used instead. for these values, predecessor information as well
// as index in the original sequence is saved. to find the solution the 
// last element in the array of end elements is picked and from that one 
// the solution is constructed through backtracking.

// Complexity:
// for loop over all n numbers O(n), in each iteration a binary search
// is performed O(log(n)) resulting in O(n*log(n)).

// Input constraints and expectations:
// The input consists of between 1 and 64 test cases. Each test case has two lines. 
// The first line has a positive integer n <= 100000, indicating the length of a sequence. 
// Then follows a line containing a sequence of n integers, each in the range -2^31 to 2^31. 
// Input ends at end of file.

vi constructSol(vi & p, int & maxIndex){
    // p are the predecessors
    // maxindex is the index in the original sequence
    // the last legitimate value in endofseqs.
    vi longestSubSeq;
    int pred{p[maxIndex]};
    longestSubSeq.push_back(maxIndex);

    while (pred != -1){
        longestSubSeq.push_back(pred);
        pred = p[pred];
    }

    return longestSubSeq;
}

vi lis(vector<ll> & sequence, int & seqLen){
    vector<ll> endOfSeqs(seqLen + 1, LLINF), indexOfSeqs(seqLen, -1);
    vi predecessors(seqLen, -1);
    int length{0}, maxIndex{0};

    for (int i{0}; i < seqLen; ++i){
        // find index where current element is the end of longest
        // subsequence. sequence[i] <= element
        int inx = lower_bound(endOfSeqs.begin(), endOfSeqs.end(), sequence[i]) - endOfSeqs.begin();

        if (endOfSeqs[inx+1] == LLINF){
            maxIndex = i;
            length = inx + 1;
        }

        endOfSeqs[inx] = sequence[i]; indexOfSeqs[inx] = i;

        if(inx){
            predecessors[i] = indexOfSeqs[inx - 1];
        }

        // if inx == 0, the current element should be at the beginning of a 
        // subsequence of length one and therefore has no predecessor.
        else predecessors[inx] = -1;

    }
    vi out = constructSol(predecessors, maxIndex);
    return out;
}

int main() {
    //freopen("prog.in", "r", stdin);
    ll temp; int l;
    vector<ll> sequence;

    while(scanf("%d ", &l) != EOF){

        if ( l == 0) {cout << "0\n"; continue;}

        for(int i{0}; i < l; ++i){
            scanf("%lld", &temp);
            sequence.push_back(temp);
        }

        vi out = lis(sequence, l);
        cout << (int) out.size() << '\n';

        if (!out.empty()){

            for (int i{(int) out.size()-1}; i >= 0; --i){
                cout << out[i];
                if (i != 0) cout << " ";
            }

            cout << '\n';
        }

        sequence = {};
    }
    
    return 0;
}