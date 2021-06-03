package com.company;

import java.io.IOException;
import java.io.File;

public class Main {

    public static void main(String[] args) {

        ProcessBuilder pb = new ProcessBuilder();
        pb.directory(new File("/Users/oscar/Local/compu-methods/actividad_3_4"));
        pb.command("./a.out", "3", "TextFile2");

        try {
            Process process = pb.start();
            int ret = process.waitFor();

            System.out.printf("C++ exited with code: %d", ret);
        } catch (IOException | InterruptedException e) {
            e.printStackTrace();
        }

    }
}
