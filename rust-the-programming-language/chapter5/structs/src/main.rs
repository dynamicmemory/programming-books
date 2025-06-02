struct User {
    active: bool,
    username: String,
    email: String,
    sign_in_count: u64, 
}

// Tuple structs 
struct Color(i32, i32, i32);
struct Point(i32, i32, i32);

fn main() {
    let mut user1 = User {
        active: true,
        username: String::from("someusername123"),
        email: String::from("someone@example.com"),
        sign_in_count: 1, 
    };

    user1.email = String::from("changed");

    let user2 = User {
        active: user1.active,
        username: user1.username,
        email: String::from("new"),
        sign_in_count: user1.sign_in_count,
    };

    // let user3 = User {
    //     email: String::from("new"),
    //     ..user1 
    // };

    let black = Color(0, 0, 0);
    let origin = Point(0, 0, 0);
}

fn create_user(username: String, email: String) -> User {
    User {
        active: true, 
        username,
        email,
        sign_in_count: 1,
    }
}
