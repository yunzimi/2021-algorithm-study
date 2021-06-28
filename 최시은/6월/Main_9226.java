import java.util.Scanner;

public class Main_9226 {

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		Scanner sc = new Scanner(System.in);

		while (true) {
			String input = sc.next();

			if (input.length() <= 20) {

				if (input.equals("#")) {
					break;
				}

				StringBuffer sb = new StringBuffer(input);

				for (int i = 0; i < input.length(); i++) {

					if ((sb.charAt(0) == 'a') || (sb.charAt(0) == 'e') || (sb.charAt(0) == 'i') || (sb.charAt(0) == 'o')
							|| (sb.charAt(0) == 'u')) {
						System.out.println(sb + "ay");
						break;
					}

					else {
						if (i == input.length() - 1) {
							System.out.println(input + "ay");
							break;
						}
						
						sb.append(sb.charAt(0));
						sb.deleteCharAt(0);
					}
				}
			}

		}
	}

}
