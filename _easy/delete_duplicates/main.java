
class main {

	public static ListNode deleteDuplicates(ListNode head) {
		ListNode current = head;
		while (current != null && current.next != null){
			if (current.next.val == current.val){
				current.next = current.next.next;
			} else {
				current = current.next;
			}
		}
		return head;
	}
	

	public static <T> void log(T s){
		System.out.println(s);
	}


	public static void llog(ListNode head){
		if (head == null){
			System.out.println(":empty:");
			return;
		}
		while (head.next != null){
			System.out.print(head.val + " -> ");
			head = head.next;
		}
		System.out.print(head.val + "\n");
	}


	public static ListNode createLL(int[] arrvals){
		if (arrvals.length == 0){
			return null;
		}
		ListNode head = new ListNode(arrvals[0],null);
		ListNode tmp = head;
		for (int i = 1; i < arrvals.length; ++i){
			tmp.next = new ListNode(arrvals[i],null);
			tmp = tmp.next;
		}
		return head;
	}


	public static void main(String[] args){
		llog(deleteDuplicates(createLL(new int[]{1,2,2,3})));
		llog(deleteDuplicates(createLL(new int[]{1,2,2,2,3,3,4,5,5,6,7})));
		llog(deleteDuplicates(createLL(new int[]{})));
	}
}


