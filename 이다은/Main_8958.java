package github;

import java.util.Scanner;

public class Main_8958 {

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		Scanner sc = new Scanner(System.in);
		
		 int a = sc.nextInt();
		 String[]b = new String[a];
		 
		 for(int i=0;i<a;i++){
			 b[i]=sc.next();
		 }
		 
		 for(int i=0;i<a;i++){
			 int c = 0;
			 int d = 0;
			 for(int j=0;j<b[i].length();j++){
				 if(b[i].charAt(j)=='O'){
					c++;
				 }else{
					 c=0;
				 }d=d+c;
			 }System.out.println(d);
		 }
	}
}
