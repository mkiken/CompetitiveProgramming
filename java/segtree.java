// http://acm.zju.edu.cn/onlinejudge/showProblem.do?problemCode=3381

import java.io.PrintWriter;
import java.util.Scanner;

public class Q3381 {

	static int[] rmq;
	static int qn = 0;

	public static void main(String[] args) {
		doIt();
	}
	static void doIt() {
		Scanner sc = new Scanner(System.in);
		PrintWriter pw = new PrintWriter(System.out);
		while(sc.hasNext()){
			int n = sc.nextInt();
			int[] s = new int[n];
			int[] x = new int[n];
			int[] y = new int[n];
			qn = pow2(n);
			rmq = new int[qn*4];
			for (int i = 0; i < n; i++) {
				s[i] = sc.nextInt();
				x[i] = sc.nextInt();
				y[i] = sc.nextInt();
			}
			int[] dp = new int[n];
			for (int i = n - 1; 0 <= i; i--) {
				dp[i] = s[i] + get(i + x[i], i + y[i]);
				add(i, dp[i]);
			}
			pw.println(dp[0]);
		}
		pw.close();
	}

	static int get(int a, int b){
		return getMax(0, a, b, 0, qn);
	}
	static int getMax(int i, int a, int b, int l, int r){
		int ret = 0;
		if(b <= l || r <= a) return ret;
		else if(a <= l && r <= b) ret = rmq[i];
		else ret = Math.max(getMax(2*i + 1, a, b, l, (l + r) / 2), getMax(2*i + 2, a, b, (l + r) / 2, r));

		return ret;
	}
	static void add(int i, int e){
		i += qn - 1;
		rmq[i] = e;
		while(0 < i){
			i = (i - 1) / 2;
			rmq[i] = Math.max(rmq[i], e);
		}
	}
	//numを上回る最小の2のベキ乗を返す
	static int pow2(int num){
		int c = 1;
		while(c < num) c*= 2;
		return c;
	}
}

