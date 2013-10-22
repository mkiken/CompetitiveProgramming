import scala.io.Source
import java.io.PrintWriter
import java.io.File
import scala.util.control.Breaks

// Codeforces Round #155 (Div. 2)のC. Anagram
// http://codeforces.com/contest/254/problem/C

object CF254c {

    def main(args: Array[String]): Unit = {
            doIt();
    }
    def doIt(){
        /*val sc = new Scanner(System.in);
        val s = sc.next().toCharArray();
        val t = sc.next().toCharArray();*/
        val reader = Source.fromFile("input.txt").getLines;
        val s = reader.next().toCharArray();
        val t = reader.next().toCharArray();
        val writer = new PrintWriter(new File("output.txt" ));
        val loop = new Breaks;
        var as = new Array[Int](26);
        var at = new Array[Int](26);
        var cnts = new Array[Int](26);
        val len = s.length;
        for(e <- s){ //foreach
            as(e - 'A') += 1; //配列は()。++は駄目
            cnts(e - 'A') += 1;
        }
        for(e <- t) at(e - 'A') += 1; //{}は省略可能
        var count = 0;
        for(i <- 0 until len){ //0 .. len - 1
            var idx = s(i) - 'A';
            if(at(idx) < as(idx)){
                loop.breakable{
                    for(j <- 0 until as.length)
                        if(as(j) < at(j) && ((j < idx) || cnts(idx) <= as(idx) - at(idx) )){
                            s(i) = (j + 'A').toChar;
                            as(j) += 1;
                            as(idx) -= 1;
                            count += 1;
                            loop.break;
                        }
                }
            }
            cnts(idx) -= 1;
        }
        writer.println(count);
        writer.println(s.mkString);
        writer.close();
        /*println(count);
        println(s.mkString); //toStringでは駄目*/
    }

}
