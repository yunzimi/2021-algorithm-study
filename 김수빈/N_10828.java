import java.util.*;
import java.io.*;


public class N_10828 {
		public static void main(String[] args) throws IOException{
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		List<Integer> list = new LinkedList<Integer>();
		int N = Integer.parseInt(br.readLine());
		for(int i = 0; i<N; i++) {
			String[] s = br.readLine().split(" ");
			if(s[0].equals("push")) {
			    list.add(Integer.parseInt(s[1]));
			}
			if(s[0].equals("top")) {
				if(list.isEmpty()) {
					System.out.println(-1);
				}else {
					System.out.println(list.get(list.size()-1));
				}
			}
			if(s[0].equals("size")) {
				System.out.println(list.size());
			}
			if(s[0].equals("empty")) {
				if(list.isEmpty()) {
					System.out.println(1);
				}else {
					System.out.println(0);
				}
			}
			if(s[0].equals("pop")) {
				if(list.isEmpty()) {
					System.out.println(-1);
				}else {
					System.out.println(list.remove(list.size()-1));
				}
			}
		}
        br.close();
		
	}
}