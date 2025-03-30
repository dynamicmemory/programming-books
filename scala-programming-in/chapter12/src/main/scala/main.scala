trait Philosophical {

  def philosophize() =
    println("I consume memory, therefore I am")
}

class Animal
trait HasLegs

class Frog extends Animal with Philosophical with { 

  override def toString = "green"

  override def philosophize() = 
    println("It aint easy being " + toString + "!")
}


@main
def run(): Unit = {
  val frog = new Frog
  frog.philosophize()

  val phil: Philosophical = frog
  phil.philosophize()

}
