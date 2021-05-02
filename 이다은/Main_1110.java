package github;

import java.util.Scanner;

public class Main_1110 {

	public static void main(String[] args) {
		// TODO Auto-generated method stub
        Scanner sc = new Scanner(System.in);
		
        int a = sc.nextInt();    
        int count = 0;
        int temp = 0;
        int n = a;
        
       while(true){
    	   count++;
    	   int b=n/10;
       	   int c =n%10;
    	   temp = c;
    	   c=(b+c)%10;
           b=temp; 
           n=b*10+c;          
           
           if(n==a) 
        	    break;                      
        }
        System.out.println(count);		
	}
}
