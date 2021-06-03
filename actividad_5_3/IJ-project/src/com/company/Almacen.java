package com.company;

public class Almacen {
    private String[] espacio;
    private int ocupados = 0;
    private int numConsumidores;
    private boolean producing = true;
    private long[] tiempos;

    Almacen(int numConsumidores) {
        this.espacio = new String[5]; // 0 = nulo
        this.numConsumidores = numConsumidores;
        for (int i = 0; i < this.espacio.length; i++) {
            this.espacio[i] = "";
        }
        this.tiempos = new long[numConsumidores];
    }

    synchronized String consumir() {


        while (this.ocupados == 0) {
            try {
                wait();
            } catch (InterruptedException e) {
                e.printStackTrace();
            }
        }

        for (int i = 0; i < this.espacio.length; i++) {
            if (this.espacio[i].length() != 0) {
                String producto = this.espacio[i];
                this.espacio[i] = "";
                this.ocupados--;
                notifyAll();
                return producto;
            }
        }

        return "";
    }

    synchronized void producir(String producto) {
        while (this.ocupados != 0) {
            try {
                wait();
            } catch (InterruptedException e) {
                e.printStackTrace();
            }
        }

        for (int i = 0; i < this.espacio.length; i++) {
            if (this.espacio[i].length() == 0) {
                this.espacio[i] = producto;
                this.ocupados++;
                notifyAll();
                break;
            }
        }
    }

    void stopProduction() {
        // this.ocupados++;
        this.producing = false;
    }

    boolean isProducing() {
        return this.producing;
    }

    public void addTiempo(int pos, long val) {
        this.tiempos[pos] += val;
    }

    public long getMaxTime() {
        long max = 0;
        for (long t :
                this.tiempos) {
                if (t > max) {
                    max = t;
                }
            }
        return max;
    }
}

// [2, 3, 1]
