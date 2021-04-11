import java.util.*;

public class N_1654 {

	public static void main(String[] args) {
		Scanner scan = new Scanner(System.in);
		
		String[] input = scan.nextLine().split(" ");
		int K = Integer.parseInt(input[0]);
		int N = Integer.parseInt(input[1]);
		
		long[] arr = new long[K];
		
		for(int i = 0; i<K; i++){
			arr[i] = Integer.parseInt(scan.nextLine());
		}
		
		Arrays.sort(arr);
		
		long count;
		long left = 1;
		long right = arr[K-1];
		long mid;
		
		while(left <= right){
			count = 0;
			mid = (left + right)/2;
			
			for(int i = 0; i<K; i++){
				count += arr[i]/mid;
			}
			
			if(count >= N){
				left = mid + 1;
			}else if( count < N){
				right = mid - 1;
			}
		}
		
		System.out.println(right);

	}

}
