import java.io.PrintWriter;
import java.util.Arrays;
import java.util.Scanner;
import java.util.Vector;

public class prime {

    static boolean[] prime;
    static Vector<Integer> primes;
    static void makePrimes(int n){
        int i;
        prime = new boolean[n+1];
        primes = new Vector<Integer>(1000, 1000);
        Arrays.fill(prime, true);
        prime[0] = prime[1] = false;
        for (i = 2; i*i < prime.length; i++) {
            if(prime[i]){
                primes.add(i);
                for (int j = i*2; j < prime.length; j += i) {
                    prime[j] = false;
                }
            }
        }
        for(; i < prime.length; i++) primes.add(i);
    }

    public static void main(String[] args) {
        doIt();
    }

    //http://www.codechef.com/APRIL14/problems/POTATOES
    static void doIt() {
        Scanner sc = new Scanner(System.in);
        PrintWriter pw = new PrintWriter(System.out);
        int t, x, y;
        makePrimes(2500);
        t = sc.nextInt();
        while(0 < t){
            x = sc.nextInt();
            y = sc.nextInt();
            for(int i = 0; i < primes.size(); i++){
                int e = primes.elementAt(i);
                if(x + y < e){
                    System.out.println(e - (x + y));
                    break;
                }
            }
            t--;
        }
    }
}
