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
    bool hasCycle(ListNode* head) {
        ListNode* fast=head;
        ListNode* slow=head;
        while(fast!=NULL && fast->next!=NULL){
            fast=fast->next->next;
            slow=slow->next;
        
        if(fast==slow){
            return true;
        }}
        if(fast->next!=NULL)
            return false;
        }


        
    
};
Pattern
Fast & Slow Pointers (Floyd's Cycle Detection)
Key Insight

If a cycle exists:

Slow moves 1 step
Fast moves 2 steps

Fast will eventually catch Slow inside the cycle.

Like two runners on a circular track.

Intuition
No Cycle
1 -> 2 -> 3 -> 4 -> NULL

Fast reaches:

NULL

before Slow.

Return:

false
Cycle Exists
1 -> 2 -> 3 -> 4
          ^    |
          |____|

Fast keeps gaining on Slow.

Eventually:

fast == slow

Return:

true
Brute Force Thought Process
Idea 1: Add a flag to every node
Visit node
flag++
If flag == 2 → cycle

Problem:

Cannot modify LeetCode's ListNode structure.
Idea 2: Store Visited Node Addresses

Use:

unordered_set<ListNode*>

Store addresses of visited nodes.

If current node address already exists:

Cycle found
Complexity
Time  : O(n)
Space : O(n)
Optimal Idea

Use:

slow
fast

No extra memory.

Complexity
Time  : O(n)
Space : O(1)
Algorithm

Initialize:

slow = head;
fast = head;

Loop:

while(fast != NULL && fast->next != NULL)

Move:

slow = slow->next;
fast = fast->next->next;

Check:

if(slow == fast)
    return true;

If loop ends:

return false;
Common Mistakes
1. Using || instead of &&

Wrong:

while(fast != NULL || fast->next != NULL)

Need both conditions to be true.

Correct:

while(fast != NULL && fast->next != NULL)
2. Wrong Order of Checks

Wrong:

fast->next != NULL && fast != NULL

If fast is NULL:

fast->next

crashes.

Correct:

fast != NULL && fast->next != NULL
3. Starting with
fast = head->next->next;

Can crash for:

[]
[1]
[1,2]

Safer:

fast = head;
slow = head;
4. Moving Fast Only One Step

Wrong:

fast = fast->next;

Then both pointers move at same speed.

Correct:

fast = fast->next->next;
5. Checking Before Moving

Wrong:

while(fast != slow)

because initially:

fast == slow == head

Loop never runs.

Move first, then compare.

Edge Cases
Empty List
head = NULL

Output:

false
Single Node
1 -> NULL

Output:

false
Single Node Cycle
1
↑|
|↓

Output:

true
Interview Takeaway

When you see:

Linked List + Cycle

immediately think:

Fast & Slow Pointers

This pattern is reused in:

Reverse Linked List variants
Linked List Cycle II
Find Duplicate Number
Happy Number
One-Line Summary

Move Slow by 1 step and Fast by 2 steps; if they ever meet, a cycle exists, otherwise Fast reaches NULL and no cycle exists.
