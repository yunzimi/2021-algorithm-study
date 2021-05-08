package github;

import java.util.Scanner;

public class Main_2577 {

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		Scanner sc = new Scanner(System.in);
		
		int a=sc.nextInt();
		int b=sc.nextInt();
		int c=sc.nextInt();
		int d =a*b*c;
		
		int[]count = new int[10];
		
		String e = String.valueOf(d);
		char[] f = e.toCharArray();
		
		for(int i =0;i<10;i++){
			for(int j=0;j<f.length;j++){
				if((f[j] - '0')==i){
				 count[i]++;
				}
			}System.out.println(count[i]);
		}
	}
}
