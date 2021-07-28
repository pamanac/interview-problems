/*
 *
You are given an m x n grid where each cell can have one of three values:

0 representing an empty cell,
1 representing a fresh orange, or
2 representing a rotten orange.
Every minute, any fresh orange that is 4-directionally adjacent to a rotten orange becomes rotten.

Return the minimum number of minutes that must elapse until no cell has a fresh orange. If this is impossible, return -1.
 *
 *
 */

#include <iostream>
#include <tuple>
using namespace std;

class Solution {
    bool becomesRotten(int i, int j, vector<vector<int>>& grid){
        bool up = i-1 >= 0 ? grid[i-1][j] == 2 : false;
        bool down = i+1 < grid.size() ? grid[i+1][j] == 2 : false;
        bool left = j-1 >= 0 ? grid[i][j-1] == 2 : false;
        bool right = j+1 < grid[i].size() ? grid[i][j+1] == 2 : false;

        return up || down || left || right;
    }
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int N = grid.size();
        tuple<int,int> changes[N*grid[0].size()];
        int numChanges = 0;
        int startChanges = 0;
        int targetChanges = 0;
        int MAX_ATTEMPTS = N*grid[0].size();
        int attemptID = 0;
        bool rottenPresent = false;
        for(int row=0; row<N;row++){
            for(int col=0;col<grid[row].size();col++){
                if(grid[row][col]==1)
                    targetChanges++;
                else if(grid[row][col] == 2)
                    rottenPresent = true;
            }
        }
        if(targetChanges == 0)
            return 0;
        if(!rottenPresent)
            return -1;

        while(attemptID != MAX_ATTEMPTS && numChanges != targetChanges){
            attemptID++;
            for(int row=0; row<N; row++){
                for(int col=0; col<grid[row].size(); col++){
                    if(grid[row][col] == 1 && becomesRotten(row,col,grid)){
                        changes[numChanges++] = std::make_pair(row,col);
                    }
                }
            }
            for(int ch = startChanges; ch < numChanges; ch++){
                grid[std::get<0>(changes[ch])][std::get<1>(changes[ch])] = 2;
            }
            startChanges = numChanges;
        }
        return numChanges == targetChanges ? attemptID : -1;
    }
};
