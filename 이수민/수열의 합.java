import java.util.*;
public class b1024 {
    public static void main(String[] args) {
        Scanner scan = new Scanner(System.in);

        String[] nl = scan.nextLine().split(" ");
        int n = Integer.parseInt(nl[0]);
        int l = Integer.parseInt(nl[1]);

        int left = 0;
        int right = 0;
        int sum = 0;

        int min=101,a=0,b=0;
        while(left <= right)
        {
            if(sum < n)
            {
                right++;
                sum += right;
            }
            else if(sum > n)
            {
                sum -= left;
                left++;
            }
            else
            {
                int len = right - left + 1;
                if(len >= l)
                {
                    if(min > len)
                    {
                        min = len;
                        a = left;
                        b = right;
                    }
                }
                sum -= left;
                left++;
            }
        }

        if(min == 101) System.out.println(-1);
        else for(int i=a;i<=b;i++) System.out.printf("%d ",i);
        scan.close();
    }
}