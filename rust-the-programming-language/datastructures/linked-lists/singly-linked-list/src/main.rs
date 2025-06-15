use std::ptr;

struct Node<T> {
    next: *mut Node<T>, 
    key: T, 
}

struct List<T> {
    head: *mut Node<T>,
}

impl<T> List<T> {
    fn init(key: T) -> Self {
        let inital_node = Box::new(Node {
            next: ptr::null_mut(),
            key,
        });
        
        let head = Box::into_raw(inital_node);

        List { head }
    }

    fn empty() {
    }

    fn add() {
    }

    fn search() {
    }

    fn delete() {
    }
   
    fn print() {
    }
}


fn main() {
    let list = List::init(66);

    unsafe {
        println!("{:?}", (*list.head).key);
    }
}
