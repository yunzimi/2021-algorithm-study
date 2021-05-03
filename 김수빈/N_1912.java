import java.util.*;

public class N_1912 {

	public static void main(String[] args) {
		Scanner scan = new Scanner(System.in);
		int N = Integer.parseInt(scan.nextLine());
		String[] str = scan.nextLine().split(" ");
		int[] input = new int[N];
		for(int i = 0; i<N;i++){
			input[i] = Integer.parseInt(str[i]);
		}
		int result = dp(input);
		System.out.println(result);

	}
	public static int dp(int[] arr){
		int n = arr.length;
		int sum = Integer.MIN_VALUE;
		int partialsum = 0;
		
		for(int k = 0; k<n;k++){
			partialsum = Math.max(arr[k], partialsum+arr[k]);
			sum = Math.max(sum, partialsum);
		}
		
		return sum;
	}

}