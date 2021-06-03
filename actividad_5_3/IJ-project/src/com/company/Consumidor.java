package com.company;

import java.io.File;
import java.io.IOException;
import java.util.Arrays;

public class Consumidor extends Thread {
    int id;
    boolean bandera = true;
    Almacen almacen;
    long tiempo;

    Consumidor(int id, Almacen almacen) {
        this.id = id;
        this.almacen = almacen;
    }

    @Override
    public void run() {
        System.out.println("Consumidor " + this.id);

        this.tiempo = System.currentTimeMillis();

        while (almacen.isProducing()) {
            String producto = this.almacen.consumir();

            System.out.println("[" + this.id + "] Consume: " + producto);

            String[] command = {"./a.out", "3", producto};
            try {
                int ret = Runtime.getRuntime().exec(command).waitFor();
                System.out.printf("[%s] exited with code: %d\n", this.id, ret);
            } catch (IOException | InterruptedException e) {
                e.printStackTrace();
            }

            almacen.addTiempo(this.id, System.currentTimeMillis() - this.tiempo);
            System.out.println("Max time after [" + this.id + "]: " + almacen.getMaxTime() + "ms");
            /*
            almacen.addTiempo(this.id, System.currentTimeMillis() - this.tiempo);
            System.out.println("Max time for [" + this.id + "]: " + almacen.getMaxTime() + "ms");

             */
        }
    }

    public void detener() {
        this.bandera = false;
    }
}
