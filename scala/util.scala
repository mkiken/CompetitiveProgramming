import java.util.Scanner

// Euler43
object Main {
  def main(args: Array[String]){
    doIt()
  }

  def doIt(){
    val sc = new Scanner(System.in);
    var ans = 0;
//    "0123456789".permutations.foreach(println)
    //"0123456789".permutations.map(conv)
    // println("0123456789".permutations.map(conv).mkString(", "))
    println("0123456789".permutations.map(conv).fold(0L)(_ + _))

    println("End.");

  }

  def conv(s:String):Long = {
    if(s.substring(1, 4).toInt % 2 == 0
      && s.substring(2, 5).toInt % 3 == 0
      && s.substring(3, 6).toInt % 5 == 0
      && s.substring(4, 7).toInt % 7 == 0
      && s.substring(5, 8).toInt % 11 == 0
      && s.substring(6, 9).toInt % 13 == 0
      && s.substring(7, 10).toInt % 17 == 0){
      //println(s.substring(1, 3));
      return s.toLong;
    }
    return 0;
  }
}
