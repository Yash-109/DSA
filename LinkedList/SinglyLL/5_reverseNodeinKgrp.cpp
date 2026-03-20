// Definition for a singly-linked list node (LeetCode format)
// Each node has a value and a pointer to the next node
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

/*
 * Problem: 25. Reverse Nodes in k-Group
 * Difficulty: Hard
 * Link: https://leetcode.com/problems/reverse-nodes-in-k-group/
 *
 * You are given the head of a singly linked list and an integer k.
 * Reverse the nodes of the list k at a time, and return the modified list.
 * If the number of nodes is not a multiple of k, leave the last nodes as-is.
 *
 * Constraints:
 *   - The list is singly-linked
 *   - 1 <= k <= length of the list
 *
 * Approach Used Here: Recursive k-group reversal
 * ------------------------------------------------
 * Step 1 (Check length):
 *   - Traverse k nodes to ensure that a full group exists.
 *   - If fewer than k nodes remain, return head (no change for this segment).
 *
 * Step 2 (Recurse on remaining list):
 *   - Recursively call reverseKGroup starting from the (k+1)-th node.
 *   - This returns the head of the already processed remainder of the list.
 *
 * Step 3 (Reverse current k-group):
 *   - Reverse the first k nodes so that their next pointers point to
 *     the head returned from Step 2.
 *   - The last node of this reversed group will now correctly connect
 *     to the recursively processed remainder.
 *
 * Time Complexity : O(n)   - each node is visited a constant number of times
 * Space Complexity: O(n/k) - recursion depth (worst-case O(n) if k = 1)
 */

class Solution {
public:
    ListNode* reverseKGroup(ListNode* head, int k) {
        // Edge case: empty list or single node (no change)
        if (head == nullptr || k <= 1) {
            return head;
        }

        ListNode* temp = head;
        int cnt = 0;

        // Step 1: check if there are at least k nodes remaining
        while (cnt < k) {
            if (temp == nullptr) {
                // Less than k nodes left: do not reverse this segment
                return head;
            }
            temp = temp->next;
            cnt++;
        }

        // Step 2: recursively process the rest of the list starting from temp
        ListNode* prevNode = reverseKGroup(temp, k);

        // Step 3: reverse the current group of k nodes
        temp = head;
        cnt = 0;

        while (cnt < k) {
            ListNode* next = temp->next;  // store next node
            temp->next = prevNode;        // point current node to already processed part

            prevNode = temp;              // move prevNode one step forward
            temp = next;                  // move temp to next node in original list

            cnt++;
        }

        // prevNode is the new head of this reversed k-group
        return prevNode;
    }
};