/*
 Power of Four

Solution
Given an integer (signed 32 bits), write a function to check whether it is a power of 4.

Example 1:

Input: 16
Output: true
Example 2:

Input: 5
Output: false
Follow up: Could you solve it without loops/recursion?
*/
auto i1 = []()
{
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        cout.tie(NULL);
        return 0;
}();
class Solution {
    float logn(int n,int p)
    {
            return log(n)/log(p);
    }
public:
    bool isPowerOfFour(int num) {
            if (num==0)
                    return false;
            return (floor(logn(num,4))==ceil(logn(num,4)));
        
    }
};