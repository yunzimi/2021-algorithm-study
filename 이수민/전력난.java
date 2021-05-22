package b6497;
import java.util.*;
import java.io.*;
class node implements Comparable<node> {
    int a,b,c;

    public node(int a, int b, int c)
    {
        this.a = a;
        this.b = b;
        this.c = c;
    }

    @Override
    public int compareTo(node n)
    {
        return this.c - n.c;
    }
}
public class b6497 {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        while(true)
        {
            String[] nm = br.readLine().split(" ");
            int n = Integer.parseInt(nm[0]);
            int m = Integer.parseInt(nm[1]);
            if(n == 0 && m == 0) break;
            List<node> list = new ArrayList<>();
            int[] parent = new int[n + 1];
            int Allsum = 0;
            for(int i=0; i<n; i++) parent[i] = i;
            for(int i=0; i<m; i++)
            {
                String[] s = br.readLine().split(" ");
                int a = Integer.parseInt(s[0]);
                int b = Integer.parseInt(s[1]);
                int c = Integer.parseInt(s[2]);
                Allsum += c;
                list.add(new node(a,b,c));
            }

            Collections.sort(list);
            int sum = 0;
            for(node nn : list)
            {
                int a = nn.a;
                int b = nn.b;
                int c = nn.c;

                if(getparent(parent,a) != getparent(parent,b))
                {
                    sum += c;
                    unionparent(parent,a,b);
                }
            }
            System.out.println(Allsum - sum);
        }
    }

    public static int getparent(int[] parent, int x)
    {
        if(parent[x] == x) return x;
        return parent[x] = getparent(parent,parent[x]);
    }

    public static void unionparent(int[] parent, int a, int b)
    {
        a = getparent(parent, a);
        b = getparent(parent, b);
        if(a < b) parent[b] = a;
        else parent[a] = b;
    }
}
