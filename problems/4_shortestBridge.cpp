#include <iostream> 
#include <vector>
using namespace std;

class Solution {
public:
    int shortestBridge(vector<vector<int>>& A) {
        int dist;
        int i, j; 
        for(i=0; i< A.size(); i++)
        for (j=0; j<A[i].size(); j++) {
            if (A[i][j]==1) {
                dist=finddist(A, i, j); 
                if (shortest>dist)
                    shortest = dist;
            }
        }
        return shortest; 
    }
private: 
    int finddist(vector<vector<int>>& A, int i, int j) {
        
    }
    int shortest = 200;
};

int main( ) {
    Solution obj;

    vector< vector<int> > grid1 {
        {0,1},
        {1,0}
        };

    vector< vector<int> > grid2 {
        {0,1,0},
        {0,0,0},
        {0,0,1}
        };
    vector< vector<int> > grid3 {
        {1,1,1,1,1},
        {1,0,0,0,1},
        {1,0,1,0,1},
        {1,0,0,0,1},        
        {1,1,1,1,1}
        };        

    cout <<  "shortestBridge " << obj.shortestBridge(grid1) <<  endl;  
    return 0;                        
}