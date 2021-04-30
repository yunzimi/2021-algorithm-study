import java.util.Scanner;

public class Main_1157 {

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		Scanner sc = new Scanner(System.in);

		char[] Uppercase = { 'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K', 'L', 'M', 'N', 'O', 'P', 'Q', 'R',
				'S', 'T', 'U', 'V', 'W', 'X', 'Y', 'Z' };
		char[] Lowercase = { 'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p', 'q', 'r',
				's', 't', 'u', 'v', 'w', 'x', 'y', 'z' };

		int[] count = new int[26];

		String input = sc.next();

		for (int i = 0; i < input.length(); i++) {
			if (input.length() == 0) {
				break;
			}

			for (int j = 0; j < 26; j++) {

				if ((int) input.charAt(i) == (int) Uppercase[j]) {
					count[j]++;
					continue;
				} else if ((int) input.charAt(i) == (int) Lowercase[j]) {
					count[j]++;
					continue;
				}

			}

		}
		int best = 0;
		char result = '?';
		for (int i = 0; i < 26; i++) {
			if (input.length() == 1) {
				for (int j = 0; j < 26; j++) {

					if ((int) input.charAt(0) == (int) Uppercase[j]) {
						result = Uppercase[j];
						break;
					} else if ((int) input.charAt(0) == (int) Lowercase[j]) {
						result = Uppercase[j];
						break;
					}

				}
			} else if (0 == count[i] || 1 == count[i]) {
				continue;
			} else {
				if (best < count[i]) {
					best = count[i];
					result = Uppercase[i];
				} else if (best == count[i]) {
					result = '?';
				}

			}
		}
		System.out.println(result);

	}
}
