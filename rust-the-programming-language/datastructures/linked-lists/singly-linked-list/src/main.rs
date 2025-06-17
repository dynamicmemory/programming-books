use std::alloc::dealloc;
use std::ptr::{self, null, null_mut};
use std::fmt::{Display, Pointer};

struct Node<T> {
    next: *mut Node<T>, 
    key: T, 
}

struct List<T> {
    head: *mut Node<T>,
}

impl<T: Display + PartialEq> List<T> {
    fn new() -> Self {
        List { head: ptr::null_mut() }
    }

    fn empty(&self) -> bool {
        self.head.is_null() 
    }

    fn add(&mut self, key: T) {
        let node = Box::new(Node {
            next: self.head, 
            key: key,
        });

        self.head = Box::into_raw(node);
    }

    fn search(&self, key: T) -> *mut Node<T> {
        unsafe {
            let mut current = self.head;
            while !current.is_null() {
                if (*current).key == key {
                    return current
                }
                current = (*current).next;
            } 
            return null_mut()
        }
    }

    fn delete(&mut self, key: T) {
        unsafe {
            let current = self.search(key);
            if current == null_mut() {
                return 
            }

            if current == self.head {
                self.head = (*current).next;
            }
            else {
                let mut prev = self.head;

                if prev.is_null() {
                    return 
                }
                while (*prev).next != current {
                    prev = (*prev).next;
                }
                (*prev).next = (*current).next;
            }
            drop(Box::from_raw(current));
        }
    }
   

    fn print(&self) {
        unsafe {
            if !self.empty() {
                let mut current = self.head;
                while !current.is_null() {
                    println!("{}", (*current).key);
                    current = (*current).next;
                }
            }
        }
    }
}


fn main() {
    let mut list: List<i32> = List::new();
    list.add(69);
    list.add(420);
    list.print();
 
    list.delete(419);
    list.add(666);
    list.print();
    list.delete(69);
    list.print();
    
}
