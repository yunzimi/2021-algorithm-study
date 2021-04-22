package github;

import java.util.Scanner;

public class Main_2884 {

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		Scanner sc = new Scanner(System.in); 
		
		 int a = sc.nextInt();
		 int b = sc.nextInt();
		 int c= (a*60 + b)-45;
		 int d= c/60;
		 int e= c%60;
				 
		 if(a==0 && b<45){
			 a=24;
			 c= (a*60 + b)-45;
			 d= c/60;
			 e= c%60;
			 System.out.println(d+" "+e);
		 }else {
			 System.out.println(d+" "+e);
		 }		 
		 
	}

}
