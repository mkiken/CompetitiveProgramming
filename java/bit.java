// http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=1175&lang=jp

import java.util.Scanner;

public class Q1175 {
	static Scanner sc = new Scanner(System.in);
	static int n;
	static int r[];
	static int x[];
	static int y[];
	static int c[];

	static boolean dp[];
	static boolean table[][];

	static void solve() {
		dp[0] = true;

		makeTable();
		int len = 1 << n;
		for(int bit = 0; bit < len; bit++){
			if(dp[bit]){
				for (int s = 0; s < n; s++) {
					if ((bit >> s & 1) == 0) {
						for (int k = s + 1; k < n; k++) {
							if ((bit >> k & 1) == 0) {
								if (canGet(bit, s, k)) {
									dp[bit + (1 << s) + (1 << k)] = true;
								}
							}
						}
					}
				}
			}
		}

		printAns();
	}

	static void printAns() {
		int max = 0;
		for (int i = 0; i < dp.length; i++) {
			if (dp[i]) {
				// iの1の数を計算
				int count = 0;
				int k = i;
				for (int j = 0; j < n; j++) {
					if (((k & 1) == 1)) {
						count++;
					}
					k = k >> 1;
				}
				max = count > max ? count : max;
			}

		}

		System.out.println(max);
	}

	static void makeTable() {
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < i; j++) {
				//重なっていればtrue
				table[i][j] = d(x[i] - x[j]) + d(y[i] - y[j]) < d(r[i] + r[j]) ? true : false;
			}
		}
	}

	static int d(int a){
		return a*a;
	}

	static boolean canGet(int bit, int s, int k) {
		if (c[s] != c[k]) {
			return false;
		}

		for (int i = 0; i < n; i++) {
			if ((bit >> i & 1) == 0) {
				if (table[s][i] || table[k][i]) {
					return false;
				}
			}
		}

		return true;
	}

	static public boolean read() {
		n = sc.nextInt();
		if (n == 0) {
			return false;
		}

		dp = new boolean[1 << n];
		table = new boolean[n][n];
		x = new int[n];
		y = new int[n];

		r = new int[n];
		c = new int[n];

		for (int i = 0; i < n; i++) {
			x[i] = sc.nextInt();
			y[i] = sc.nextInt();
			r[i] = sc.nextInt();
			c[i] = sc.nextInt();
		}
		return true;
	}

	public static void main(String args[]) {
		while (read())
			solve();
	}
}
