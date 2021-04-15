import java.util.Scanner;

public class Main_2953 {

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		int count = 1;
		int best_score = 0;
		int best_parti = 0;
		Scanner sc = new Scanner(System.in);
		
		while (count <= 5) {
			String parti = sc.nextLine();
			String[] score = parti.split(" ");
			int score_sum = 0;
			for (int i = 0; i < 4; i++) {
				score_sum += Integer.parseInt(score[i]);	
			}
			if (score_sum > best_score) {
				best_score = score_sum;
				best_parti = count;
			}
			count++;
		}
		System.out.println(best_parti + " " + best_score);
	}

}
