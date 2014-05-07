import java.io.PrintWriter;
import java.util.Scanner;
import java.util.Vector;
import java.util.Arrays;
import java.util.PriorityQueue;
import java.util.Queue;
import java.io.IOException;

public class Main {
    private static final int MOD = (int)1e9+7;
    private static final int INF = (int)2e9+1;
    private static final int MAX_N = 1000;
    private static Scanner sc;
    private static PrintWriter pw;

    private static int getInt(){
        return Integer.parseInt(sc.next());
    }
    private static int[] getInts(final int n){
        final int[] res = new int[n];
        for(int i = 0; i < n; i++) res[i] = getInt();
        return res;
    }
    private static int[][] getInt2D(final int n, final int k) {
        final int[][] res = new int[n][];
        for(int i = 0; i < n; i++) res[i] = getInts(k);
        return res;
    }
    private static long getLong(){
        return Long.parseLong(sc.next());
    }
    private static long[] getLongs(final int n){
        final long[] res = new long[n];
        for(int i = 0; i < n; i++) res[i] = getLong();
        return res;
    }
    private static long[][] getLong2D(final int n, final int k) {
        final long[][] res = new long[n][];
        for(int i = 0; i < n; i++) res[i] = getLongs(k);
        return res;
    }
    private static void printInts(int[] ary){
        printInts(ary, ary.length);
    }
    private static void printInts(int[] ary, int n){
        for(int i = 0; i < n; i++)
            pw.printf("%d%c", ary[i], i==n-1? '\n' : ' ');
        pw.flush();
    }
    private static void printLongs(long[] ary){
        printLongs(ary, ary.length);
    }
    private static void printLongs(long[] ary, int n){
        for(int i = 0; i < n; i++)
            pw.printf("%d%c", ary[i], i==n-1? '\n' : ' ');
        pw.flush();
    }


    static void solve(){
    }

    static void doIt() {
        sc = new Scanner(System.in);
        pw = new PrintWriter(System.out);
        int t = 1;
        // t = sc.nextInt();
        while(0 < t){
            solve();
            t--;
        }
    }
    public static void main(String[] args) {
        doIt();
    }
}
