public class Solution {
    public ListNode reverseBetween(ListNode head, int m, int n) {
        // Edge case: If head is null or m equals n (no need to reverse)
        if (head == null || m == n) {
            return head;
        }

        // Create a dummy node to simplify edge cases like reversing from the head
        ListNode dummy = new ListNode(0);
        dummy.next = head;
        
        // Step 1: Move `preHead` to the node just before the m-th node
        ListNode preHead = dummy;
        for (int i = 1; i < m; i++) {
            preHead = preHead.next;
        }
        
        // Step 2: Start reversing the sublist from m-th to n-th node
        ListNode start = preHead.next;  // m-th node
        ListNode then = start.next;     // (m+1)-th node
        
        for (int i = 0; i < n - m; i++) {
            start.next = then.next;
            then.next = preHead.next;
            preHead.next = then;
            then = start.next;
        }
        
        // Return the modified list, starting from dummy.next
        return dummy.next;
    }
}
nput
head =
[1,2,3,4,5]
left =
2
right =
4
Output
[1,4,3,2,5]
Expected
[1,4,3,2,5]
