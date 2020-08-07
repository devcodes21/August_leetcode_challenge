/*Vertical Order Traversal of a Binary Tree

Solution
Given a binary tree, return the vertical order traversal of its nodes values.

For each node at position (X, Y), its left and right children respectively will be at positions (X-1, Y-1) and (X+1, Y-1).

Running a vertical line from X = -infinity to X = +infinity, whenever the vertical line touches some nodes, we report the values of the nodes in order from top to bottom (decreasing Y coordinates).

If two nodes have the same position, then the value of the node that is reported first is the value that is smaller.

Return an list of non-empty reports in order of X coordinate.  Every report will have a list of values of nodes.

 

Example 1:



Input: [3,9,20,null,null,15,7]
Output: [[9],[3,15],[20],[7]]
Explanation: 
Without loss of generality, we can assume the root node is at position (0, 0):
Then, the node with value 9 occurs at position (-1, -1);
The nodes with values 3 and 15 occur at positions (0, 0) and (0, -2);
The node with value 20 occurs at position (1, -1);
The node with value 7 occurs at position (2, -2).
Example 2:



Input: [1,2,3,4,5,6,7]
Output: [[4],[2],[1,5,6],[3],[7]]
Explanation: 
The node with value 5 and the node with value 6 have the same position according to the given scheme.
However, in the report "[1,5,6]", the node value of 5 comes first since 5 is smaller than 6.
 

Note:

The tree will have between 1 and 1000 nodes.
Each node's value will be between 0 and 1000.
*/


/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */

/*Approach
Used DFS here to traverse the array.
So while doing dfs we push the nodes to a vector with a data type called point
which we have made and the struct contains x (horizontal distance) y (vertical distance) 
and val which is node value;

So if we keep the root as the reference for horizontal distance then x = 0 for root
and if we move left x = x-1 and if we move right x = x+1
Similarly y = 0 for root and as we traverse down y is going to decrease anyway
so y = y-1 at each level;

Now after now we perform dfs and fill our vector..
Now we need to sort it;
For sorting we need to follow guidelines given in the question which says

1. if x(horizontal distance) for two nodes are same then check for their y and one with more y will come first

2. if y (vertical distance) for two nodes are same then check for the node values the node with less value should come first.

So this purpose can be solved with the following sorting comparator.

sort(cord.begin(),cord.end(),[](point a,point b){
                    return a.x==b.x ? a.y==b.y ? a.val<b.val : a.y>b.y: a.x<b.x;
            });

So now that cord is sorted we can push the nodes with same x value to a same row in ans;            
*/


class Solution {
public:
    struct point
    {
            int x;
            int y;
            int val;
    };
    vector<point> cord;
    void dfs(TreeNode *root,int x,int y)
    {
            cord.push_back({x,y,root->val});
            if(root->left)
                dfs(root->left,x-1,y-1);
            if(root->right)
                dfs(root->right,x+1,y-1);
    }
    vector<vector<int>> verticalTraversal(TreeNode* root) {
            vector<vector<int>> ans;
            dfs(root,0,0);
            sort(cord.begin(),cord.end(),[](point a,point b){
                    return a.x==b.x ? a.y==b.y ? a.val<b.val : a.y>b.y: a.x<b.x;
            });
            
            for(int i=0;i<cord.size();)
            {
                    vector<int> temp;
                    do
                    {
                            temp.push_back(cord[i++].val);
                    }while(i<cord.size() && cord[i-1].x==cord[i].x);
                    
                    ans.push_back(temp);
                    
            }
            
            return ans;
        
    }
};