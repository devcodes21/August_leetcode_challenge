/*
Find All Duplicates in an Array

Solution
Given an array of integers, 1 ≤ a[i] ≤ n (n = size of array), some elements appear twice and others appear once.

Find all the elements that appear twice in this array.

Could you do it without extra space and in O(n) runtime?

Example:
Input:
[4,3,2,7,8,2,3,1]

Output:
[2,3]
*/

/*
Approach:
So we do this in place so that sc is O(1);
we treat elements as array indices as elements are from 1 to n
at each iteration we go to abs(element-1) index and make it negative(this will be our marker)
So in this way the elements are present twice then (element-1)  index will be finally positive.
And the element which occurs just once will be then (element-1) index will be finally negative
So we just have to chose the indices where elements will be finally negative
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
    vector<int> findDuplicates(vector<int>& nums) {
            vector<int> ans;
            int n = nums.size();
            for(auto x:nums)
            {
                    if(nums[abs(x)-1]>0)
                            nums[abs(x)-1] *= -1;
                    else if(nums[abs(x)-1]<0)
                            ans.push_back(abs(x));
            }
            
            return ans;
        
    }
};

/*
[4,3,2,7,8,2,3,1]

[4,3,2,7,8,2,3,1]
*/