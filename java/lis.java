// http://acm.zju.edu.cn/onlinejudge/showProblem.do?problemCode=3523

import java.io.PrintWriter;
import java.util.Arrays;
import java.util.Scanner;

public class Q3523 {

	public static void main(String[] args) {
		doIt();
	}
	static void doIt() {
		Scanner sc = new Scanner(System.in);
		PrintWriter pw = new PrintWriter(System.out);
		while(sc.hasNext()){
			int n = sc.nextInt();
			int m = sc.nextInt();
			sc.nextLine();
			int ans = 0;
			for(int ii = 0; ii < n; ii++) {
				String[] input = new String[m];
				int[] lis = new int[m];
				for(int i = 0; i < input.length; i++) input[i] = sc.nextLine();
				for(int i = 0; i < input.length; i++) {
					for(int j = 0; j < i; j++) {
						if(lis[i] <= lis[j] && 0 <= input[i].compareTo(input[j])) lis[i] = lis[j] + 1;
					}
				}
				Arrays.sort(lis);
				ans += m - (lis[m - 1] + 1);
			}
			pw.println(ans);
		}
		pw.close();
	}
}
