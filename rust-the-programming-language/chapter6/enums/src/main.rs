enum IpAddrKind {
    V4,
    V6,
}

enum IpAddr {
    V4(u8, u8, u8, u8),
    V6(String),
}

enum Message {
    Quit,
    Move {x: i32, y: i32}
    Write(String),
    ChangeColor(i32, i32, i32),
}

impl Message {
    fn call(&self) {
        // Method body
    }
}

enum Option<T> {
    None,
    Some(T),
}


fn main() {

    let four = IpAddrKind::V4;
    let six = IpAddrKind::V6;

    route(IpAddrKind::V4);
    route(IpAddrKind::V6);

    let home = IpAddr::V4(127, 0, 0, 1);

    let loopback = IpAddr::V6(String::from("::1"));
     
    let m = Message::Write(String::from("Hello"));
    m.call();


    let a = Some(5);
    let b = Some('r');
    let c: Option<i32> = None;
}

fn route(ip_kind: IpAddrKind) {}
