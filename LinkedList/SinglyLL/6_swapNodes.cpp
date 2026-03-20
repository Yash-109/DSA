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
 * Problem: 24. Swap Nodes in Pairs
 * Difficulty: Medium
 * Link: https://leetcode.com/problems/swap-nodes-in-pairs/
 *
 * You are given the head of a singly linked list. You need to
 * swap every two adjacent nodes and return its head.
 *
 * Example:
 *   Input : 1 -> 2 -> 3 -> 4
 *   Output: 2 -> 1 -> 4 -> 3
 *
 * Note:
 *   - The values in the nodes must NOT be modified, only the
 *     node pointers can be changed.
 *
 * Approach Used Here: Iterative pointer manipulation
 * --------------------------------------------------
 * Step 1 (Handle small lists):
 *   - If the list is empty or has only one node, return head directly.
 *
 * Step 2 (Iteratively swap pairs):
 *   - Use three main pointers:
 *       first: points to the first node in the current pair
 *       sec  : points to the second node in the current pair
 *       prev : points to the last node of the previously swapped pair
 *   - For each pair [first, sec]:
 *       1) Save `third = sec->next` (start of the next pair).
 *       2) Reverse the link between first and sec:
 *            sec->next = first;
 *            first->next = third;
 *       3) Connect the previous pair's tail (prev) to sec. If prev is
 *          null, it means we're at the first pair, so update head to sec.
 *       4) Move prev to first (which is now the tail of the current pair)
 *          and advance first and sec to the next pair.
 *
 * Time Complexity : O(n) - each node is visited a constant number of times
 * Space Complexity: O(1) - in-place swapping using a fixed number of pointers
 */

class Solution {
public:
    ListNode* swapPairs(ListNode* head) {
        // Base case: 0 or 1 node, nothing to swap
        if (head == nullptr || head->next == nullptr) {
            return head;
        }

        ListNode* first = head;
        ListNode* sec = head->next;
        ListNode* prev = nullptr;

        // Process the list in pairs
        while (first != nullptr && sec != nullptr) {
            // third is the start of the next pair
            ListNode* third = sec->next;

            // Swap first and sec
            sec->next = first;
            first->next = third;

            // Connect previous pair to the current swapped pair
            if (prev != nullptr) {
                prev->next = sec;
            } else {
                // For the very first pair, update head
                head = sec;
            }

            // Update pointers for next iteration
            prev = first;
            first = third;

            if (third != nullptr) {
                sec = third->next;
            } else {
                sec = nullptr;
            }
        }

        return head;
    }
};