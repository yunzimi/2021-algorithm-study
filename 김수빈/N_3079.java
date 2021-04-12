import java.util.*;

public class N_3079 {

	public static void main(String[] args) {
		Scanner scan = new Scanner(System.in);
		
		String[] input = scan.nextLine().split(" ");
		long N = Long.parseLong(input[0]);
		long M = Long.parseLong(input[1]);
		
		long[] arr = new long[(int) N];
		
		for(int i = 0; i<N; i++){
			arr[i] = Integer.parseInt(scan.nextLine());
		}
		
		Arrays.sort(arr);
		
		long left = 1;
		long right = arr[(int) (N-1)]*M;
		long mid;
		long answer = right;
		long people;
		
		while(left <= right){
			people = 0;
			mid = (left+right)/2;
			for(int i = 0; i<N; i++){
				people += mid / arr[i];
			}
			if(people >= M){
				answer = Math.min(answer, mid);
				right = mid - 1;
			}else if(people < M){
				left = mid + 1;
			}
		}
		System.out.println(answer);
		

	}

}
