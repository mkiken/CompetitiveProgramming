import java.util.Scanner;

object Solution  {
  val MOD = 1000000007;
  val MAX_N = 1000;

  def buildFail(p:String):Array[Int] = {
    val m = p.length();
    val fail = new Array[Int](m+1);
    var j = -1;
    fail(0) = -1;
    for (i <- 1 to m) {
      while (j >= 0 && p(j) != p(i-1)) j = fail(j);
      j += 1;
      fail(i) = j;
    }
    return fail;
  }

  def _match(t:String, p:String, fail:Array[Int]):Int = {
    val n = t.length();
    val m = p.length();
    var count = 0;
    var k = 0;
    for (i <- 0 until n) {
      while (k >= 0 && p(k) != t(i)) k = fail(k);
      k += 1;
      if (k >= m) {
        count += 1; // match at t(i-m+1 .. i)
        k = fail(k);
      }
    }
    return count;
  }

  def kmp(t:String, p:String): Int = {
    return _match(t, p, buildFail(p));
  }

  def main(args: Array[String]){
    doIt();
  }

  //https://www.hackerrank.com/contests/lambda-calculi-mar14/challenges/kmp-fp
  def doIt(){
    val sc = new Scanner(System.in);
    val t = sc.nextInt();
    for(i <- 0 until t){
      val text = sc.next();
      val pat = sc.next();
      println(if(kmp(text, pat) > 0) "YES" else "NO");
    }
  }
}
