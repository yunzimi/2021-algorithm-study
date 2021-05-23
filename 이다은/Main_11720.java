import java.util.Scanner;

public class Main_11720 {

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		Scanner sc = new Scanner(System.in);
		
		int a = sc.nextInt();
		String[]b = sc.next().split("");
		
		int[]c = new int[a];
		int sum = 0;
		
		for(int i=0;i<a;i++){
			c[i]=Integer.parseInt(b[i]);
			sum += c[i];
		}
		System.out.println(sum);
	}
}
