/*
Longest Subarray of 1's After Deleting One Element
Given a binary array nums, you should delete one element from it.
Return the size of the longest non-empty subarray containing only 1's in the resulting array. Return 0 if there is no such subarray.

Example 1:
Input: nums = [1,1,0,1]
Output: 3
Explanation: After deleting the number in position 2, [1,1,1] contains 3 numbers with value of 1's.
*/
// approach: sliding window 
class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        int zero_count=0;
        int longest_window=0;
        int start=0;
        for(int i=0;i<nums.size();i++){
            if(nums[i]==0)zero_count++;
            while(zero_count>1){
                if(nums[start]==0)zero_count--;
                start++;
            }
            longest_window=max(longest_window,i-start);
        }
        return longest_window;
    }
};
