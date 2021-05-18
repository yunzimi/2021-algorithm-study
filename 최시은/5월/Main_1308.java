import java.util.Scanner;

public class Main_1308 {

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		Scanner sc = new Scanner(System.in);
		
		String start = sc.nextLine();
		String[] start_spl = start.split(" ");
		
		int start_y = Integer.parseInt(start_spl[0]);
		int start_m = Integer.parseInt(start_spl[1]);
		int start_d = Integer.parseInt(start_spl[2]);
		
		String end = sc.nextLine();
		String[] end_spl = end.split(" ");
		int end_y = Integer.parseInt(end_spl[0]);
		int end_m = Integer.parseInt(end_spl[1]);
		int end_d = Integer.parseInt(end_spl[2]);
		
		int y = start_y;
		int m = start_m;
		int d = start_d;
		
		
		int d_day = 0;

		boolean limited = false;
		boolean leapyear = false;
		
		while (true) {
			
			if (limited == true) {
				break;
			}
			
			if (y == end_y && m == end_m && d == end_d) {
				break;
			}
			
			if (y % 4 == 0) {
				
				if (y % 100 == 0) {
					
					if (y % 400 == 0) {
						leapyear = true;
					} else {
						leapyear = false;
					}
				} else {
					leapyear = true;
				}
			} else {
				leapyear = false;
			}
			
			d_day++;
			d++;
			
			if (leapyear == true && m == 2 && d == 30) {
				m++;
				d = 1;
			}
			
			if (leapyear == false && m ==2 && d == 29) {
				m++;
				d = 1;
			}
			
			if ((m == 4 || m == 6 || m == 9 || m == 11) && (d == 31)) {
				m++;
				d = 1;
			}
			
			if ((m == 1 || m == 3 || m == 5 || m == 7 || m == 8 || m == 10) && (d == 32)) {
				m++;
				d = 1;
			}
			
			if (m == 12 && d == 32) {
				y++;
				m = 1;
				d = 1;
			}
			
			if (start_y + 1000 == y) {
				
				if (start_m == m) {
					
					if (start_d == d) {
						
						limited = true;
					}
				}
			}
			
		}
		
		if (limited == false) {
			System.out.println("D-" + d_day);
		} else {
			System.out.println("gg");
		}
		
	}

}
