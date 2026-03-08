
#include <cstddef>  // for NULL

// Definition for singly-linked list (LeetCode format)
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};
/*
 * Problem: 141. Linked List Cycle
 * Difficulty: Easy
 * Link: https://leetcode.com/problems/linked-list-cycle/
 * 
 * Detect if a linked list has a cycle (loop) in it
 * A cycle exists if a node can be reached again by continuously following next pointers
 * 
 * Example with cycle:
 * Input: head = [3,2,0,-4], pos = 1 (tail connects to node at index 1)
 * Visual:
 *     3 -> 2 -> 0 -> -4
 *          ↑_____________|
 *          (cycle: -4 points back to 2)
 * Output: true (there is a cycle)
 * 
 * Example without cycle:
 * Input: head = [1,2,3,4]
 * Visual:
 *     1 -> 2 -> 3 -> 4 -> NULL
 * Output: false (no cycle)
 * 
 * Time Complexity: O(n) - traverse list once
 * Space Complexity: O(1) - only using 2 pointers
 */

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */

// Floyd's Cycle Detection Algorithm (Tortoise and Hare Algorithm)
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
 * If there's a cycle, fast and slow will eventually meet inside the cycle
 * If there's no cycle, fast will reach NULL
 * 
 * Why they meet if cycle exists?
 * - Once both pointers enter the cycle, fast approaches slow by 1 position per iteration
 * - Eventually the gap becomes 0 and they meet
 * 
 * Example Walkthrough (with cycle):
 * List with cycle:
 *     1 -> 2 -> 3 -> 4
 *          ↑___________|
 *          (4 points back to 2)
 * 
 * Iteration 1: slow=1, fast=1 → slow=2, fast=3
 * Iteration 2: slow=2, fast=3 → slow=3, fast=2
 * Iteration 3: slow=3, fast=2 → slow=4, fast=4
 * slow == fast → cycle detected! ✓
 */

class Solution {
public:
    bool hasCycle(ListNode *head) { 
        // Initialize two pointers both starting at head
        ListNode* slow = head;  // Slow pointer: moves 1 step at a time
        ListNode* fast = head;  // Fast pointer: moves 2 steps at a time

        // Move fast pointer 2 steps and slow pointer 1 step
        while(fast != NULL && fast->next != NULL) {
            slow = slow->next;       // Move slow by 1 step
            fast = fast->next->next; // Move fast by 2 steps

            // If slow and fast meet, cycle exists
            if(slow == fast) {
                return true;
            }
        }

        // If fast reaches NULL, no cycle exists
        return false;
    }
};


/*
 * Problem: 142. Linked List Cycle II
 * Difficulty: Medium
 * Link: https://leetcode.com/problems/linked-list-cycle-ii/
 * 
 * Find the starting node of the cycle in a linked list
 * If no cycle exists, return NULL
 * 
 * Example with cycle:
 * Input: head = [3,2,0,-4], pos = 1 (tail connects to node at index 1)
 * Visual:
 *     3 -> 2 -> 0 -> -4
 *          ↑_____________|
 *          (cycle starts at node 2)
 * Output: node with value 2 (cycle start)
 * 
 * Example without cycle:
 * Input: head = [1,2]
 * Visual:
 *     1 -> 2 -> NULL
 * Output: NULL (no cycle)
 * 
 * Time Complexity: O(n) - traverse list at most twice
 * Space Complexity: O(1) - only using 2 pointers
 */

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */

// Floyd's Cycle Detection + Starting Node Algorithm
// Time Complexity: O(n), Space Complexity: O(1)

/*
 * Logic:
 * 
 * Step 1: Detect if cycle exists (same as Problem 141)
 * - Use slow and fast pointers
 * - If they meet, cycle exists
 * 
 * Step 2: Find starting node of cycle
 * - After detecting cycle, reset slow to head
 * - Move both slow and fast by 1 step at a time
 * - When they meet again, that's the starting node
 * 
 * Why does this work?
 * Mathematical proof:
 * Let:
 *   L = distance from head to cycle start
 *   C = cycle length
 *   K = distance from cycle start to meeting point
 * 
 * When they meet:
 *   - Slow traveled: L + K
 *   - Fast traveled: L + K + nC (where n is number of complete cycles)
 *   - Since fast is 2x slow: 2(L + K) = L + K + nC
 *   - Simplifying: L + K = nC → L = nC - K
 * 
 * This means: distance from head to cycle start = distance from meeting point to cycle start
 * 
 * Example Walkthrough:
 * List with cycle:
 *     1 -> 2 -> 3 -> 4 -> 5
 *               ↑___________|
 *               (5 points back to 3, cycle starts at node 3)
 * 
 * Phase 1: Detect Cycle
 * - slow and fast meet somewhere in cycle (e.g., at node 4)
 * 
 * Phase 2: Find Start
 * - Reset slow to head (node 1)
 * - Both move 1 step at a time
 * - slow: 1 -> 2 -> 3
 * - fast: 4 -> 5 -> 3
 * - They meet at node 3 (cycle start) ✓
 */

class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        // Phase 1: Detect if cycle exists using Floyd's algorithm
        ListNode* slow = head;  // Slow pointer: moves 1 step at a time
        ListNode* fast = head;  // Fast pointer: moves 2 steps at a time
        bool isCycle = false;   // Flag to track if cycle exists

        // Move pointers until they meet or fast reaches end
        while(fast != NULL && fast->next != NULL) {
            slow = slow->next;       // Move slow by 1 step
            fast = fast->next->next; // Move fast by 2 steps

            // If pointers meet, cycle detected
            if(slow == fast) {
                isCycle = true;
                break;  // Exit to start phase 2
            }
        }

        // If no cycle found, return NULL
        if(!isCycle) {
            return NULL;
        }

        // Phase 2: Find the starting node of cycle
        // Reset slow to head, keep fast at meeting point
        slow = head;
        
        // Move both pointers 1 step at a time
        while(slow != fast) {
            slow = slow->next;  // Move slow by 1 step
            fast = fast->next;  // Move fast by 1 step (not 2!)
        }

        // When they meet, that's the cycle start node
        return slow;  // or return fast (both point to same node)
    }
};



/*
 * Problem: Remove Cycle from Linked List
 * Difficulty: Medium
 * 
 * Remove the cycle from a linked list if it exists
 * After removal, the last node should point to NULL
 * 
 * Example:
 * Input: head = [3,2,0,-4], pos = 1 (tail connects to node at index 1)
 * Before removal:
 *     3 -> 2 -> 0 -> -4
 *          ↑_____________|
 *          (cycle exists)
 * 
 * After removal:
 *     3 -> 2 -> 0 -> -4 -> NULL
 *          (cycle removed, now points to NULL)
 * 
 * Output: head = [3,2,0,-4] with no cycle
 * 
 * Time Complexity: O(n) - traverse list at most twice
 * Space Complexity: O(1) - only using 2 pointers
 */

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */

// Floyd's Cycle Detection + Remove Cycle Algorithm
// Time Complexity: O(n), Space Complexity: O(1)

/*
 * Logic:
 * 
 * Step 1: Detect if cycle exists (same as Problem 141)
 * - Use slow and fast pointers
 * - If they meet, cycle exists
 * 
 * Step 2: Find the node just before cycle start
 * - Reset slow to head
 * - Use prev pointer to track node before fast
 * - Move slow and fast by 1 step each until they meet
 * - prev will be the node whose next points to cycle start
 * 
 * Step 3: Remove cycle
 * - Set prev->next = NULL
 * 
 * Example Walkthrough:
 * List with cycle:
 *     1 -> 2 -> 3 -> 4 -> 5
 *               ↑___________|
 *               (5 points back to 3, cycle starts at node 3)
 * 
 * Phase 1: Detect Cycle
 * - slow and fast meet (cycle detected)
 * 
 * Phase 2: Find node before cycle start
 * - Reset slow to head (node 1)
 * - Move both 1 step, tracking prev:
 *   slow=1, fast=3, prev=5
 *   slow=2, fast=4, prev=3
 *   slow=3, fast=5, prev=4
 *   slow=3, fast=3 → they meet!
 * - prev is at node 5 (last node in cycle)
 * 
 * Phase 3: Remove cycle
 * - Set prev->next = NULL (node 5 now points to NULL)
 * 
 * After removal:
 *     1 -> 2 -> 3 -> 4 -> 5 -> NULL ✓
 */

class Solution {
public:
    void removeCycle(ListNode *head) {
        // Phase 1: Detect if cycle exists using Floyd's algorithm
        ListNode* slow = head;  // Slow pointer: moves 1 step at a time
        ListNode* fast = head;  // Fast pointer: moves 2 steps at a time
        bool isCycle = false;   // Flag to track if cycle exists

        // Move pointers until they meet or fast reaches end
        while(fast != NULL && fast->next != NULL) {
            slow = slow->next;       // Move slow by 1 step
            fast = fast->next->next; // Move fast by 2 steps

            // If pointers meet, cycle detected
            if(slow == fast) {
                isCycle = true;
                break;  // Exit to start phase 2
            }
        }

        // If no cycle found, return without modification
        if(!isCycle) {
            return;
        }

        // Phase 2: Find the node just before cycle start
        // Reset slow to head, keep fast at meeting point
        slow = head;
        ListNode* prev = NULL;  // Track node before fast pointer
        
        // Move both pointers 1 step at a time
        while(slow != fast) {
            slow = slow->next;  // Move slow by 1 step
            prev = fast;        // Store current fast position
            fast = fast->next;  // Move fast by 1 step (not 2!)
        }

        // Phase 3: Remove the cycle
        // prev points to the last node in cycle
        prev->next = NULL;  // Break the cycle by setting last node's next to NULL
    }
};
