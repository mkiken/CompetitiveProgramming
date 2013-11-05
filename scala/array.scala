import java.util.Scanner

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
