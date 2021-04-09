import java.util.Scanner;

public class Main_2884 {

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		Scanner sc = new Scanner(System.in);
		int h = sc.nextInt();
		int m = sc.nextInt();

		m -= 45;
		while (m < 0) {
			m = 60 + m;
			h--;
			if (h > 24) {
				h = h - 24;
			} else if (h < 0) {
				h = h + 24;
			}
		}
		System.out.print(h);
		System.out.print(" ");
		System.out.print(m);

	}

}
