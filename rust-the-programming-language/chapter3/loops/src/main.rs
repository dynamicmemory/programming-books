fn main() {

    loop {
        println!("again!");
    }
 

    let mut  counter = 0;

    let result = loop {
        counter += 1;

        if counter == 10 {
            break counter * 2;
        }
    };

    println!("The result is {result}");




    let mut count = 0;
    
    'counting_up: loop {
        println!("count = {count}");
        let mut remaining = 10;

        loop {
            println!("remaining = {remaining}");
            if remaining == 9 {
                break;
            }
            if count == 2 {
                break 'counting_up;
            }
            remaining -= 1;
        }

        count += 1;
    }
    println!("end count = {count}");



    let mut number = 3;

    while number != 0 {
        println!("{number}!");
        number  -= 1;
    }

    println!("Liftoff!!!");

    
    let a = [10, 20, 30, 50, 60];
    let mut index = 0;

    while index < 5 {
        println!("the vlaue os: {}", a[index]);

        index += 1;
    }

    for element in a {
        println!("The value is: {}", element);
    }



    for number in (1..10) {
        println!(number);
    }

    for number in (1..10).rev() {
        println!(number);
    }


}
