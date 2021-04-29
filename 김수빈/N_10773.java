import java.util.ArrayList;
import java.util.List;
import java.util.Scanner;
	
public class N_10773 {
	
	public static void main(String[] args) {
		Scanner scan = new Scanner(System.in);
		List<Integer> list = new ArrayList<Integer>();
		int N = scan.nextInt();
		for(int i = 0; i<N;i++) {
			int a = scan.nextInt();
			if(i==0&&a==0) {
				continue;
			}
			if(a==0) {
				list.remove(list.size()-1);
			}else {
				list.add(a);
			}
		}
		int result = 0;
		for(int j = 0; j<list.size(); j++) {
			result+=list.get(j);
		}
		System.out.println(result);
		scan.close();
	}
}