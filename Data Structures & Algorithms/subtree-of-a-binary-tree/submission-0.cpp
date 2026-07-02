/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */

class Solution {
public:
bool isSameTree(TreeNode* p, TreeNode* q) {
        if(p==NULL && q==NULL)
            return true;
        if(p==NULL || q==NULL)
            return false;
        if(p->val != q->val)
            return false;
        return (isSameTree(p->left,q->left)&&isSameTree(p->right,q->right));
        
    }
    bool isSubtree(TreeNode* root, TreeNode* subRoot) {
        if(root==NULL)
            return false;
        if(subRoot==NULL)
            return true;
        return (isSameTree(root,subRoot)||isSubtree(root->left,subRoot)||isSubtree(root->right,subRoot));
        
    }
};
Pattern
DFS Search + Same Tree.
Approach
At every node:
Check if current subtree equals subRoot.
Otherwise search left.
Otherwise search right.
Key Point
Uses two recursive functions:
isSame() → compares trees.
isSubtree() → searches the main tree.
Time
O(m × n)
Space
O(h) (recursion stack)
Common Mistakes
Comparing only root values.
Calling isSubtree(root, subRoot) again (infinite recursion).
Calling isSame(root->left, subRoot) instead of isSame(root, subRoot).
Using && instead of ||.
