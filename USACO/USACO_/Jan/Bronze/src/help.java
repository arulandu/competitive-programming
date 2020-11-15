import java.util.*;

public class help {
    public static void main(String[] args) {
        Queue<Integer> qq = new LinkedList<Integer>();

        qq.add(1);
        qq.add(2);
        qq.add(3);
        qq.add(4);

        System.out.println(qq.toString());
        mirrorHalves(qq);
        System.out.println(qq.toString());
    }

    public static void mirrorHalves(Queue<Integer> q) {
        Stack<Integer> s1 = new Stack<Integer>();
        Stack<Integer> s2 = new Stack<Integer>();
        int size = q.size();
        int o;
        for (int i = 0; i < size; i++) {
            s1.push(q.remove());
        }
        s2 = (Stack<Integer>) s1.clone();
        // Reverse 1/2 in stack
        for (int i = 0; i < size / 2; i++) {
            q.add(s2.pop());
        }
        for (int i = 0; i < size / 2; i++) {
            s2.push(q.remove());
        }
        //Moving in half
        for (int i = 0; i < size / 2; i++) {
            q.add(s2.pop());
        }
        for (int i = 0; i < size / 2; i++) {
            q.add(s1.pop());
        }


        // 2nd half
        // Reverse 1/2 in stack
        for (int i = 0; i < size / 2; i++) {
            q.add(s2.pop());
        }
        for (int i = 0; i < size; i++) {
            q.add(q.remove());
        }

        for (int i = 0; i < size / 2; i++) {
            s2.push(q.remove());
        }
        //Moving in half
        for (int i = 0; i < size / 2; i++) {
            q.add(s2.pop());
        }
        for (int i = 0; i < size / 2; i++) {
            q.add(s1.pop());
        }


        s1.clear();
        while (!q.isEmpty()) {
            s1.push(q.remove());
        }
        while (!s1.isEmpty()) {
            q.add(s1.pop());
        }



    }
}
