import java.util.*;
import java.io.*;

class nuggets {
    public static void main(String[] args) throws IOException {
        Scanner scan = new Scanner(new File("nuggets.in"));
        PrintWriter out = new PrintWriter(new File("nuggets.out"));
        int N = scan.nextInt();
        int[] nums = new int[N];
        HashSet<Integer> visited = new HashSet<Integer>();
        for(int i = 0; i < N; i++) {
            nums[i] = scan.nextInt();
            visited.add(nums[i]);
        }
        visited.add(0);
        Arrays.sort(nums);
        int max = nums[0]-1;
        int suc = 0;
        for(int i = nums[0]; suc != nums[0]; i++) {
            boolean visited = false;
            for(int j = 0; j < N; j++) {
                if(i-nums[j] >= 0) {
                    if(visited.contains(i-nums[j])) {
                        visited = true;
                        break;
                    }
                }
            }
            if(visited) {
                visited.add(i);
                suc += 1;
            }
            else {
                suc = 0;
            }
        }
        print.println(suc);
    }
}
