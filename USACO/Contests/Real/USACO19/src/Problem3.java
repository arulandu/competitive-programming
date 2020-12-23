import java.util.*;
import java.io.*;

public class Problem3 {
    public static void main(String[] args) throws Exception {
        ArrayList<String> list = new ArrayList<String>(Arrays.asList("Beatrice", "Belinda", "Bella", "Bessie", "Betsy", "Blue", "Buttercup", "Sue"));

        Scanner scanner = new Scanner(new File("lineup.in"));
        int N = Integer.parseInt(scanner.nextLine().trim());
        int cons = 1;
        String[] parts;
        ArrayList<Cow> cows = new ArrayList<Cow>();

        ArrayList<Cow> consts = new ArrayList<Cow>();

        Cow out = null;

        for (String s : list) {
            cows.add(new Cow(s));
        }

        while (cons <= N) {
            parts = scanner.nextLine().trim().split(" ");
            cows.get(convertNum(parts[0]) - 1).link(cows.get(convertNum(parts[parts.length - 1]) - 1));
            consts.add(cows.get(convertNum(parts[0]) - 1));
            cons++;
        }


        ArrayList<Cow> curr = null;
        while(cows.size() != 0) {
            curr = alphabetize(consts, cows).cowsHere();

            for (Cow c : cows) {
                if (curr.contains(c)) {
                    cows.remove(c);
                }
            }

            for (Cow c : consts) {
                if (curr.contains(c)) {
                    consts.remove(c);
                }
            }
        }

        PrintWriter write = new PrintWriter(new FileWriter( new File("lineup.out")));
        for(Cow c : curr) {
            write.println(c.name);
        }
        write.close();
    }

    public static Cow alphabetize(ArrayList<Cow> consts, ArrayList<Cow> cows){
        Cow leastIndiv = null;
        Cow out;

        for(Cow c : consts){
            if(c != null && c.front.name.compareTo(c.back.name) > 0){
                Cow temp  = c.front;
                c.front = c.back;
                c.back = temp;
            }
        }

        for (Cow c : cows){
            if(c != null && !c.isGrouped){
                if(leastIndiv == null){
                    leastIndiv = c;
                } else if(c.name.compareTo(leastIndiv.name) < 0) {
                    leastIndiv = c;
                }
            }
        }

        Cow least = consts.get(0);
        for (Cow c : consts){
            if(c != null && c.name.compareTo(least.name) < 0){
                least = c;
            }
        }

        if(leastIndiv.name.compareTo(least.name) < 0){
            out = leastIndiv;
        } else {
            out = least;
        }
        return out;
    }
    public static int convertNum(String str) {
        switch (str) {
            case "Beatrice":
                return 1;
            case "Belinda":
                return 2;
            case "Bella":
                return 3;
            case "Bessie":
                return 4;
            case "Betsy":
                return 5;
            case "Blue":
                return 6;
            case "Buttercup":
                return 7;
            case "Sue":
                return 8;
        }
        return -1;
    }

    static class Cow {
        public String name;
        public Cow next;
        public Cow prev;

        public Cow front = this;
        public Cow back;

        public boolean isGrouped = false;

        public Cow(String str) {
            name = str;
        }

        public void link(Cow b) {
            if(this.prev != null){
                prev.back = b;
            }
            if(b.next == null){
                this.prev
            }
            this.next = b;
            b.prev = next;
            back = b;
            this.isGrouped = true;
            b.isGrouped = true;
        }

        public ArrayList<Cow> cowsHere(){
            ArrayList<Cow> arr = new ArrayList<Cow>();
            Cow temp = next;
            while(temp != null){
                arr.add(temp);
                temp = temp.next;
            }
            return arr;
        }
    }
}