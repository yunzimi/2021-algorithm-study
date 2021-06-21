import java.util.*;

public class Main_2739 {

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		Scanner sc = new Scanner(System.in);
		
		int num = sc.nextInt();
		
		if (num >= 1 || num <= 2) {
			for (int i = 1; i <= 9; i++) {
				System.out.printf("%d * %d = %d%n", num, i, num * i);
			}
		}
		
	}

}
