/*
 * Problem: 206. Reverse Linked List
 * Difficulty: Easy
 * Link: https://leetcode.com/problems/reverse-linked-list/
 * 
 * Reverse a singly linked list
 * Input: 1 -> 2 -> 3 -> 4 -> 5 -> NULL
 * Output: 5 -> 4 -> 3 -> 2 -> 1 -> NULL
 * 
 * Time Complexity: O(n) - traverse all nodes once
 * Space Complexity: O(1) - only using 3 pointers
 */

/*
 * Pseudocode (Iterative 3-Pointer Reversal)
 * ----------------------------------------
 *   function reverseList(head):
 *       prev = NULL
 *       curr = head
 *
 *       while curr != NULL:
 *           nextNode = curr.next      // store next
 *           curr.next = prev         // reverse link
 *           prev = curr              // move prev forward
 *           curr = nextNode          // move curr forward
 *
 *       return prev   // new head of reversed list
 */

class ListNode {
public:
    int val;
    ListNode* next;
    ListNode(int x) : val(x), next(nullptr) {}
};

// Iterative Approach - Using 3 Pointers
// Time Complexity: O(n), Space Complexity: O(1)

/*
 * Logic:
 * 
 * We use 3 pointers: prevNode, currNode, nextNode
 * 
 * Initial State:
 * prevNode = NULL (no previous node initially)
 * currNode = head (start from first node)
 * nextNode = NULL (temporary storage for next node)
 * 
 * Steps:
 * 1. Store next node: nextNode = currNode->next (save reference before breaking link)
 * 2. Reverse the link: currNode->next = prevNode (point current node backwards)
 * 3. Move prevNode forward: prevNode = currNode
 * 4. Move currNode forward: currNode = nextNode
 * 5. Repeat until currNode becomes NULL
 * 
 * Example Walkthrough:
 * Original: 1 -> 2 -> 3 -> NULL
 * 
 * Iteration 1:
 *   prevNode=NULL, currNode=1, nextNode=2
 *   After reversal: NULL <- 1    2 -> 3 -> NULL
 *   
 * Iteration 2:
 *   prevNode=1, currNode=2, nextNode=3
 *   After reversal: NULL <- 1 <- 2    3 -> NULL
 *   
 * Iteration 3:
 *   prevNode=2, currNode=3, nextNode=NULL
 *   After reversal: NULL <- 1 <- 2 <- 3
 *   
 * Final: prevNode points to new head (3)
 */

class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        // Initialize three pointers for reversal
        ListNode* prevNode = nullptr;  // Previous node (initially NULL)
        ListNode* currNode = head;     // Current node (start from head)
        ListNode* nextNode = nullptr;  // Next node (temporary storage)

        // Traverse and reverse each link
        while(currNode != nullptr) {
            nextNode = currNode->next;  // Step 1: Save next node before changing link
            currNode->next = prevNode;  // Step 2: Reverse the link (point backwards)

            // Step 3 & 4: Move pointers forward
            prevNode = currNode;        // Move prevNode to current position
            currNode = nextNode;        // Move currNode to next position
        }

        // When loop ends, currNode is NULL and prevNode is at new head
        return prevNode;
    }
};