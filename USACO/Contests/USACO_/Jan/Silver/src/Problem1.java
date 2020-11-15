import java.util.*;
import java.io.*;

public class Problem1 {
	static ArrayList<Integer> perm;
	static ArrayList<Integer> berries = new ArrayList<Integer>();
	public static void main(String[] args) throws Exception{
		//"D:\\CalebArulandu\\USACO\\Jan\\Silver\\src\\berries.in"
	    Scanner s = new Scanner(new File("berries.in"));
	    PrintWriter write = new PrintWriter(new FileWriter(new File("berries.out")));
	    String[] first = s.nextLine().trim().split(" ");
	    int N = Integer.parseInt(first[0]);
	    int K = Integer.parseInt(first[1]);
	    int sum = 0;
	    for(String berry : s.nextLine().trim().split(" ")){
	    	berries.add(Integer.parseInt(berry));
			sum += Integer.parseInt(berry);
		}

	    Collections.sort(berries, Collections.reverseOrder());
	    perm = (ArrayList<Integer>) berries.clone();

	    int count = 0;
	    int amt = 0;
	    int min = berries.get(berries.size() - 1);
	    // Get better lower bound
		outer:
	    for (int i = Math.min((sum * 2) / K, 1000); i > min; i--){
	    	for(int j = 0; j < K/2; j++) {
				Collections.sort(berries, Collections.reverseOrder());
				if(i <= berries.get(0)){
					berries.set(0, berries.get(0) - i);
				} else {
					berries = (ArrayList<Integer>) perm.clone();
					continue outer;
				}
			}
	    	// Check max that can be made
			amt = findMax(K / 2, i);
	    	if(amt > count){
	    		count = amt;
			}
		}
	    write.println(count);
	    write.close();
    }

    public static int findMax(int baskets, int upper){
    	int sum = 0;
    	for (int i = 0; i < baskets; i++){
			Collections.sort(berries, Collections.reverseOrder());
    		if(berries.get(0) <= upper){
    			sum += berries.get(0);
    			berries.set(0, 0);
			} else {
    			sum += upper;
    			berries.set(0, berries.get(0) - upper);
			}
		}
    	berries = (ArrayList<Integer>) perm.clone();
    	return sum;
	}
}
