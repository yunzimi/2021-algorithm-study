import java.util.*;
import java.io.*;

public class N_1655 {

	public static void main(String[] args) throws Exception, IOException {
		BufferedReader br= new BufferedReader(new InputStreamReader(System.in));
		PriorityQueue<Integer> min = new PriorityQueue<>();
		PriorityQueue<Integer> max = new PriorityQueue<>(Comparator.reverseOrder());
		StringBuilder sb = new StringBuilder();
		
		int N = Integer.parseInt(br.readLine());
		for(int i = 0; i<N; i++){
			int num = Integer.parseInt(br.readLine());
			if(max.size()==min.size()){
				max.add(num);
			}else{
				min.add(num);
			}
			if(!max.isEmpty()&&!min.isEmpty()){
				if(max.peek()>min.peek()){
					min.add(max.poll());
					max.add(min.poll());
				}
			}
			
			sb.append(max.peek()+"\n");
		}
		System.out.println(sb);

	}

}