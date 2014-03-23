import java.util.Scanner

// http://www.codechef.com/FEB14/problems/COLARR
// TLE...
object Main{
  def main(args: Array[String]){
    doIt();
  }
  def doIt(){
    val sc = new Scanner(System.in);
    val t = sc.nextInt();
    for(ii <- 0 until t){
      val n, m, k = sc.nextInt();
      val A = Array.fill(n)(sc.nextInt());
      val B, C = Array.fill(n)(Array.fill(m)(sc.nextInt()));
      val grd = new Array[Int](n);
      var value = 0;
      for(i <- 0 until n){
        var max = 0;
        for(j <- 0 until m){
          max = Math.max(max, B(i)(j) - C(i)(j) - B(i)(A(i)-1));
        }
        grd(i) = max;
        value += B(i)(A(i)-1);
      }
      println(value + grd.sorted.reverse.take(k).sum);
    }
  }

}

object Euler18 {
  def main(args: Array[String]){
    // val ar = Array.fill(n)(sc.nextInt());
    doIt()
  }

  def doIt(){
    val n = 100; // 15 for Euler18, 100 for Euler67
    val input = Array.ofDim[Int](n+1, n+1);
    val sc = new Scanner(System.in);

    for (i <- 0 to n-1){
      for(j <- 0 to i) input(i)(j) = sc.nextInt();
    }
    val dp = Array.ofDim[Int](n+1, n+1);
    //dp(0)(0) = input(0)(0);
    for (i <- 0 to n-1){
      for(j <- 0 to i){
        dp(i)(j) += input(i)(j);
        dp(i+1)(j) = Math.max(dp(i+1)(j), dp(i)(j));
        dp(i+1)(j+1) = Math.max(dp(i+1)(j+1), dp(i)(j));
      }
    }
    for (i <- 0 to n-1){
      for(j <- 0 to i) printf("%d ", dp(i)(j));
      println();
    }
    println(dp(n-1).max);
  }
}
