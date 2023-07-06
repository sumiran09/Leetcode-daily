/*
Minimum Size Subarray Sum
Given an array of positive integers nums and a positive integer target, return the minimal length of a 
subarray whose sum is greater than or equal to target. If there is no such subarray, return 0 instead.

Example 1:
Input: target = 7, nums = [2,3,1,2,4,3]
Output: 2
Explanation: The subarray [4,3] has the minimal length under the problem constraint.
*/
//approach: sliding window
class Solution {
public:
    //sliding window
    int minSubArrayLen(int target, vector<int>& nums) {
        int left=0;int right=0; int sumofcurrwindow=0;
        int ans=INT_MAX;
        for(int right=0;right<nums.size();right++){
            sumofcurrwindow+=nums[right];
            while(sumofcurrwindow >= target){
                ans=min(ans,right-left+1);
                sumofcurrwindow-=nums[left];  //to remove the first element from the current window
                left++;
            }
        }
        if(ans==INT_MAX)return 0;
        else return ans;

    }
};
