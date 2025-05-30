fn main() {
    let mut x = 5;
    println!("The value of x is: {}",x);

    let x = 6;
    println!("The value of x is: {}",x);
    
    const A_CONSTANT_VALUE: u32 = 3;

    //shadowing
    let x = 5;
    let x = x + 1;
    { 
        let x = x*2;
        println!("The valie of x is {x}");
    }

    println!("The value of x is {x}");


    // will work 
    let spaces = "    ";
    let spaces = spaces.len();

    // will not work 
    // let mut spaces = "     ";
    // spaces = spaces.len();

    
}
