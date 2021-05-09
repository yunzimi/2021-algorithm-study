import java.util.Scanner;

public class Main_2386 {

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		Scanner sc = new Scanner(System.in);

		while (true) {
			String input = sc.nextLine();

			String[] spl = input.split(" ");
			char alpha = spl[0].charAt(0);
			if (alpha == '#') {
				break;
			}

			int count = 0;
			for (int i = 1; i < spl.length; i++) {

				for (int j = 0; j < spl[i].length(); j++) {

					if (alpha == spl[i].charAt(j) || alpha - 32 == spl[i].charAt(j)) {
						count++;
					}
				}
			}
			System.out.println(alpha + " " + count);

		}
	}

}
