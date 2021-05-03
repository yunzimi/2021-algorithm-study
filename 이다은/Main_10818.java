import java.util.Scanner;

public class Main_10818 {

	public static void main(String[] args) {
		// TODO Auto-generated method stub
       Scanner sc = new Scanner(System.in);
		
        int a = sc.nextInt();   
        int[]c = new int[a];
        
        for(int i=0;i<a;i++) {
         c[i]=sc.nextInt();
        }
        int max=c[0];
        int min=c[0];
        
        for(int j=0;j<a;j++){
        	if(c[j]>max) {
        		max = c[j];
        	}else if(c[j]<min) {
        		min = c[j];
        	}
        }System.out.print(min);
         System.out.print(" ");
         System.out.print(max);
        
	}

}
