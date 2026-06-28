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
    int maxDepth(TreeNode* root) {
        if(root==NULL){
            return NULL;
        }
       return 1+max(maxDepth(root->left),maxDepth(root->right));
    }
};
Maximum Depth of Binary Tree (LeetCode 104)
Pattern
DFS
Recursion
Divide and Conquer
Key Insight

For every node:

depth = 1 + max(leftDepth, rightDepth)
1 → current node
leftDepth → depth of left subtree
rightDepth → depth of right subtree
Recursive Structure
if(root == NULL)
    return 0;

return 1 + max(maxDepth(root->left),
               maxDepth(root->right));
Base Case
if(root == NULL)
    return 0;
Empty tree has depth 0.
Why DFS Works
Find depth of left subtree.
Find depth of right subtree.
Take the larger depth.
Add current node.
Time Complexity
O(n)
Every node visited exactly once.
Space Complexity
O(h)

where h = height of tree.

Balanced Tree → O(log n)
Skewed Tree → O(n)
Common Mistakes
1. Returning 1 for NULL

Wrong:

if(root == NULL)
    return 1;

Reason:

Empty tree depth is 0.

    
2. Using Min Instead of Max
Wrong:

1 + min(leftDepth, rightDepth)

Reason:
We need the longest root-to-leaf path.

3. Forgetting Current Node
Wrong:

return max(leftDepth, rightDepth);

Reason:
Must count current node.
Correct:

return 1 + max(leftDepth, rightDepth);

4. Confusing Height and Number of Edges
In this problem:
Depth = Number of nodes
not number of edges.

Interview Takeaways
Classic DFS recursion problem.
Parent answer depends on children answers.
Think: "Get answer from left, get answer from right, combine."
One-Line Summary

Maximum depth of a tree = 1 + max(depth of left subtree, depth of right subtree).
