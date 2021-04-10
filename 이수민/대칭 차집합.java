import java.util.*;
import java.io.*;

public class b1269 {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
        HashSet<String> set1 = new HashSet<>();
        HashSet<String> set2 = new HashSet<>();

        HashSet<String> sub1;
        HashSet<String> sub2;

        String[] s = br.readLine().split(" ");
        int a = Integer.parseInt(s[0]);
        int b = Integer.parseInt(s[1]);

        String[] ss = br.readLine().split(" ");
        for(String str : ss) set1.add(str);

        String[] sss = br.readLine().split(" ");
        for(String str : sss) set2.add(str);

        sub1 = new HashSet<>(set1);
        sub1.removeAll(set2);

        sub2 = new HashSet<>(set2);
        sub2.removeAll(set1);

        int size = sub1.size() + sub2.size();
        bw.write(String.valueOf(size));
        bw.newLine();

        bw.close();
        br.close();
    }
}
