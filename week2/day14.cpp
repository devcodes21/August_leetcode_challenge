/*
Longest Palindrome

Solution
Given a string which consists of lowercase or uppercase letters, find the length of the longest palindromes that can be built with those letters.

This is case sensitive, for example "Aa" is not considered a palindrome here.

Note:
Assume the length of given string will not exceed 1,010.

Example:

Input:
"abccccdd"

Output:
7

Explanation:
One longest palindrome that can be built is "dccaccd", whose length is 7.
*/
class Solution {
public:
    int longestPalindrome(string s) {
            unordered_map<char,int> um1;
            for(auto it:s)
            {
                    um1[it]++;
            }
            int len = 0;
            for(auto x:um1)
            {
                 if(x.second%2==0)
                 {
                         len += x.second;
                 }
                    
                 else
                 {
                         len += x.second - 1;
                 }
            }
            
            if(len<s.size())
            {
                    len += 1;
            }
            
            return len;
            
        
    }
};