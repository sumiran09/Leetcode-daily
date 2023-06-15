/* ques: Maximum Level Sum of a Binary Tree
Given the root of a binary tree, the level of its root is 1, the level of its children is 2, and so on.
Return the smallest level x such that the sum of all the values of nodes at level x is maximal.
Input: root = [1,7,0,7,-8,null,null]
Output: 2
Explanation: 
Level 1 sum = 1.
Level 2 sum = 7 + 0 = 7.
Level 3 sum = 7 + -8 = -1.
So we return the level with the maximum sum which is level 2.  */

class Solution {
public:
    int maxLevelSum(TreeNode* root) {
        int lsf=INT_MIN;
        int ans=0;
        int level=0;
        queue<TreeNode*>q;
        q.push(root);
        while(!q.empty()){
            level++;
            int currlevelsum=0;
            for(int i=q.size();i>0;i--){
                TreeNode* node=q.front();
                q.pop();
                currlevelsum=currlevelsum+ node->val;
                if(node->left!=nullptr)q.push(node->left);
                if(node->right!=nullptr)q.push(node->right);
            }
            if(lsf<currlevelsum){
                lsf=currlevelsum;
                ans=level;
            }
        }
        return ans;
    }
};
 
