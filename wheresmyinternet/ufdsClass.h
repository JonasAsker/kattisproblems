// Implementation of the union find disjoint sets data structure
// all in one file for fast copy paste in a competetion setting

// this has been modified to fit the problem wheresmyinternet

#ifndef UFDSCLASS_H
#define UFDSCLASS_H

#include <vector>
#include <algorithm>

class Ufds{

    private:
        std::vector<int> parents;
        std::vector<int> treeHeights;

    public:
        Ufds(int n){
            parents.assign(n, 0);
            treeHeights.assign(n, 0);

            for (int i{0}; i < n; ++i){
                parents[i] = i;
            }
        };
        
        int getParent(int a){

            if (parents[a] == a){
                return a;
            }

            parents[a] = getParent(parents[a]);
            return parents[a];
        }

        bool same(int a, int b){
        
            if (getParent(a) == getParent(b)){
                return true;
            }

            return false;
        }

        void makeUnion(int a, int b){
        
            if (!same(a, b)){
                int parentA{getParent(a)}, parentB{getParent(b)};
                int parent = std::min(parentA, parentB);
                int child = std::max(parentA, parentB);
                //int heightA{treeHeights[parentA]}, heightB{treeHeights[parentB]};

                //if (heightA < heightB){
                //    parents[parentA] = parentB;
                //}

                //else {
                    parents[child] = parent;
                //}

                //if (heightA == heightB){
                //    ++ treeHeights[parentA];
                //}
            }
        }
        
};

#endif