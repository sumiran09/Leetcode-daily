/* ques: Check If It Is a Straight Line
You are given an array coordinates, 
coordinates[i] = [x, y], where [x, y] represents the coordinate of a point. 
Check if these points make a straight line in the XY plane. */

class Solution {
public:
    bool checkStraightLine(vector<vector<int>>& coordinates) {
        // first two set of coordinates 
        int x1=coordinates[0][0];
        int y1=coordinates[0][1];
        int x2=coordinates[1][0];
        int y2=coordinates[1][1];
        for(int i=2;i<coordinates.size();i++){
            int x=coordinates[i][0];
            int y=coordinates[i][1];
            if((x-x1)*(y-y2)!=(x-x2)*(y-y1)){
                return false;
            }
        }
        return true;
    }
};
