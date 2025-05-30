use std::io;


fn main() {

    let x = 2.0;
    let y: f32 = 3.0;

    let sum = 5 + 10;
    let difference = 5 - 10;
    let product = 5*20;
    let quotient = 34.3/56.5;
    let truncated = 4/3;
    let remainder = 45%4;

    let t = true;
    let f: bool = false;

    let c = 'x';
    let z: char = 'z';

    let tup: (i32, f64, u8) = (500,6.4, 1);
    let (x,y,z) = tup;

    println!("The value of y is: {y}");

    let five_hundred = tup.0;
    let six_point_four = tup.1;
    let one = tup.2;

    let a = [1,2,3,4,5];
    let a: [i32; 5] = [1,2,3,4,5];
    let a = [3; 5]; //3,3,3,3,3
    
    let first = a[0];
    let second = a[1];

    println!("Please enter an array index");

    let mut index = String::new();

    io::stdin().read_line(&mut index).expect("Failed to read line");

    let index: usize = index 
        .trim()
        .parse()
        .expect("Index enter was not a number");

    let element = a[index];

    println!("the cvalur of the element at index{index} is : {element}");
    


}
