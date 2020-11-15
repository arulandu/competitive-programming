import java.util.*;
import java.io.*;

public class Problem2 {
    public static int N;

    public static void main(String[] args) throws Exception {
        long nano = System.nanoTime();
        //"D:\\CalebArulandu\\USACO\\February\\Silver\\src\\triangles.in"
        Scanner s = new Scanner(new File("D:\\\\CalebArulandu\\\\USACO\\\\February\\\\Silver\\\\src\\\\triangles.in"));
        PrintWriter write = new PrintWriter(new FileWriter(new File("triangles.out")));
        String[] first = s.nextLine().trim().split(" ");
        N = Integer.parseInt(first[0]);
        boolean[][] grid = new boolean[20001][20001];
        for (int i = 0; i < N; i++) {
            String[] parts = s.nextLine().trim().split(" ");
            grid[Integer.parseInt(parts[1]) + 10000][Integer.parseInt(parts[0]) + 10000] = true;
        }

        ArrayList<Integer> x = new ArrayList<Integer>();
        ArrayList<Integer> y = new ArrayList<Integer>();
        for (int i = 0; i < 20001; i++) {
            if (sidesInRow(grid, i)) {
                x.add(i);
            }

            if (sidesInCol(grid, i)) {
                y.add(i);
            }
        }

        ArrayList<int[]> corners = new ArrayList<int[]>();
        int triSum = 0;
        for (Integer xi : x) {
            for (Integer yi : y) {
                if (grid[xi][yi]) {
                    for (int i = 0; i < 20001; i++) {
                        if (grid[xi][i]) {
                            for (int j = 0; j < 20001; j++) {
                                if (grid[j][yi]) {
                                    triSum += Math.abs(i - xi) * Math.abs(j - yi);
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

    public static boolean sidesInRow(boolean[][] ar, int row) {
        int c = 0;
        for (int i = 0; i < ar[row].length; i++) {
            if (ar[row][i]) {
                c++;
            }
            if (c >= 2) {
                return true;
            }
        }
        return false;
    }

    public static boolean sidesInCol(boolean[][] ar, int col) {
        int c = 0;
        for (int i = 0; i < ar.length; i++) {
            if (ar[i][col]) {
                c++;
            }
            if (c >= 2) {
                return true;
            }
        }
        return false;
    }
}
