/* ques: Find K Pairs with Smallest Sums
You are given two integer arrays nums1 and nums2 sorted in ascending order and an integer k.
Define a pair (u, v) which consists of one element from the first array and one element from the second array.
Return the k pairs (u1, v1), (u2, v2), ..., (uk, vk) with the smallest sums.

Example 1:
Input: nums1 = [1,7,11], nums2 = [2,4,6], k = 3
Output: [[1,2],[1,4],[1,6]]
Explanation: The first 3 pairs are returned from the sequence: [1,2],[1,4],[1,6],[7,2],[7,4],[11,2],[7,6],[11,4],[11,6]
*/

class Solution {
public:
    vector<vector<int>> kSmallestPairs(vector<int>& nums1, vector<int>& nums2, int k){
        vector<vector<int>>ans; //result vector to store the pairs
        priority_queue<pair<int, int>,vector<pair<int, int>>,greater<pair<int, int>>> pq;
        //priority queue to store pairs with smallest sums, sorted by the sum
        //push the initial pairs into the priority queue
        for(int x: nums1){
            pq.push({x+nums2[0],0});//the sum and the index of the second element in nums2
        }
        //pop the k smallest pairs from the priority queue
        while(k-- && !pq.empty()){
            int sum=pq.top().first; //get the smallest sum
            int pos=pq.top().second; //get the index of the second element in nums2
            ans.push_back({sum-nums2[pos],nums2[pos]});//Add the pair to the result vector
            pq.pop();//remove the pair from the priority queue
        //if there are more elements in nums2,push the next pair into the priority queue
            if(pos + 1<nums2.size()){
                pq.push({sum-nums2[pos]+nums2[pos+1],pos+1});
            }
        }
        return ans; //return the k smallest pairs
    }
};
