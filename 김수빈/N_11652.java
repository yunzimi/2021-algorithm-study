import java.util.*;

public class N_11652 {

	public static void main(String[] args) {
		Scanner scan = new Scanner(System.in);
		int N = Integer.parseInt(scan.nextLine());
		Map<Long, Integer> map = new TreeMap<>();
		long input;
		for(int i = 0; i<N; i++){
			input = Long.parseLong(scan.nextLine());
			if(map.get(input)==null){
				map.put(input,1);
			}else{
				int temp = map.get(input)+1;
				map.put(input, temp);
			}
		}
		long max = 0;
		long answer = 0;
		for(Long l : map.keySet()){
			if(map.get(l)>max){
				max = map.get(l);
				answer = l;
			}
		}
		System.out.println(answer);

	}

}