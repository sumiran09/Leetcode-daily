/*ques: Number of Ways to Reorder Array to Get Same BST
Given an array nums that represents a permutation of integers from 1 to n. We are going to construct a binary search tree (BST) by inserting
the elements of nums in order into an initially empty BST. 
Find the number of different ways to reorder nums so that the constructed BST is identical to that formed from the original array nums.

For example, given nums = [2,1,3], we will have 2 as the root, 1 as a left child, and 3 as a right child.
The array [2,3,1] also yields the same BST but [3,2,1] yields a different BST.
Return the number of ways to reorder nums such that the BST formed is identical to the original BST formed from nums.

Since the answer may be very large, return it modulo 109 + 7.
Example 1:
Input: nums = [2,1,3]
Output: 1
Explanation: We can reorder nums to be [2,3,1] which will yield the same BST. There are no other ways to reorder nums which will yield the same BST.
*/

class Solution {
public:
    int numOfWays(vector<int>& nums) {
        int m=nums.size();
        table.resize(m+1);
        for(int i=0;i<m+1;i++){
            table[i]=vector<long long> (i+1,1);
            for(int j = 1; j < i; ++j){
                table[i][j] = (table[i - 1][j - 1] + table[i - 1][j]) % mod;
            }
        }
        return (dfs(nums)-1)%mod;
    }
private:
    vector<vector<long long>>table;
    long long mod=1e9 + 7;
    long long dfs(vector<int>& nums){
        int m=nums.size();
        if(m<3)return 1;
        vector<int> leftnodes,rightnodes;
        for(int i=1;i<m;i++){
            if(nums[i]<nums[0])leftnodes.push_back(nums[i]);
            else{
                rightnodes.push_back(nums[i]);
            }
        }
        long long leftways = dfs(leftnodes) % mod;
        long long rightways = dfs(rightnodes) % mod;
        return (((leftways * rightways) % mod) * table[m - 1][leftnodes.size()]) % mod;
    }

};
