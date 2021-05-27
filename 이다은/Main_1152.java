import java.util.Scanner;

public class Main_1152 {

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		Scanner sc = new Scanner(System.in);
		
		String a = sc.nextLine().trim();
		
		String[]b = a.split(" ");
		
		if(a.isEmpty()){
		  System.out.println("0");	
		}
		else{
			if(b[0]==""){
				System.out.println(b.length-1);
			}
			else{
			  System.out.println(b.length);	
			}	
		}
	}
}


