
package com.company;

/**
 *
 * @author ariay
 */
public class JavaApplication4 {

    /**
     * @param args the command line arguments
     */
    public static void main(String[] args) throws InterruptedException {
        // Varios hilos

        int n = 275;
        int limit = 5000000;

        long t1 = System.currentTimeMillis();
        MiHilo[] hilos = new MiHilo[n];
        for (int i=0 ; i<n ; i++) {
            hilos[i] = new MiHilo(i * limit/n + 1, (i+1) * limit/n);
            hilos[i].start();
        }
        long resultadoFinal = 0;
        for (int i=0 ; i<n ; i++) {
            hilos[i].join();
            resultadoFinal += hilos[i].getSum();
        }
        long t2 = System.currentTimeMillis();

        System.out.println("Tiempo: " + (t2-t1));
        System.out.println("Resultado Final " + resultadoFinal);

    }
    
}


