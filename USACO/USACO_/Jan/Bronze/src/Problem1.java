import java.io.*;
import java.util.*;

public class Problem1 {
    public static void main(String[] args) throws Exception {
        Scanner s = new Scanner(new File("word.in"));
        PrintWriter write = new PrintWriter(new FileWriter(new File("word.out")));
        String[] line = s.nextLine().trim().split(" ");
        String[] words = s.nextLine().trim().split(" ");
        int N = Integer.parseInt(line[0]);
        int K = Integer.parseInt(line[1]);
        String out = "";
        int length = 0;
        for(String word : words){
            if(length + word.length() <= K){
                out += word + " ";
                length += word.length();
            } else {
                out = out.trim();
                write.println(out);
                out = word + " ";
                length = word.length();
            }
        }
        if(!out.equals("")){
            out = out.trim();
            write.println(out);
        }
        write.close();
    }
}
