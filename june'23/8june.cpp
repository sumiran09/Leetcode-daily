/*ques: Given a m x n matrix grid which is sorted in non-increasing order both row-wise and column-wise, return the number of negative numbers in grid.

Example 1:

Input: grid = [[4,3,2,-1],[3,2,1,-1],[1,1,-1,-2],[-1,-1,-2,-3]]
Output: 8
Explanation: There are 8 negatives number in the matrix. */

//The given matrix is sorted row-wise and column-wise in decreasing order thus we  start from the bottom-left corner

class Solution {
public:
    int countNegatives(vector<vector<int>>& grid) {
        int count=0;
        int rows=grid.size(); //rows
        int columns=grid[0].size();  //columns 
        int i=rows-1;
        int j=0;
        while(i>=0 and j<columns){
            if(grid[i][j]<0){
                count=count+(columns-j);  //incrementing count by remaining no. of columns becuase,
              // if the current number is negative, all the numbers to its right in the same row will also be negative, as the matrix is sorted.
                i--; //moving to previous row
            }
            else{
                j++;   //moving to next column
            }
        }
        return count;

    }
};
