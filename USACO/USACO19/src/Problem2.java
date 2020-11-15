import java.io.*;
import java.util.*;

public class Problem2 {
    public static String letters = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    public static void main(String[] args) throws Exception{
        Scanner scanner = new Scanner(new File("D:\\Caleb Arulandu\\IdeaProjects\\USACO19\\src\\whereami.txt"));
        int N = Integer.parseInt(scanner.nextLine().trim());
        String seq = scanner.nextLine().trim();

        ArrayList<Starting> starts = new ArrayList<Starting>();
        for(int i = 0; i < letters.length(); i++){
            starts.add(new Starting(seq, letters.charAt(i) + ""));
        }
        int K = seq.length();
        int up;
        for(Starting s : starts){
            up = s.update();
            if(up < K && up != -1){
                if(up == 1 && s.start.equals(seq.charAt(seq.length() - 1) + "") && hasMult(seq, s)){

                } else {
                    K = up;
                }
            }
        }

        PrintWriter write = new PrintWriter(new FileWriter( new File("whereami.out")));
        write.println(K);
        write.close();

    }
    public static boolean hasMult(String seq, Starting s){
        int ind = seq.indexOf(s.start, 0);
        int occ = 0;
        while(ind != -1) {
            occ++;
            ind = seq.indexOf(s.start, ind + 1);
        }

        return occ > 1;
    }
}

class Starting {
    public String seq;
    public String start;
    public int oCount;

    public int nextOcc;

    ArrayList<Integer> nexts;

    ArrayList<Starting> creations = new ArrayList<Starting>();



    public Starting(String str, String letter, int next){
        seq = str;
        start = letter;
        nexts = new ArrayList<Integer>();
        nextOcc = next;
    }

    public Starting(String str, String letter){
        seq = str;
        start = letter;
        nexts = new ArrayList<Integer>();
    }


    private void checkOccurences(){
        int ind = seq.indexOf(start, 0);
        int occ = 0;
        while(ind != -1) {
            occ++;
            nexts.add(ind + start.length());
            ind = seq.indexOf(start, ind + 1);
        }

        oCount = occ;
    }

    public int update(){
        int K = seq.length();
        int creationK;
        checkOccurences();
        Starting creation;
        if(oCount == 0){
            return -1;
        }
        if(oCount == 1){
            return start.length();
        } else {
            for(int i = 0; i < nexts.size(); i++){
                if(i == nexts.size() - 1){
                    if(nexts.get(i) > seq.length() - 1){
                        creationK = start.length();
                    } else {
                        creation = new Starting(seq, start + seq.charAt(nexts.get(i)));
                        creationK = creation.update();
                    }
                } else {
                    creation = new Starting(seq, start + seq.charAt(nexts.get(i)), nexts.get(i + 1) - 1);
                    if((seq.charAt(creation.nextOcc) + "").equals(start.charAt(0) + "")){
                        creationK = creation.start.length();
                    } else {
                        creationK = creation.update();
                    }
                }

                if(creationK < K){
                    K = creationK;
                }
            }
        }
        return K;
    }


}
