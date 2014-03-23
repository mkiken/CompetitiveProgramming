import java.util.Scanner;
import java.math.BigInteger;

object Solution  {
  val MOD = 1000000007;
  def main(args: Array[String]){
    doIt()
  }

  def doIt(){
    val sc = new Scanner(System.in);
    val t = sc.nextInt();
    0 until t foreach{ ii =>
      val as = sc.next();
      val bs = sc.next();
      val a = new BigInteger(as).mod(new BigInteger("1000000007")).longValue();
      var b = new BigInteger(bs).mod(new BigInteger("1000000006")).longValue();
      println(pow(a.toInt, b.toInt, MOD));
    }
  }
  def pow(n1:Int, p1:Int, m:Int):Int = {
    var n = n1.toLong;
    var p = p1;
	var ans = 1L;
	while (p != 0) {
	  if((p&1) == 1) ans = (ans*n) % m;
	  n = (n*n) % m;
	  p = p>>1;
	}
	return ans.toInt;
  }
}
