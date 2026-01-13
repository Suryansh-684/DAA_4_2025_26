#include <bits/stdc++.h>
using namespace std;


void complexRec(int n) {


   if (n <= 2) {
       return;
   }


   int p = n;
   while (p > 0) {
       vector<int> temp(n);
       for (int i = 0; i < n; i++) {
           temp[i] = i ^ p;
       }
       p >>= 1;
   }


   vector<int> small(n);
   for (int i = 0; i < n; i++) {
       small[i] = i * i;
   }


   if (n % 3 == 0) {
       reverse(small.begin(), small.end());
   } else {
       reverse(small.begin(), small.end());
   }


   complexRec(n / 2);
   complexRec(n / 2);
   complexRec(n / 2);
}







import java.util.*;


public class ComplexRecursion {


   static void complexRec(int n) {


       if (n <= 2) {
           return;
       }


       int p = n;
       while (p > 0) {
           int[] temp = new int[n];
           for (int i = 0; i < n; i++) {
               temp[i] = i ^ p;
           }
           p >>= 1;
       }


       int[] small = new int[n];
       for (int i = 0; i < n; i++) {
           small[i] = i * i;
       }


       // Reverse array
       reverseArray(small);


       complexRec(n / 2);
       complexRec(n / 2);
       complexRec(n / 2);
   }


   private static void reverseArray(int[] arr) {
       int left = 0, right = arr.length - 1;
       while (left < right) {
           int temp = arr[left];
           arr[left] = arr[right];
           arr[right] = temp;
           left++;
           right--;
       }
   }


   public static void main(String[] args) {
       complexRec(16);
   }
}



