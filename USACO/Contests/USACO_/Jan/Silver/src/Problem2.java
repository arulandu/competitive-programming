import java.util.*;
import java.io.*;

public class Problem2 {
    static long N;
    static long K;
    static long M;

    public static void main(String[] args) throws Exception {
        //"D:\\CalebArulandu\\USACO\\Jan\\Silver\\src\\loan.in"
        Scanner s = new Scanner(new File("loan.in"));
        PrintWriter write = new PrintWriter(new FileWriter(new File("loan.out")));
        String[] first = s.nextLine().trim().split(" ");
        N = Long.parseLong(first[0]);
        K = Long.parseLong(first[1]);
        M = Long.parseLong(first[2]);

        long largest = 1;
        long gals;
        for (long X = 2; X < N; X++) {
            if (tryX(X)) {
                largest = X;
            } else {
                break;
            }
        }
        write.println(largest);
        write.close();
    }

    public static boolean tryX(long X) {
        long G = 0;
        for (long i = 1; i <= K; i++) {
            long Y = (N - G) / X;
            if (Y < M) {
                Y = M;
            }
            G += Y;
            if (G >= N) {
                return true;
            }
        }
        return false;
    }
}
