import java.util.Scanner;

// https://www.hackerrank.com/contests/hindley-milner-feb14/challenges/brainf_k-interpreter-fp
object Solution {
  val MOD = 1000000007;
  val MAX_N = 1000;
  var pointer = 0;
  val data = new Array[Int](100005);
  var input = "";
  var inputPtr = 0;
  val prg = new Array[Char](5100);
  var prgLen = 0;
  var ptr = 0;
  var loop_index = new Array[Int](5100);
  // var loop_use = 0;
  def main(args: Array[String]){
    doIt();
  }

  // Increment data pointer so that it point to next location in memory.
  def f_>(){
    pointer += 1;
    ptr += 1;
  }

  // Decrement data pointer so that it point to previous locaion in memory.
  def f_<(){
    pointer -= 1;
    ptr += 1;
  }

  // Increment the byte pointed by data pointer by 1. If it is already at its maximum value, 255, then new value will be 0.
  def f_+(){
    if(data(pointer) == 255) data(pointer) = 0;
    else data(pointer) += 1;
    ptr += 1;
  }

  // Decrement the byte pointed by data pointer by 1. If it is at its minimum value, 0, then new value will be 255.0.
  def f_-(){
    if(data(pointer) == 0) data(pointer) = 255;
    else data(pointer) -= 1;
    ptr += 1;
  }

  // Output the character represented by the byte at the data pointer.
  def f_dot(){
    printf("%c", data(pointer));
    ptr += 1;
  }

  // Read one byte and store it at the memory location pointed by data pointer.
  def f_comma(){
    data(pointer) = input(inputPtr);
    inputPtr += 1;
    ptr += 1;
  }

  // If the byte pointed by data pointer is zero, then move instruction pointer to next matching ']', otherwise move instruction pointer to next command.
  def f_op(){
    if(data(pointer) == 0){
      ptr = loop_index(ptr);
    }
    else{
      ptr += 1;
    }
  }

  // If the byte pointed by data pointer is non-zero, then move instruction pointer to previous matching '[' command, otherwise to next command.
  def f_cl(){
    if(data(pointer) != 0){
      ptr = loop_index(ptr);
    }
    else{
      ptr += 1;
    }
  }

  def doIt(){
    val sc = new Scanner(System.in);
    val n, m = sc.nextInt();
    var ops = 0;
    sc.nextLine();
    input = sc.nextLine();
    for(i <- 0 until m){
      val s = sc.nextLine();
      for(j <- 0 until s.length){
        s(j) match {
          case '>' | '<' | '+'  | '-' | '.' | ',' | '[' | ']'
              => prg(prgLen) = s(j); prgLen += 1;
          case _ => ;
        }
      }
    }

    val buf = new Array[Int](5100);
    var bnest = 0;
    //括弧の対応を求める
    for(i <- 0 until prgLen){
      if(prg(i) == '['){
        buf(bnest) = i;
        bnest += 1;
      }
      else if(prg(i) == ']'){
        bnest -= 1;
        loop_index(buf(bnest)) = i;
        loop_index(i) = buf(bnest);
      }
    }

    // printf("prg = %s", prg.mkString(""));
    while(ops < 100000 && ptr < prgLen){
      prg(ptr) match {
        case '>' => f_>();
        case '<' => f_<();
        case '+' => f_+();
        case '-' => f_-();
        case '.' => f_dot();
        case ',' => f_comma();
        case '[' => f_op();
        case ']' => f_cl();
        // case _ => println("???");
        case _ => ;
      }
      // printf("ptr = %d\n", ptr);
      ops += 1;
    }
    if(ops == 100000 && ptr < prgLen){
      printf("\n%s", "PROCESS TIME OUT. KILLED!!!");
    }
  }
}
