import java.util.Scanner;

public class Main_1546 {

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		Scanner sc = new Scanner(System.in);
		
		int a = sc.nextInt();
		float[]b = new float[a];
		
		for(int i=0;i<a;i++){
			b[i]=sc.nextInt();
		}
		
		float max =b[0];
		
		for(int i=0; i<a;i++){
				if(b[i]>max){
					max = b[i];
				}
		}
	
		float[]c = new float[a];
		
		for(int i=0;i<a;i++){
			c[i]=(b[i]/max*100);
		}
		
		 float sum = 0;
		
		for(int i =0;i<a;i++){
			sum=sum+c[i];
		}
		System.out.println(sum/a);
	}
}
