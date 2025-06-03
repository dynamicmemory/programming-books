enum Spreadsheetcell {
    Int(i32),
    Float(f64),
    Text(String),
}

fn main() {

    let v: Vec<i32> = Vec::new();

    let v = vec![1,2,3];

    let mut v = Vec::new();
    v.push(4);
    v.push(2);

    let v = vec![1,2,3,4,5];

    let third = &v[2];
    println!("The third element is {third}");

    let third = v.get(2);
    match third {
        Some(third) => println!("The third element is {third}"),
        None => println!("There is no third element."),
    }

    // let does_not_exist = &v[100];
    loop {

        let does_not_exist = v.get(100);
        match does_not_exist {
            Some(val) => println!("That is a valid element"),
            None => { println!("Element not in structure, enter a value between 0 and {}", v.len());
                break;
            }
        }
    }


    // Doesnt work as you are reffing v before adding an element, if it had to 
    // resize due to that element push, you are now reffing dealocated memory.
    // let mut v = vec![1,2,3,4,5];
    // let first = &v[0];
    // v.push(6);
    // println!("The first element is: {first}");

    let v = vec![100, 32, 57];
    for i in &v {
        println!("{i}");
    }

    let mut v = vec![1,23,3,4,5];
    for i in &mut v {
        *i += 50;
    }

    let row = vec![
        Spreadsheetcell::Int(3),
        Spreadsheetcell::Text(String::from("blue")),
        Spreadsheetcell::Float(10.12),
    ];
    
}
