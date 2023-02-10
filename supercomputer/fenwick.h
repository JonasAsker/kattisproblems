// Implementation of the fenwick tree data structure
// assumes 1 based indexing
// all in one file for fast copy paste in a competetion setting

// expects to be initialized with an integer which is the length 
// of the original array.
// the method update expects on integer for the index and a ll for the value
// it adds the value to the index given and updates the tree
// rsq wants an integer for the index and sums up to that point and 
// returns the value.

// this fenwick has been modified to fit the problem supercomputer

#ifndef FENWICK_H
#define FENWICK_H

#include <vector>

typedef long long ll;

class Fenwick{
    private:
        std::vector<ll> memory;
        std::vector<ll> cumFreqs;
        int size{0};

    public:
        Fenwick(int n){
            size = n+1;
            cumFreqs.assign(n+1, 0);
            memory.assign(n+1, 0);
        }

        void update(int i){
            ll v{0};

            if (memory[i] == 1){
                memory[i] = 0;
                v = -1;
            }

            else{
                memory[i] = 1;
                v = 1;
            }
            
            while(i <= size){
                cumFreqs[i] += v;
                i += ((i) & -(i));
            }
        }

        ll rsq(int i){
            if (i == 0) return 0;
            ll out{0};

            while( i>0 ){
                out += cumFreqs[i];
                i -= (i & -i);
            }

            return out;
        }
};

#endif