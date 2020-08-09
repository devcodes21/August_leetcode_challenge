/*
Rotting Oranges

Solution
In a given grid, each cell can have one of three values:

the value 0 representing an empty cell;
the value 1 representing a fresh orange;
the value 2 representing a rotten orange.
Every minute, any fresh orange that is adjacent (4-directionally) to a rotten orange becomes rotten.

Return the minimum number of minutes that must elapse until no cell has a fresh orange.  If this is impossible, return -1 instead.
Example 1:
Input: [[2,1,1],[1,1,0],[0,1,1]]
Output: 4
Example 2:

Input: [[2,1,1],[0,1,1],[1,0,1]]
Output: -1
Explanation:  The orange in the bottom left corner (row 2, column 0) is never rotten, because rotting only happens 4-directionally.
Example 3:

Input: [[0,2]]
Output: 0
Explanation:  Since there are already no fresh oranges at minute 0, the answer is just 0.
 

Note:

1 <= grid.length <= 10
1 <= grid[0].length <= 10
grid[i][j] is only 0, 1, or 2.
*/

/*
The approach is to use BFS algo. I have used a queue and defined a datatype for that as pair<int,pair<int,int>> which will store timeframe and i and j index of each rotten orange.

So we push all the rotten oranges to the queue and then we apply bfs till the queue gets empty.

Now after this we check if there is any orange which is still not rotten that is we check for 1 in a grid. If we find a 1 then we cannot rot all the oranges so we return -1;
else we return the count.
*/

auto i1 = []()
{
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        cout.tie(NULL);
        return 0;
}();
class Solution {
        typedef pair<int,pair<int,int>> pp1; 
        
public:
    int orangesRotting(vector<vector<int>>& grid) {
            queue<pp1> q;
            int n = grid.size();
            int m = grid[0].size();
            int count = 0;
            for(int i=0;i<n;i++)
            {
                    for(int j=0;j<m;j++)
                    {
                            if(grid[i][j]==2)
                                    q.push({0,{i,j}});
                    }
            }
            
            while(!q.empty())
            {
                    pp1 temp = q.front();
                    count = temp.first;
                    int x = temp.second.first;
                    int y = temp.second.second;
                    //cout<<x<<endl;
                    //cout<<y<<endl;
                    
                    if(x+1<n)
                    {
                            if(grid[x+1][y]==1)
                            {
                                    grid[x+1][y] = 2;
                                    q.push({count+1,{x+1,y}});
                            }
                    }
                    
                    if(x-1>=0)
                    {
                            if(grid[x-1][y]==1)
                            {
                                    grid[x-1][y]=2;
                                    q.push({count+1,{x-1,y}});
                            }
                    }
                    
                    if(y+1<m)
                    {
                            if(grid[x][y+1]==1)
                            {        
                                    grid[x][y+1] = 2;
                                    q.push({count+1,{x,y+1}});
                            }
                            
                    }
                    
                    if(y-1>=0)
                    {
                            if(grid[x][y-1]==1)
                            {
                                    grid[x][y-1] = 2;
                                    q.push({count+1,{x,y-1}});
                            }
                    }
                    
                    q.pop();
            }
            
            for(int i=0;i<n;i++)
            {
                    for(int j=0;j<m;j++)
                    {
                            if(grid[i][j]==1)
                                    return -1;
                    }
            }
            
            return count;
        
    }
};