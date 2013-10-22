// https://www.facebook.com/hackercup/problems.php?pid=321892127915788&round=189890111155691

import java.io.PrintWriter;
import java.util.Collections;
import java.util.PriorityQueue;
import java.util.Scanner;

public class Q2013_R1_1 {
	static final int MOD = 1000000007;

	public static void main(String[] args) {
		doIt();
	}
	static void doIt(){
		Scanner sc = new Scanner(System.in);
		PrintWriter out = new PrintWriter(System.out);
		int t = sc.nextInt();
		for(int i = 0; i < t; i++){
			int n = sc.nextInt();
			int k = sc.nextInt();
			if(n == 1){
				out.println("Case #" + (i + 1) + ": " + sc.nextInt());
				continue;
			}
			PriorityQueue<Long> queue = new PriorityQueue<Long>(n, Collections.reverseOrder());
			for(int j = 0; j < n; j++) queue.add(sc.nextLong());
			long ans = 0;
			n--;k--;
			while(k <= queue.size() && k <= n){
				long b = queue.poll();
				ans += (b * combi(n--,k)) % MOD;
				ans %= MOD;
			}
			out.println("Case #" + (i + 1) + ": " + ans);
		}
		out.flush();
	}
	static long pow(long n, long p){
		long ans = 1;
		while(p != 0){
			if((p&1) == 1) ans = (ans*n) % MOD;
			n = (n*n) % MOD;
			p = p>>1;
		}
		return ans;
	}
	static long combi(long n, long k){
		long a = 0;
		if(n - k < k) a = n - k;
		else a = k;
		long m = 1;
		long c = 1;
		for(int i = 0; i < a; i++){
			m = (m * (n - i)) % MOD;
			c = (c * (a - i)) % MOD;
		}
		return (m * pow(c, MOD - 2)) % MOD;
	}
}

