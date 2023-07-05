/*
Single Number II
Given an integer array nums where every element appears three times except for one, which appears exactly once. Find the single element and return it.

You must implement a solution with a linear runtime complexity and use only constant extra space.
(however this is a brute force approach, for linear space we'd have to use bit manipulation or xor
Example 1:
Input: nums = [2,2,3,2]
Output: 3
 */
class Solution {
public:
    int singleNumber(vector<int>& nums) {
        //brute:
        unordered_map<int, int> mpp;
        
        for(auto n: nums){
            mpp[n]++;
        }

        for(auto x: mpp){
            if(x.second == 1){
                return x.first;
            }
        }
        return -1;
    }
};
