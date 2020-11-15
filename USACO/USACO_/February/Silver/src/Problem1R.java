import java.util.*;
import java.io.*;

public class Problem1R {
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

        ArrayList<Integer> ar = new ArrayList<Integer>();
        for(int i = 1; i <= N; i++){
            ar.add(i);
        }
        ArrayList<Integer> ar2 = new ArrayList<>(ar);

        int[][] pairs = new int[M][2];
        for (int i = 0; i < M; i++){
            String line = s.nextLine().trim();
            String[] parts = line.split(" ");
            int a = Integer.parseInt(parts[0]) - 1;
            int b = Integer.parseInt(parts[1]) - 1;
            pairs[i] = new int[]{a, b};
        }
        for(int q = 1; q <= K; q++) {
            for(int r = 0; r < M; r++){
                Integer[] rev = reverse(ar, pairs[r][0], pairs[r][1]);
                int j = 0;
                for (int i = pairs[r][0]; i <= pairs[r][1]; i++) {
                    ar.set(i, rev[j]);
                    j++;
                }
            }
            if(ar.equals(ar2)){
                K = K % q;
                q = 1;
            }
        }

        for(Integer i : ar){
            write.println(i);
        }
        write.close();
    }

    public static Integer[] reverse(ArrayList<Integer> ar, int a, int b){
        Integer[] rev = new Integer[b - a + 1];
        int j = 0;
        for(int i = b; i >= a; i--){
            rev[j] = ar.get(i);
            j++;
        }
        return rev;
    }
}