import java.util.*;

class State {
    String input;
    int value;

    public State(String input, int value)
    {
        this.input = input;
        this.value = value;
    }

    public int Output()
    {
        if(value == 0)
        {
            if(input.equals("(")) return 2;
            else return 3;
        }
        else
        {
            if(input.equals("(")) return value * 2;
            else return value * 3;
        }
    }

    
}
public class b2504 {
    public static void main(String[] args) {
        Scanner scan = new Scanner(System.in);
        String[] arr = scan.nextLine().split("");
        Stack<State> stack = new Stack<>();
        boolean isOk = true;
        stack.add(new State("",0));
        for(String s : arr)
        {
            if(s.equals("(") || s.equals("["))
            {
                stack.add(new State(s,0));
            }
            else if(s.equals(")"))
            {
                if(stack.peek().input.equals("("))
                {
                    int value = stack.pop().Output();
                    stack.peek().value += value;
                }
                else
                {
                    isOk = false;
                }
            }
            else if(s.equals("]"))
            {
                if(stack.peek().input.equals("["))
                {
                    int value = stack.pop().Output();
                    stack.peek().value += value;
                }
                else
                {
                    isOk = false;
                }
            }
        }
    
        if(!isOk || stack.size() != 1) System.out.println(0);
        else System.out.println(stack.pop().value);

        scan.close();
    }
}
