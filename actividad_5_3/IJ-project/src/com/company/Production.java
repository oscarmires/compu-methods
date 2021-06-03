package com.company;

public class Production {
    private void runProduction() {

        long t1 = System.currentTimeMillis();

        int nConsumidores = 40;
        System.out.println("Número de consumidores: " + nConsumidores);

        Almacen a = new Almacen(nConsumidores);
        Productor p = new Productor(1, a);
        Consumidor[] c = new Consumidor[nConsumidores];

        for (int i = 0; i < nConsumidores; i++) {
            c[i] = new Consumidor(i, a);
            c[i].start();
        }

        p.start();



    }

    public static void main(String[] args) {
        // long t1 = System.currentTimeMillis();

        Production production = new Production();
        production.runProduction();

        // long t2 = System.currentTimeMillis();

        // System.out.println("Tiempo: " + (t2-t1));
    }
}
