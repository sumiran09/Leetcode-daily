/* ques: You are given three positive integers: n, index, and maxSum. You want to construct an array nums (0-indexed) that satisfies the following conditions:

*nums.length == n
*nums[i] is a positive integer where 0 <= i < n.
*abs(nums[i] - nums[i+1]) <= 1 where 0 <= i < n-1.
*The sum of all the elements of nums does not exceed maxSum.
*nums[index] is maximized.
*Return nums[index] of the constructed array.
Note that abs(x) equals x if x >= 0, and -x otherwise.

Example 1:

Input: n = 4, index = 2,  maxSum = 6
Output: 2
Explanation: nums = [1,2,2,1] is one array that satisfies all the conditions.
There are no arrays that satisfy all the conditions and have nums[2] == 3, so 2 is the maximum nums[2]. */


class Solution {
public:
 //to maximize nums[index] while ensuring the sum the array does not exceed maxSum
        //thus we use greedy
        //to maximize nums[index] all other values should be as small as possible  
        /* other constraints to be kept in mind :
           ~ The difference between adjacent numbers cannot be greater than 1.
           ~ nums[i] must be positive.  */

        // numbers left to nums[index] should decrease until they reach 1 
        // numbers right to nums[index] should decrease until they reach 1
    long calc(long n){
            return (n*(n+1))/2;
        }
    long getsum(int totallen,int val){
        long totalsum=0;
        int declen=val; //count of [val,val-1,val-2,...1,1,1,1]
        if(totallen>=declen){
            long currsum=calc(val);
            int remsum=totallen-declen;  //all 1's
            totalsum=currsum+remsum;

        }
        else{ //[val,val-1,val-2]
            long lastval=declen-totallen;
            totalsum=calc(val)-calc(lastval);
        }
        return totalsum;
    }
        
    int maxValue(int n, int index, int maxSum) {
       int s=1; int e= maxSum;
       int lc=index; int rc=n-index-1;
       int ans=-1;
       while(s<=e){
           int mid=s+(e-s)/2;
           long leftsum=getsum(lc,mid-1);
           long rightsum=getsum(rc,mid-1);
           long totalsum=leftsum + mid + rightsum;
           if(totalsum>maxSum){
              e=mid-1;
           }
           else{
               ans=mid;
               s=mid+1;
            }
        }
        return ans;
        
    }
};
