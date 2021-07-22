/*
 * Alvan Caleb Arulandu
 * Thomas Jefferson HIgh School for Science and Technology
 * Junior-5 Division
 * Contest #1 2019-2020
 *  */

import java.util.*;
import java.io.*;

public class Main {

    public static void main(String[] args) throws FileNotFoundException {
        // Gets the full path of the desired text file
        String path = "1jr_testdata.txt";

        // Uses the Scanner class to read the file
        Scanner readFile = null;
        try {
            readFile = new Scanner(new File(path));
        } catch (FileNotFoundException e) {
            System.out.println("File Not Found");
            System.exit(0);
        } catch (Exception e) {
            System.out.println("An Unknown Exception Occurred");
            System.exit(0);
        }

        // Declares variables to store the later parsed data
        String[] parsedParts;
        int p;
        int d;
        int originalLength;
        int pthDigit;

        // Stores the line number read
        int count = 1;

        // Continues to read each line of the file
        while (readFile.hasNextLine()) {

            // Parses the read line, calculating its original length and storing the integers P and D
            parsedParts = readFile.nextLine().trim().split(" ");
            originalLength = parsedParts[0].length();
            p = Integer.parseInt(parsedParts[1]);
            d = Integer.parseInt(parsedParts[2]);

            // Handles invalid values
            if(p <= 0 || p > parsedParts.length){
                System.out.println("Invalid value for P.");
                System.exit(0);
            }
            // Calculates the pthDigit from the right
            pthDigit = Integer.parseInt(parsedParts[0].charAt(parsedParts[0].length() - p) + "");

            // Preforms the necessary process based on the value of the Pth digit
            if (pthDigit >= 0 && pthDigit <= 4) {
                parsedParts[0] = parsedParts[0].substring(0, parsedParts[0].length() - p) + ((pthDigit + d) % 10);
            } else if (pthDigit >= 5 && pthDigit <= 9) {
                parsedParts[0] = parsedParts[0].substring(0, parsedParts[0].length() - p) + (Math.abs(pthDigit - d) + "").charAt(0);
            }

            // Appends 0s to the end of the string
            while (parsedParts[0].length() < originalLength) {
                parsedParts[0] += "0";
            }

            // Prints out the new number, updating count
            System.out.println(count + ". " + parsedParts[0]);
            count++;
        }
    }
}