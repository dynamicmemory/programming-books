use std::fs;
use std::env;

fn main() {
    let args: Vec<String> = env::args().collect();

    let config = parse_config(&args);

    // let (query, file_path) = parse_config(&args);
    // println!("Searching for {}", query);
    // println!("In file {}", file_path);

    let file_content = fs::read_to_string(config.file_path).expect("File does not exist");

    println!("{file_content}");
}

struct Config {
    query: String,
    file_path: String,
}

fn parse_config(args: &[String]) -> Config {
    let query = args[1].clone();
    let file_path = args[2].clone();

    Config{query, file_path}
}
