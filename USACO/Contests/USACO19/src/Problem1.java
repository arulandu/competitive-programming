import java.io.*;
import java.util.*;

public class Problem1 {
    public static void main(String[] args) throws Exception {
        Scanner scanner = new Scanner(new File("gymnastics.in"));
        String[] parts = scanner.nextLine().trim().split(" ");
        int K = Integer.parseInt(parts[0]);
        int N = Integer.parseInt(parts[1]);
        int session = 0;

        ArrayList<Pair> cowPairs = new ArrayList<Pair>();
        for(int i  = 1; i <= N; i++){
            for(int k = i + 1; k <= N; k++){
                cowPairs.add(new Pair(i + "", k + ""));
            }
        }

        List<String> data;
        while(session < K){
            data = Arrays.asList(scanner.nextLine().trim().split(" "));
            for(Pair p : cowPairs){
                p.update(data);
            }
            session++;
        }

        int count = 0;
        for(Pair p : cowPairs){
            if(p.isGood()){
                count++;
            }
        }
        PrintWriter write = new PrintWriter(new FileWriter( new File("gymnastics.out")));
        write.println(count);
        write.close();
    }

}

class Pair {
    private String first;
    private String second;
    private boolean firstBest;
    private boolean isFirst = true;
    private boolean good = true;
    public Pair(String one, String two){
        first = one;
        second = two;
    }

    public boolean isGood(){
        return good;
    }

    public void update(List<String> parts){
        int f = parts.indexOf(first);
        int s = parts.indexOf(second);

        if(isFirst){
            isFirst = false;
            if(f < s){
                firstBest = true;
            } else {
                firstBest = false;
            }
        } else {
            if(firstBest){
                if(f > s){
                    good = false;
                }
            } else {
                if(f < s){
                    good = false;
                }
            }
        }
    }
}