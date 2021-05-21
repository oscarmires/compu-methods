/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package com.company;

import static java.lang.Math.ceil;
import static java.lang.Math.sqrt;

/**
 *
 * @author ariay
 */
public class MiHilo extends Thread{
    long sum;
    int r1, r2;

    public MiHilo(int r1, int r2) {
        this.r1 = r1;
        this.r2 = r2;
        this.sum = 0;
    }
    
     /**
     *
     * @param n
     * @return
     */
    public boolean numprimo (int n){
        if(n < 2){
            return false;
        } else if (n == 2) {
            return true;
        }
        else{
            for(int i = 2; i <= ceil(sqrt(n)) ; i++ ){
                 
                if(n%i == 0){
                    return false;
                }
                
            }
            
            return true;
        }
        
    }
    
    @Override
    
    public void run (){

        for(int i = this.r1; i < this.r2 ; i++ ){
            if(numprimo(i)){
                this.sum = i+ this.sum;
            }
            
        }
    }

   public long getSum() {
        return this.sum;
   }
}

