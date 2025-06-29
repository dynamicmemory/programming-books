use std::env;
use std::process;

use minigrep::Config;

fn main() {
    let args: Vec<String> = env::args().collect();

    let config = Config::build(&args).unwrap_or_else(|err| {
        println!("Problem parsing arguments: {err}");
        process::exit(1);
    });
    // let (query, file_path) = parse_config(&args);
    println!("Searching for {}", config.query);
    println!("In file {}", config.file_path);
    
    if let Err(e) = minigrep::run(config) {
        println!("application error: {e}");
        process::exit(1);
    }
}
