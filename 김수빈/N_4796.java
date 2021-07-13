import java.util.*;

public class N_4796 {
	static int cal(int L, int P, int V){
		int temp = V / P;
		int swap = V % P;
		if(L < swap){
			swap = L;
		}
		int answer = temp * L + swap; 
		return answer;
	}
	public static void main(String[] args) {
		Scanner scan = new Scanner(System.in);
		int i = 1;
		while(true){
			String[] input = scan.nextLine().split(" ");
			int L = Integer.parseInt(input[0]);
			int P = Integer.parseInt(input[1]);
			int V = Integer.parseInt(input[2]);
			if(L==0&&P==0&&V==0){
				break;
			}
			int answer = cal(L,P,V);
			System.out.println("Case "+i+": "+answer);
			i++;
		}
		scan.close();
	}

}