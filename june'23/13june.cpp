/* ques: Equal Row and Column Pairs
Given a 0-indexed n x n integer matrix grid, return the number of pairs (ri, cj) such that row ri and column cj are equal.

A row and column pair is considered equal if they contain the same elements in the same order (i.e., an equal array).

 Example 1:
Input: grid = [[3,2,1],[1,7,6],[2,7,7]]
Output: 1
Explanation: There is 1 equal row and column pair:
- (Row 2, Column 1): [2,7,7] */


class Solution {
public:
    int equalPairs(vector<vector<int>>& grid) {
        map<vector<int>,int> mpp; //storing each row as a key
        //storing frequency of each row as value
        int row=grid.size();
        int col=grid[0].size();
        int ans=0;
        for(vector<int> row: grid){
            mpp[row]++;
        }
        // to fetch each list of column values 
        for(int i=0;i<row;i++){
            vector<int> col_list={};
            for(int j=0;j<col;j++){
                col_list.push_back(grid[j][i]);
            }
            ans=ans+mpp[col_list];//to see if the col keys match the row keys we created
        }
        return ans;
    }
};
