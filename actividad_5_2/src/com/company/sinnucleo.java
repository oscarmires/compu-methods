package com.company;


import static java.lang.Math.sqrt;


public class sinnucleo {

    public static boolean numprimo (int n){
        if(n < 2) {
            return false;
        } else{
            for(int i = 2; i <= sqrt(n) ; i++ ){
                if(n%i == 0){
                    return false;
                }
            }
            return true;
        }
    }

    public static void main(String[] args) {
        long num =0;
        long t1 = System.currentTimeMillis();
        for(int i = 0; i < 5000000 ; i++ ){
            if(numprimo(i)){
                num= i+num;
            }
        }
        System.out.println(num);
        long t2 = System.currentTimeMillis();
        System.out.println(t2-t1);
    }

}