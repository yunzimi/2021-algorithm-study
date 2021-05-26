import java.util.Scanner;

public class Main_1157 {

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		Scanner sc = new Scanner(System.in);
		
		String a = sc.next();
		a = a.toUpperCase();
		
		int[]b = new int[26];
	    
		for(int i=0;i<a.length();i++){
		     b[(int)(a.charAt(i))-65]++;
		}//문자 아스키 코드롤 변환
		
		int max = b[0];
		int max_index = 0;
		int[]c = new int [1];
		
		for(int i=0;i<b.length;i++){
			if(max<b[i]){
				max=b[i];
				max_index = i;
			}
		}//가장 많이 나온 문자 찾기
		
		for(int i=0;i<b.length-1;i++){
			if(max==b[i]){
				c[0]++;
			}
		}
				
		if(c[0]>1){
			System.out.println("?");
		}else{
		   System.out.println((char)(max_index+65));
		}	
	}
}

