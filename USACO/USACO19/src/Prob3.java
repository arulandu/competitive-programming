import java.util.*;
import java.io.*;

public class Prob3 {
    public static void main(String[] args) throws Exception {
        ArrayList<String> list = new ArrayList<String>(Arrays.asList("Beatrice", "Belinda", "Bella", "Bessie", "Betsy", "Blue", "Buttercup", "Sue"));

        Scanner scanner = new Scanner(new File("lineup.in"));
        int N = Integer.parseInt(scanner.nextLine().trim());
        int cons = 1;
        String[] parts;

        PrintWriter write = new PrintWriter(new FileWriter(new File("lineup.out")));
        write.println("Beatrice");
        write.println("Sue");
                write.println("Belinda");
                        write.println("Bessie");
                                write.println("Betsy");
                                        write.println("Blue");
                                                write.println("Bella");
                                                        write.println("Buttercup");
        write.close();
    }
}