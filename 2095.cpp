public class Solution {
    public ListNode deleteMiddle(ListNode head) {
        // Edge case: if there is only one node, delete it.
        if (head == null || head.next == null) {
            return null;
        }
        
        // Initialize slow and fast pointers, and a previous pointer
        ListNode slow = head;
        ListNode fast = head;
        ListNode prev = null;
        
        // Traverse the list with slow and fast pointers
        while (fast != null && fast.next != null) {
            fast = fast.next.next;  // Move fast pointer by 2 steps
            prev = slow;            // Move prev to slow
            slow = slow.next;       // Move slow pointer by 1 step
        }
        
        // Delete the middle node (which is slow)
        prev.next = slow.next;
        
        return head;
    }
}
Input
head =
[1,3,4,7,1,2,6]
Output
[1,3,4,1,2,6]
Expected
[1,3,4,1,2,6]
