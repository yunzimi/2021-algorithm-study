package github;

import java.util.Scanner;

public class Main_2675 {

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		Scanner sc = new Scanner(System.in);
		
		int a = sc.nextInt();
		
		for(int i=0;i<a;i++){
	       int c = sc.nextInt();
	       String d = sc.next();
	       for(int j=0;j<d.length();j++){
	    	   for(int g=0;g<c;g++){
	    		   System.out.print(d.charAt(j));
	    	   }
	       }System.out.println();
		}
	}
}

