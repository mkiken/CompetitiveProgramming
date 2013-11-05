import java.util.Scanner

object Main  {
  val MOD = 1000000007;
  def main(args: Array[String]){
    doIt()
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


  def doIt(){
    val sc = new Scanner(System.in);
  }
}
