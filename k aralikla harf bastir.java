package com.company;

import java.util.Scanner;

public class Main {

    public static void main(String[] args) {
        Scanner myObj = new Scanner(System.in);
        String x = myObj.nextLine();
        String y[] = x.split(",");
        String z[] = y[0].split(" ");

        int k = Integer.parseInt(String.valueOf(y[1].charAt(1)));
        int arr[] = new int[z.length];
        for(int i = 0; i < z.length; i++){

            arr[i] = Integer.parseInt(z[i]);

        }

        //int arr[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};

        KAralik(arr, k, 1, arr.length - 1);
    }

    public static void KAralik(int arr[], int k, int n, int sira){
        if(sira < 0){
            return;
        }
        else if(n != k){
            n++;
            sira--;
            KAralik(arr, k, n, sira);
        }
        else{
            System.out.print(arr[sira] + " ");
            n = 1;
            sira--;
            KAralik(arr, k, n, sira);
        }
    }

    public static int[] sort(int arr[]){

        int minimum = -999;
        int minindex = 0;
        if(arr.length == 1){
            return arr;
        }

        for(int i = 0; i < arr.length; i++){
            if(arr[i] < minimum){
                minimum = arr[i];
                minindex = i;
            }
        }



        int slice[] = new int[arr.length - 1];
        for(int i = 1; i < arr.length; i++){
            slice[i-1] = arr[i];
        }

        sort(slice);
        return arr;
    }
}
