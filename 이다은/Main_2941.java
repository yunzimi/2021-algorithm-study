import java.util.*;

public class Main_2941 {

	public static void main(String[] args) {
		// TODO Auto-generated method stub
        Scanner sc = new Scanner(System.in);
        
        String a = sc.nextLine();
        
        a = a.replace("c=", "a");
        a= a.replace("c-", "a");
        a = a.replace("dz=", "a");
        a = a.replace("d-", "a");
        a= a.replace("lj", "a");
        a = a.replace("nj", "a");
        a = a.replace("s=", "a");
        a= a.replace("z=", "a");
        
        System.out.println(a.length());
     }
}


