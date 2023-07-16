public class LeetCode21 {
    public ListNode mergeTwoLists(ListNode list1, ListNode list2) {
        ListNode head = new ListNode();
        int i = 0, j = 0;
        while (list1.next != null){
            if(list1.val < list2.val){
                head.val = list1.val;
            } else {
                head.val = list2.val;
            }
            list1 = list1.next;
            list2 = list2.next;
        }
        return head;
    }
}
