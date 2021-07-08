import java.util.*;

public class Main_3009 {

	public static void main(String[] args) {
		// TODO Auto-generated method stub
        Scanner sc = new Scanner(System.in);
        
        int x[] = new int[3];
        int y[] = new int[3];
        
        for(int i=0; i<3; i++) {
           x[i] = sc.nextInt();
           y[i] = sc.nextInt();
        }

        if(x[0]==x[1]){
        	if(y[0]==y[2]){
        	  System.out.println(x[2]+" "+y[1]);
        	}
        	if(y[1]==y[2]){
        	  System.out.println(x[2]+" "+y[0]);
        	}
        }
        if(x[0]==x[2]){
        	if(y[0]==y[1]){
        	  System.out.println(x[1]+" "+y[2]);
        	}
        	if(y[2]==y[1]){
        	  System.out.println(x[1]+" "+y[0]);
        	}       	
        }
        if(x[1]==x[2]){
        	if(y[1]==y[0]){
        	  System.out.println(x[0]+" "+y[2]);
        	}
        	if(y[2]==y[0]){
        	  System.out.println(x[0]+" "+y[1]);
        	}	
        }        
    }        
}
