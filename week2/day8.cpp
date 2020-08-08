/*
 Path Sum III

Solution
You are given a binary tree in which each node contains an integer value.

Find the number of paths that sum to a given value.

The path does not need to start or end at the root or a leaf, but it must go downwards (traveling only from parent nodes to child nodes).

The tree has no more than 1,000 nodes and the values are in the range -1,000,000 to 1,000,000.

Example:

root = [10,5,-3,3,2,null,11,3,-2,null,1], sum = 8

      10
     /  \
    5   -3
   / \    \
  3   2   11
 / \   \
3  -2   1

Return 3. The paths that sum to 8 are:

1.  5 -> 3
2.  5 -> 2 -> 1
3. -3 -> 11
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

/*
Approach:
Used simple dfs here
as given in the question path need not start from root or end on the leaf
we can have any nodes involved in the path.
So for each node we run dfs starting with the root and whenever we get the required sum we increment count.
*/
auto i1 = []()
{
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        cout.tie(NULL);
        return 0;
}();
class Solution {
    void dfs(TreeNode* root,int sum,int& count,int curr)
    {
            if(root)
            {
                    curr+= root->val;
                    if(curr==sum)
                    {
                            count++;
                    }
                    
                    dfs(root->left,sum,count,curr);
                    dfs(root->right,sum,count,curr);
            }
    }
    void helper(TreeNode* root,int sum,int& count)
    {
            if(root)
            {
                    dfs(root,sum,count,0);
                    helper(root->left,sum,count);
                    helper(root->right,sum,count);
            }
    }
public:
    int pathSum(TreeNode* root, int sum) {
            if(!root)
                    return 0;
            int count = 0;
            helper(root,sum,count);
            return count;
        
    }
};