import java.lang.reflect.Array;
import java.util.*;
import java.io.*;

public class Problem2R {
    public static int N;

    public static void main(String[] args) throws Exception {
        long nano = System.nanoTime();
        //"D:\\CalebArulandu\\USACO\\February\\Silver\\src\\triangles.in"
        Scanner s = new Scanner(new File("triangles.in"));
        PrintWriter write = new PrintWriter(new FileWriter(new File("triangles.out")));
        String[] first = s.nextLine().trim().split(" ");
        N = Integer.parseInt(first[0]);
        ArrayList<Integer> X = new ArrayList<Integer>();
        ArrayList<Integer> Y = new ArrayList<Integer>();
        for (int i = 0; i < N; i++) {
            String[] parts = s.nextLine().trim().split(" ");
            X.add(Integer.parseInt(parts[0]));
            Y.add(Integer.parseInt(parts[1]));
        }

        ArrayList<Integer> xMults = new ArrayList<Integer>();
        ArrayList<Integer> yMults = new ArrayList<Integer>();

        for (Integer i : X) {
            if (!xMults.contains(i) && mult(X, i)) {
                xMults.add(i);
            }
        }
        for (Integer i : Y){
            if (!yMults.contains(i) && mult(Y, i)) {
                yMults.add(i);
            }
        }

        ArrayList<int[]> corners = new ArrayList<int[]>();
        int triSum = 0;
        for (Integer xi : xMults) {
            for (Integer yi : yMults) {
                // Makes sure the point is a corner
                if (containsPoint(X, Y, xi, yi)) {
                    // Iterates through summing x*y for all other possible points
                    for (int i = 0; i < Y.size(); i++) {
                        if (X.get(i).equals(xi)) {
                            for (int j = 0; j < X.size(); j++) {
                                if (Y.get(j).equals(yi)) {
                                    triSum += Math.abs(Y.get(i) - xi) * Math.abs(X.get(j) - yi);
                                }
                            }
                        }
                    }
                }
            }
        }

        write.println((int) (triSum % (Math.pow(10, 9) + 7)));
        write.close();
        System.out.println((System.nanoTime() - nano)/1000000000.0);
    }
    public static boolean containsPoint(ArrayList<Integer> x, ArrayList<Integer> y, int X, int Y){
        for(int i = 0; i < x.size(); i++){
            if(x.get(i) == X && y.get(i) == Y){
                return true;
            }
        }
        return false;
    }
    public static boolean mult(ArrayList<Integer> ar, int row) {
        int c = 0;
        for (int i = 0; i < ar.size(); i++) {
            if (ar.get(i) == row) {
                c++;
            }
            if (c >= 2) {
                return true;
            }
        }
        return false;
    }
}
