struct Point<T> {
    x: T, 
    y: T, 
}

impl<T> Point<T> {
    fn x(&self) -> &T {
        &self.x 
    }
}

impl Point<f32> {
    fn distance_from_origin(&self) -> f32 {
        (self.x.powi(2) + self.y.powi(2)).sqrt()
    }
}

struct MultiPoint<T, U> {
    x: T,
    y: U,
}

enum Option<T> {
    Some(T),
    None,
}

enum Result<T, E> {
    Ok(T),
    Err(E),
}


fn main() {
    
    let number_list = vec![32, 5, 99, 33, 93];
    let ret = largest(&number_list);
    println!("{ret}");

    let char_list = vec!['y', 'm', 'a', 'q'];
    let ret = largest(&char_list);
    println!("{ret}");



    let integer = Point {x: 5, y: 10};
    let float = Point {x: 1.0, y:5.0};

    // let number_list = vec![34, 50, 25, 100, 65];
    //
    // let mut largest = &number_list[0];
    //
    // for number in &number_list {
    //     if number > largest {
    //         largest = number;
    //     }
    // }
    //
    // println!("The largest number is {largest}");
}


fn largest_non_generic(list: &[i32]) -> &i32 {
    let mut largest = &list[0];

    for item in list {
        if item > largest {
            largest = item;
        }
    }
    largest
}

fn largest<T: std::cmp::PartialOrd>(list: &[T]) -> &T {
    let mut largest = &list[0];

    for item in list {
        if item > largest {
            largest = item;
        }
    }
    largest 
}
