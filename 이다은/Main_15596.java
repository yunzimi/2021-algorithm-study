package github;

import java.util.Scanner;

public class Main_15596 {

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		Scanner sc = new Scanner(System.in);
		Test t = new Test();
		
		String a = sc.next();
		String[]b=a.split("");
		int[]c = new int [b.length];
		
		for(int i=0;i<c.length;i++){
			c[i]=Integer.parseInt(b[i]);
		}
		
		System.out.println(t.sum(c));
	}
}


class Test {
	
	int sum;
	
	long sum(int[]a){
		for(int i=0;i<a.length;i++){
		   	this.sum +=a[i];
		}
		return sum;
	}
}