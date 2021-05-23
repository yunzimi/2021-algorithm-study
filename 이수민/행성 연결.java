package b16398;
import java.util.*;
class node implements Comparable<node> {
    int a,b,c;

    public node(int a, int b, int c)
    {
        this.a=a;
        this.b=b;
        this.c=c;
    }

    @Override
    public int compareTo(node n)
    {
        return this.c - n.c;
    }
}
public class b16398 {
    public static void main(String[] args) {
        Scanner scan = new Scanner(System.in);
        List<node> list = new ArrayList<>();
        int n = Integer.parseInt(scan.nextLine());
        int[] parent = new int[n + 1];
        for(int i=1; i<=n; i++) parent[i] = i;
        for(int i=1; i<=n; i++)
        {
            String[] s = scan.nextLine().split(" ");
            for(int j=i+1; j<=n; j++)
            {
                int k = Integer.parseInt(s[j - 1]);
                list.add(new node(i,j,k));
            }
        }

        Collections.sort(list);
        long sum = 0;
        for(node nn : list)
        {
            if(getparent(parent, nn.a) != getparent(parent, nn.b))
            {
                sum += nn.c;
                unionparent(parent, nn.a, nn.b);
            }
        }
        System.out.println(sum);
        scan.close();
    }

    public static int getparent(int[] parent, int x)
    {
        if(parent[x] == x) return x;
        return parent[x] = getparent(parent, parent[x]);
    }

    public static void unionparent(int[] parent, int a, int b)
    {
        a = getparent(parent,a);
        b = getparent(parent,b);

        if(a < b) parent[b] = a;
        else parent[a] = b;
    }
}
