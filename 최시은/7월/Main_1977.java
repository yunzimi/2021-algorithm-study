import java.util.Scanner;

public class Main_1977 {

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		Scanner sc = new Scanner(System.in);
		int a = sc.nextInt();
		int b = sc.nextInt();
		
		if (a <= 10000 && b <= 10000 && a <= b) {
			int range;
			int min = 0;
			int sum = 0;
			
			if (a < 2500) {
				if (a < 625) {
					range = 0;
				} else {
					range = 25;
				}
			} else {
				if (a < 5625) {
					range = 50;
				} else {
					range = 75;
				}
			}
			
			boolean bo = false;
			
			while (range * range <= b) {
				if (range * range < a) {
					range++;
					continue;
				} else if (bo == false && range * range >= a) {
					bo = true;
					min = range * range;
					sum += range * range;
					range++;
				} else {
					sum += range * range;
					range++;
				}
			}
			
			if (bo == true) {
				System.out.println(sum);
				System.out.println(min);
			} else {
				System.out.println(-1);
			}
			
			
		}
	}

}
