package com.company;

import java.io.File;
import java.util.Random;

public class Productor extends Thread {
    int id;
    boolean bandera = true;
    Almacen almacen;

    Productor(int id, Almacen almacen) {
        this.id = id;
        this.almacen = almacen;
    }

    String[] getArchivos() {
        File directorio = new File("/Users/oscar/Local/compu-methods/actividad_5_3/IJ-project/scripts");
        File[] archivos = directorio.listFiles();
        String[] nombres = new String[archivos.length];
        for (int i = 0; i < archivos.length; i++) {
            System.out.println(archivos[i].getName());
            nombres[i] = archivos[i].getName().split("\\.")[0];
        }
        return nombres;
    }

    @Override
    public void run() {


        String[] productos = getArchivos();
        System.out.println("Productor " + this.id);

        for (int i = 0; i < productos.length; i++) {
            this.almacen.producir(productos[i]);

            System.out.println("Produce: " + productos[i]);

        }

        almacen.stopProduction();
    }

    public void detener() {
        this.bandera = false;
    }
}
