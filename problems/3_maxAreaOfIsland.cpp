#include <iostream> 
#include <vector>
using namespace std;

class Solution {
public:
    int maxAreaOfIsland(vector<vector<int> >& grid) {
        int count = 0;
        for (int i=0; i<grid.size(); i++)
            for(int j=0; j < grid[i].size(); j++) {
                if (grid[i][j]==1) {
                    count = islandsearch(grid, i, j);
                    if (count>maxcount)
                        maxcount = count;
                }
            }        
        return maxcount;
    }
private:
    int islandsearch(vector<vector<int> >& grid, int i, int j) {
        int count = 1; 
        grid[i][j] = 2; 
        
        if (i>0 && grid[i-1][j]==1)
            count += islandsearch(grid, i-1, j);
        if (j>0 && grid[i][j-1]==1)
            count += islandsearch(grid, i, j-1);
        if (i<grid.size()-1 && grid[i+1][j]==1)
            count += islandsearch(grid, i+1, j);
        if (j<grid[i].size()-1 && grid[i][j+1]==1)
            count += islandsearch(grid, i, j+1);  
        return count;
    } 
    int maxcount = 0; 
};

int main( ) {
    Solution obj;

    vector< vector<int> > grid {
        {0,0,1,0,0,0,0,1,0,0,0,0,0},
        {0,0,0,0,0,0,0,1,1,1,0,0,0},
        {0,1,1,0,1,0,0,0,0,0,0,0,0},
        {0,1,0,0,1,1,0,0,1,0,1,0,0},
        {0,1,0,0,1,1,0,0,1,1,1,0,0},
        {0,0,0,0,0,0,0,0,0,0,1,0,0},
        {0,0,0,0,0,0,0,1,1,1,0,0,0},
        {0,0,0,0,0,0,0,1,1,0,0,0,0}
        };

    cout <<  "maxAreaOfIsland " << obj.maxAreaOfIsland(grid) <<  endl;  
    return 0;                        
}