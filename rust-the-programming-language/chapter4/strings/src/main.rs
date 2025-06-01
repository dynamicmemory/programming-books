// Each value in rust has an owner.
// There can only be one owner at a time.
// When the owner goes out of scope, the value will be dropped.

fn main() {
    let s = "Hello";
    let s = String::from("Hello"); 

    let mut s = String::from("hello");
    s.push_str(", world");
    println!("{s}");
    
    let s1 = String::from("Hello");
    let s2 = s1;

    let s1 = String::from("Hello");
    let s2 = s1.clone();

    println!("s1 = {s1}, s2 = {s2}");

    let s = String::from("Hello");

    takes_ownership(s);

    let x = 5;

    makes_copy(x);

    println!("{}", x);
     
    let s1 = gives_ownership();
    let s2 = String::from("Hello");
    let s3 = takes_and_gives_back(s2);

    let s1 = String::from("Hello");

    let (s2, len) = calculate_length(s1);

    println!("The length of '{s2}' is {len}.");

    let s1 = String::from("Hello");
    let len = calculate_length_ref(&s1);
    println!("{len}");


    let mut s1 = String::from("Hello");
    change(&mut s1);
    println!("{s1}");


    let mut s = String::from("Hello");

    let r1 = &mut s;
    // let r2 = &mut s;

    // println!("{}, {}", r1, r2);
    

    let s = String::from("Hello world");

    let hello = &s[0..5];
    let world = &s[6..11];

    let hello = &s[..2] == &s[0..2];

    let len = s.len();
    &s[0..len] == &s[..];

}

fn first_word(s: &String) -> &str {
    let bytes = s.as_bytes();

    for (i, &item) in bytes.iter().enumerate() {
        if item == b' ' {
            return &s[0..i];
        }
    }
    &s[..]
}


fn change(s: &mut String) {
    s.push_str(", world");
}


fn calculate_length_ref(string: &String) -> usize {
    string.len()
}


fn calculate_length(s: String) -> (String, usize) {
    let length = s.len();
    (s, length)
}


fn takes_ownership(some_string: String) {
    println!("{some_string}");
}


fn makes_copy(some_integer: i32) {
    println!("{some_integer}");
}

fn gives_ownership() -> String {
    let some_string = String::from("yours");

    some_string
}

fn takes_and_gives_back(a_string: String) -> String {
    a_string
}
