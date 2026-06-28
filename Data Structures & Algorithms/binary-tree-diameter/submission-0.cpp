class Solution {
public:
    int maxDiameter = 0;
    int getHeight(TreeNode* root) {
        if(root == NULL){
            return 0;
        }
        
        int leftH = getHeight(root->left);
        int rightH = getHeight(root->right);
        
        maxDiameter = max(maxDiameter, leftH + rightH);
        return 1 + max(leftH, rightH);
    }

    int diameterOfBinaryTree(TreeNode* root) {
        getHeight(root);
        return maxDiameter;
    }
};