import java.io.PrintWriter;
import java.util.Scanner;
import java.util.Vector;
import java.util.Arrays;
import java.util.PriorityQueue;
import java.util.Queue;
import java.io.IOException;

public class Main {

    static final int MOD = (int)1e9+7;
    static final int MAX_N = 1000;
    static Scanner sc;
    static PrintWriter pw;

    static int getInt() throws IOException{
        return Integer.parseInt(sc.next());
    }
    static int[] getInts(final int n) throws IOException{
        final int[] res = new int[n];
        for(int i = 0; i < n; i++) res[i] = getInt();
        return res;
    }
    static int[][] getInt2D(final int n, final int k) throws IOException {
        final int[][] res = new int[n][];
        for(int i = 0; i < n; i++) res[i] = getInts(k);
        return res;
    }

    static void solve(){
    }

    static void doIt() {
        sc = new Scanner(System.in);
        pw = new PrintWriter(System.out);
        int t = 1;
        // int t = sc.nextInt();
        while(0 < t){
            solve();
            t--;
        }
    }
    public static void main(String[] args) {
        doIt();
    }
}
