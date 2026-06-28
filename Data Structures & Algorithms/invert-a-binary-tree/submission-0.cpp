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
    TreeNode* invertTree(TreeNode* root) {
        TreeNode* temp;
        if(root==NULL){
            return NULL;
        }
        temp=root->left;
        root->left=root->right;
        root->right=temp;
        invertTree(root->left);
        invertTree(root->right);
       
        return root;
    }
};
Invert Binary Tree (LeetCode 226)
Pattern
DFS
Recursion
Tree Traversal
Key Insight

At every node:

swap(root->left, root->right);

Then recursively invert:

invertTree(root->left);
invertTree(root->right);
Tree Pointer Concepts
root->left
Stores address of left child node.
root->right
Stores address of right child node.
root->left->val
Access value of left child node.
Important

Nodes do not move in memory.

Only the child pointers are swapped.

Recursive Structure
if(root == NULL)
    return NULL;

swap(root->left, root->right);

invertTree(root->left);
invertTree(root->right);

return root;
Base Case
if(root == NULL)
    return NULL;

Stops recursion when a subtree is empty.

Time Complexity
O(n)
Every node visited exactly once.
Space Complexity
O(h)

where h = height of tree.

Balanced Tree: O(log n)
Skewed Tree: O(n)
Common Mistakes
1. Infinite Recursion

Wrong:

return invertTree(root);

Reason:

Function is called again on the same node.
No progress towards base case.
2. Returning After First Recursive Call

Wrong:

return invertTree(root->left);
return invertTree(root->right);

Reason:

First return exits function.
Right subtree never processed.
3. Forgetting Base Case

Wrong:

swap(root->left, root->right);

without checking:

root == NULL

Can cause null pointer access.

4. Thinking Recursion Doesn't Return
invertTree(root->left);
invertTree(root->right);
Left subtree is processed completely.
Control returns to current node.
Right subtree is then processed.
Interview Takeaways
Trees are pointer-based data structures.
left and right store addresses of child nodes.
Invert current node → recurse on children.
Order of left/right recursion does not matter.
