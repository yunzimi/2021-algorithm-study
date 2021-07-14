import java.util.*;

public class N_12865 {
	

	public static void main(String[] args) {
		Scanner scan = new Scanner(System.in);
		
		String[] input = scan.nextLine().split(" ");
		int N = Integer.parseInt(input[0]);
		int K = Integer.parseInt(input[1]);
		
		int[] W = new int[N+1];
		int[] V = new int[N+1];
		int[][] dp = new int[N+1][K+1];
		
		for(int i = 1; i<N+1; i++){
			input = scan.nextLine().split(" ");
			W[i] = Integer.parseInt(input[0]);
			V[i] = Integer.parseInt(input[1]);
		}
		
		for(int i = 0; i<=N; i++){
			dp[i][0] = 0;
		}
		for(int i = 0; i<=K; i++){
			dp[0][i] = 0;
		}
		int max = 0;
		for(int i = 1; i<K+1; i++){
			for(int j = 1; j<N+1; j++){
				if(W[j] > i){
					dp[j][i] = dp[j-1][i];
				}else{
					dp[j][i] = Math.max(dp[j-1][i], dp[j-1][i-W[j]]+V[j]);
				}
				max = Math.max(max, dp[j][i]);
			}
		}
		System.out.println(max);
		
		
		scan.close();
	}

}