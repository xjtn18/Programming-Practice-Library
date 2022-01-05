package myjava;

public class LinkNode {

    int val;
    LinkNode next;

    public LinkNode(int _val) { val = _val; }

    public void print() {
        LinkNode node = this;
        System.out.printf("[%d", node.val);
        node = node.next;
        while (node != null) {
            System.out.printf(", %d", node.val);
            node = node.next;
        }
        System.out.print("]\n");
    }

    public static LinkNode buildList(String data) {
        int sIndex = 0;
        LinkNode head = new LinkNode(0);
        LinkNode curr = head;
        while (curr != null) {
            int nextComma = data.indexOf(',', sIndex);
            if (nextComma == -1) nextComma = data.length();
            curr.val = Integer.parseInt(data.substring(sIndex, nextComma));
            sIndex = nextComma + 1;
            if (sIndex < data.length()) curr.next = new LinkNode(0);
            curr = curr.next;
        }
        return head;
    }
};
