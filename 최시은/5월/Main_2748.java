import java.util.Scanner;

public class Main_2748 {
	
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		Fibo fb = new Fibo();
		
		long num = sc.nextLong();
		System.out.println(fb.seq(num));
	}

}

class Fibo {
	long sn1 = 0;
	long sn2 = 1;

	long seq(long num) {
		long result = 0;
		if (num == 0)
			return 0;
		else if (num == 1) {
			return 1;
		}

		else {
			for (int i = 1; i < num; i++) {
				result = sn1 + sn2;
				sn1 = sn2;
				sn2 = result;
			}

		}
		return result;
	}

}