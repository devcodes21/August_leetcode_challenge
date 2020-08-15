/*
Non-overlapping Intervals

Solution
Given a collection of intervals, find the minimum number of intervals you need to remove to make the rest of the intervals non-overlapping.

 

Example 1:

Input: [[1,2],[2,3],[3,4],[1,3]]
Output: 1
Explanation: [1,3] can be removed and the rest of intervals are non-overlapping.
Example 2:

Input: [[1,2],[1,2],[1,2]]
Output: 2
Explanation: You need to remove two [1,2] to make the rest of intervals non-overlapping.
Example 3:

Input: [[1,2],[2,3]]
Output: 0
Explanation: You don't need to remove any of the intervals since they're alre
*/

 bool comp(vector<int>& a,vector<int>& b)
    {
            return a[1]<b[1];
    }
class Solution {
   
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
            int n = intervals.size();
            if(n==0)
                    return 0;
            int ans = -1;
            sort(intervals.begin(),intervals.end(),comp);
            vector<int> temp = intervals[0];
            for(auto i: intervals)
            {
                    if(temp[1]>i[0])
                            ans++;
                    else
                            temp = i;
            }
            
            return ans;
            
            
            
            
        
    }
};



/*
Input: [[1,2],[2,3],[3,4],[1,3]]

[1,2] [2,3] [1,3] [3,4]
*/