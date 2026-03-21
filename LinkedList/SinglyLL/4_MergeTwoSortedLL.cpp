/*
 * Problem: 21. Merge Two Sorted Lists
 * Difficulty: Easy
 * Link: https://leetcode.com/problems/merge-two-sorted-lists/
 * 
 * Merge two sorted linked lists into one sorted linked list
 * Input: list1 = [1,2,4], list2 = [1,3,4]
 * Output: [1,1,2,3,4,4]
 * 
 * Time Complexity: O(n + m) - traverse both lists once
 * Space Complexity: O(n + m) - recursive call stack
 */

class ListNode {
public:
    int val;
    ListNode* next;
    ListNode(int x) : val(x), next(nullptr) {}
};

// Recursive Approach
// Time Complexity: O(n + m), Space Complexity: O(n + m)

/*
 * Pseudocode (Recursive Merge of Two Sorted Lists)
 * -----------------------------------------------
 *   function mergeTwoLists(l1, l2):
 *       if l1 is NULL:
 *           return l2
 *       if l2 is NULL:
 *           return l1
 *
 *       if l1.val <= l2.val:
 *           l1.next = mergeTwoLists(l1.next, l2)
 *           return l1
 *       else:
 *           l2.next = mergeTwoLists(l1, l2.next)
 *           return l2
 */

/*
 * Logic:
 * 
 * Recursively compare the heads of both lists and attach smaller node
 * 
 * Base Case:
 * - If one list is NULL, return the other list
 * 
 * Recursive Case:
 * - Compare head1->val and head2->val
 * - Attach smaller node to result
 * - Recursively merge remaining nodes
 * 
 * Steps:
 * 1. If head1 or head2 is NULL, return the non-NULL list
 * 2. Compare head1->val with head2->val
 * 3. If head1->val <= head2->val:
 *    - Attach head1 and recursively merge head1->next with head2
 * 4. Else:
 *    - Attach head2 and recursively merge head1 with head2->next
 * 5. Return the merged list head
 * 
 * Example Walkthrough:
 * list1: 1 -> 2 -> 4 -> NULL
 * list2: 1 -> 3 -> 4 -> NULL
 * 
 * Call 1: merge(1, 1) → 1<=1, attach 1, merge(2, 1)
 * Call 2: merge(2, 1) → 2>1, attach 1, merge(2, 3)
 * Call 3: merge(2, 3) → 2<=3, attach 2, merge(4, 3)
 * Call 4: merge(4, 3) → 4>3, attach 3, merge(4, 4)
 * Call 5: merge(4, 4) → 4<=4, attach 4, merge(NULL, 4)
 * Call 6: merge(NULL, 4) → return 4
 * 
 * Result: 1 -> 1 -> 2 -> 3 -> 4 -> 4 -> NULL
 */

class Solution {
public:
    ListNode* mergeTwoLists(ListNode* head1, ListNode* head2) {
        // Base case: if one list is empty, return the other
        if(head1 == nullptr || head2 == nullptr) {
            return head1 == nullptr ? head2 : head1;
        }

        // Recursive case: compare and merge
        if(head1->val <= head2->val) {
            // head1 is smaller, attach it and merge rest
            head1->next = mergeTwoLists(head1->next, head2);
            return head1;
        } 
        else {
            // head2 is smaller, attach it and merge rest
            head2->next = mergeTwoLists(head1, head2->next);
            return head2;
        }
    }
};