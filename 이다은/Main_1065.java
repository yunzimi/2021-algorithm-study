import java.util.Scanner;

public class Main_1065 {

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		Scanner sc = new Scanner(System.in);
		
		int a = sc.nextInt();
		
		int count = 0;
		
		for(int i=1;i<=a;i++){			
	     
			int a100 = i/100;
			int a10 = i%100/10;
			int a1 = i%100%10;
		   
			if(a100==0 && a10==0){   //1의 자리
				count++;	
		   }if(a100==0 && a10!=0){   //10의 자리
			   count++;	  
		   }if(a100!=0){            //100의 자리
			  if((a100-a10)==(a10-a1)){
				count++;  
			  }
		   }
		}
		System.out.println(count);
	}
}
