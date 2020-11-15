import java.io.*;
import java.util.*;

public class Problem3 {
    public static void main(String[] args) throws Exception {
        Scanner s = new Scanner(new File("race.in"));
        PrintWriter write = new PrintWriter(new FileWriter(new File("race.out")));
        String[] vals = s.nextLine().trim().split(" ");
        int K = Integer.parseInt(vals[0]);
        int N = Integer.parseInt(vals[1]);
        int[] Xs = new int[N];
        for(int i = 0; i < N; i++){
            Xs[i] = Integer.parseInt(s.nextLine().trim());
        }

        int ends;
        int still;
        double stillD;
        int maxS;
        for(Integer X : Xs){
            maxS = K;
            for(int i = 1; i <= K; i++){
                if(i >= X) {
                    ends = ((i * (i + 1)) / 2) + ((i - 1 + X) * (i - X)) / 2;

                    if (ends <= K) {
                        //Rounding
                        stillD = (K - ends) / (i * 1.0);
                        still = (int) stillD;
                        if (stillD > still) {
                            still++;
                        }
                        //Seconds calc
                        if (i + i - X + still < maxS) {
                            maxS = i + i - X + still;
                        }
                    } else {
                        break;
                    }
                } else {
                    ends = ((i * (i + 1)) / 2);

                    if (ends <= K) {
                        //Rounding
                        stillD = (K - ends) / (i * 1.0);
                        still = (int) stillD;
                        if (stillD > still) {
                            still++;
                        }
                        //Seconds calc
                        if (i + still < maxS) {
                            maxS = i + still;
                        }
                    } else {
                        break;
                    }
                }
            }
            write.println(maxS);
            System.out.println(maxS);
        }
        write.close();

    }
}
