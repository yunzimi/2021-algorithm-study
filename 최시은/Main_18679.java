import java.util.Scanner;

public class Main_18679 {

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		Scanner sc = new Scanner(System.in);
		int num = Integer.parseInt(sc.nextLine());
		String[] eng = new String[num];
		String[] min = new String[num];

		for (int i = 0; i < num; i++) {
			String[] trans = sc.nextLine().split(" ");
			eng[i] = trans[0];
			min[i] = trans[2];

		}
		int sen = Integer.parseInt(sc.nextLine());

		for (int i = 0; i < sen; i++) {
			int words = Integer.parseInt(sc.nextLine());
			String[] sentence = sc.nextLine().split(" ");

			for (int j = 0; j < words; j++) {

				for (int k = 0; k < num; k++) {
					if (sentence[j].equals(eng[k])) {
						sentence[j] = min[k];
					}
				}
			}
			for (int l = 0; l < words; l++) {
				if(l == words - 1) {
					System.out.println(sentence[l]);
				} else {
					System.out.print(sentence[l] + " ");
				}
			}
		}

	}

}