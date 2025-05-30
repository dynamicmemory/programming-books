from typing import Optional, Any

class Node:
    
    def __init__(self, key: Any, next: Optional['Node'] = None) -> None:
        """
        Constructor for the Node class 
        """

        self.key: Any = key
        self.next: Optional[Node] = next 


class Stack:
    
    def __init__(self) -> None:
        """
        Constructor for the stack class
        """

        self.top = None


    def is_empty(self) -> bool:
        """
        Returns true if the stack is empty and false otherwise 
        """
        
        return self.top is None


    def push(self, key): 
        """
        Insert an element to the top of the stack
        """

        self.top = Node(key, self.top)


    def pop(self) -> Any:
        """
        Removes and returns the top element from the stack or raises an 
        error if stack is empty
        """
        
        if not self.top:
            raise IndexError("Stack be empty brah")
        val = self.top.key 
        self.top = self.top.next
        return val 


    def peek(self) -> Optional[Any]:
        """
        Returns none if stack is empty or the top of the stack
        """

        if not self.top:
            return None 
        return self.top.key


    def print_stack(self) -> None:
        """
        Prints the stack
        """

        top = self.top 
        while top != None:
            print(top.key)
            top = top.next 

s = Stack()

s.push(1)
s.push(2)
s.push(3)
s.push(4)
s.push(5)

s.print_stack()

print(s.peek())

print(s.pop())















# from typing import Optional, Any
#
# class Node:
#
#     def __init__(self, key: Any, next: Optional['Node'] = None) -> None:
#         """
#         Constructor for the Node class 
#         """
#
#         self.key: Any = key
#         self.next: Optional[Node] = next 
#
#
# class Stack:
#
#     def __init__(self) -> None:
#         """
#         Constructor for the stack class
#         """
#
#         self.top = None
#
#
#     def is_empty(self) -> bool:
#         """
#         Returns true if the stack is empty and false otherwise 
#         """
#
#         return self.top is None
#
#
#     def push(self, key): 
#         """
#         Insert an element to the top of the stack
#         """
#
#         self.top = Node(key, self.top)
#
#
#     def pop(self) -> Any:
#         """
#         Removes and returns the top element from the stack or raises an 
#         error if stack is empty
#         """
#
#         if not self.top:
#             raise IndexError("Stack be empty brah")
#         val = self.top.key 
#         self.top = self.top.next
#         return val 
#
#
#     def peek(self) -> Optional[Any]:
#         """
#         Returns none if stack is empty or the top of the stack
#         """
#
#         if not self.top:
#             return None 
#         return self.top.key
#
#
#     def print_stack(self) -> None:
#         """
#         Prints the stack
#         """
#
#         top = self.top 
#         while top != None:
#             print(top.key)
#             top = top.next 
#
# s = Stack()
#
# s.push(1)
# s.push(2)
# s.push(3)
# s.push(4)
# s.push(5)
#
# s.print_stack()
#
# print(s.peek())
#
# print(s.pop())
#
#
#
#
#
#
#
#
#
#
#
#
#
#
#
# from typing import Optional, Any
#
# class Node:
#
#     def __init__(self, key: Any, next: Optional['Node'] = None) -> None:
#         """
#         Constructor for the Node class 
#         """
#
#         self.key: Any = key
#         self.next: Optional[Node] = next 
#
#
# class Stack:
#
#     def __init__(self) -> None:
#         """
#         Constructor for the stack class
#         """
#
#         self.top = None
#
#
#     def is_empty(self) -> bool:
#         """
#         Returns true if the stack is empty and false otherwise 
#         """
#
#         return self.top is None
#
#
#     def push(self, key): 
#         """
#         Insert an element to the top of the stack
#         """
#
#         self.top = Node(key, self.top)
#
#
#     def pop(self) -> Any:
#         """
#         Removes and returns the top element from the stack or raises an 
#         error if stack is empty
#         """
#
#         if not self.top:
#             raise IndexError("Stack be empty brah")
#         val = self.top.key 
#         self.top = self.top.next
#         return val 
#
#
#     def peek(self) -> Optional[Any]:
#         """
#         Returns none if stack is empty or the top of the stack
#         """
#
#         if not self.top:
#             return None 
#         return self.top.key
#
#
#     def print_stack(self) -> None:
#         """
#         Prints the stack
#         """
#
#         top = self.top 
#         while top != None:
#             print(top.key)
#             top = top.next 
#
# s = Stack()
#
# s.push(1)
# s.push(2)
# s.push(3)
# s.push(4)
# s.push(5)
#
# s.print_stack()
#
# print(s.peek())
#
# print(s.pop())
#
#
#
#
#
#
#
#
#
#
#
#
#
#
#
# from typing import Optional, Any
#
# class Node:
#
#     def __init__(self, key: Any, next: Optional['Node'] = None) -> None:
#         """
#         Constructor for the Node class 
#         """
#
#         self.key: Any = key
#         self.next: Optional[Node] = next 
#
#
# class Stack:
#
#     def __init__(self) -> None:
#         """
#         Constructor for the stack class
#         """
#
#         self.top = None
#
#
#     def is_empty(self) -> bool:
#         """
#         Returns true if the stack is empty and false otherwise 
#         """
#
#         return self.top is None
#
#
#     def push(self, key): 
#         """
#         Insert an element to the top of the stack
#         """
#
#         self.top = Node(key, self.top)
#
#
#     def pop(self) -> Any:
#         """
#         Removes and returns the top element from the stack or raises an 
#         error if stack is empty
#         """
#
#         if not self.top:
#             raise IndexError("Stack be empty brah")
#         val = self.top.key 
#         self.top = self.top.next
#         return val 
#
#
#     def peek(self) -> Optional[Any]:
#         """
#         Returns none if stack is empty or the top of the stack
#         """
#
#         if not self.top:
#             return None 
#         return self.top.key
#
#
#     def print_stack(self) -> None:
#         """
#         Prints the stack
#         """
#
#         top = self.top 
#         while top != None:
#             print(top.key)
#             top = top.next 
#
# s = Stack()
#
# s.push(1)
# s.push(2)
# s.push(3)
# s.push(4)
# s.push(5)
#
# s.print_stack()
#
# print(s.peek())
#
# print(s.pop())
#
#
#
#
#
#
#
#
#
#
#
#
#
#
#
# from typing import Optional, Any
#
# class Node:
#
#     def __init__(self, key: Any, next: Optional['Node'] = None) -> None:
#         """
#         Constructor for the Node class 
#         """
#
#         self.key: Any = key
#         self.next: Optional[Node] = next 
#
#
# class Stack:
#
#     def __init__(self) -> None:
#         """
#         Constructor for the stack class
#         """
#
#         self.top = None
#
#
#     def is_empty(self) -> bool:
#         """
#         Returns true if the stack is empty and false otherwise 
#         """
#
#         return self.top is None
#
#
#     def push(self, key): 
#         """
#         Insert an element to the top of the stack
#         """
#
#         self.top = Node(key, self.top)
#
#
#     def pop(self) -> Any:
#         """
#         Removes and returns the top element from the stack or raises an 
#         error if stack is empty
#         """
#
#         if not self.top:
#             raise IndexError("Stack be empty brah")
#         val = self.top.key 
#         self.top = self.top.next
#         return val 
#
#
#     def peek(self) -> Optional[Any]:
#         """
#         Returns none if stack is empty or the top of the stack
#         """
#
#         if not self.top:
#             return None 
#         return self.top.key
#
#
#     def print_stack(self) -> None:
#         """
#         Prints the stack
#         """
#
#         top = self.top 
#         while top != None:
#             print(top.key)
#             top = top.next 
#
# s = Stack()
#
# s.push(1)
# s.push(2)
# s.push(3)
# s.push(4)
# s.push(5)
#
# s.print_stack()
#
# print(s.peek())
#
# print(s.pop())
#
#
#
#
#
#
#
#
#
#
#
#
#
#
#
# from typing import Optional, Any
#
# class Node:
#
#     def __init__(self, key: Any, next: Optional['Node'] = None) -> None:
#         """
#         Constructor for the Node class 
#         """
#
#         self.key: Any = key
#         self.next: Optional[Node] = next 
#
#
# class Stack:
#
#     def __init__(self) -> None:
#         """
#         Constructor for the stack class
#         """
#
#         self.top = None
#
#
#     def is_empty(self) -> bool:
#         """
#         Returns true if the stack is empty and false otherwise 
#         """
#
#         return self.top is None
#
#
#     def push(self, key): 
#         """
#         Insert an element to the top of the stack
#         """
#
#         self.top = Node(key, self.top)
#
#
#     def pop(self) -> Any:
#         """
#         Removes and returns the top element from the stack or raises an 
#         error if stack is empty
#         """
#
#         if not self.top:
#             raise IndexError("Stack be empty brah")
#         val = self.top.key 
#         self.top = self.top.next
#         return val 
#
#
#     def peek(self) -> Optional[Any]:
#         """
#         Returns none if stack is empty or the top of the stack
#         """
#
#         if not self.top:
#             return None 
#         return self.top.key
#
#
#     def print_stack(self) -> None:
#         """
#         Prints the stack
#         """
#
#         top = self.top 
#         while top != None:
#             print(top.key)
#             top = top.next 
#
# s = Stack()
#
# s.push(1)
# s.push(2)
# s.push(3)
# s.push(4)
# s.push(5)
#
# s.print_stack()
#
# print(s.peek())
#
# print(s.pop())
#
#
#
#
#
#
#
#
#
#
#
#
#
#
#
# from typing import Optional, Any
#
# class Node:
#
#     def __init__(self, key: Any, next: Optional['Node'] = None) -> None:
#         """
#         Constructor for the Node class 
#         """
#
#         self.key: Any = key
#         self.next: Optional[Node] = next 
#
#
# class Stack:
#
#     def __init__(self) -> None:
#         """
#         Constructor for the stack class
#         """
#
#         self.top = None
#
#
#     def is_empty(self) -> bool:
#         """
#         Returns true if the stack is empty and false otherwise 
#         """
#
#         return self.top is None
#
#
#     def push(self, key): 
#         """
#         Insert an element to the top of the stack
#         """
#
#         self.top = Node(key, self.top)
#
#
#     def pop(self) -> Any:
#         """
#         Removes and returns the top element from the stack or raises an 
#         error if stack is empty
#         """
#
#         if not self.top:
#             raise IndexError("Stack be empty brah")
#         val = self.top.key 
#         self.top = self.top.next
#         return val 
#
#
#     def peek(self) -> Optional[Any]:
#         """
#         Returns none if stack is empty or the top of the stack
#         """
#
#         if not self.top:
#             return None 
#         return self.top.key
#
#
#     def print_stack(self) -> None:
#         """
#         Prints the stack
#         """
#
#         top = self.top 
#         while top != None:
#             print(top.key)
#             top = top.next 
#
# s = Stack()
#
# s.push(1)
# s.push(2)
# s.push(3)
# s.push(4)
# s.push(5)
#
# s.print_stack()
#
# print(s.peek())
#
# print(s.pop())
#
#
#
#
#
#
#
#
#
#
#
#
#
#
#
# from typing import Optional, Any
#
# class Node:
#
#     def __init__(self, key: Any, next: Optional['Node'] = None) -> None:
#         """
#         Constructor for the Node class 
#         """
#
#         self.key: Any = key
#         self.next: Optional[Node] = next 
#
#
# class Stack:
#
#     def __init__(self) -> None:
#         """
#         Constructor for the stack class
#         """
#
#         self.top = None
#
#
#     def is_empty(self) -> bool:
#         """
#         Returns true if the stack is empty and false otherwise 
#         """
#
#         return self.top is None
#
#
#     def push(self, key): 
#         """
#         Insert an element to the top of the stack
#         """
#
#         self.top = Node(key, self.top)
#
#
#     def pop(self) -> Any:
#         """
#         Removes and returns the top element from the stack or raises an 
#         error if stack is empty
#         """
#
#         if not self.top:
#             raise IndexError("Stack be empty brah")
#         val = self.top.key 
#         self.top = self.top.next
#         return val 
#
#
#     def peek(self) -> Optional[Any]:
#         """
#         Returns none if stack is empty or the top of the stack
#         """
#
#         if not self.top:
#             return None 
#         return self.top.key
#
#
#     def print_stack(self) -> None:
#         """
#         Prints the stack
#         """
#
#         top = self.top 
#         while top != None:
#             print(top.key)
#             top = top.next 
#
# s = Stack()
#
# s.push(1)
# s.push(2)
# s.push(3)
# s.push(4)
# s.push(5)
#
# s.print_stack()
#
# print(s.peek())
#
# print(s.pop())
#
#
#
#
#
#
#
#
#
#
#
#
#
#
#
# from typing import Optional, Any
#
# class Node:
#
#     def __init__(self, key: Any, next: Optional['Node'] = None) -> None:
#         """
#         Constructor for the Node class 
#         """
#
#         self.key: Any = key
#         self.next: Optional[Node] = next 
#
#
# class Stack:
#
#     def __init__(self) -> None:
#         """
#         Constructor for the stack class
#         """
#
#         self.top = None
#
#
#     def is_empty(self) -> bool:
#         """
#         Returns true if the stack is empty and false otherwise 
#         """
#
#         return self.top is None
#
#
#     def push(self, key): 
#         """
#         Insert an element to the top of the stack
#         """
#
#         self.top = Node(key, self.top)
#
#
#     def pop(self) -> Any:
#         """
#         Removes and returns the top element from the stack or raises an 
#         error if stack is empty
#         """
#
#         if not self.top:
#             raise IndexError("Stack be empty brah")
#         val = self.top.key 
#         self.top = self.top.next
#         return val 
#
#
#     def peek(self) -> Optional[Any]:
#         """
#         Returns none if stack is empty or the top of the stack
#         """
#
#         if not self.top:
#             return None 
#         return self.top.key
#
#
#     def print_stack(self) -> None:
#         """
#         Prints the stack
#         """
#
#         top = self.top 
#         while top != None:
#             print(top.key)
#             top = top.next 
#
# s = Stack()
#
# s.push(1)
# s.push(2)
# s.push(3)
# s.push(4)
# s.push(5)
#
# s.print_stack()
#
# print(s.peek())
#
# print(s.pop())
#
#
#
#
#
#
#
#
#
#
#
#
#
#
#
# from typing import Optional, Any
#
# class Node:
#
#     def __init__(self, key: Any, next: Optional['Node'] = None) -> None:
#         """
#         Constructor for the Node class 
#         """
#
#         self.key: Any = key
#         self.next: Optional[Node] = next 
#
#
# class Stack:
#
#     def __init__(self) -> None:
#         """
#         Constructor for the stack class
#         """
#
#         self.top = None
#
#
#     def is_empty(self) -> bool:
#         """
#         Returns true if the stack is empty and false otherwise 
#         """
#
#         return self.top is None
#
#
#     def push(self, key): 
#         """
#         Insert an element to the top of the stack
#         """
#
#         self.top = Node(key, self.top)
#
#
#     def pop(self) -> Any:
#         """
#         Removes and returns the top element from the stack or raises an 
#         error if stack is empty
#         """
#
#         if not self.top:
#             raise IndexError("Stack be empty brah")
#         val = self.top.key 
#         self.top = self.top.next
#         return val 
#
#
#     def peek(self) -> Optional[Any]:
#         """
#         Returns none if stack is empty or the top of the stack
#         """
#
#         if not self.top:
#             return None 
#         return self.top.key
#
#
#     def print_stack(self) -> None:
#         """
#         Prints the stack
#         """
#
#         top = self.top 
#         while top != None:
#             print(top.key)
#             top = top.next 
#
# s = Stack()
#
# s.push(1)
# s.push(2)
# s.push(3)
# s.push(4)
# s.push(5)
#
# s.print_stack()
#
# print(s.peek())
#
# print(s.pop())
#
#
#
#
#
#
#
#
#
#
#
#
#
#
#
# from typing import Optional, Any
#
# class Node:
#
#     def __init__(self, key: Any, next: Optional['Node'] = None) -> None:
#         """
#         Constructor for the Node class 
#         """
#
#         self.key: Any = key
#         self.next: Optional[Node] = next 
#
#
# class Stack:
#
#     def __init__(self) -> None:
#         """
#         Constructor for the stack class
#         """
#
#         self.top = None
#
#
#     def is_empty(self) -> bool:
#         """
#         Returns true if the stack is empty and false otherwise 
#         """
#
#         return self.top is None
#
#
#     def push(self, key): 
#         """
#         Insert an element to the top of the stack
#         """
#
#         self.top = Node(key, self.top)
#
#
#     def pop(self) -> Any:
#         """
#         Removes and returns the top element from the stack or raises an 
#         error if stack is empty
#         """
#
#         if not self.top:
#             raise IndexError("Stack be empty brah")
#         val = self.top.key 
#         self.top = self.top.next
#         return val 
#
#
#     def peek(self) -> Optional[Any]:
#         """
#         Returns none if stack is empty or the top of the stack
#         """
#
#         if not self.top:
#             return None 
#         return self.top.key
#
#
#     def print_stack(self) -> None:
#         """
#         Prints the stack
#         """
#
#         top = self.top 
#         while top != None:
#             print(top.key)
#             top = top.next 
#
# s = Stack()
#
# s.push(1)
# s.push(2)
# s.push(3)
# s.push(4)
# s.push(5)
#
# s.print_stack()
#
# print(s.peek())
#
# print(s.pop())
#
#
#
#
#
#
#
#
#
#
#
#
#
#
#
# from typing import Optional, Any
#
# class Node:
#
#     def __init__(self, key: Any, next: Optional['Node'] = None) -> None:
#         """
#         Constructor for the Node class 
#         """
#
#         self.key: Any = key
#         self.next: Optional[Node] = next 
#
#
# class Stack:
#
#     def __init__(self) -> None:
#         """
#         Constructor for the stack class
#         """
#
#         self.top = None
#
#
#     def is_empty(self) -> bool:
#         """
#         Returns true if the stack is empty and false otherwise 
#         """
#
#         return self.top is None
#
#
#     def push(self, key): 
#         """
#         Insert an element to the top of the stack
#         """
#
#         self.top = Node(key, self.top)
#
#
#     def pop(self) -> Any:
#         """
#         Removes and returns the top element from the stack or raises an 
#         error if stack is empty
#         """
#
#         if not self.top:
#             raise IndexError("Stack be empty brah")
#         val = self.top.key 
#         self.top = self.top.next
#         return val 
#
#
#     def peek(self) -> Optional[Any]:
#         """
#         Returns none if stack is empty or the top of the stack
#         """
#
#         if not self.top:
#             return None 
#         return self.top.key
#
#
#     def print_stack(self) -> None:
#         """
#         Prints the stack
#         """
#
#         top = self.top 
#         while top != None:
#             print(top.key)
#             top = top.next 
#
# s = Stack()
#
# s.push(1)
# s.push(2)
# s.push(3)
# s.push(4)
# s.push(5)
#
# s.print_stack()
#
# print(s.peek())
#
# print(s.pop())
#
#
#
#
#
#
#
#
#
#
#
#
#
#
#
# from typing import Optional, Any
#
# class Node:
#
#     def __init__(self, key: Any, next: Optional['Node'] = None) -> None:
#         """
#         Constructor for the Node class 
#         """
#
#         self.key: Any = key
#         self.next: Optional[Node] = next 
#
#
# class Stack:
#
#     def __init__(self) -> None:
#         """
#         Constructor for the stack class
#         """
#
#         self.top = None
#
#
#     def is_empty(self) -> bool:
#         """
#         Returns true if the stack is empty and false otherwise 
#         """
#
#         return self.top is None
#
#
#     def push(self, key): 
#         """
#         Insert an element to the top of the stack
#         """
#
#         self.top = Node(key, self.top)
#
#
#     def pop(self) -> Any:
#         """
#         Removes and returns the top element from the stack or raises an 
#         error if stack is empty
#         """
#
#         if not self.top:
#             raise IndexError("Stack be empty brah")
#         val = self.top.key 
#         self.top = self.top.next
#         return val 
#
#
#     def peek(self) -> Optional[Any]:
#         """
#         Returns none if stack is empty or the top of the stack
#         """
#
#         if not self.top:
#             return None 
#         return self.top.key
#
#
#     def print_stack(self) -> None:
#         """
#         Prints the stack
#         """
#
#         top = self.top 
#         while top != None:
#             print(top.key)
#             top = top.next 
#
# s = Stack()
#
# s.push(1)
# s.push(2)
# s.push(3)
# s.push(4)
# s.push(5)
#
# s.print_stack()
#
# print(s.peek())
#
# print(s.pop())
#
#
#
#
#
#
#
#
#
#
#
#
#
#
#
# from typing import Optional, Any
#
# class Node:
#
#     def __init__(self, key: Any, next: Optional['Node'] = None) -> None:
#         """
#         Constructor for the Node class 
#         """
#
#         self.key: Any = key
#         self.next: Optional[Node] = next 
#
#
# class Stack:
#
#     def __init__(self) -> None:
#         """
#         Constructor for the stack class
#         """
#
#         self.top = None
#
#
#     def is_empty(self) -> bool:
#         """
#         Returns true if the stack is empty and false otherwise 
#         """
#
#         return self.top is None
#
#
#     def push(self, key): 
#         """
#         Insert an element to the top of the stack
#         """
#
#         self.top = Node(key, self.top)
#
#
#     def pop(self) -> Any:
#         """
#         Removes and returns the top element from the stack or raises an 
#         error if stack is empty
#         """
#
#         if not self.top:
#             raise IndexError("Stack be empty brah")
#         val = self.top.key 
#         self.top = self.top.next
#         return val 
#
#
#     def peek(self) -> Optional[Any]:
#         """
#         Returns none if stack is empty or the top of the stack
#         """
#
#         if not self.top:
#             return None 
#         return self.top.key
#
#
#     def print_stack(self) -> None:
#         """
#         Prints the stack
#         """
#
#         top = self.top 
#         while top != None:
#             print(top.key)
#             top = top.next 
#
# s = Stack()
#
# s.push(1)
# s.push(2)
# s.push(3)
# s.push(4)
# s.push(5)
#
# s.print_stack()
#
# print(s.peek())
#
# print(s.pop())
#
#
#
#
#
#
#
#
#
#
#
#
#
#
#
# from typing import Optional, Any
#
# class Node:
#
#     def __init__(self, key: Any, next: Optional['Node'] = None) -> None:
#         """
#         Constructor for the Node class 
#         """
#
#         self.key: Any = key
#         self.next: Optional[Node] = next 
#
#
# class Stack:
#
#     def __init__(self) -> None:
#         """
#         Constructor for the stack class
#         """
#
#         self.top = None
#
#
#     def is_empty(self) -> bool:
#         """
#         Returns true if the stack is empty and false otherwise 
#         """
#
#         return self.top is None
#
#
#     def push(self, key): 
#         """
#         Insert an element to the top of the stack
#         """
#
#         self.top = Node(key, self.top)
#
#
#     def pop(self) -> Any:
#         """
#         Removes and returns the top element from the stack or raises an 
#         error if stack is empty
#         """
#
#         if not self.top:
#             raise IndexError("Stack be empty brah")
#         val = self.top.key 
#         self.top = self.top.next
#         return val 
#
#
#     def peek(self) -> Optional[Any]:
#         """
#         Returns none if stack is empty or the top of the stack
#         """
#
#         if not self.top:
#             return None 
#         return self.top.key
#
#
#     def print_stack(self) -> None:
#         """
#         Prints the stack
#         """
#
#         top = self.top 
#         while top != None:
#             print(top.key)
#             top = top.next 
#
# s = Stack()
#
# s.push(1)
# s.push(2)
# s.push(3)
# s.push(4)
# s.push(5)
#
# s.print_stack()
#
# print(s.peek())
#
# print(s.pop())
#
#
#
#
#
#
#
#
#
#
#
#
#
#
#
# from typing import Optional, Any
#
# class Node:
#
#     def __init__(self, key: Any, next: Optional['Node'] = None) -> None:
#         """
#         Constructor for the Node class 
#         """
#
#         self.key: Any = key
#         self.next: Optional[Node] = next 
#
#
# class Stack:
#
#     def __init__(self) -> None:
#         """
#         Constructor for the stack class
#         """
#
#         self.top = None
#
#
#     def is_empty(self) -> bool:
#         """
#         Returns true if the stack is empty and false otherwise 
#         """
#
#         return self.top is None
#
#
#     def push(self, key): 
#         """
#         Insert an element to the top of the stack
#         """
#
#         self.top = Node(key, self.top)
#
#
#     def pop(self) -> Any:
#         """
#         Removes and returns the top element from the stack or raises an 
#         error if stack is empty
#         """
#
#         if not self.top:
#             raise IndexError("Stack be empty brah")
#         val = self.top.key 
#         self.top = self.top.next
#         return val 
#
#
#     def peek(self) -> Optional[Any]:
#         """
#         Returns none if stack is empty or the top of the stack
#         """
#
#         if not self.top:
#             return None 
#         return self.top.key
#
#
#     def print_stack(self) -> None:
#         """
#         Prints the stack
#         """
#
#         top = self.top 
#         while top != None:
#             print(top.key)
#             top = top.next 
#
# s = Stack()
#
# s.push(1)
# s.push(2)
# s.push(3)
# s.push(4)
# s.push(5)
#
# s.print_stack()
#
# print(s.peek())
#
# print(s.pop())
#
#
#
#
#
#
#
#
#
#
#
#
#
#
#
# from typing import Optional, Any
#
# class Node:
#
#     def __init__(self, key: Any, next: Optional['Node'] = None) -> None:
#         """
#         Constructor for the Node class 
#         """
#
#         self.key: Any = key
#         self.next: Optional[Node] = next 
#
#
# class Stack:
#
#     def __init__(self) -> None:
#         """
#         Constructor for the stack class
#         """
#
#         self.top = None
#
#
#     def is_empty(self) -> bool:
#         """
#         Returns true if the stack is empty and false otherwise 
#         """
#
#         return self.top is None
#
#
#     def push(self, key): 
#         """
#         Insert an element to the top of the stack
#         """
#
#         self.top = Node(key, self.top)
#
#
#     def pop(self) -> Any:
#         """
#         Removes and returns the top element from the stack or raises an 
#         error if stack is empty
#         """
#
#         if not self.top:
#             raise IndexError("Stack be empty brah")
#         val = self.top.key 
#         self.top = self.top.next
#         return val 
#
#
#     def peek(self) -> Optional[Any]:
#         """
#         Returns none if stack is empty or the top of the stack
#         """
#
#         if not self.top:
#             return None 
#         return self.top.key
#
#
#     def print_stack(self) -> None:
#         """
#         Prints the stack
#         """
#
#         top = self.top 
#         while top != None:
#             print(top.key)
#             top = top.next 
#
# s = Stack()
#
# s.push(1)
# s.push(2)
# s.push(3)
# s.push(4)
# s.push(5)
#
# s.print_stack()
#
# print(s.peek())
#
# print(s.pop())
#
#
#
#
#
#
#
#
#
#
#
#
#
#
#
# from typing import Optional, Any
#
# class Node:
#
#     def __init__(self, key: Any, next: Optional['Node'] = None) -> None:
#         """
#         Constructor for the Node class 
#         """
#
#         self.key: Any = key
#         self.next: Optional[Node] = next 
#
#
# class Stack:
#
#     def __init__(self) -> None:
#         """
#         Constructor for the stack class
#         """
#
#         self.top = None
#
#
#     def is_empty(self) -> bool:
#         """
#         Returns true if the stack is empty and false otherwise 
#         """
#
#         return self.top is None
#
#
#     def push(self, key): 
#         """
#         Insert an element to the top of the stack
#         """
#
#         self.top = Node(key, self.top)
#
#
#     def pop(self) -> Any:
#         """
#         Removes and returns the top element from the stack or raises an 
#         error if stack is empty
#         """
#
#         if not self.top:
#             raise IndexError("Stack be empty brah")
#         val = self.top.key 
#         self.top = self.top.next
#         return val 
#
#
#     def peek(self) -> Optional[Any]:
#         """
#         Returns none if stack is empty or the top of the stack
#         """
#
#         if not self.top:
#             return None 
#         return self.top.key
#
#
#     def print_stack(self) -> None:
#         """
#         Prints the stack
#         """
#
#         top = self.top 
#         while top != None:
#             print(top.key)
#             top = top.next 
#
# s = Stack()
#
# s.push(1)
# s.push(2)
# s.push(3)
# s.push(4)
# s.push(5)
#
# s.print_stack()
#
# print(s.peek())
#
# print(s.pop())
#
#
#
#
#
#
#
#
#
#
#
#
#
#
#
# from typing import Optional, Any
#
# class Node:
#
#     def __init__(self, key: Any, next: Optional['Node'] = None) -> None:
#         """
#         Constructor for the Node class 
#         """
#
#         self.key: Any = key
#         self.next: Optional[Node] = next 
#
#
# class Stack:
#
#     def __init__(self) -> None:
#         """
#         Constructor for the stack class
#         """
#
#         self.top = None
#
#
#     def is_empty(self) -> bool:
#         """
#         Returns true if the stack is empty and false otherwise 
#         """
#
#         return self.top is None
#
#
#     def push(self, key): 
#         """
#         Insert an element to the top of the stack
#         """
#
#         self.top = Node(key, self.top)
#
#
#     def pop(self) -> Any:
#         """
#         Removes and returns the top element from the stack or raises an 
#         error if stack is empty
#         """
#
#         if not self.top:
#             raise IndexError("Stack be empty brah")
#         val = self.top.key 
#         self.top = self.top.next
#         return val 
#
#
#     def peek(self) -> Optional[Any]:
#         """
#         Returns none if stack is empty or the top of the stack
#         """
#
#         if not self.top:
#             return None 
#         return self.top.key
#
#
#     def print_stack(self) -> None:
#         """
#         Prints the stack
#         """
#
#         top = self.top 
#         while top != None:
#             print(top.key)
#             top = top.next 
#
# s = Stack()
#
# s.push(1)
# s.push(2)
# s.push(3)
# s.push(4)
# s.push(5)
#
# s.print_stack()
#
# print(s.peek())
#
# print(s.pop())
#
#
#
#
#
#
#
#
#
#
#
#
#
#
#
# from typing import Optional, Any
#
# class Node:
#
#     def __init__(self, key: Any, next: Optional['Node'] = None) -> None:
#         """
#         Constructor for the Node class 
#         """
#
#         self.key: Any = key
#         self.next: Optional[Node] = next 
#
#
# class Stack:
#
#     def __init__(self) -> None:
#         """
#         Constructor for the stack class
#         """
#
#         self.top = None
#
#
#     def is_empty(self) -> bool:
#         """
#         Returns true if the stack is empty and false otherwise 
#         """
#
#         return self.top is None
#
#
#     def push(self, key): 
#         """
#         Insert an element to the top of the stack
#         """
#
#         self.top = Node(key, self.top)
#
#
#     def pop(self) -> Any:
#         """
#         Removes and returns the top element from the stack or raises an 
#         error if stack is empty
#         """
#
#         if not self.top:
#             raise IndexError("Stack be empty brah")
#         val = self.top.key 
#         self.top = self.top.next
#         return val 
#
#
#     def peek(self) -> Optional[Any]:
#         """
#         Returns none if stack is empty or the top of the stack
#         """
#
#         if not self.top:
#             return None 
#         return self.top.key
#
#
#     def print_stack(self) -> None:
#         """
#         Prints the stack
#         """
#
#         top = self.top 
#         while top != None:
#             print(top.key)
#             top = top.next 
#
# s = Stack()
#
# s.push(1)
# s.push(2)
# s.push(3)
# s.push(4)
# s.push(5)
#
# s.print_stack()
#
# print(s.peek())
#
# print(s.pop())
#
#
#
#
#
#
#
#
#
#
#
#
#
#
#
# from typing import Optional, Any
#
# class Node:
#
#     def __init__(self, key: Any, next: Optional['Node'] = None) -> None:
#         """
#         Constructor for the Node class 
#         """
#
#         self.key: Any = key
#         self.next: Optional[Node] = next 
#
#
# class Stack:
#
#     def __init__(self) -> None:
#         """
#         Constructor for the stack class
#         """
#
#         self.top = None
#
#
#     def is_empty(self) -> bool:
#         """
#         Returns true if the stack is empty and false otherwise 
#         """
#
#         return self.top is None
#
#
#     def push(self, key): 
#         """
#         Insert an element to the top of the stack
#         """
#
#         self.top = Node(key, self.top)
#
#
#     def pop(self) -> Any:
#         """
#         Removes and returns the top element from the stack or raises an 
#         error if stack is empty
#         """
#
#         if not self.top:
#             raise IndexError("Stack be empty brah")
#         val = self.top.key 
#         self.top = self.top.next
#         return val 
#
#
#     def peek(self) -> Optional[Any]:
#         """
#         Returns none if stack is empty or the top of the stack
#         """
#
#         if not self.top:
#             return None 
#         return self.top.key
#
#
#     def print_stack(self) -> None:
#         """
#         Prints the stack
#         """
#
#         top = self.top 
#         while top != None:
#             print(top.key)
#             top = top.next 
#
# s = Stack()
#
# s.push(1)
# s.push(2)
# s.push(3)
# s.push(4)
# s.push(5)
#
# s.print_stack()
#
# print(s.peek())
#
# print(s.pop())
#
#
#
#
#
#
#
#
#
#
#
#
#
#
#
# from typing import Optional, Any
#
# class Node:
#
#     def __init__(self, key: Any, next: Optional['Node'] = None) -> None:
#         """
#         Constructor for the Node class 
#         """
#
#         self.key: Any = key
#         self.next: Optional[Node] = next 
#
#
# class Stack:
#
#     def __init__(self) -> None:
#         """
#         Constructor for the stack class
#         """
#
#         self.top = None
#
#
#     def is_empty(self) -> bool:
#         """
#         Returns true if the stack is empty and false otherwise 
#         """
#
#         return self.top is None
#
#
#     def push(self, key): 
#         """
#         Insert an element to the top of the stack
#         """
#
#         self.top = Node(key, self.top)
#
#
#     def pop(self) -> Any:
#         """
#         Removes and returns the top element from the stack or raises an 
#         error if stack is empty
#         """
#
#         if not self.top:
#             raise IndexError("Stack be empty brah")
#         val = self.top.key 
#         self.top = self.top.next
#         return val 
#
#
#     def peek(self) -> Optional[Any]:
#         """
#         Returns none if stack is empty or the top of the stack
#         """
#
#         if not self.top:
#             return None 
#         return self.top.key
#
#
#     def print_stack(self) -> None:
#         """
#         Prints the stack
#         """
#
#         top = self.top 
#         while top != None:
#             print(top.key)
#             top = top.next 
#
# s = Stack()
#
# s.push(1)
# s.push(2)
# s.push(3)
# s.push(4)
# s.push(5)
#
# s.print_stack()
#
# print(s.peek())
#
# print(s.pop())
#
#
#
#
#
#
#
#
#
#
#
#
#
#
#
# from typing import Optional, Any
#
# class Node:
#
#     def __init__(self, key: Any, next: Optional['Node'] = None) -> None:
#         """
#         Constructor for the Node class 
#         """
#
#         self.key: Any = key
#         self.next: Optional[Node] = next 
#
#
# class Stack:
#
#     def __init__(self) -> None:
#         """
#         Constructor for the stack class
#         """
#
#         self.top = None
#
#
#     def is_empty(self) -> bool:
#         """
#         Returns true if the stack is empty and false otherwise 
#         """
#
#         return self.top is None
#
#
#     def push(self, key): 
#         """
#         Insert an element to the top of the stack
#         """
#
#         self.top = Node(key, self.top)
#
#
#     def pop(self) -> Any:
#         """
#         Removes and returns the top element from the stack or raises an 
#         error if stack is empty
#         """
#
#         if not self.top:
#             raise IndexError("Stack be empty brah")
#         val = self.top.key 
#         self.top = self.top.next
#         return val 
#
#
#     def peek(self) -> Optional[Any]:
#         """
#         Returns none if stack is empty or the top of the stack
#         """
#
#         if not self.top:
#             return None 
#         return self.top.key
#
#
#     def print_stack(self) -> None:
#         """
#         Prints the stack
#         """
#
#         top = self.top 
#         while top != None:
#             print(top.key)
#             top = top.next 
#
# s = Stack()
#
# s.push(1)
# s.push(2)
# s.push(3)
# s.push(4)
# s.push(5)
#
# s.print_stack()
#
# print(s.peek())
#
# print(s.pop())
#
#
#
#
#
#
#
#
#
#
#
#
#
#
#
# from typing import Optional, Any
#
# class Node:
#
#     def __init__(self, key: Any, next: Optional['Node'] = None) -> None:
#         """
#         Constructor for the Node class 
#         """
#
#         self.key: Any = key
#         self.next: Optional[Node] = next 
#
#
# class Stack:
#
#     def __init__(self) -> None:
#         """
#         Constructor for the stack class
#         """
#
#         self.top = None
#
#
#     def is_empty(self) -> bool:
#         """
#         Returns true if the stack is empty and false otherwise 
#         """
#
#         return self.top is None
#
#
#     def push(self, key): 
#         """
#         Insert an element to the top of the stack
#         """
#
#         self.top = Node(key, self.top)
#
#
#     def pop(self) -> Any:
#         """
#         Removes and returns the top element from the stack or raises an 
#         error if stack is empty
#         """
#
#         if not self.top:
#             raise IndexError("Stack be empty brah")
#         val = self.top.key 
#         self.top = self.top.next
#         return val 
#
#
#     def peek(self) -> Optional[Any]:
#         """
#         Returns none if stack is empty or the top of the stack
#         """
#
#         if not self.top:
#             return None 
#         return self.top.key
#
#
#     def print_stack(self) -> None:
#         """
#         Prints the stack
#         """
#
#         top = self.top 
#         while top != None:
#             print(top.key)
#             top = top.next 
#
# s = Stack()
#
# s.push(1)
# s.push(2)
# s.push(3)
# s.push(4)
# s.push(5)
#
# s.print_stack()
#
# print(s.peek())
#
# print(s.pop())
#
#
#
#
#
#
#
#
#
#
#
#
#
#
#
# from typing import Optional, Any
#
# class Node:
#
#     def __init__(self, key: Any, next: Optional['Node'] = None) -> None:
#         """
#         Constructor for the Node class 
#         """
#
#         self.key: Any = key
#         self.next: Optional[Node] = next 
#
#
# class Stack:
#
#     def __init__(self) -> None:
#         """
#         Constructor for the stack class
#         """
#
#         self.top = None
#
#
#     def is_empty(self) -> bool:
#         """
#         Returns true if the stack is empty and false otherwise 
#         """
#
#         return self.top is None
#
#
#     def push(self, key): 
#         """
#         Insert an element to the top of the stack
#         """
#
#         self.top = Node(key, self.top)
#
#
#     def pop(self) -> Any:
#         """
#         Removes and returns the top element from the stack or raises an 
#         error if stack is empty
#         """
#
#         if not self.top:
#             raise IndexError("Stack be empty brah")
#         val = self.top.key 
#         self.top = self.top.next
#         return val 
#
#
#     def peek(self) -> Optional[Any]:
#         """
#         Returns none if stack is empty or the top of the stack
#         """
#
#         if not self.top:
#             return None 
#         return self.top.key
#
#
#     def print_stack(self) -> None:
#         """
#         Prints the stack
#         """
#
#         top = self.top 
#         while top != None:
#             print(top.key)
#             top = top.next 
#
# s = Stack()
#
# s.push(1)
# s.push(2)
# s.push(3)
# s.push(4)
# s.push(5)
#
# s.print_stack()
#
# print(s.peek())
#
# print(s.pop())
#
#
#
#
#
#
#
#
#
#
#
#
#
#
#
# from typing import Optional, Any
#
# class Node:
#
#     def __init__(self, key: Any, next: Optional['Node'] = None) -> None:
#         """
#         Constructor for the Node class 
#         """
#
#         self.key: Any = key
#         self.next: Optional[Node] = next 
#
#
# class Stack:
#
#     def __init__(self) -> None:
#         """
#         Constructor for the stack class
#         """
#
#         self.top = None
#
#
#     def is_empty(self) -> bool:
#         """
#         Returns true if the stack is empty and false otherwise 
#         """
#
#         return self.top is None
#
#
#     def push(self, key): 
#         """
#         Insert an element to the top of the stack
#         """
#
#         self.top = Node(key, self.top)
#
#
#     def pop(self) -> Any:
#         """
#         Removes and returns the top element from the stack or raises an 
#         error if stack is empty
#         """
#
#         if not self.top:
#             raise IndexError("Stack be empty brah")
#         val = self.top.key 
#         self.top = self.top.next
#         return val 
#
#
#     def peek(self) -> Optional[Any]:
#         """
#         Returns none if stack is empty or the top of the stack
#         """
#
#         if not self.top:
#             return None 
#         return self.top.key
#
#
#     def print_stack(self) -> None:
#         """
#         Prints the stack
#         """
#
#         top = self.top 
#         while top != None:
#             print(top.key)
#             top = top.next 
#
# s = Stack()
#
# s.push(1)
# s.push(2)
# s.push(3)
# s.push(4)
# s.push(5)
#
# s.print_stack()
#
# print(s.peek())
#
# print(s.pop())
#
#
#
#
#
#
#
#
#
#
#
#
#
#
#
# from typing import Optional, Any
#
# class Node:
#
#     def __init__(self, key: Any, next: Optional['Node'] = None) -> None:
#         """
#         Constructor for the Node class 
#         """
#
#         self.key: Any = key
#         self.next: Optional[Node] = next 
#
#
# class Stack:
#
#     def __init__(self) -> None:
#         """
#         Constructor for the stack class
#         """
#
#         self.top = None
#
#
#     def is_empty(self) -> bool:
#         """
#         Returns true if the stack is empty and false otherwise 
#         """
#
#         return self.top is None
#
#
#     def push(self, key): 
#         """
#         Insert an element to the top of the stack
#         """
#
#         self.top = Node(key, self.top)
#
#
#     def pop(self) -> Any:
#         """
#         Removes and returns the top element from the stack or raises an 
#         error if stack is empty
#         """
#
#         if not self.top:
#             raise IndexError("Stack be empty brah")
#         val = self.top.key 
#         self.top = self.top.next
#         return val 
#
#
#     def peek(self) -> Optional[Any]:
#         """
#         Returns none if stack is empty or the top of the stack
#         """
#
#         if not self.top:
#             return None 
#         return self.top.key
#
#
#     def print_stack(self) -> None:
#         """
#         Prints the stack
#         """
#
#         top = self.top 
#         while top != None:
#             print(top.key)
#             top = top.next 
#
# s = Stack()
#
# s.push(1)
# s.push(2)
# s.push(3)
# s.push(4)
# s.push(5)
#
# s.print_stack()
#
# print(s.peek())
#
# print(s.pop())
#
#
#
#
#
#
#
#
#
#
#
#
#
#
#
# from typing import Optional, Any
#
# class Node:
#
#     def __init__(self, key: Any, next: Optional['Node'] = None) -> None:
#         """
#         Constructor for the Node class 
#         """
#
#         self.key: Any = key
#         self.next: Optional[Node] = next 
#
#
# class Stack:
#
#     def __init__(self) -> None:
#         """
#         Constructor for the stack class
#         """
#
#         self.top = None
#
#
#     def is_empty(self) -> bool:
#         """
#         Returns true if the stack is empty and false otherwise 
#         """
#
#         return self.top is None
#
#
#     def push(self, key): 
#         """
#         Insert an element to the top of the stack
#         """
#
#         self.top = Node(key, self.top)
#
#
#     def pop(self) -> Any:
#         """
#         Removes and returns the top element from the stack or raises an 
#         error if stack is empty
#         """
#
#         if not self.top:
#             raise IndexError("Stack be empty brah")
#         val = self.top.key 
#         self.top = self.top.next
#         return val 
#
#
#     def peek(self) -> Optional[Any]:
#         """
#         Returns none if stack is empty or the top of the stack
#         """
#
#         if not self.top:
#             return None 
#         return self.top.key
#
#
#     def print_stack(self) -> None:
#         """
#         Prints the stack
#         """
#
#         top = self.top 
#         while top != None:
#             print(top.key)
#             top = top.next 
#
# s = Stack()
#
# s.push(1)
# s.push(2)
# s.push(3)
# s.push(4)
# s.push(5)
#
# s.print_stack()
#
# print(s.peek())
#
# print(s.pop())
#
#
#
#
#
#
#
#
#
#
#
#
#
#
#
# from typing import Optional, Any
#
# class Node:
#
#     def __init__(self, key: Any, next: Optional['Node'] = None) -> None:
#         """
#         Constructor for the Node class 
#         """
#
#         self.key: Any = key
#         self.next: Optional[Node] = next 
#
#
# class Stack:
#
#     def __init__(self) -> None:
#         """
#         Constructor for the stack class
#         """
#
#         self.top = None
#
#
#     def is_empty(self) -> bool:
#         """
#         Returns true if the stack is empty and false otherwise 
#         """
#
#         return self.top is None
#
#
#     def push(self, key): 
#         """
#         Insert an element to the top of the stack
#         """
#
#         self.top = Node(key, self.top)
#
#
#     def pop(self) -> Any:
#         """
#         Removes and returns the top element from the stack or raises an 
#         error if stack is empty
#         """
#
#         if not self.top:
#             raise IndexError("Stack be empty brah")
#         val = self.top.key 
#         self.top = self.top.next
#         return val 
#
#
#     def peek(self) -> Optional[Any]:
#         """
#         Returns none if stack is empty or the top of the stack
#         """
#
#         if not self.top:
#             return None 
#         return self.top.key
#
#
#     def print_stack(self) -> None:
#         """
#         Prints the stack
#         """
#
#         top = self.top 
#         while top != None:
#             print(top.key)
#             top = top.next 
#
# s = Stack()
#
# s.push(1)
# s.push(2)
# s.push(3)
# s.push(4)
# s.push(5)
#
# s.print_stack()
#
# print(s.peek())
#
# print(s.pop())
#
#
#
#
#
#
#
#
#
#
#
#
#
#
#
# from typing import Optional, Any
#
# class Node:
#
#     def __init__(self, key: Any, next: Optional['Node'] = None) -> None:
#         """
#         Constructor for the Node class 
#         """
#
#         self.key: Any = key
#         self.next: Optional[Node] = next 
#
#
# class Stack:
#
#     def __init__(self) -> None:
#         """
#         Constructor for the stack class
#         """
#
#         self.top = None
#
#
#     def is_empty(self) -> bool:
#         """
#         Returns true if the stack is empty and false otherwise 
#         """
#
#         return self.top is None
#
#
#     def push(self, key): 
#         """
#         Insert an element to the top of the stack
#         """
#
#         self.top = Node(key, self.top)
#
#
#     def pop(self) -> Any:
#         """
#         Removes and returns the top element from the stack or raises an 
#         error if stack is empty
#         """
#
#         if not self.top:
#             raise IndexError("Stack be empty brah")
#         val = self.top.key 
#         self.top = self.top.next
#         return val 
#
#
#     def peek(self) -> Optional[Any]:
#         """
#         Returns none if stack is empty or the top of the stack
#         """
#
#         if not self.top:
#             return None 
#         return self.top.key
#
#
#     def print_stack(self) -> None:
#         """
#         Prints the stack
#         """
#
#         top = self.top 
#         while top != None:
#             print(top.key)
#             top = top.next 
#
# s = Stack()
#
# s.push(1)
# s.push(2)
# s.push(3)
# s.push(4)
# s.push(5)
#
# s.print_stack()
#
# print(s.peek())
#
# print(s.pop())
#
#
#
#
#
#
#
#
#
#
#
#
#
#
#
# from typing import Optional, Any
#
# class Node:
#
#     def __init__(self, key: Any, next: Optional['Node'] = None) -> None:
#         """
#         Constructor for the Node class 
#         """
#
#         self.key: Any = key
#         self.next: Optional[Node] = next 
#
#
# class Stack:
#
#     def __init__(self) -> None:
#         """
#         Constructor for the stack class
#         """
#
#         self.top = None
#
#
#     def is_empty(self) -> bool:
#         """
#         Returns true if the stack is empty and false otherwise 
#         """
#
#         return self.top is None
#
#
#     def push(self, key): 
#         """
#         Insert an element to the top of the stack
#         """
#
#         self.top = Node(key, self.top)
#
#
#     def pop(self) -> Any:
#         """
#         Removes and returns the top element from the stack or raises an 
#         error if stack is empty
#         """
#
#         if not self.top:
#             raise IndexError("Stack be empty brah")
#         val = self.top.key 
#         self.top = self.top.next
#         return val 
#
#
#     def peek(self) -> Optional[Any]:
#         """
#         Returns none if stack is empty or the top of the stack
#         """
#
#         if not self.top:
#             return None 
#         return self.top.key
#
#
#     def print_stack(self) -> None:
#         """
#         Prints the stack
#         """
#
#         top = self.top 
#         while top != None:
#             print(top.key)
#             top = top.next 
#
# s = Stack()
#
# s.push(1)
# s.push(2)
# s.push(3)
# s.push(4)
# s.push(5)
#
# s.print_stack()
#
# print(s.peek())
#
# print(s.pop())
#
#
#
#
#
#
#
#
#
#
#
#
#
#
#
