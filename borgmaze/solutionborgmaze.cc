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
#include <numeric>

#include "dijkstra.h"

using namespace std;

//const int INF = 1e9; 
//const int LLINF = 4e18; 
//const double EPS = 1e-9;
//typedef long long ll; // common data types 
//typedef unsigned long ul;
typedef pair<int, int> ii; // comments that are mixed typedef 
typedef vector<int> vi; // in with code are placed 
typedef vector<ii> vii; // on the right side 
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

// Title: Killing aliens in a Borg Maze

// Description:

// Complexity:

// Input constraints and expectations: 50x50 map, possible to have 2500 nodes
// therefore, Floyd Warshall is infeasible and so is an Adjacency Matrix. Instead,
// do Dijkstra for all aliens and the start node, 101*O(V*log(V)), V <= 2500, 
// should be within limits.

int main() {
    //freopen("g.in", "r", stdin);
    int C, H, W;
    string line;
    scanf("%d ", &C);
    while(C--){
        scanf("%d %d ", &W, &H);
        vii nodes;
        int numNodes{0};
        int x{0}, y{0};
        set<int> aliens;
        set<int> start;
        set<int> calculated;

        while(H--){
            getline(cin, line);
            y = -1;
            for (char c: line){
                y++;
                if (c == '#'){
                    continue;
                }

                else if (c == ' '){
                    nodes.push_back(make_pair(x, y));
                    numNodes++;
                }

                else if (c == 'S'){
                    nodes.push_back(make_pair(x, y));
                    start.insert(numNodes);
                    numNodes++;
                }

                else{
                    nodes.push_back(make_pair(x, y));
                    aliens.insert(numNodes);
                    numNodes++;
                }
            }
            x++;
        }

        vector<vii> adjacencyList(numNodes, vii());

        for (int i = 0; i < numNodes; i++){
            int x1 = nodes[i].first;
            int y1 = nodes[i].second;

            for(int j = 0; j < numNodes; j++){
                int x2 = nodes[j].first;
                int y2 = nodes[j].second;

                if (abs(x1-x2) + abs(y1-y2) == 1){
                    adjacencyList[i].emplace_back(j, 1);
                }
            }
        }

        int outSum{0}, nextStart{0};
        vector<vi> shortestPaths(numNodes, vi());

        while (!aliens.empty()){
            int distance{INF};
            for (const int &startNode: start){

                if (calculated.find(startNode) == calculated.end()){
                    Dijkstra Dijkstra(adjacencyList, startNode);
                    shortestPaths[startNode] = Dijkstra.shortestPath()[0];
                    calculated.insert(startNode);
                }

                for (const int &targetNode: aliens){
                    if (shortestPaths[startNode][targetNode] < distance){
                        distance = shortestPaths[startNode][targetNode];
                        nextStart = targetNode;
                    }
                }
            }

            aliens.erase(nextStart);
            start.insert(nextStart);
            outSum += distance;
        }

        cout << outSum << "\n";
    }

    return 0;
}
