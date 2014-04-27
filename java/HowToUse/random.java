//http://kupc2012pr.contest.atcoder.jp/tasks/kupc2012pr_4

import java.util.Arrays;
import java.util.Random;
import java.util.Scanner;

public class Main {

	public static void main(String[] args) {
		doIt();
	}

	static void doIt(){
		Scanner sc = new Scanner(System.in);
		int n = sc.nextInt();
		int[][] A = new int[n][n];
		int[][] B = new int[n][n];
		int[][] C = new int[n][n];
		for(int i = 0; i < n; i++) for(int j = 0; j < n; j++) A[i][j] = sc.nextInt();
		for(int i = 0; i < n; i++) for(int j = 0; j < n; j++) B[i][j] = sc.nextInt();
		for(int i = 0; i < n; i++) for(int j = 0; j < n; j++) C[i][j] = sc.nextInt();

		Random rnd = new Random();
		int[] x = new int[n];
		long[] Bx = new long[n];
		long[] ABx = new long[n];
		long[] Cx = new long[n];
		boolean bOK = true;
		int count = 0;

		while(count <= 10){
			Arrays.fill(Bx, 0);
			Arrays.fill(Cx, 0);
			Arrays.fill(ABx, 0);
			for(int i = 0; i < n; i++) x[i] = rnd.nextInt(1000);
			for(int i = 0; i < n; i++)
				for(int j = 0; j < n; j++){
					Bx[i] += (long)B[i][j] * x[j];
					Cx[i] += (long)C[i][j] * x[j];
				}
			for(int i = 0; i < n; i++) for(int j = 0; j < n; j++) ABx[i] += A[i][j] * Bx[j];
			for(int i = 0; i < n; i++) if(ABx[i] != Cx[i]){bOK = false; break;}
			if(!bOK) break;
			count++;
		}
		System.out.println(bOK == true? "YES" : "NO");
	}
}
