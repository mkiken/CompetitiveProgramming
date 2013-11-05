import java.util.Scanner

object Main  {
  def makePrimes(n:Int):Array[Int] = {
    var ar = Array.fill(n+1)(true);
    val buf = scala.collection.mutable.ArrayBuffer.empty[Int];
    ar(0) = false;
    ar(1) = false;
    for(i <- 2 to n){
      if(ar(i)){
        buf += i;
        for(j <- 2 to n / i) ar(j * i) = false;
      }
    }
    return buf.toArray;
  }

  def main(args: Array[String]){
    doIt()
  }

  def doIt(){
    val sc = new Scanner(System.in);
    val prs = makePrimes(100100);
    var t, pos = 0;
    var a, b = 0L;
    // println(prs.take(4).mkString(", "))
    t = sc.nextInt();
    for(i <- 1 to t){
      a = sc.nextLong();
      b = sc.nextLong();
      pos = 0;
      while(prs(pos) * prs(pos) <= b){
        if(a < prs(pos) * prs(pos)){
          println(prs(pos));
        }
        pos += 1;
      }
    }

  }
}
