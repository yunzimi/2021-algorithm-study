package github;

import java.util.Scanner;

public class Main_5622 {

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		Scanner sc = new Scanner(System.in);
		
		String a = sc.nextLine();
		
		String[] b = a.split("");
		int[] c = new int[b.length];
		int count = 0;
		
		for(int i=0;i<b.length;i++){
	      if(b[i].equals("A") || b[i].equals("B")|| b[i].equals("C")){
	    	  c[i]=2;
	    	  count +=3;
	      }if(b[i].equals("D") || b[i].equals("E")|| b[i].equals("F")){
	    	 c[i]=3;
	    	 count +=4;
	      }if(b[i].equals("G") || b[i].equals("H")|| b[i].equals("I")){
	    	 c[i]=4;
	    	 count +=5;
	      }if(b[i].equals("J") || b[i].equals("K")|| b[i].equals("L")){
	    	 c[i]=5;
	    	 count +=6;
	      }if(b[i].equals("M") || b[i].equals("N")|| b[i].equals("O")){
	    	 c[i]=6;
	    	 count +=7;
	      }if(b[i].equals("P") || b[i].equals("Q")|| b[i].equals("R")||b[i].equals("S")){
	    	 c[i]=7;
	    	 count +=8;
	      }if(b[i].equals("T") || b[i].equals("U")|| b[i].equals("V")){
	    	 c[i]=8;
	    	 count +=9;
	      }if(b[i].equals("W") || b[i].equals("X")|| b[i].equals("Y")||b[i].equals("Z")){
	    	 c[i]=9;
	    	 count +=10;
	      }
		}
		System.out.println(count);
	}
}

