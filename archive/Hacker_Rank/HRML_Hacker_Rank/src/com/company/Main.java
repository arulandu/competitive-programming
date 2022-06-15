package com.company;

import java.util.*;
import java.io.*;

public class Main {

    public static void main(String[] args) throws FileNotFoundException {
        // id, name, value
        Scanner s = new Scanner(new File("src\\com\\company\\input.txt"));
        String[] counts = s.nextLine().trim().split(" ");
        int tagCount = Integer.parseInt(counts[0]);
        int queryCount = Integer.parseInt(counts[1]);

        ArrayList<String[]> tags = new ArrayList<String[]>();
        Stack<String[]> opened = new Stack<String[]>();
        for(int i = 0; i < tagCount; i++){
            String line = s.nextLine().trim();
            if(line.contains("</")){
                opened.pop();
            } else {
                // Start tag
                int nameInd = line.indexOf("name");
                int valueInd = line.indexOf("value");

                String[] tag = new String[4];
                tag[0] = line.substring(1, line.indexOf(" "));
                if(nameInd != -1){
                    tag[1] = line.substring(nameInd + 8, line.indexOf("\"", nameInd + 8));
                }

                if(valueInd != -1){
                    tag[2] = line.substring(valueInd + 9, line.indexOf("\"", valueInd + 9));
                }

                if(!opened.isEmpty()) {
                    opened.peek()[3] = tag[0];
                }
                opened.push(tag);
                tags.add(tag);
            }
        }

        for(int i = 0; i < queryCount; i++){
            String line = s.nextLine().trim();
            int dotInd = line.indexOf(".");
            int valInd = line.indexOf("~");
            String[] curTag = getName(tags, line.substring(0, valInd));
            while(dotInd != -1){
                curTag = getName(tags, line.substring(0, dotInd));
                curTag = getName(tags, curTag[3]);
                dotInd = line.indexOf(".", dotInd + 1);
            }
            String attrib = line.substring(valInd + 1).trim();
            int code = 0;
            if(attrib.equals("name")){
                code = 1;
            } else if(attrib.equals("value")){
                code = 2;
            }

            if(code == 0 || curTag[code] == null){
                System.out.println("Not Found");
            } else {
                System.out.println(curTag[code]);
            }
        }
    }

    public static String[] getName(ArrayList<String[]> ar, String name){
        for(String[] tag : ar){
            if(tag[0].equals(name)){
                return tag;
            }
        }

        return null;
    }
}