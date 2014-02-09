// import java.io.PrintWriter;
import java.util.Scanner;

// https://www.hackerrank.com/contests/hindley-milner-feb14/challenges/range-minimum-query
object Solution {

  val MAX_N = 100005;
  val INF = 1000000007;
  val segMin = new Array[Long](MAX_N * 4);
  val segAddMin = new Array[Long](MAX_N * 4);

  def _addMin(a:Int, b:Int, x:Int, kk:Int, l:Int, r:Int){
    var k = kk;
    if (r <= a || b <= l) return;
    if (a <= l && r <= b){
	  segAddMin(k) += x;
	  while (0 < k){
	    k = (k - 1) / 2;
	    segMin(k) = Math.min(segMin(k * 2 + 1) + segAddMin(k * 2 + 1), segMin(k * 2 + 2) + segAddMin(k * 2 + 2));
	  }
	  return;
    }
    _addMin(a, b, x, k * 2 + 1, l, (l + r) / 2);
    _addMin(a, b, x, k * 2 + 2, (l + r) / 2, r);
  }
  def _getMin(a:Int, b:Int, k:Int, l:Int, r:Int):Long = {
    if (r <= a || b <= l) return INF;
    if (a <= l && r <= b) return segMin(k) + segAddMin(k);
    val left = _getMin(a, b, k * 2 + 1, l, (l + r) / 2);
    val right = _getMin(a, b, k * 2 + 2, (l + r) / 2, r);
    return Math.min(left, right) + segAddMin(k);
  }
  //区間[a, b)に値xを加算する.sizeは木の要素数
  def addMin(a:Int, b:Int, x:Int, size:Int){
    _addMin(a, b, x, 0, 0, size);
  }
  def getMin(a:Int, b:Int, size:Int):Long = {
    return _getMin(a, b, 0, 0, size);
  }

  def main(args: Array[String]) {
	doIt();
  }

  def doIt() {
	val sc = new Scanner(System.in);
    val n, m = sc.nextInt();
    val arr = Array.fill(n)(sc.nextInt());
    for(i <- 0 until n){
      addMin(i,i+1, arr(i), n);
    }
    for(i <- 0 until m){
      val l, r = sc.nextInt();
      println(getMin(l, r+1, n));
    }
  }
}
