import java.util.*;
import java.io.*;

public class B {
    public static void main(String[] args) {
        Scanner scan = new Scanner(System.in);
        int n = scan.nextInt();
        int[] arr = new int[n];
        HashSet<Integer> nums = new HashSet<Integer>();
        for(int i = 0; i < n; i++) {
            int temp = scan.nextInt();
            arr[i] = temp;
            nums.add(temp);
        }
        int index = n-1;
        while(nums.size() != 1) {
            int temp = arr[index];
            index -= 1;
            nums.remove(temp);
        }
        Iterator<Integer> iter = nums.iterator();
        int answer = iter.next();
        System.out.println(answer);
        
    }
}
