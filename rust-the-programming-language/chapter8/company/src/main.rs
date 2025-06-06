use std::io;
use std::collections::HashMap;

fn main() {

    let mut map = HashMap::new();
    let mut emp_list = Vec::new();
    loop {
        let mut command = String::from("");

        println!("Enter a command\n(a)dd\n(v)iew\n(e)xit\n");

        io::stdin()
            .read_line(&mut command)
            .expect("Failed to get user input");
        
        let command = command.trim();

        match command {
            "a" => {

                }, 
            "v" => {
                for (key, val) in map {
                    println!("{} {}", key, val);
                }
            },
            "e" => break, 
            _ => println!("Invalid command\n"),
        }

    }
        
    println!("Shutting down");
}

fn add_employee(vec: Vec, map: Hashmap) {
    println!("Enter the name of employee");
    let mut employee = String::from("");
    io::stdin()
        .read_line(&mut employee)
        .expect("Failed to get user input");

    println!("Enter the department of employee");
    let mut department= String::from("");
        io::stdin()
        .read_line(&mut department)
        .expect("Failed to get user input");

    map.entry(department).or_insert();
}
