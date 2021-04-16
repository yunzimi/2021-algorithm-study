import java.util.Scanner;

public class Main_2744 {

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		Scanner sc = new Scanner(System.in);
		String input = sc.nextLine();

		for (int i = 0; i < input.length(); i++) {
			if ((int) input.charAt(i) >= 97) {
				int alphabet = (int) input.charAt(i) - 32;
				System.out.print((char) alphabet);
			} else {
				int alphabet = (int) input.charAt(i) + 32;
				System.out.print((char) alphabet);
			}
		}

	}

}
