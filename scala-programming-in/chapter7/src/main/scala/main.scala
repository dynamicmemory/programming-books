@main
def run(): Unit = 

  def makeRowSeq(row: Int) =
    for (col <- 1 to 12) yield {
      val prod = (row * col).toString
      val padding = " " * (4 - prod.length)
      padding + prod 
    }

  def makeRow(row: Int) = makeRowSeq(row).mkString

  def multitable() = 
    val tableSeq = 
      for (row <- 1 to 12)
      yield(makeRow(row))
    tableSeq.mkString("\n")

  println(multitable())
