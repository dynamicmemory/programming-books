
def twice(op: Double => Double, x: Double) = op(op(x))

@main
def run(): Unit = {

  println(twice(_ + 1, 5))
}
