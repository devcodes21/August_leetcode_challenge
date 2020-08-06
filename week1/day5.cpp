/*
Add and Search Word - Data structure design

Solution
Design a data structure that supports the following two operations:

void addWord(word)
bool search(word)
search(word) can search a literal word or a regular expression string containing only letters a-z or .. A . means it can represent any one letter.

Example:

addWord("bad")
addWord("dad")
addWord("mad")
search("pad") -> false
search("bad") -> true
search(".ad") -> true
search("b..") -> true
Note:
You may assume that all words are consist of lowercase letters a-z.
*/

/*Approach
So here we use a hash map where key is the string length and its value 
is a vector of strings . so when we have a word to search we first
find its length and then search in the key;
*/

auto i1 = []()
{
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        cout.tie(NULL);
        return 0;
}();
class WordDictionary {
public:
    /** Initialize your data structure here. */
    unordered_map<int,vector<string>> um1;
    
    bool check(string a,string b)
    {
            int n = a.size();
            for(int i=0;i<n;i++)
            {
                    if(a[i]=='.')
                            continue;
                    else if(a[i]!=b[i])
                            return false;
            }
            
            return true;
    }
   
    /** Adds a word into the data structure. */
    void addWord(string word) {
        int n = word.size();
        um1[n].push_back(word);    
    }
    
    /** Returns if the word is in the data structure. A word could contain the dot character '.' to represent any one letter. */
    bool search(string word) {
            int n = word.size();
            for(string s:um1[n])
            {
                    if(check(word,s))
                            return true;
            }
            
            return false;
        
    }
};

/**
 * Your WordDictionary object will be instantiated and called as such:
 * WordDictionary* obj = new WordDictionary();
 * obj->addWord(word);
 * bool param_2 = obj->search(word);
 */