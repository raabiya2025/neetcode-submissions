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
};
Pattern
Tree DFS (Recursion)
Compare two trees simultaneously.
Approach
Compare current nodes.
If both NULL → same.
If one NULL → different.
If values differ → different.
Recursively compare left AND right subtrees.
Key Point
Use && because both subtrees must match.
Time
O(n)
Space
O(h) (recursion stack)
Common Mistakes
Forgetting NULL base cases.
Accessing node->val before checking NULL.
Using || instead of &&.
