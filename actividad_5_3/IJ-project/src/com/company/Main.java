package com.company;

public class Main {
    public static void main(String[] args) {
        long t1 = System.currentTimeMillis();

        int nConsumidores = 2;
        System.out.println("Número de consumidores: " + nConsumidores);

        Almacen a = new Almacen(nConsumidores);
        Productor p = new Productor(1, a);
        Consumidor[] c = new Consumidor[nConsumidores];

        for (int i = 0; i < nConsumidores; i++) {
            c[i] = new Consumidor(i, a);
            c[i].start();
        }

        p.start();

        for (int i = 0; i < nConsumidores; i++) {
            try {
                c[i].join();
            } catch (InterruptedException e) {
                e.printStackTrace();
            }
        }

        long t2 = System.currentTimeMillis();

        System.out.println("Tiempo (" + nConsumidores + " hilos): " + (t2-t1));
    }
}
