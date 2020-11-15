import java.io.*;
import java.util.*;

public class Prob2 {
    public static String letters = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    public static void main(String[] args) throws Exception{
        Scanner scanner = new Scanner(new File("whereami.in"));
        int N = Integer.parseInt(scanner.nextLine().trim());
        String seq = scanner.nextLine().trim();

        int K = N;
        for(int i = 2; i <= N; i++){
            if(kWorks(seq, i)){
                K = i;
                break;
            }
        }
        PrintWriter write = new PrintWriter(new FileWriter( new File("whereami.out")));
        write.println(K);
        write.close();

    }

    public static boolean kWorks(String seq, int K){
        for(int i = 0; i <= seq.length() - K; i++){
            if(hasMult(seq, seq.substring(i, i + K))){
                return false;
            }
        }
        return true;
    }

    public static boolean hasMult(String seq, String peice){
        int ind = seq.indexOf(peice, 0);
        int occ = 0;
        while(ind != -1) {
            occ++;
            ind = seq.indexOf(peice, ind + 1);
        }

        return occ > 1;
    }

}
