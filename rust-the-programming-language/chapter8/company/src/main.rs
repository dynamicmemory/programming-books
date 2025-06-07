use std::io::{self, Empty};
use std::collections::BTreeMap;

fn main() {
    // let mut map = HashMap::new();
    //
    // let employee = "Amir";
    // let department = "Accounting";
    //
    // let this = map.entry(department).or_insert(Vec::new());
    // this.push(employee);
    //
    // println!("{:?}", map);
    //
    // let employee = "Denis";
    // let department = "Admin";
    //
    // let this = map.entry(department).or_insert(Vec::new());
    // this.push(employee);
    //
    // println!("{:?}", map);
    //
    // let employee = "Urkel";
    // let department = "Accounting";
    //
    // let this = map.entry(department).or_insert(Vec::new());
    // this.push(employee);
    //
    // println!("{:?}", map);
    // }
    let mut map: BTreeMap<String, Vec<String>> = BTreeMap::new();
    
    loop {
        let mut command = String::from("");

        println!("Enter a command\n(a)dd\n(v)iew\n(e)xit\n");

        io::stdin()
            .read_line(&mut command)
            .expect("Failed to get user input");

        let command = command.trim();

        match command {
            "a" => add(&mut map), 
            "v" => {
                println!("Enter the department name you wish to retrieve or all for all employees");
                let mut department = String::new();
                io::stdin()
                    .read_line(&mut department)
                    .expect("Failed to retrieve input");
                
                let department = department.trim();
                if department == "all" {
                    for (key, val) in &map {
                        println!("{key}, {val:?}");
                    }
                }
                else if map.contains_key(department) {
                    for val in &map.get(department) {
                        println!("{}\n {val:?}", department);
                    }
                }
                else {
                    println!("Department does not exist\n");
                }

            },
            "e" => break, 
            _ => println!("Invalid command\n"),
        }

    }

    println!("Shutting down");
}

fn add(map: &mut BTreeMap<String, Vec<String>>) {
                println!("Enter the name of employee");
                let mut employee = String::from("");
                io::stdin()
                    .read_line(&mut employee)
                    .expect("Failed to get user input");
                let employee = employee.trim();

                println!("Enter the department of employee");
                let mut department= String::from("");
                    io::stdin()
                    .read_line(&mut department)
                    .expect("Failed to get user input");
                let department = department.trim();
                let this = map.entry(department.to_string()).or_insert(Vec::new());
                this.push(employee.to_string());
}
