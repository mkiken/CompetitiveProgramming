// Codeforces Round #166 (Div. 2) B

import java.io.PrintWriter;
import java.util.Arrays;
import java.util.Scanner;
import java.util.TreeMap;

public class B {
	static final int MAX = 100500;

	public static void main(String[] args) {
		doIt();
	}

	static void doIt() {
		Scanner sc = new Scanner(System.in);
		PrintWriter pw = new PrintWriter(System.out);
		boolean[] prime = new boolean[MAX];
		Arrays.fill(prime, true);
		prime[0] = prime[1] = false;
		TreeMap<Integer, Integer> map = new TreeMap<Integer, Integer>();
		for (int i = 2; i < prime.length; i++) {
			if(prime[i]){
				map.put(i, 0);
				for (int j = i*2; j < prime.length; j += i) {
					prime[j] = false;
				}
			}
		}
		int n = sc.nextInt();
		int m = sc.nextInt();
		int[][] matrix = new int[n][m];
		int[] rowsum = new int[n];
		int[] clmsum = new int[m];
		for (int i = 0; i < n; i++) {
			for(int j = 0; j < m; j++) {
				int e = sc.nextInt();
				if(prime[e]) matrix[i][j] = 0;
				else matrix[i][j] = map.ceilingKey(e) - e;
				rowsum[i] += matrix[i][j];
				clmsum[j] += matrix[i][j];
			}
		}
		Arrays.sort(rowsum);
		Arrays.sort(clmsum);
		System.out.println(Math.min(rowsum[0], clmsum[0]));
		
	}
}
