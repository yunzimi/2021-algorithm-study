import java.util.*;
import java.io.*;

public class N_4949 {

	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		String input;
		boolean answer;
		
		while(true){
			input = br.readLine();
			
			if(input.equals(".")){
				break;
			}
			
			char[] arr = input.toCharArray();
			Stack<Character> stack = new Stack<>();
			answer = true;
			
			for(int i = 0; i<arr.length; i++){
				if(arr[i]=='('){
					stack.add(arr[i]);
				}else if(arr[i]=='['){
					stack.add('[');
				}else if(arr[i]==')' && !stack.isEmpty() && stack.peek()=='('){
					stack.pop();
				}else if(arr[i]==']' && !stack.isEmpty() && stack.peek()=='['){
					stack.pop();
				}else if(arr[i]==')'||arr[i]==']'){
					answer = false;
					break;
				}
			}
			if(!stack.isEmpty()){
				answer = false;
			}
			
			if(answer){
				System.out.println("yes");
			}else{
				System.out.println("no");
			}
		}

	}

}
