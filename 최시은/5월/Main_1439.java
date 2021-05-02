import java.util.Scanner;

public class Main_1439 {

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		Scanner sc = new Scanner(System.in);
		String input = sc.next();
		String[] bin = input.split("");
		int count = 0;

		boolean changed = false;

		for (int i = 0; i < bin.length; i++) {

			if (Integer.parseInt(bin[0]) != Integer.parseInt(bin[i])) {
				changed = true;
				count++;
				

				while (changed == true) {
					if (Integer.parseInt(bin[0]) != Integer.parseInt(bin[bin.length - 1]) && i == bin.length - 1) {
						changed = false;
						break;
					}

					if (Integer.parseInt(bin[0]) == Integer.parseInt(bin[i])) {
						changed = false;
						break;
					}
					i++;

				}
			}

		}

		System.out.println(count);

	}

}
