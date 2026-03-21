// Definition for a Node (LeetCode format)
// Each node is part of a doubly linked list and may have a child pointer
class Node {
public:
    int val;
    Node* prev;
    Node* next;
    Node* child;

    Node(int _val) {
        val = _val;
        prev = nullptr;
        next = nullptr;
        child = nullptr;
    }
};

/*
 * Problem: 430. Flatten a Multilevel Doubly Linked List
 * Difficulty: Medium
 * Link: https://leetcode.com/problems/flatten-a-multilevel-doubly-linked-list/
 *
 * You are given the head of a multilevel doubly linked list. Each node has:
 *   - prev  : pointer to previous node
 *   - next  : pointer to next node
 *   - child : pointer to a child doubly linked list (or nullptr)
 *
 * Task: Flatten the list so that all nodes appear in a single-level doubly
 * linked list using depth-first order. The child pointers should be set to
 * nullptr in the final list.
 *
 * Approach Used Here: Recursive DFS flattening in-place
 * -----------------------------------------------------
 * Overall idea:
 *   - Traverse the list from head using a pointer `curr`.
 *   - Whenever a node with a non-null child is found:
 *       1) Save `curr->next` (the original next node).
 *       2) Recursively flatten the child list and attach it as `curr->next`.
 *       3) Fix the `prev` pointer of the flattened child head to point to `curr`.
 *       4) Nullify `curr->child` because it is now merged.
 *       5) Move `curr` to the end (tail) of this newly attached child list.
 *       6) Reattach the saved `next` to the end of the flattened child list,
 *          updating both `next` and `prev` pointers.
 *   - Continue traversal until the end of the list.
 *
 * Time Complexity : O(n)   - each node is visited a constant number of times
 * Space Complexity: O(d)   - recursion depth where d is the maximum depth
 *                            of the multilevel list
 */

/*
 * Pseudocode (Recursive DFS Flatten)
 * ---------------------------------
 *   function flatten(head):
 *       if head == NULL:
 *           return head
 *
 *       curr = head
 *
 *       while curr != NULL:
 *           if curr.child == NULL:
 *               curr = curr.next
 *               continue
 *
 *           // save original next
 *           nextNode = curr.next
 *
 *           // step 1: flatten child and attach
 *           childHead = flatten(curr.child)
 *           curr.next = childHead
 *           childHead.prev = curr
 *           curr.child = NULL
 *
 *           // step 2: move to tail of child list
 *           tail = curr
 *           while tail.next != NULL:
 *               tail = tail.next
 *
 *           // step 3: reattach saved next
 *           if nextNode != NULL:
 *               tail.next = nextNode
 *               nextNode.prev = tail
 *
 *           curr = nextNode
 *
 *       return head
 */

class Solution {
public:
    Node* flatten(Node* head) {
        // Base case: empty list
        if (head == nullptr) {
            return head;
        }

        Node* curr = head;

        // Iterate through the list
        while (curr != nullptr) {
            // When a child is present, we need to merge the child sublist
            if (curr->child != nullptr) {
                // Store original next pointer
                Node* next = curr->next;

                // Step 1: flatten the child list and attach it after curr
                curr->next = flatten(curr->child);
                curr->next->prev = curr;

                // Child is now merged, so remove the child pointer
                curr->child = nullptr;

                // Step 2: move curr to the tail of the newly attached child list
                while (curr->next != nullptr) {
                    curr = curr->next;
                }

                // Step 3: reattach the originally stored next node (if any)
                if (next != nullptr) {
                    curr->next = next;
                    next->prev = curr;
                }
            }

            // Move forward in the (now partially flattened) list
            curr = curr->next;
        }

        return head;
    }
};