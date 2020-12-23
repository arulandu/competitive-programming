import java.io.*;
import java.util.*;

public class Problem2 {
    public static void main(String[] args) throws Exception {
        Scanner s = new Scanner(new File("photo.in"));
        PrintWriter write = new PrintWriter(new FileWriter(new File("photo.out")));
        int N = Integer.parseInt(s.nextLine().trim());
        String[] bs = s.nextLine().trim().split(" ");

        String seq;
        int num;
        boolean isGood;

        // IN SOME CASES is Good is always false
        String out = "";
        outer:
        for (int i = 1; i <= N; i++) {
            num = i;
            seq = i + " ";
            for (int j = 0; j < N - 1; j++) {
                num = Integer.parseInt(bs[j]) - num;
                if (seq.contains(" " + num + " ") || num == i || num <= 0 || num > N) {
                    continue outer;
                }
                seq += num + " ";
            }
            if (out.equals("") || out.compareTo(seq) > 0) {
                out = seq;
            }

        }


        write.println(out.trim());
        write.close();
    }
/*
    public static String lower(String first, String sec){
        boolean inEqual = true;
        String F = first.replace(" ", "");
        String S = sec.replace(" ", "");
        String f,s;
        for(int i = 0; i < F.length(); i++){
            f = F.charAt(i) + "";
            s = S.charAt(i) + "";
            if(!f.equals(s)){
                inEqual = false;
            }

            if(!inEqual){
                if(f.compareTo(s) > 0){
                    return sec;
                } else if (f.compareTo(s) < 0){
                    return f;
                }
            }
        }
        return "";
    }
    */

}
