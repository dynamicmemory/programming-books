fn main() {

    let s = "apple";

    println!("{}", iglatinpay(s));

    let s = "poop";

    println!("{}", iglatinpay(s));
}

fn iglatinpay(s: &str) -> String{
    let first = &s[..1];
    match first {
        "a" => {
            let s = format!("{s}-hay");
            s
        },
        "e" => {
            let s = format!("{s}-hay");
            s
        },
        "i" => {
            let s = format!("{s}-hay");
            s
        },
        "o" => {
            let s = format!("{s}-hay");
            s
        },
        "u" => {
            let s = format!("{s}-hay");
            s
        },
        _ => {
            let c = &s[..1];
            let a = &s[1..];
            let s = format!("{a}-{c}ay");
            s
        }
    }
}
