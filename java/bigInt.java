import java.util.Scanner;
import java.math.BigInteger;

// http://www.codechef.com/NOV13/problems/SPOTWO/
public class bigInt  {
	static final int MOD = 1000000007;
	public static void main(String[] args) {
		doIt();
	}

	static void doIt() {
		Scanner sc = new Scanner(System.in);
		// PrintWriter pw = new PrintWriter(System.out);
		int t, n = 0;
		String bin = "";
		long ans = 0L;
		t = sc.nextInt();
		for(int ii = 0; ii < t; ii++){
			n = sc.nextInt();
			bin = Integer.toString(n, 2);
			ans = pow(2, new BigInteger(bin), MOD);
			ans = ans * ans % MOD;
			System.out.println(ans);
		}

	}

	static long pow(int n1, BigInteger p, int m){
		long n = n1;
		long ans = 1L;
		while (!p.equals(BigInteger.ZERO)) {
			// if((p&1) == 1) ans = (ans*n) % m;
			if(p.getLowestSetBit() == 0) ans = (ans*n) % m;
			n = (n*n) % m;
			// p = p>>1;
			p = p.shiftRight(1);
		}
		return ans;
	}

}
