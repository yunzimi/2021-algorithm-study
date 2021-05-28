import java.util.Scanner;

public class Main_2908 {

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		Scanner sc = new Scanner(System.in);

		int a = sc.nextInt();
		int b = sc.nextInt();
		
		int a_reverse = (a%100%10*100)+(a%100/10*10)+a/100;
		int b_reverse = (b%100%10*100)+(b%100/10*10)+b/100;
		
		if(a_reverse>b_reverse){
		   System.out.println(a_reverse);
		}else{
		   System.out.println(b_reverse); 	
		}
	}	
}
