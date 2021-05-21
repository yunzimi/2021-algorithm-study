package testarray;
import java.io.*;
import java.util.*;
class node implements Comparable<node> {
    int next, distance;
    public node(int n, int d)
    {
        this.next = n;
        this.distance = d;
    }

    @Override
    public int compareTo(node n)
    {
        return this.distance - n.distance;
    }
}
public class b1916 {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int n = Integer.parseInt(br.readLine());
        List<node>[] list = new List[n + 1];
        int[] cost = new int[n + 1];
        for(int i=1; i<=n; i++) 
        {
            cost[i] = Integer.MAX_VALUE;
            list[i] = new ArrayList<>();
        }
        int m = Integer.parseInt(br.readLine());
        for(int i=0; i<m; i++)
        {
            String[] s = br.readLine().split(" ");

            int a = Integer.parseInt(s[0]);
            int b = Integer.parseInt(s[1]);
            int c = Integer.parseInt(s[2]);

            list[a].add(new node(b,c));
        }
        String[] se = br.readLine().split(" ");
        int start = Integer.parseInt(se[0]);
        int end = Integer.parseInt(se[1]);

        f(list, cost, start);

        System.out.println(cost[end]);
    }

    public static void f(List<node>[] list, int[] cost, int start)
    {
        PriorityQueue<node> pq = new PriorityQueue<>();
        pq.add(new node(start, 0));
        

        while(!pq.isEmpty())
        {
            node a = pq.remove();
            int current = a.next;
            int currentdistacne = a.distance;

            int size = list[current].size();
            for(int i=0; i<size; i++)
            {
                node n = list[current].get(i);
                int next = n.next;
                int nextdistance = n.distance + currentdistacne;

                if(nextdistance < cost[next])
                {
                    cost[next] = nextdistance;
                    pq.add(new node(next, nextdistance));
                }
            }
            
        }
    }
}
