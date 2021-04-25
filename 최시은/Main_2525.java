import java.util.Scanner;

public class Main_2525 {
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		String time = sc.nextLine();
		String[] time_array = time.split(" ");

		Timer t = new Timer();

		t.HourSet(Integer.parseInt(time_array[0]));
		t.MinuteSet(Integer.parseInt(time_array[1]));

		t.TimerSet(sc.nextInt());

		System.out.println(t.result());
		sc.close();

	}

}

class Timer {
	int hour;
	int minute;
	int timer;

	void HourSet(int h) {
		if (h >= 0 && h <= 23) {
			hour = h;
		}
	}

	void MinuteSet(int m) {
		if (m >= 0 && m <= 59) {
			minute = m;
		}
	}

	void TimerSet(int t) {
		if (t >= 0 && t <= 1000) {
			timer = t;
		}
	}

	String result() {
		if (minute + timer >= 0 && minute + timer <= 59) {
			minute = minute + timer;
			return hour + " " + minute;
		} else {
			minute = minute + timer - 60;
			hour++;
			while (minute > 59) {
				minute = minute - 60;
				hour++;
			}

			if (hour > 23) {
				hour = hour - 24;
				return hour + " " + minute;
			} else {
				return hour + " " + minute;
			}
		}
	}
}