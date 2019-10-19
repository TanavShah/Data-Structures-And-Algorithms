/* package codechef; // don't place package name! */

import java.util.*;
import java.lang.*;
import java.io.*;

/* Name of the class has to be "Main" only if the class is public. */
class Codechef
{
    public static void qSort(int[] a) {
        quickSort(a, 0, a.length - 1);
    }
    
    public static void quickSort(int[] a, int left, int right) {
        if(left >= right) return;
        int pivot = a[(left + right)/2];
        int index = partition(a, left, right, pivot);
        quickSort(a, left, index-1);
        quickSort(a, index, right);
    }
    
    public static int partition(int[] a, int left, int right, int pivot) {
        while(left <= right) {
            while(a[left] < pivot) {
                left++;
            }
            while(a[right] > pivot) {
                right--;
            }
            if(left <= right) {
                swap(a, left, right);
                left++;
                right--;   
            }
        }
        return left;
    }
    
    public static void swap(int[] arr, int l, int r) {
        int t = arr[l];
        arr[l] = arr[r];
        arr[r] = t;
    }
    
	public static void main (String[] args) throws java.lang.Exception
	{
		// your code goes here
		int[] a = {4,3,5,8,1,7};
		qSort(a);
		for(int x : a) System.out.println(x);
	}
}
