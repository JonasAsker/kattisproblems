// Implementation of the union find disjoint sets data structure
// all in one file for fast copy paste in a competetion setting
// modified to match problem ladice

#ifndef UFDSCLASS_H
#define UFDSCLASS_H

#include <vector>

class Ufds{

    private:
        std::vector<int> parents;
        std::vector<int> treeHeights;
        std::vector<int> setSize;

    public:
        Ufds(int n){
            parents.assign(n, 0);
            treeHeights.assign(n, 0);
            setSize.assign(n, 1);

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

        int getSize(int a) {
            return setSize[getParent(a)];
        }

        void decreaseSize(int a){
            setSize[getParent(a)] -= 1;
        }

        void makeUnion(int a, int b){
        
            if (!same(a, b)){
                int parentA{getParent(a)}, parentB{getParent(b)};
                int heightA{treeHeights[parentA]}, heightB{treeHeights[parentB]};

                if (heightA < heightB){
                    parents[parentA] = parentB;
                    setSize[parentB] += setSize[parentA];
                }

                else {
                    parents[parentB] = parentA;
                    setSize[parentA] += setSize[parentB];
                }

                if (heightA == heightB){
                    ++ treeHeights[parentA];
                }
            }
        }
        
};

#endif