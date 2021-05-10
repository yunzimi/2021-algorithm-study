import java.util.Scanner;

public class Main_1475 {

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		Scanner sc = new Scanner(System.in);

		String num = sc.next();

		int[] numnum = new int[10];
		int count = 0;

		for (int i = 0; i < num.length(); i++) {

			for (int j = 0; j < 10; j++) {

				if (j == num.charAt(i) - 48) {

					numnum[j]++;

					if ((numnum[j] > count) && (j != 6) && (j != 9)) {

						count = numnum[j];

					}
					if (((numnum[6] + numnum[9]) / 2) + ((numnum[6] + numnum[9]) % 2) > count) {
						count = (numnum[6] + numnum[9]) / 2 + (numnum[6] + numnum[9]) % 2;
					}
				}
			}
		}
		System.out.println(count);
	}

}
