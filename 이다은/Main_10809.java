import java.util.Scanner;

public class Main_10809 {

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		Scanner sc = new Scanner(System.in);
		
		String s = sc.next();
		
		int[]a = new int [26];
		
		for(int i=0;i<a.length;i++){
			a[i]=-1;
		}
		
		for(int i=s.length()-1;i>-1;i--){
			int b = s.charAt(i)-97;
			a[b]=i;
		}
		for(int i=0;i<a.length;i++){
			System.out.print(a[i]+" ");
		}
	}
}
