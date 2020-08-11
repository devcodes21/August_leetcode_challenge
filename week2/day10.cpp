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

auto i1 = []()
{
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        cout.tie(NULL);
        return 0;
} ();
class Solution {
public:
    int titleToNumber(string s) {
            int i = 0;
            int colNo = 0;
            while(i<s.size())
            {
               colNo = colNo*26 + (s.at(i)-'A'+1);
               i++;      
            }
            return colNo;
        
    }
};
/*
A - 1
B - 2
...        
Z - 26
AA - 27
AB - 28
..
AZ - 52
..
BA - 53
BB - 54
..
BZ - 78
..
CA - 79
CB - 80
..
CZ - 104        
*/