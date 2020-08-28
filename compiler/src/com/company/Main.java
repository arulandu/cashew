package com.company;

import java.io.BufferedWriter;
import java.io.File;
import java.io.FileWriter;
import java.io.IOException;
import java.util.Scanner;

public class Main {
    private static String suffix = ".cash";
    public static void main(String[] args) throws Exception {
        if(!args[0].endsWith(suffix)){
            throw new Exception("Invalid file type");
        }

        Scanner inf = new Scanner(new File(args[0]));

        String outputFn = args[0].substring(0, args[0].length() - suffix.length()) + ".cpp";
        BufferedWriter br = new BufferedWriter(new FileWriter(new File(outputFn)));

        while(inf.hasNextLine()){
            br.write(inf.nextLine() + System.getProperty("line.separator"));
        }

        inf.close();
        br.close();
    }
}
