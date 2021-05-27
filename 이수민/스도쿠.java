package b2239;
import java.util.*;
public class b2239 {
    public static boolean isOk = true;
    public static void main(String[] args) {
        Scanner scan = new Scanner(System.in);
        int[][] arr = new int[9][9];
        for(int i=0; i<9; i++)
        {
            String[] s = scan.nextLine().split("");
            for(int j=0; j<9; j++)
            {
                arr[i][j] = Integer.parseInt(s[j]);
            }
        }

        f(arr,0,0);
        scan.close();
    }

    public static void f(int[][] arr, int x, int y)
    {
        if(!isOk) return;
        //System.out.println(x + " " + y + " " + arr[x][y]);
        if(arr[x][y] != 0)
        {
            // move
            if(y == 8)
            {
                if(x == 8)
                {
                    if(isOk)
                    {
                         output(arr);
                         isOk = false;
                    }
                    else return;
                }
                else
                {
                    f(arr, x+1, 0);
                }
            }
            else
            {
                f(arr, x, y+1);
            }
        }
        else
        {
            for(int k=1; k<=9; k++)
            {
                if(check(arr,x,y,k))
                {
                    
                    arr[x][y] = k;
                    //System.out.println(x + " " + y + " " + arr[x][y]);
                    if(y == 8)
                    {
                        if(x == 8)
                        {
                            if(isOk)
                            {
                                output(arr);
                                isOk = false;
                            }
                            else return;
                        }
                        else
                        {
                            f(arr, x+1, 0);
                        }
                    }
                    else
                    {
                        f(arr, x, y+1);
                    }
                }
                arr[x][y] = 0;
            }
        }
    }

    public static boolean check(int[][] arr, int x, int y, int n)
    {
        // 가로줄 
        for(int i=0; i<9; i++)
        {
            if(arr[x][i] == n) return false;
        }
        // 세로줄
        for(int i=0; i<9; i++)
        {
            if(arr[i][y] == n) return false;
        }
        // 같은 3x3 공간
        x /= 3;
        x *= 3;
        y /= 3;
        y *= 3;
        for(int i=x; i<x+3; i++)
        {
            for(int j=y; j<y+3; j++)
            {
                if(arr[i][j] == n) return false;
            }
        }
        return true;
    }

    public static void output(int[][] arr)
    {
        for(int i=0; i<9; i++)
        {
            for(int j=0; j<9; j++)
            {
                System.out.print(arr[i][j]);
            }
            System.out.println("");
        }
    }
}
