/* ques: Find Smallest Letter Greater Than Target
You are given an array of characters letters that is sorted in non-decreasing order, and a character target. There are at least two different characters in letters.
Return the smallest character in letters that is lexicographically greater than target. If such a character does not exist, return the first character in letters.

Example 1:
Input: letters = ["c","f","j"], target = "a"
Output: "c"
Explanation: The smallest character that is lexicographically greater than 'a' in letters is 'c'. */

class Solution {
public:
    char nextGreatestLetter(vector<char>& letters, char target) {
        int s=0;
        int n=letters.size();
        int e=n-1;
        while(s<=e){
            int mid=s+(e-s)/2;
            if(letters[mid]<=target)s=mid+1; //searching in right half of the array 
            // if mid<target  then all values <mid would alse be <than target 
            else{
                e=mid-1; //searching in left half 
            }
        }
        if(s==n){
            return letters[0];
        }
        else{
            return letters[s];
        }
    }
};
