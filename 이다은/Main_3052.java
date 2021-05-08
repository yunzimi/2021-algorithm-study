package github;

import java.util.Scanner;
import java.util.ArrayList;

public class Main_3052 {

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		Scanner sc = new Scanner(System.in);
		ArrayList<Integer> list = new ArrayList<>();
		   
        int[]a = new int[10];
        
        for(int i=0;i<10;i++) {
         a[i]=(sc.nextInt()%42);
        }
        
        for(int j:a){
        	if(!list.contains(j)){
        		list.add(j);
        	}
        }System.out.println(list.size());     
	}
}
