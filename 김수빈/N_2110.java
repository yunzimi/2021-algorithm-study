import java.util.*;

public class N_2110 {

	public static void main(String[] args) {
		Scanner scan = new Scanner(System.in);
		
		String[] input = scan.nextLine().split(" ");
		long N = Long.parseLong(input[0]);
		long C = Long.parseLong(input[1]);
		
		long[] arr = new long[(int)N];
		
		for(int i = 0; i<N; i++){
			arr[i] = Long.parseLong(scan.nextLine());
		}
		Arrays.sort(arr);
		
		long left = 1;
		long right = arr[(int)N-1]-arr[0];
		long mid;
		long answer = 0;
		
		while(left <= right){
			long pre = arr[0];
			long count = 1;
			mid = (left + right) / 2;
			for(int i = 0; i<N; i++){
				if(arr[i] - pre >= mid){
					count++;
					pre = arr[i];
				}
				
			}
			
			if(count >= C){
				answer = Math.max(answer, mid);
				left = mid + 1;
			}else{
				right = mid - 1;
			}
		}
		System.out.println(answer);

	}

}