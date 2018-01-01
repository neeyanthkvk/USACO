import java.util.*;
import java.io.*;
/*
PROG: telecow
LANG: JAVA
*/
public class telecow {
    public static void main(String[] args) throws IOException{
        Scanner scan = new Scanner(new File("telecow.in"));
        PrintWriter pw = new PrintWriter(new File("telecow.out"));
        int N = scan.nextInt();
        int M = scan.nextInt();
        int c1 = scan.nextInt();
        int c2 = scan.nextInt();
        HashMap<Integer, HashSet<Integer>> graph = new HashMap<Integer, HashSet<Integer>>();
        for(int i = 0; i < M; i++) {
            int temp1 = scan.nextInt();
            int temp2 = scan.nextInt();
            if(graph.containsKey(temp1)) {
                graph.get(temp1).add(temp2);
            }
            else {
                graph.put(temp1, new HashSet<Integer>());
                graph.get(temp1).add(temp2);
            }
            if(graph.containsKey(temp2)) {
                graph.get(temp2).add(temp1);
            }
            else {
                graph.put(temp2, new HashSet<Integer>());
                graph.get(temp2).add(temp1);
            }
        }
        LinkedList<State> queue = new LinkedList<State>();
        ArrayList<State> answers = new ArrayList<State>();
        queue.add(new State(c1));
        boolean found = false;
        int ans = -1;
        while(queue.size() != 0) {
            State curr = queue.pop();
            if(found == true && curr.path.size() > ans) {
                break;
            }
            if(curr.path.get(curr.path.size()-1) == c2) {
                found = true;
                ans = curr.path.size();
                answers.add(curr);
            }
            if(!found) {
                HashSet<Integer> neigh = graph.get(curr.path.get(curr.path.size()-1));
                Iterator<Integer> iter = neigh.iterator();
                while(iter.hasNext()) {
                    int temp = iter.next();
                    State temp2 = new State(curr, temp);
                    queue.push(temp2);
                }
            }
        }
        pw.println((ans-2));
        int index = 0;
        while(answers.size() != 1) {
            int min = N;
            for(State s: answers) {
                min = Math.min(min, s.path.get(index));
            }
            ArrayList<State> answer2 = new ArrayList<State>();
            for(State s: answers) {
                if(s.path.get(index) == min) {
                    answer2.add(s);
                }
            }
            answers = answer2;
        }
        for(int i = 1; i < answers.get(0).path.size()-2; i++) {
            pw.print(answers.get(0).path.get(i) + " ");
        }
        pw.println(answers.get(0).path.get(answers.get(0).path.size()-2));
        pw.flush();
    }
}

class State {
    ArrayList<Integer> path;
    public State(int n) {
        path = new ArrayList<Integer>();
        path.add(n);
    }
    public State(State old, int next) {
        path = new ArrayList<Integer>();
        for(int x:old.path) {
            path.add(x);
        }
        path.add(next);
    }
}
