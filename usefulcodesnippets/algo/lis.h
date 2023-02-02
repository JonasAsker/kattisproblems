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

using namespace std;

typedef long long ll;
const ll LLINF = 4e18; 
typedef vector<int> vi;

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