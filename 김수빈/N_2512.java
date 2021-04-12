import java.util.*;

public class N_2512 {

	public static void main(String[] args) {
		Scanner scan = new Scanner(System.in);
		
		
		int N = Integer.parseInt(scan.nextLine());
		
		int[] arr = new int[N];
		
		String[] input = scan.nextLine().split(" ");
		for(int i = 0; i<N; i++){
			arr[i] = Integer.parseInt(input[i]);
		}
		
		int M = Integer.parseInt(scan.nextLine());
		
		Arrays.sort(arr);
		
		int left = 1;
		int right = arr[N-1];
		int mid;
		long sum;
		
		while(left<=right){
			sum = 0;
			mid = (left + right)/2;
			
			for(int i = 0; i<N; i++){
				if(arr[i]>=mid){
					sum += mid;
				}else{
					sum += arr[i];
				}
			}
			
			if(sum > M){
				right = mid - 1;
			}else if( sum <= M){
				left = mid + 1;
			}
		}
		System.out.println(right);
		
		scan.close();
	}

}
