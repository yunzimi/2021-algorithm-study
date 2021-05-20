package github;

public class Main_4673 {

	static int a = 10000;
	static int[]b = new int[a+1];
	
	public static void main(String[] args) {
		// TODO Auto-generated method stub
		
		for(int i =1;i<a+1;i++){
		         d(i);
		}
		for(int i=1;i<a+1;i++){
			if(b[i]==0){
				System.out.println(i);
			}	
		}
	}
		
		public static void d(int c){
			
			int sum = c;
			
			while(c!=0){
				int e = c%10;
				c/=10;
				sum+=e;
			}
			if(sum<=a){
				b[sum]=1;
			}
		
	}
}


	