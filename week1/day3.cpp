/*
Valid Palindrome

Solution
Given a string, determine if it is a palindrome, considering only alphanumeric characters and ignoring cases.

Note: For the purpose of this problem, we define empty string as valid palindrome.

Example 1:

Input: "A man, a plan, a canal: Panama"
Output: true
Example 2:

Input: "race a car"
Output: false
 

Constraints:

s consists only of printable ASCII characters.
*/

//Use !isalnum() to skip through non alphanumeric chars and then check
class Solution {
public:
    bool isPalindrome(string s) {
            int n = s.length();
            int j = n-1;
            int i = 0;
            while(i<=j)
            {
            while(i<j && !isalnum(s[i]))
                    i++;
            while(i<j && !isalnum(s[j]))
                    j--;
            if(tolower(s[i])==tolower(s[j]))
            {
                    i++;
                    j--;
            }
            
            else
                return false;
            }
          return true;
        
    }
};