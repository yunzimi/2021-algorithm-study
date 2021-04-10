import java.util.Scanner;

public class Main_2439 {

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		Scanner sc = new Scanner(System.in);
		int input = sc.nextInt();

		for (int i = input; i > 0; i--) {
			for (int j = i - 1; j > 0; j--) {
				System.out.print(" ");
			}
			for (int k = input - i + 1; k > 0; k--) {
				System.out.print("*");
			}

			System.out.println("");
		}

	}

}
