use std::collections::HashMap;

fn main() {

    let mut v = vec![5,2,1,7,2,8,0,5,6,4,2,9];

    println!("{v:?}");

    v.sort();

    println!("{v:?}");

    let med: f32 = median(&mut v);
    println!("median is {}", med);

    println!("Mode is {}", mode(&mut v));
}

fn median(v: &mut Vec<i32>) -> f32 {
    v.sort();
   
    let length = v.len();


    if length % 2 == 1 {
        let mid = length / 2;
        v[mid] as f32
    }
    else {
        let mid = length / 2;
        let value1: f32 = v[mid] as f32;
        let value2: f32 = v[mid - 1] as f32;
        (value1 + value2) / 2.0
    }
}

fn mode(v: &mut Vec<i32>) -> i32 {
    let mut map = HashMap::new();

    v.sort();
    for num in v {
        let count = map.entry(num).or_insert(0);
        *count += 1;
    }

    let mut result = 0;
    let mut m = 0;
    for (key, val) in map {
        if val > result {
            m = *key;
            result = val
        }
    }
    m
}
