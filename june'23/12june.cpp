/* ques: Summary Ranges
You are given a sorted unique integer array nums.
A range [a,b] is the set of all integers from a to b (inclusive).
Return the smallest sorted list of ranges that cover all the numbers in the array exactly. 
That is, each element of nums is covered by exactly one of the ranges, and there is no integer x such that x is in one of the ranges but not in nums.
Each range [a,b] in the list should be output as:

"a->b" if a != b
"a" if a == b
 
Example 1:

Input: nums = [0,1,2,4,5,7]
Output: ["0->2","4->5","7"]
Explanation: The ranges are:
[0,2] --> "0->2"
[4,5] --> "4->5"
[7,7] --> "7"    */

class Solution {
public:
    vector<string> summaryRanges(vector<int>& nums) {
        vector<string> ranges;
        int n=nums.size();
        for(int i=0;i<n;i++){
            int s=nums[i]; //To start, save the current range's beginning in start = nums[i].
            while(i+1<n and nums[i]+1==nums[i+1]){
                i++;
                //c heck whether the next element in nums at index i + 1 differs from nums[i] by 1 or more. If the next element differs by 1, 
              //we increase i by 1 to include the (i+1)th element in this range and move ahead to check the next element. 
            }
            if(s!=nums[i]){ //if start != nums[i], we add the string start->nums[i] to ranges.
                ranges.push_back(to_string(s)+ "->"  +to_string(nums[i]));
            }
            else{ //Otherwise, if the next element differs by more than 1 or we have covered all the elements in nums, we check whether start is equal to nums[i] or not
                ranges.push_back(to_string(s)); //If start == nums[i], we only add start as a string to ranges as we just have a single element in this range
            }
        }
        return ranges;

    }
};
