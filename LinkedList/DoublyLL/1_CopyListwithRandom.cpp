// Definition for a Node (LeetCode format)
// Each node has a value, a next pointer, and a random pointer
class Node {
public:
    int val;
    Node* next;
    Node* random;

    Node(int _val) {
        val = _val;
        next = nullptr;
        random = nullptr;
    }
};

/*
 * Problem: 138. Copy List with Random Pointer
 * Difficulty: Medium
 * Link: https://leetcode.com/problems/copy-list-with-random-pointer/
 * 
 * You are given the head of a linked list where each node has:
 *   - next  : pointer to the next node
 *   - random: pointer to any node in the list (or NULL)
 * 
 * Task: Create a deep copy of the list
 * - Deep copy means: create completely new nodes
 * - Next and random pointers of the new list should mimic the original list
 * - Return the head of the copied list
 * 
 * Example:
 * Input (visual):
 *   Node 1: val = 7,  next -> 13, random -> NULL
 *   Node 2: val = 13, next -> 11, random -> 7
 *   Node 3: val = 11, next -> 10, random -> 5
 *   Node 4: val = 10, next -> 1,  random -> 11
 *   Node 5: val = 1,  next -> NULL, random -> 7
 * 
 * Output:
 *   A completely new list with same structure of next and random pointers
 * 
 * Approach Used Here: HashMap / Unordered Map
 * ------------------------------------------------
 * Step 1:
 *   - Traverse the original list
 *   - For each original node, create a new node (copy) with same value
 *   - Build a mapping: original node -> copied node
 *   - Also connect the next pointers for the copied list
 * 
 * Step 2:
 *   - Traverse again from head using the stored mapping
 *   - For each original node, set:
 *       copiedNode->random = mapping[originalNode->random]
 *   - This assigns correct random pointers in the copied list
 * 
 * Time Complexity : O(n)   - we traverse the list twice
 * Space Complexity: O(n)   - extra hashmap to store mapping
 */

/*
 * Pseudocode (HashMap-Based Deep Copy)
 * ------------------------------------
 *   function copyRandomList(head):
 *       if head == NULL:
 *           return NULL
 *
 *       mapping = empty hashmap from Node* -> Node*
 *
 *       // step 1: copy nodes and next pointers
 *       newHead = new Node(head.val)
 *       mapping[head] = newHead
 *
 *       oldTemp = head.next
 *       newTemp = newHead
 *
 *       while oldTemp != NULL:
 *           copyNode = new Node(oldTemp.val)
 *           mapping[oldTemp] = copyNode
 *           newTemp.next = copyNode
 *           oldTemp = oldTemp.next
 *           newTemp = newTemp.next
 *
 *       // step 2: assign random pointers
 *       oldTemp = head
 *       newTemp = newHead
 *       while oldTemp != NULL:
 *           newTemp.random = mapping[oldTemp.random]
 *           oldTemp = oldTemp.next
 *           newTemp = newTemp.next
 *
 *       return newHead
 */

#include <unordered_map>
using namespace std;

class Solution {
public:
    Node* copyRandomList(Node* head) {
        // Base case: if list is empty, nothing to copy
        if(head == nullptr){
            return nullptr;
        }

        // Map to store relation: original node -> copied node
        // Key  : pointer to original node
        // Value: pointer to its corresponding copied node
        unordered_map<Node*, Node*> mapping;

        // Step 1: Create copy of first node and initialize new list
        Node* newHead = new Node(head->val);  // copy of head

        // Store mapping for first node (original -> copy)
        // Required so random pointers (including self-random) can be assigned later
        mapping[head] = newHead;

        // oldTemp: used to traverse the original list (starting from 2nd node)
        // newTemp: used to build the copied list
        Node* oldTemp = head->next;
        Node* newTemp = newHead;

        // Step 2: Copy remaining nodes and build next pointers
        while(oldTemp != nullptr){
            // Create a new node (copy) with same value as oldTemp
            Node* copyNode = new Node(oldTemp->val);

            // Store mapping of current original node to its copy
            mapping[oldTemp] = copyNode;

            // Connect previous copied node to current copied node
            newTemp->next = copyNode;

            // Move both pointers one step forward
            oldTemp = oldTemp->next;
            newTemp = newTemp->next;
        }

        // Step 3: Assign random pointers using the stored mapping
        oldTemp = head;
        newTemp = newHead;

        while(oldTemp != nullptr){
            // For current original node oldTemp, its copy is newTemp
            // oldTemp->random points to some node R in original list (or NULL)
            // mapping[oldTemp->random] gives:
            //   - copy of R if R is not NULL
            //   - default nullptr if oldTemp->random is NULL
            newTemp->random = mapping[oldTemp->random];

            // Move to next pair of nodes
            oldTemp = oldTemp->next;
            newTemp = newTemp->next;
        }

        // Return head of deep copied list
        return newHead;
    }
};