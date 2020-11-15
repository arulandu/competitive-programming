import java.util.*;
import java.io.*;

public class Problem2 {

    public static void main(String[] args) throws Exception {
        //"D:\\CalebArulandu\\USACO\\Open\\Silver\\src\\cereal.in"
        Scanner s = new Scanner(new File("cereal.in"));
        PrintWriter write = new PrintWriter(new FileWriter(new File("cereal.out")));
        String[] first = s.nextLine().trim().split(" ");

        int N = Integer.parseInt(first[0]);
        int M = Integer.parseInt(first[1]);

        ArrayList<Integer[]> cows = new ArrayList<Integer[]>();

        while (s.hasNextLine()){
            String[] parts = s.nextLine().trim().split(" ");
            cows.add(new Integer[]{Integer.parseInt(parts[0]), Integer.parseInt(parts[1])});
        }

        for (int i = 0; i < N; i++){
            int served = 0;
            boolean[] boxes = new boolean[M];
            for (int j = i; j < cows.size(); j++){
                Integer[] cow = cows.get(j);
                if(!boxes[cow[0] - 1]){
                    served++;
                    boxes[cow[0] - 1] = true;
                } else if(!boxes[cow[1] - 1]){
                    served++;
                    boxes[cow[1] - 1] = true;
                }
            }
            write.println(served);
        }

        write.close();
    }
}
