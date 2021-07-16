import java.util.*;

public class N_2293 {

	public static void main(String[] args) {
		Scanner scan = new Scanner(System.in);
		String[] input = scan.nextLine().split(" ");
		int N = Integer.parseInt(input[0]);
		int K = Integer.parseInt(input[1]);
		int[] coin = new int[N+1];
		int[] money = new int[K+1];
		for(int i = 1; i<N+1; i++){
			coin[i] = Integer.parseInt(scan.nextLine());
		}
		money[0] = 1;
		for(int i = 1; i<N+1; i++){
			for(int j = 1; j<K+1; j++){
				if(coin[i]<=j){
					money[j] += money[j-coin[i]];
				}
			}
		}
		System.out.println(money[K]);
	}

}
