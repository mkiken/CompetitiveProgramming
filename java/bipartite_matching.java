// https://www.facebook.com/notes/facebook-hacker-cup/2013-round-1-solutions/606859202663318

import java.util.Arrays;
import java.util.Scanner;
import java.util.Vector;

public class R1_2013_B {
	static Vector<Integer>[] edge;
	static int[] match;
	static boolean[] used;
	static int v, m;
	static char[][] k1s, k2s;

	public static void main(String[] args) {
		doIt();
	}

	static void doIt() {
		Scanner sc = new Scanner(System.in);
		int T = sc.nextInt();
		for (int i = 0; i < T; i++) {
			m = sc.nextInt();
			String k1 = sc.next();
			String k2 = sc.next();
			int sec = k1.length() / m;
			k1s = new char[m][sec];
			k2s = new char[m][sec];
			for (int j = 0; j < m; j++) {
				k1s[j] = k1.substring(sec * j, sec * j + sec).toCharArray();
				k2s[j] = k2.substring(sec * j, sec * j + sec).toCharArray();
			}
			v = 2 * m;
			edge = (Vector<Integer>[]) new Vector[v];
			for (int j = 0; j < v; j++) edge[j] = new Vector<Integer>();
			match = new int[2 * m];
			used = new boolean[2 * m];

			if(m != bipartite_matching()){
				System.out.println("Case #" + (i + 1) + ": IMPOSSIBLE");
			}
			else{
				String ans = "";
				for (int j = 0; j < m; j++) {
					String s = "";
					for (int k = 0; k < sec; k++) {
						if(k1s[j][k] == '?'){
							for(char c = 'a'; c <= 'f';c++){
								k1s[j][k] = c;
								if(m == bipartite_matching()){s += c;break;}
							}
						}
						else s += k1s[j][k];
					}
					ans += s;
				}
				System.out.println("Case #" + (i + 1) + ": "  + ans);
			}
		}
	}
	static int bipartite_matching(){
		for (int j = 0; j < v; j++) edge[j].clear();
		for (int j = 0; j < m; j++) {
			for (int j2 = 0; j2 < m; j2++) {
				if(cmp(k1s[j], k2s[j2])){
					edge[j].add(m + j2);
					edge[m + j2].add(j);
				}
			}
		}

		Arrays.fill(match, -1);
		int res = 0;
		for (int j = 0; j < v; j++) {
			if(match[j] == -1){
				Arrays.fill(used, false);
				if(dfs(j)) res++;
			}
		}
		return res;
	}
	static boolean cmp(char[] a, char[] b){
		for (int i = 0; i < a.length; i++) {
			if(a[i] != '?' && b[i] != '?' && a[i] != b[i]) return false;
		}
		return true;
	}
	static boolean dfs(int v0){
		used[v0] = true;
		for (int i = 0; i < edge[v0].size(); i++) {
			int u = edge[v0].get(i);
			int w = match[u];
			if(w == -1 || used[w] == false && dfs(w)){
				match[v0] = u;
				match[u] = v0;
				return true;
			}
		}
		return false;
	}
}
