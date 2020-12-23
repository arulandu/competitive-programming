import java.util.*;
import java.io.*;

public class Problem1 {
	public static int N;
	public static int M;
	public static int K;

	public static void main(String[] args) throws Exception {
		//"D:\\CalebArulandu\\USACO\\February\\Silver\\src\\swap.in"
		Scanner s = new Scanner(new File("swap.in"));
		PrintWriter write = new PrintWriter(new FileWriter(new File("swap.out")));
		String[] first = s.nextLine().trim().split(" ");
		N = Integer.parseInt(first[0]); // number of cows
		M = Integer.parseInt(first[1]); // number of steps
		K = Integer.parseInt(first[2]); // number of passes(run-throughs)

		ListNode<Integer> list = new ListNode<Integer>(1, null, null);
		ListNode<Integer> previous = list;
		ListNode<Integer> current = null;
		// Create DLL
		for (int i = 2; i <= N; i++) {
			current = new ListNode<Integer>(i, null, previous);
			previous.next = current;
			previous = current;
		}
		current.next = null;
		ArrayList<int[]> pairs = new ArrayList<int[]>();
		for(int i = 0; i < M; i++){
			String[] parts = s.nextLine().trim().split(" ");
			pairs.add(new int[]{Integer.parseInt(parts[0]), Integer.parseInt(parts[1])});
		}

		for(int k = 1; k <= K; k++){
			for(int[] pair : pairs){
				reverse(list, pair[0], pair[1]);
			}
		}

		ListNode<Integer> N = list;
		while(N != null){
			write.println(N.value);
			N = N.next;
		}

		write.close();
	}

	public static void reverse(ListNode<Integer> node, int a, int b){
		ListNode<Integer> A = getPointer(node, a);
		ListNode<Integer> B = getPointer(node, b);

		ListNode<Integer> PREV = A.previous;
		ListNode<Integer> PrevPrev = null;
		if(PREV != null){
			PrevPrev = PREV.previous;
		}
		ListNode<Integer> P = A.previous;
		ListNode<Integer> C = A;
		ListNode<Integer> N = C.next;
		for(int i = a; i <= b; i++){
			if(C != null) {
				C.next = P;
				C.previous = N;
			}
			if(P != null) {
				P.previous = C;
			}

			P = C;
			C = N;
			if(N != null) {
				N = N.next;
			}
		}

		if(C != null){
			C.previous = A;
		}
		if(PREV != null) {
			PREV.next = B;
			PREV.previous = PrevPrev;
		}
		B.previous = node;
		A.next = C;

	}
	public static ListNode<Integer> getPointer(ListNode<Integer> node, int a){
		ListNode<Integer> fin = node;
		for(int i = 1; i < a; i++){
			fin = fin.next;
		}
		return fin;
	}
}

class ListNode<E>{
	public ListNode<E> next;
	public ListNode<E> previous;
	public E value;

	public ListNode(){
		next=null;
		value=null;
	}
	public ListNode(E o,ListNode<E> next, ListNode<E> previous){
		value=o;
		this.next=next;
		this.previous = previous;
	}

}