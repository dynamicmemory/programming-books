
fn another_function() {
    println!("another value");
}

fn another_another_function(x: i32) {
    println!("The value of x: {}", x);
}

fn print_measurements(value: i32, unit: char) {
    println!("The value is {}{}",value,unit);
}

fn main() {
    println!("Hello, world!");
    another_function();
    another_another_function(5);
    print_measurements(4, 'm');

    let y = 6;

    let y = {
        let x = 3;
        x + 1
    };

    println!("The value of y is: {y}");
}

fn five() -> i32 {
    5
}

fn five_n_1(x: i32) -> i32 {
    x + 1 
}



