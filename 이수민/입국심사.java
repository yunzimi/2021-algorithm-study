import java.util.*;
import java.io.*;
public class b3079 {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        String[] s = br.readLine().split(" ");
        int n = Integer.parseInt(s[0]);
        int m = Integer.parseInt(s[1]);
        int[] arr = new int[n];
        for(int i=0; i<n; i++)
        {
            arr[i] = Integer.parseInt(br.readLine());
        }
        Arrays.sort(arr);

        long left = 0;
        long right = arr[arr.length - 1] * (long)m;
        System.out.println(right);
        long output = Long.MAX_VALUE; 
        while(left <= right)
        {
            long mid = (left+right) / 2;
            long cnt = 0;
            
            for(int i=0; i<n; i++)
            {
                cnt += mid / arr[i];
                if(cnt >= m) break;
            }
            if(cnt >= m)
            {
                output = output > mid ? mid : output;
                right = mid - 1;
            }
            else 
            {
                left = mid + 1;
            }
        }
        System.out.println(output);
        br.close();
    }
}
