import java.util.*;
import java.io.*;


public class Problem3 {

    public static void main(String[] args) throws Exception{
        Scanner s = new Scanner(new File("moop.in"));
        PrintWriter write = new PrintWriter(new FileWriter(new File("moop.out")));
        String[] first = s.nextLine().trim().split(" ");

        int[] x_val = {Integer.MAX_VALUE, Integer.MIN_VALUE};
        int[] y_val = {Integer.MAX_VALUE, Integer.MIN_VALUE};

        int q = -1;

        ArrayList<Integer[]> moops = new ArrayList<>();
        while (s.hasNextLine()){
            String[] parts = s.nextLine().trim().split(" ");
            int x = Integer.parseInt(parts[0]);
            int y = Integer.parseInt(parts[1]);

            moops.add(new Integer[]{x, y});

            x_val[0] = Integer.min(x_val[0], x);
            y_val[0] = Integer.min(y_val[0], y);

            x_val[1] = Integer.max(x_val[1], x);
            y_val[1] = Integer.max(y_val[1], y);
        }

        int rem = 1;
        while (true) {
            x_val = new int[]{Integer.MAX_VALUE, Integer.MIN_VALUE};
            y_val = new int[]{Integer.MAX_VALUE, Integer.MIN_VALUE};

            for (Integer[] moop : moops) {
                int x = moop[0];
                int y = moop[1];

                x_val[0] = Integer.min(x_val[0], x);
                y_val[0] = Integer.min(y_val[0], y);

                x_val[1] = Integer.max(x_val[1], x);
                y_val[1] = Integer.max(y_val[1], y);
            }

            int c = 0;
            for (Integer[] moop : moops) {
                if ((moop[0] == x_val[0] && moop[1] == y_val[1]) || (moop[0] == x_val[1] && moop[1] == y_val[0])) {
                    c++;
                    moops.remove(moop);
                    break;
                }
            }

            if (c == 0){
                break;
            } else {
                rem += c;
            }
        }

        write.println(rem);

        write.close();
    }
}
