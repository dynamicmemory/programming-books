class Rational(n: Int, d: Int) {
  // Avoid zero division error
  require(d != 0)

  private val g = gcd(n.abs, d.abs)

  val numer = n / g
  val denom = d / g

  def this(n: Int) = this(n, 1)

  override def toString = s"Created $numer / $denom"
  

  def + (that: Rational): Rational = 
    Rational(numer * that.denom + denom * that.numer, d * that.denom)

  def + (i: Int): Rational = 
    Rational(numer + i * denom, denom)


  def * (that: Rational): Rational = 
    Rational(numer * that.denom, denom * that.numer)

  def * (i: Int): Rational = 
    Rational(numer * i, denom)

  // imagine subtraction and division below


  private def gcd(a: Int, b: Int): Int = 
    if (b == 0) a else gcd(b, a%b)

}

@main
def run(): Unit = {

  val rat1: Rational = Rational(408425444,12)
  val rat2: Rational = Rational(3,2)
  println(rat1) 
}
