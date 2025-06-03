use std::collections::HashMap;

fn main() {

    let mut scores = HashMap::new();
    
    scores.insert(String::from("Blue"), 10);
    scores.insert(String::from("Yellow"), 50);

    let team_name = String::from("Blue");
    let score = scores.get(&team_name).copied().unwrap_or(0);

    for (key, value) in &scores {
        println!("{key}: {value}");
    }


    let field_name = String::from("Favourite color");
    let field_value = String::from("Blue");

    let mut map = HashMap::new();
    map.insert(field_name, field_value);
    // field name and value are now owned by the map and therefore invalid vars 

    // Overwritting values 
    let mut scores = HashMap::new();

    scores.insert(String::from("Blue"), 10);
    scores.insert(String::from("Yellow"), 25);

    println!("{scores:?}");

    // adding key and value only if not present 
    let mut scores = HashMap::new();

    scores.insert(String::from("Blue"), 10);

    scores.entry(String::from("Yellow")).or_insert(50);
    scores.entry(String::from("Blue")).or_insert(50);  // Wont be entered as Blue alreaady has a value 

    println!("{scores:?}");


    // Updating a value based on the old value 
    let text = "hello world wonderful world";

    let mut map = HashMap::new();

    for word in text.split_whitespace() {
        let count = map.entry(word).or_insert(0);
        *count += 1;
    }

    println!("{map:?}");
}

