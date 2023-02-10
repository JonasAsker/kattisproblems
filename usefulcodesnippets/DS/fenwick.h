// Implementation of the fenwick tree data structure
// assumes 1 based indexing
// all in one file for fast copy paste in a competetion setting

#ifndef FENWICK_H
#define FENWICK_H

#include <vector>

typedef long long ll;

class Fenwick{
    private:
        std::vector<ll> cumFreqs;
        int size{0};

    public:
        Fenwick(int n){
            size = n+1;
            cumFreqs.assign(n+1, 0);
        }

        void update(int i, ll v){
            ++i; 
            
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