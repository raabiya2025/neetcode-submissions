/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */

class Solution {
public:
    ListNode* reverseList(ListNode* head) {
       ListNode* prev=NULL;
       ListNode* curr=head;
       ListNode* next;
       while(curr!=NULL){
        next=curr->next;
        curr->next=prev;
        prev=curr;
        curr=next;
       }
       return prev;

        

        
    }
};

Reverse Linked List
Pattern
Linked List + Pointer Manipulation

Key Observation
We are not reversing values.
We are reversing the next pointers.

Before:
0 -> 1 -> 2 -> 3 -> 4 -> NULL

After:
4 -> 3 -> 2 -> 1 -> 0 -> NULL

Why Not Swap Values?
Example:
1 -> 2 -> 3 -> 4 -> 5
no swap first and last:

Easy to reach last node.
Cannot move backward from last node.

Because:
Singly Linked List
has only:
node->next

No:

node->prev

    
Optimal Approach
Use 3 pointers:
prev
curr
next

Pointer Meaning
prev

Already reversed portion.

2 -> 1 -> 0 -> NULL

curr
Current node being processed.

3

next
Stores remaining list.

4 -> 5 -> NULL

Prevents losing the list after reversing a pointer.

algorithm
Step 1
Save next node.

next = curr->next;

Step 2
Reverse pointer.

curr->next = prev;

This is the most important line.

Step 3
Move pointers forward.

prev = curr;
curr = next;

Meaning:
Current node becomes part of reversed list.
Move to next node.


Common Mistakes
1. Forgetting next

Wrong:

curr->next = prev;
curr = curr->next;

You lose the rest of the list.

Always save:

next = curr->next;first.

2. Returning head

Wrong:

return head;

At the end:

head = original first node

Correct:

return prev;

because prev becomes the new head.

3. Reversing Values Instead of Pointers

Interviewers expect:

Pointer reversal

not swapping node values.


    Complexity
Time O(n)

Each node visited once.

Space
O(1)

Only 3 pointers used.

Interview Takeaway

The entire solution revolves around:

curr->next = prev;

Everything else (prev, curr, next) exists only to safely move through the list while reversing links.

Similar Problems
Reverse Linked List II
Reorder List
Palindrome Linked List
Reverse Nodes in K Group
Swap Nodes in Pairs
One-Line Summary

Maintain prev, curr, and next; 
reverse the current node's pointer using curr->next = prev, 
then advance all pointers until the list is fully reversed.
