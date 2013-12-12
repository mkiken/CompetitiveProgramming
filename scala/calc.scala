import java.util.Scanner

object Main  {
  val MOD = 1000000007;
  def main(args: Array[String]){
    doIt()
  }


  def pow(n1:Int, p1:Int):Int = {
    var n = n1.toLong;
    var p = p1;
	var ans = 1L;
	while (p != 0) {
	  if((p&1) == 1) ans = (ans*n) % MOD;
	  n = (n*n) % MOD;
	  p = p>>1;
	}
	return ans.toInt;
  }

  def mod_inverse(a: Int):Int = {
    if(a == 0) 0;
    else ((new BigInteger(a.toString).modInverse(new BigInteger(MOD.toString)).longValue) % MOD).toInt;
  }

  def fact(n: Int) = {
    var ans = 1L;
    for(i <- 2 to n) ans = ans * i % MOD;
    ans.toInt;
  }

  def _mod_inverse(a: Int, m: Int):Int = {
    if(a == 0) 0;
    else ((new BigInteger(a.toString).modInverse(new BigInteger(m.toString)).longValue) % m).toInt;
  }

  def _fact(n: Int, m: Int){
    var ans = 1L;
    for(i <- 2 to n) ans = ans * n % m;
    return ans.toInt;
  }


  def _pow(n1:Int, p1:Int, m:Int):Int = {
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


  def doIt(){
    val sc = new Scanner(System.in);
  }
}
