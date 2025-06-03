fn main() {
    let mut s = String::new();

    let data = "initial contents";
    let s = data.to_string();
    let s = "initial contents".to_string();

    let s = String::from("Hello there");

    let mut s = String::from("foo");
    s.push_str("bar");

    let mut s1 = String::from("foo");
    let s2 = "bar";
    s1.push_str(s2);
    println!("s2 is {s2}");
    
    let mut s1 = String::from("Lo");
    s.push('L');


    let s1 = String::from("Hello, ");
    let s2 = String::from("world!");
    let s3 = s1 + &s2;

    let s1 = String::from("Tic");
    let s2 = String::from("Tac");
    let s3 = String::from("Toc");

    let s = s1 + "-" + &s2 + "-" + &s3;

    let s1 = String::from("Tic");
    let s2 = String::from("Tac");
    let s3 = String::from("Toc");
    
    let s = format!("{s1}-{s2}-{s3}");

    let hello = "Здравствуйте";
    let s = &hello[0..4];

    for c in "Зд".chars() {
        println!("{c}");
    }

    // to get the bytes instead 
    for b in "Здравствуйте".bytes() {
        println!("{b}");
    }
}

fn add(self, s: &str) -> String {
    // This is what the + does when using it for strings, the method looks 
    // something like this, hence why we need a reff to what is being +ed
    s 
}
