public class Solution {
    public ListNode mergeTwoLists(ListNode l1, ListNode l2) {
        // Create a dummy node to simplify the merge logic
        ListNode dummy = new ListNode(0);
        ListNode current = dummy;
        
        // Traverse both lists and merge them in sorted order
        while (l1 != null && l2 != null) {
            if (l1.val <= l2.val) {
                current.next = l1;
                l1 = l1.next;
            } else {
                current.next = l2;
                l2 = l2.next;
            }
            current = current.next;
        }
        
        // If there are remaining nodes in either list, append them
        if (l1 != null) {
            current.next = l1;
        } else if (l2 != null) {
            current.next = l2;
        }
        
        // Return the merged list, which starts after the dummy node
        return dummy.next;
    }
}
Input
list1 =
[1,2,4]
list2 =
[1,3,4]
Output
[1,1,2,3,4,4]
Expected
[1,1,2,3,4,4]
