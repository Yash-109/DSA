/*
 * Problem: 876. Middle of the Linked List
 * Difficulty: Easy
 * Link: https://leetcode.com/problems/middle-of-the-linked-list/
 * 
 * Find the middle node of a linked list
 * Input: 1 -> 2 -> 3 -> 4 -> 5 -> NULL
 * Output: 3 -> 4 -> 5 -> NULL (return middle node)
 * 
 * If there are two middle nodes, return the second middle node
 * Input: 1 -> 2 -> 3 -> 4 -> 5 -> 6 -> NULL
 * Output: 4 -> 5 -> 6 -> NULL
 * 
 * Time Complexity: O(n) - traverse list once
 * Space Complexity: O(1) - only using 2 pointers
 */

class ListNode {
public:
    int val;
    ListNode* next;
    ListNode(int x) : val(x), next(nullptr) {}
};

// Slow-Fast Pointer Approach (Tortoise and Hare Algorithm)
// Time Complexity: O(n), Space Complexity: O(1)

/*
 * Logic:
 * 
 * We use 2 pointers: slow and fast
 * 
 * Initial State:
 * slow = head (moves 1 step at a time)
 * fast = head (moves 2 steps at a time)
 * 
 * Key Idea:
 * When fast pointer reaches the end, slow pointer will be at middle
 * - fast moves 2x speed of slow
 * - By the time fast reaches end, slow is at halfway point
 * 
 * Example Walkthrough (Odd Length):
 * Original: 1 -> 2 -> 3 -> 4 -> 5 -> NULL
 * 
 * Iteration 1:
 *   slow=1, fast=1
 *   After move: slow=2, fast=3
 *   
 * Iteration 2:
 *   slow=2, fast=3
 *   After move: slow=3, fast=5
 *   
 * Iteration 3:
 *   slow=3, fast=5
 *   fast->next = NULL, loop ends
 *   Return slow (node 3) ✓
 * 
 * Example Walkthrough (Even Length):
 * Original: 1 -> 2 -> 3 -> 4 -> 5 -> 6 -> NULL
 * 
 * Iteration 1: slow=2, fast=3
 * Iteration 2: slow=3, fast=5
 * Iteration 3: slow=4, fast=NULL
 * Return slow (node 4) - second middle ✓
 */

class Solution {
public:
    ListNode* middleNode(ListNode* head) {
        // Initialize two pointers both starting at head
        ListNode* slow = head;  // Slow pointer: moves 1 step at a time
        ListNode* fast = head;  // Fast pointer: moves 2 steps at a time

        // Move fast pointer 2 steps and slow pointer 1 step
        // Loop continues until fast reaches end
        while(fast != nullptr && fast->next != nullptr) {  // first condition for even size and second consdtition for odd sized LL
            slow = slow->next;       // Move slow by 1 step
            fast = fast->next->next; // Move fast by 2 steps
        }

        // When fast reaches end, slow is at middle
        return slow;
    }
};