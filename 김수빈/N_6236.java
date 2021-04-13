import java.util.*;

public class N_6236 {

	public static void main(String[] args) {
		Scanner scan = new Scanner(System.in);
		
		String[] input = scan.nextLine().split(" ");
		int N = Integer.parseInt(input[0]);
		int M = Integer.parseInt(input[1]);
		int max = 0;
		int[] arr = new int[N];
		for(int i = 0; i<N; i++){
			arr[i] = Integer.parseInt(scan.nextLine());
			max = Math.max(max, arr[i]);
		}
		
		
		int left = 1;
		int right = N*max;
		int mid = 0;
		int count = 0;
		int check = 0;
		int answer = Integer.MAX_VALUE;
		
		a:while(left<=right){
			mid = (left + right) / 2;
			count = 1;
			check = mid;
			for(int i = 0; i<N; i++){
				if(check - arr[i] >= 0){
					check -= arr[i];
				}else{
					check = mid;
					
					check -= arr[i];
					
					if(check < 0){
						left = mid + 1;
						continue a;
					}
					count++;
					
				}
			}
			if(count > M){
				left = mid + 1;
			}else{
				answer = Math.min(answer, mid);
				right = mid - 1;
			}
		}
		System.out.println(answer);
	}
	

}
