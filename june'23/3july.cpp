/* 
Buddy Strings
Given two strings s and goal, return true if you can swap two letters in s so the result is equal to goal, otherwise, return false.
Swapping letters is defined as taking two indices i and j (0-indexed) such that i != j and swapping the characters at s[i] and s[j].
For example, swapping at indices 0 and 2 in "abcd" results in "cbad".

Example 1:
Input: s = "ab", goal = "ba"
Output: true
Explanation: You can swap s[0] = 'a' and s[1] = 'b' to get "ba", which is equal to goal.
*/
class Solution {
public:
    bool buddyStrings(string s, string goal) {
        if(s.length()!=goal.length()) return false;
        if(s==goal){
            vector<int>hm(26,0);
            for(auto ch: s) {
                hm[ch - 'a']++;
                if(hm[ch - 'a'] == 2){ //can only swap those 2 same char if any char has a freq >  1
                    return true;
                }
            }
            return false;
        }
        int first_i=-1,second_i=-1;
        for(int i=0;i<s.length();i++){
            if(s[i]!=goal[i]){
                if(first_i==-1) first_i=i;
                else if(second_i==-1) second_i=i;
                else return false; //not possible in one swap 
            }
        }
        if(second_i==-1) return false; //if only first index was updated
        return s[first_i]==goal[second_i] and s[second_i]==goal[first_i];
        
    }
};
