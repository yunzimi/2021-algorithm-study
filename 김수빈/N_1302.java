import java.util.*;

public class N_1302 {

	public static void main(String[] args) {
		Scanner scan = new Scanner(System.in);
		int N = Integer.parseInt(scan.nextLine());
		Map<String, Integer> map = new TreeMap<>();
		String input;
		
		for(int i = 0; i<N; i++){
			input = scan.nextLine();
			if(map.get(input)==null){
				map.put(input, 1);
			}else{
				int freq = map.get(input)+1;
				map.put(input, freq);
			}
		}
		
		int max = 0;
		
		String answer="";
		for(String s : map.keySet()){
			if(map.get(s)>max){
				max = map.get(s);
				answer = s;
			}
		}
		System.out.println(answer);
	}

}
