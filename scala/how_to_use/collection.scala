import java.util.Scanner

object Main  {
  val MOD = 1000000007;
  def main(args: Array[String]){
    doIt()
  }

  // http://www.codechef.com/ODCD2013/problems/LEBALLS
  def doIt(){
    val sc = new Scanner(System.in);
    val t = sc.nextInt();
    0 until t foreach{ i =>
      val n = sc.nextInt();
      val seq = sc.next();
      var pos = 0;
      val stack = new scala.collection.mutable.Stack[Int];
      1 to n foreach{ j =>
        if(seq(pos) - '0' == j){
          pos += 1;
        }
        else{
          // println("jpush = " + j);
          stack.push(j);
        }
        while(!stack.isEmpty && pos < n && stack.top == seq(pos) - '0'){
          // println("j = " + j);
          stack.pop;
          pos += 1;
        }
        // println(stack)
      }
      // println(pos)
      while(pos < n && !stack.isEmpty){
        if(stack.top == seq(pos) - '0'){
          stack.pop;
          pos += 1;
        }
        else{
          pos = 100;
        }
      }
      if(stack.isEmpty && pos == n) println("Yes");
      else println("No");
    }
  }
}
