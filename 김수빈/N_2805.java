import java.util.*;

public class N_2805 {

	public static void main(String[] args) {
		Scanner scan = new Scanner(System.in);
		
		String[] input = scan.nextLine().split(" ");
		int N = Integer.parseInt(input[0]);
		int M = Integer.parseInt(input[1]);
		
		int[] arr = new int[N];
		
		input = scan.nextLine().split(" ");
		
		for(int i = 0; i<N; i++){
			arr[i] = Integer.parseInt(input[i]);
		}
		
		Arrays.sort(arr);
		
		long height;
		int left = 1;
		int right = arr[N-1];
		int mid;
		
		while(left <= right){
			height = 0;
			mid = (left + right)/2;
			
			for(int i = 0; i<N; i++){
				if(arr[i]>=mid){
					height += arr[i]-mid;
				}
			}
			
			if(height>=M){
				left = mid+1;
			}else if(height < M){
				right = mid - 1;
			}
		}
		
		System.out.println(right);
		
		scan.close();
	}

}