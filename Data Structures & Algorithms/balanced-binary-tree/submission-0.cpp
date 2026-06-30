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

    int dfs(TreeNode* root) {

        if (root == NULL)
            return 0;

        int left = dfs(root->left);
        int right = dfs(root->right);

        if (left == -1 || right == -1)
            return -1;

        if (abs(left - right) > 1)
            return -1;

        return 1 + max(left, right);
    }

    bool isBalanced(TreeNode* root) {
        return dfs(root) >= 0;
    }
};
# Balanced Binary Tree - Quick Notes

## Core Observation

* A node is balanced if:

  ```cpp
  abs(leftHeight - rightHeight) <= 1
  ```
* Condition must hold for **every node**, not just the root.

## Why Recursion?

* Parent needs information from children.
* For each node, we need:

  * Height of left subtree
  * Height of right subtree
* If parent can be solved using children's answers → recursion is a strong candidate.

## Naive Approach

* Compute:

  ```cpp
  leftHeight = height(root->left);
  rightHeight = height(root->right);
  ```
* Check current node balance.
* Recursively check left and right subtrees.
* Problem: Heights are recomputed many times.
* Complexity: **O(n²)** worst case.

## Optimized Idea

* Merge:

  * Height calculation
  * Balance checking
* Use a single DFS function.

## Meaning of dfs(node)

* Returns:

  * Height of subtree if balanced.
  * `-1` if subtree is unbalanced.

## Base Case

```cpp
if(root == NULL)
    return 0;
```

* Empty tree:

  * Height = 0
  * Balanced = true

## Recursive Calls

```cpp
int left = dfs(root->left);
int right = dfs(root->right);
```

## Cases

### Child Already Unbalanced

```cpp
if(left == -1 || right == -1)
    return -1;
```

### Current Node Unbalanced

```cpp
if(abs(left - right) > 1)
    return -1;
```

### Current Node Balanced

```cpp
return 1 + max(left, right);
```

## Final Check

```cpp
return dfs(root) != -1;
```

## Important Recursion Insight

* Execution goes:

  ```text
  Root → Leaf
  ```
* Information returns:

  ```text
  Leaf → Root
  ```
* Traversal is top-down.
* Computation is bottom-up.

## Recursion Design Checklist

1. What does my function represent?
2. What should it return?
3. What is the base case?
4. Can parent be solved using children's answers?

## Pattern Used Here

```text
Child returns:
    Height

Parent uses:
    Left Height
    Right Height

Parent returns:
    Height or Failure Signal (-1)
```

## Complexity

Time: (n)
Space: O(h) (recursion stack)




