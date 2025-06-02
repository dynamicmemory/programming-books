
fn fibo(n: i32, a: i32, b: i32) -> i32 {
    if n == 0 {
        a 
    }
    else {
        fibo(n - 1, b, a+b)
    }
}

fn main() {
    let nth: i32 = 5;
    // fibo(nth, 0, 1);
    println!("The {} term in the fibonaaxxxi seq is {}", nth, fibo(nth, 1, 1));
}
