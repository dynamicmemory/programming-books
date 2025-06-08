use std::fs::File;
use std::io::{ErrorKind, Read}

// enum Result<T, E> {
//     Ok(T),
//     Err(E),
// }

fn main() {
    let greeting_file_result = File::open("Hello.txt");

    let greeting_file = match greeting_file_result {
        Ok(file) => file,
        Err(error) => panic!("Problem opening the file {error:?}"),
        };


    let greeting_file = match greeting_file_result {
        Ok(file) => file,
        Err(error) => match error.kind() {
            ErrorKind::NotFound => match File::create("Hello.txt") {
                Ok(fc) => fc, 
                Err(e) => panic!("Problem creating the file: {e:?}"),
            },
            _ => {
                panic!("Problem opening the file: {error:?}");
            }
        },
    };


    let greeting_file = File::open("Hello.txt").unwrap();

    let greeting_file = File::open("Hello.txt").expect("Hello should be in project");

}

fn read_username_from_file() -> Result<String, io::Error> {
    let username_file_result = File::open("Hello.txt");

    let mut username_file = match username_file_result {
        Ok(file) => file,
        Err(e) => return Err(e),
    };
    
    let mut username = String::new();

    match username_file.read_to_string(&mut userneame) {
        Ok(_) => Ok(username),
        Err(e) => Err(e),
    }
}

fn read_from_file() -> Result<String, io::Error> {
    let mut username_file = File::open("hello.txt")?;
    let mut username = String::new();
    username_file.read_to_string(&mut username)?;
    Ok(username)
}
