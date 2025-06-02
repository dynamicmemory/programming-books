use std::io; 

fn main() {
    
    let mut fahrenheit = String::new();
    io::stdin().read_line(&mut fahrenheit).expect("Failed to read input");

    let fahrenheit: i32 = match fahrenheit.trim().parse() {
        Ok(num) => num,
        Err(_) => 0,
    };

    let celcius = converter(fahrenheit);

    println!("{} fahrenheit converts to {} celcius.", fahrenheit, celcius);
}

fn converter(fah: i32) -> i32 {
    (fah - 32) * 5 / 9
}
