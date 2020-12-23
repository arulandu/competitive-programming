import java.util.*;
import java.io.*;

/*
 * Algorithm:
 * Read in intervals and add all possible spots to an AL
 * Find the number of skips u have
 * first place all the cows in spots 1, 2, 3, no skipping - DONE
 * then, find the 2 closest and put down a skip, shifting others as necessary
 * repeat, find 2 closest put down skip shift until no skips left
 * find the 2 closest and return
 */
public class Problem1 {

	public static void main(String[] args) throws Exception {
		//"D:\\CalebArulandu\\USACO\\Open\\Silver\\src\\socdist.in"
		Scanner s = new Scanner(new File("socdist.in"));
		PrintWriter write = new PrintWriter(new FileWriter(new File("socdist.out")));
		String[] first = s.nextLine().trim().split(" ");
		int N = Integer.parseInt(first[0]);
		int M = Integer.parseInt(first[1]);

		ArrayList<Integer> spots = new ArrayList<Integer>();
		// Hold positions of each cow, indices in spots
		ArrayList<Integer> pos = new ArrayList<Integer>();
		int cR = 1;
		int cDist = Integer.MAX_VALUE;

		// Gets all possible spots
		while (s.hasNextLine()){
			String[] parts = s.nextLine().trim().split(" ");
			int start = Integer.parseInt(parts[0]);
			int end = Integer.parseInt(parts[1]);
			for (int i = start; i <= end; i++){
				spots.add(i);

				if(pos.size() < N) {
					pos.add(spots.size() - 1);
				}
			}
		}



		int skips = spots.size() - N;

		for (int i = skips; i > 0; i--){
			cDist = Integer.MAX_VALUE;
			for (int x = 1; x < pos.size(); x++){
				if (spots.get(pos.get(x)) - spots.get(pos.get(x - 1)) < cDist){
					cDist = spots.get(pos.get(x)) - spots.get(pos.get(x - 1));
					cR = x;
				}
			}

			// Put down a skip
			for (int x = cR; x < pos.size(); x++){
				pos.set(x, pos.get(x) + 1);
			}
		}
		cDist = Integer.MAX_VALUE;
		for (int x = 1; x < pos.size(); x++){
			if (spots.get(pos.get(x)) - spots.get(pos.get(x - 1)) < cDist){
				cDist = spots.get(pos.get(x)) - spots.get(pos.get(x - 1));
				cR = x;
			}
		}

		write.println(cDist);
		write.close();
	}
}
