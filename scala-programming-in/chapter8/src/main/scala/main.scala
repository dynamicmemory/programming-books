import scala.io.Source

object LongLines {
  def processFile(fileName: String, width: Int) = {
    val source = Source.fromFile(fileName)

    for (line <- source.getLines())
      processLine(fileName, width, line)
  }

  private def processLine(fileName: String, width: Int, line: String) = {
    if (line.length > width)
      println(fileName + " : " + line.trim)
  }
}

// Simplier way
object LongLines2 {
  def processFile(fileName: String, width: Int) = {
    def processLine(line: String) = {
      if (line.length > width) 
        println(fileName + " : " + line.trim)
    }

    val source = Source.fromFile(fileName)
    for (line <- source.getLines())
      processLine(line)
  }
}

@main
def run(): Unit = {

  val list: List[Int] = List(1,2,3,4,5)
  list.foreach(x => println(x*2))
  println(list.filter((x: Int) => x % 2 == 0))
  println(list.filter(_ % 2 == 0))
  
  list.foreach(println)

  def sum(a: Int, b: Int, c: Int) = a + b + c 

  val a = sum 
  println(a(1,2,3))

  val b = sum(1, _: Int, 3)
  println(b(2))

  
}
