import java.util.Scanner;

public class Main_4344 {

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		Scanner sc = new Scanner(System.in);
		
		 int a = sc.nextInt();
	 
		 for(int i=0;i<a;i++){
			 int c=sc.nextInt();
			 int [] score =new int [c];
			 int sum=0;
			 double aver = 0;
			 int count = 0;
			 for(int j=0;j<c;j++){
				score[j]=sc.nextInt();
				sum+=score[j];
		     }
			 aver=(sum/c);
			 double rate =0;
		     for(int k=0;k<c;k++){
			 if(aver<score[k]){
				 count++;
		     }
		     rate =(double)count/(double)c*100.0;
		   }
		    System.out.printf("%.3f", rate);
	        System.out.println("%");
      }
   }
}

