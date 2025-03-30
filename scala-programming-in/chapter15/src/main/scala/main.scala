def constant(x: Any) = 
  x match
    case 5 => "five"
    case true => "truth"
    case "hello" => "hi"
    case Nil => "the empty string"
    case _ => "something else"


def variable(x: Any) = 
  x match 
    case 0 => "zero"
    case somethingElse => s"not zero: $somethingElse"


@main 
def run() {
  
