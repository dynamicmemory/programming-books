fn main() {
    let number = 2;

    if number < 5 {
        println!("condition was true");
    }
    else {
        println!("condition was false");
    }

   
    if number > 10 {
        println!("greater then 10");
    }
    else if number < 5 {
        println!("less then 5");
    }
    else {
        println!("just right");
    }


    let cond = true;

    let number = if cond {5} else {6};

    println!("The value of number is: {number}");

}
