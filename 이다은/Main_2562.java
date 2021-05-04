package github;

import java.util.Scanner;

public class Main_2562 {

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		Scanner sc = new Scanner(System.in);
		   
        int[]a = new int[9];
        
        for(int i=0;i<9;i++) {
         a[i]=sc.nextInt();
        }
        
        int max=a[0];
        int index = 0;
        
        for(int j=0;j<9;j++){
        	if(a[j]>max) {
        		max = a[j];
        		index = j;
        	}
        }System.out.println(max);
         System.out.println(index+1); 
        }     
	}

