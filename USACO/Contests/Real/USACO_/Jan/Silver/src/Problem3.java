import java.util.*;
import java.io.*;

public class Problem3 {

    public static void main(String[] args) throws Exception{
        Scanner s = new Scanner(new File("wormsort.in"));
        PrintWriter write = new PrintWriter(new FileWriter(new File("wormsort.out")));
        String[] first = s.nextLine().trim().split(" ");
        String[] placement = s.nextLine().trim().split(" ");
        boolean ordered = true;
        for(int i = 0; i < placement.length; i++){
            if(Integer.parseInt(placement[i]) != i + 1) {
                ordered = false;
                break;
            }
        }

        if(ordered){
            write.println(-1);
            write.close();
        } else {
            while(s.hasNext()) {
                String[] line = s.nextLine().trim().split(" ");
                if(line[0].equals("1")) {
                    write.println(line[2]);
                    write.close();
                    break;
                }
            }
        }
    }
}
