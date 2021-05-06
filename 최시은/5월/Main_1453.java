import java.util.Scanner;

public class Main_1453 {

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		Scanner sc = new Scanner(System.in);		
		int num = Integer.parseInt(sc.nextLine());
		int[] seat = new int[100];
		int nope = 0;
		
		String client = sc.nextLine();
		String[] assigned = client.split(" ");
		
		
		for (int i = 0; i < num; i++) {
			if (seat[Integer.parseInt(assigned[i]) - 1] == Integer.parseInt(assigned[i])) {
				nope++;
				continue;
			}
			seat[Integer.parseInt(assigned[i]) - 1] = Integer.parseInt(assigned[i]);
		}
		System.out.println(nope);
		
	
	}

}
