package com.company;

import java.io.BufferedReader;
import java.io.File;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.concurrent.CompletableFuture;
import java.util.concurrent.ExecutionException;

public class Secuencial {
    public static void main(String[] args) {

        long t1 = System.currentTimeMillis();

        File directorio = new File("/Users/oscar/Local/compu-methods/actividad_5_3/IJ-project/scripts");
        File[] archivos = directorio.listFiles();

        for (int i = 0; i < archivos.length; i++) {
            System.out.println(archivos[i].getName() + ", ");
        }
        System.out.println("----------------");


        for (int i = 0; i < archivos.length; i++) {

            String nombre = archivos[i].getName().split("\\.")[0];

            System.out.println(nombre);

            String[] command = {"./a.out", "3", nombre};
            try {
                int ret = Runtime.getRuntime().exec(command).waitFor();
                System.out.printf("[%s] exited with code: %d\n", nombre, ret);
            } catch (IOException | InterruptedException e) {
                e.printStackTrace();
            }
        }

        long t2 = System.currentTimeMillis();

        System.out.println("------------------------------------");
        System.out.println("Tiempo (secuencial): " + (t2-t1) + "ms");

    }
}
