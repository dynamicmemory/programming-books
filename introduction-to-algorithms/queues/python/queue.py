from typing import Optional, Any

class Node:

    def __init__(self, key, next = None, prev = None) -> None:
        """
        Constructor for the Node 
        """

        self.key = key 
        self.next = next 
        self.prev = prev 

class queue:

    def __init__(self) -> None:
        """ 
        Constructor for the Node 
        """

        self.head = None 
        self.tail = None 

   
    def dequeue(self) -> Optional[Any]:
        """
        Remove the element in the front of the queue and return it or None if 
        the queue is empty 
        """

        if not self.head:
            raise IndexError("Queue is empty")

        val = self.head 
        self.head = self.head.next 
        return val 


    def enqueue(self, key) -> None:
        
        if not self.head:
            self.head = Node(key, None, None)
            self.tail = self.head
        else: 
            temp = Node(key, None, self.tail)
            self.tail.next = temp 
            self.tail = temp 


    def print_queue(self) -> None:

        p = self.head 
        while p != None:
            print(p.key)
            p = p.next

q = queue()

q.enqueue(1)
q.enqueue(2)
q.enqueue(3)
q.enqueue(4)
q.enqueue(5)
q.enqueue(6)
q.enqueue(7)
q.enqueue(8)
q.enqueue(9)
q.enqueue(10)

q.print_queue()

q.dequeue()

q.print_queue()

q.dequeue()
q.dequeue()
q.dequeue()
q.dequeue()
q.dequeue()
q.dequeue()
q.dequeue()
q.dequeue()
q.dequeue()
q.dequeue()














  
# from typing import Optional, Any
#
# class Node:
#
#     def __init__(self, key, next = None, prev = None) -> None:
#         """
#         Constructor for the Node 
#         """
#
#         self.key = key 
#         self.next = next 
#         self.prev = prev 
#
# class queue:
#
#     def __init__(self) -> None:
#         """ 
#         Constructor for the Node 
#         """
#
#         self.head = None 
#         self.tail = None 
#
#
#     def dequeue(self) -> Optional[Any]:
#         """
#         Remove the element in the front of the queue and return it or None if 
#         the queue is empty 
#         """
#
#         if not self.head:
#             raise IndexError("Queue is empty")
#
#         val = self.head 
#         self.head = self.head.next 
#         return val 
#
#
#     def enqueue(self, key) -> None:
#
#         if not self.head:
#             self.head = Node(key, None, None)
#             self.tail = self.head
#         else: 
#             temp = Node(key, None, self.tail)
#             self.tail.next = temp 
#             self.tail = temp 
#
#
#     def print_queue(self) -> None:
#
#         p = self.head 
#         while p != None:
#             print(p.key)
#             p = p.next
#
# q = queue()
#
# q.enqueue(1)
# q.enqueue(2)
# q.enqueue(3)
# q.enqueue(4)
# q.enqueue(5)
# q.enqueue(6)
# q.enqueue(7)
# q.enqueue(8)
# q.enqueue(9)
# q.enqueue(10)
#
# q.print_queue()
#
# q.dequeue()
#
# q.print_queue()
#
# q.dequeue()
# q.dequeue()
# q.dequeue()
# q.dequeue()
# q.dequeue()
# q.dequeue()
# q.dequeue()
# q.dequeue()
# q.dequeue()
# q.dequeue()
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
#     def __init__(self, key, next = None, prev = None) -> None:
#         """
#         Constructor for the Node 
#         """
#
#         self.key = key 
#         self.next = next 
#         self.prev = prev 
#
# class queue:
#
#     def __init__(self) -> None:
#         """ 
#         Constructor for the Node 
#         """
#
#         self.head = None 
#         self.tail = None 
#
#
#     def dequeue(self) -> Optional[Any]:
#         """
#         Remove the element in the front of the queue and return it or None if 
#         the queue is empty 
#         """
#
#         if not self.head:
#             raise IndexError("Queue is empty")
#
#         val = self.head 
#         self.head = self.head.next 
#         return val 
#
#
#     def enqueue(self, key) -> None:
#
#         if not self.head:
#             self.head = Node(key, None, None)
#             self.tail = self.head
#         else: 
#             temp = Node(key, None, self.tail)
#             self.tail.next = temp 
#             self.tail = temp 
#
#
#     def print_queue(self) -> None:
#
#         p = self.head 
#         while p != None:
#             print(p.key)
#             p = p.next
#
# q = queue()
#
# q.enqueue(1)
# q.enqueue(2)
# q.enqueue(3)
# q.enqueue(4)
# q.enqueue(5)
# q.enqueue(6)
# q.enqueue(7)
# q.enqueue(8)
# q.enqueue(9)
# q.enqueue(10)
#
# q.print_queue()
#
# q.dequeue()
#
# q.print_queue()
#
# q.dequeue()
# q.dequeue()
# q.dequeue()
# q.dequeue()
# q.dequeue()
# q.dequeue()
# q.dequeue()
# q.dequeue()
# q.dequeue()
# q.dequeue()
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
#     def __init__(self, key, next = None, prev = None) -> None:
#         """
#         Constructor for the Node 
#         """
#
#         self.key = key 
#         self.next = next 
#         self.prev = prev 
#
# class queue:
#
#     def __init__(self) -> None:
#         """ 
#         Constructor for the Node 
#         """
#
#         self.head = None 
#         self.tail = None 
#
#
#     def dequeue(self) -> Optional[Any]:
#         """
#         Remove the element in the front of the queue and return it or None if 
#         the queue is empty 
#         """
#
#         if not self.head:
#             raise IndexError("Queue is empty")
#
#         val = self.head 
#         self.head = self.head.next 
#         return val 
#
#
#     def enqueue(self, key) -> None:
#
#         if not self.head:
#             self.head = Node(key, None, None)
#             self.tail = self.head
#         else: 
#             temp = Node(key, None, self.tail)
#             self.tail.next = temp 
#             self.tail = temp 
#
#
#     def print_queue(self) -> None:
#
#         p = self.head 
#         while p != None:
#             print(p.key)
#             p = p.next
#
# q = queue()
#
# q.enqueue(1)
# q.enqueue(2)
# q.enqueue(3)
# q.enqueue(4)
# q.enqueue(5)
# q.enqueue(6)
# q.enqueue(7)
# q.enqueue(8)
# q.enqueue(9)
# q.enqueue(10)
#
# q.print_queue()
#
# q.dequeue()
#
# q.print_queue()
#
# q.dequeue()
# q.dequeue()
# q.dequeue()
# q.dequeue()
# q.dequeue()
# q.dequeue()
# q.dequeue()
# q.dequeue()
# q.dequeue()
# q.dequeue()
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
#     def __init__(self, key, next = None, prev = None) -> None:
#         """
#         Constructor for the Node 
#         """
#
#         self.key = key 
#         self.next = next 
#         self.prev = prev 
#
# class queue:
#
#     def __init__(self) -> None:
#         """ 
#         Constructor for the Node 
#         """
#
#         self.head = None 
#         self.tail = None 
#
#
#     def dequeue(self) -> Optional[Any]:
#         """
#         Remove the element in the front of the queue and return it or None if 
#         the queue is empty 
#         """
#
#         if not self.head:
#             raise IndexError("Queue is empty")
#
#         val = self.head 
#         self.head = self.head.next 
#         return val 
#
#
#     def enqueue(self, key) -> None:
#
#         if not self.head:
#             self.head = Node(key, None, None)
#             self.tail = self.head
#         else: 
#             temp = Node(key, None, self.tail)
#             self.tail.next = temp 
#             self.tail = temp 
#
#
#     def print_queue(self) -> None:
#
#         p = self.head 
#         while p != None:
#             print(p.key)
#             p = p.next
#
# q = queue()
#
# q.enqueue(1)
# q.enqueue(2)
# q.enqueue(3)
# q.enqueue(4)
# q.enqueue(5)
# q.enqueue(6)
# q.enqueue(7)
# q.enqueue(8)
# q.enqueue(9)
# q.enqueue(10)
#
# q.print_queue()
#
# q.dequeue()
#
# q.print_queue()
#
# q.dequeue()
# q.dequeue()
# q.dequeue()
# q.dequeue()
# q.dequeue()
# q.dequeue()
# q.dequeue()
# q.dequeue()
# q.dequeue()
# q.dequeue()
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
#     def __init__(self, key, next = None, prev = None) -> None:
#         """
#         Constructor for the Node 
#         """
#
#         self.key = key 
#         self.next = next 
#         self.prev = prev 
#
# class queue:
#
#     def __init__(self) -> None:
#         """ 
#         Constructor for the Node 
#         """
#
#         self.head = None 
#         self.tail = None 
#
#
#     def dequeue(self) -> Optional[Any]:
#         """
#         Remove the element in the front of the queue and return it or None if 
#         the queue is empty 
#         """
#
#         if not self.head:
#             raise IndexError("Queue is empty")
#
#         val = self.head 
#         self.head = self.head.next 
#         return val 
#
#
#     def enqueue(self, key) -> None:
#
#         if not self.head:
#             self.head = Node(key, None, None)
#             self.tail = self.head
#         else: 
#             temp = Node(key, None, self.tail)
#             self.tail.next = temp 
#             self.tail = temp 
#
#
#     def print_queue(self) -> None:
#
#         p = self.head 
#         while p != None:
#             print(p.key)
#             p = p.next
#
# q = queue()
#
# q.enqueue(1)
# q.enqueue(2)
# q.enqueue(3)
# q.enqueue(4)
# q.enqueue(5)
# q.enqueue(6)
# q.enqueue(7)
# q.enqueue(8)
# q.enqueue(9)
# q.enqueue(10)
#
# q.print_queue()
#
# q.dequeue()
#
# q.print_queue()
#
# q.dequeue()
# q.dequeue()
# q.dequeue()
# q.dequeue()
# q.dequeue()
# q.dequeue()
# q.dequeue()
# q.dequeue()
# q.dequeue()
# q.dequeue()
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
#     def __init__(self, key, next = None, prev = None) -> None:
#         """
#         Constructor for the Node 
#         """
#
#         self.key = key 
#         self.next = next 
#         self.prev = prev 
#
# class queue:
#
#     def __init__(self) -> None:
#         """ 
#         Constructor for the Node 
#         """
#
#         self.head = None 
#         self.tail = None 
#
#
#     def dequeue(self) -> Optional[Any]:
#         """
#         Remove the element in the front of the queue and return it or None if 
#         the queue is empty 
#         """
#
#         if not self.head:
#             raise IndexError("Queue is empty")
#
#         val = self.head 
#         self.head = self.head.next 
#         return val 
#
#
#     def enqueue(self, key) -> None:
#
#         if not self.head:
#             self.head = Node(key, None, None)
#             self.tail = self.head
#         else: 
#             temp = Node(key, None, self.tail)
#             self.tail.next = temp 
#             self.tail = temp 
#
#
#     def print_queue(self) -> None:
#
#         p = self.head 
#         while p != None:
#             print(p.key)
#             p = p.next
#
# q = queue()
#
# q.enqueue(1)
# q.enqueue(2)
# q.enqueue(3)
# q.enqueue(4)
# q.enqueue(5)
# q.enqueue(6)
# q.enqueue(7)
# q.enqueue(8)
# q.enqueue(9)
# q.enqueue(10)
#
# q.print_queue()
#
# q.dequeue()
#
# q.print_queue()
#
# q.dequeue()
# q.dequeue()
# q.dequeue()
# q.dequeue()
# q.dequeue()
# q.dequeue()
# q.dequeue()
# q.dequeue()
# q.dequeue()
# q.dequeue()
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
#     def __init__(self, key, next = None, prev = None) -> None:
#         """
#         Constructor for the Node 
#         """
#
#         self.key = key 
#         self.next = next 
#         self.prev = prev 
#
# class queue:
#
#     def __init__(self) -> None:
#         """ 
#         Constructor for the Node 
#         """
#
#         self.head = None 
#         self.tail = None 
#
#
#     def dequeue(self) -> Optional[Any]:
#         """
#         Remove the element in the front of the queue and return it or None if 
#         the queue is empty 
#         """
#
#         if not self.head:
#             raise IndexError("Queue is empty")
#
#         val = self.head 
#         self.head = self.head.next 
#         return val 
#
#
#     def enqueue(self, key) -> None:
#
#         if not self.head:
#             self.head = Node(key, None, None)
#             self.tail = self.head
#         else: 
#             temp = Node(key, None, self.tail)
#             self.tail.next = temp 
#             self.tail = temp 
#
#
#     def print_queue(self) -> None:
#
#         p = self.head 
#         while p != None:
#             print(p.key)
#             p = p.next
#
# q = queue()
#
# q.enqueue(1)
# q.enqueue(2)
# q.enqueue(3)
# q.enqueue(4)
# q.enqueue(5)
# q.enqueue(6)
# q.enqueue(7)
# q.enqueue(8)
# q.enqueue(9)
# q.enqueue(10)
#
# q.print_queue()
#
# q.dequeue()
#
# q.print_queue()
#
# q.dequeue()
# q.dequeue()
# q.dequeue()
# q.dequeue()
# q.dequeue()
# q.dequeue()
# q.dequeue()
# q.dequeue()
# q.dequeue()
# q.dequeue()
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
#     def __init__(self, key, next = None, prev = None) -> None:
#         """
#         Constructor for the Node 
#         """
#
#         self.key = key 
#         self.next = next 
#         self.prev = prev 
#
# class queue:
#
#     def __init__(self) -> None:
#         """ 
#         Constructor for the Node 
#         """
#
#         self.head = None 
#         self.tail = None 
#
#
#     def dequeue(self) -> Optional[Any]:
#         """
#         Remove the element in the front of the queue and return it or None if 
#         the queue is empty 
#         """
#
#         if not self.head:
#             raise IndexError("Queue is empty")
#
#         val = self.head 
#         self.head = self.head.next 
#         return val 
#
#
#     def enqueue(self, key) -> None:
#
#         if not self.head:
#             self.head = Node(key, None, None)
#             self.tail = self.head
#         else: 
#             temp = Node(key, None, self.tail)
#             self.tail.next = temp 
#             self.tail = temp 
#
#
#     def print_queue(self) -> None:
#
#         p = self.head 
#         while p != None:
#             print(p.key)
#             p = p.next
#
# q = queue()
#
# q.enqueue(1)
# q.enqueue(2)
# q.enqueue(3)
# q.enqueue(4)
# q.enqueue(5)
# q.enqueue(6)
# q.enqueue(7)
# q.enqueue(8)
# q.enqueue(9)
# q.enqueue(10)
#
# q.print_queue()
#
# q.dequeue()
#
# q.print_queue()
#
# q.dequeue()
# q.dequeue()
# q.dequeue()
# q.dequeue()
# q.dequeue()
# q.dequeue()
# q.dequeue()
# q.dequeue()
# q.dequeue()
# q.dequeue()
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
#     def __init__(self, key, next = None, prev = None) -> None:
#         """
#         Constructor for the Node 
#         """
#
#         self.key = key 
#         self.next = next 
#         self.prev = prev 
#
# class queue:
#
#     def __init__(self) -> None:
#         """ 
#         Constructor for the Node 
#         """
#
#         self.head = None 
#         self.tail = None 
#
#
#     def dequeue(self) -> Optional[Any]:
#         """
#         Remove the element in the front of the queue and return it or None if 
#         the queue is empty 
#         """
#
#         if not self.head:
#             raise IndexError("Queue is empty")
#
#         val = self.head 
#         self.head = self.head.next 
#         return val 
#
#
#     def enqueue(self, key) -> None:
#
#         if not self.head:
#             self.head = Node(key, None, None)
#             self.tail = self.head
#         else: 
#             temp = Node(key, None, self.tail)
#             self.tail.next = temp 
#             self.tail = temp 
#
#
#     def print_queue(self) -> None:
#
#         p = self.head 
#         while p != None:
#             print(p.key)
#             p = p.next
#
# q = queue()
#
# q.enqueue(1)
# q.enqueue(2)
# q.enqueue(3)
# q.enqueue(4)
# q.enqueue(5)
# q.enqueue(6)
# q.enqueue(7)
# q.enqueue(8)
# q.enqueue(9)
# q.enqueue(10)
#
# q.print_queue()
#
# q.dequeue()
#
# q.print_queue()
#
# q.dequeue()
# q.dequeue()
# q.dequeue()
# q.dequeue()
# q.dequeue()
# q.dequeue()
# q.dequeue()
# q.dequeue()
# q.dequeue()
# q.dequeue()
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
#     def __init__(self, key, next = None, prev = None) -> None:
#         """
#         Constructor for the Node 
#         """
#
#         self.key = key 
#         self.next = next 
#         self.prev = prev 
#
# class queue:
#
#     def __init__(self) -> None:
#         """ 
#         Constructor for the Node 
#         """
#
#         self.head = None 
#         self.tail = None 
#
#
#     def dequeue(self) -> Optional[Any]:
#         """
#         Remove the element in the front of the queue and return it or None if 
#         the queue is empty 
#         """
#
#         if not self.head:
#             raise IndexError("Queue is empty")
#
#         val = self.head 
#         self.head = self.head.next 
#         return val 
#
#
#     def enqueue(self, key) -> None:
#
#         if not self.head:
#             self.head = Node(key, None, None)
#             self.tail = self.head
#         else: 
#             temp = Node(key, None, self.tail)
#             self.tail.next = temp 
#             self.tail = temp 
#
#
#     def print_queue(self) -> None:
#
#         p = self.head 
#         while p != None:
#             print(p.key)
#             p = p.next
#
# q = queue()
#
# q.enqueue(1)
# q.enqueue(2)
# q.enqueue(3)
# q.enqueue(4)
# q.enqueue(5)
# q.enqueue(6)
# q.enqueue(7)
# q.enqueue(8)
# q.enqueue(9)
# q.enqueue(10)
#
# q.print_queue()
#
# q.dequeue()
#
# q.print_queue()
#
# q.dequeue()
# q.dequeue()
# q.dequeue()
# q.dequeue()
# q.dequeue()
# q.dequeue()
# q.dequeue()
# q.dequeue()
# q.dequeue()
# q.dequeue()
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
#     def __init__(self, key, next = None, prev = None) -> None:
#         """
#         Constructor for the Node 
#         """
#
#         self.key = key 
#         self.next = next 
#         self.prev = prev 
#
# class queue:
#
#     def __init__(self) -> None:
#         """ 
#         Constructor for the Node 
#         """
#
#         self.head = None 
#         self.tail = None 
#
#
#     def dequeue(self) -> Optional[Any]:
#         """
#         Remove the element in the front of the queue and return it or None if 
#         the queue is empty 
#         """
#
#         if not self.head:
#             raise IndexError("Queue is empty")
#
#         val = self.head 
#         self.head = self.head.next 
#         return val 
#
#
#     def enqueue(self, key) -> None:
#
#         if not self.head:
#             self.head = Node(key, None, None)
#             self.tail = self.head
#         else: 
#             temp = Node(key, None, self.tail)
#             self.tail.next = temp 
#             self.tail = temp 
#
#
#     def print_queue(self) -> None:
#
#         p = self.head 
#         while p != None:
#             print(p.key)
#             p = p.next
#
# q = queue()
#
# q.enqueue(1)
# q.enqueue(2)
# q.enqueue(3)
# q.enqueue(4)
# q.enqueue(5)
# q.enqueue(6)
# q.enqueue(7)
# q.enqueue(8)
# q.enqueue(9)
# q.enqueue(10)
#
# q.print_queue()
#
# q.dequeue()
#
# q.print_queue()
#
# q.dequeue()
# q.dequeue()
# q.dequeue()
# q.dequeue()
# q.dequeue()
# q.dequeue()
# q.dequeue()
# q.dequeue()
# q.dequeue()
# q.dequeue()
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
#     def __init__(self, key, next = None, prev = None) -> None:
#         """
#         Constructor for the Node 
#         """
#
#         self.key = key 
#         self.next = next 
#         self.prev = prev 
#
# class queue:
#
#     def __init__(self) -> None:
#         """ 
#         Constructor for the Node 
#         """
#
#         self.head = None 
#         self.tail = None 
#
#
#     def dequeue(self) -> Optional[Any]:
#         """
#         Remove the element in the front of the queue and return it or None if 
#         the queue is empty 
#         """
#
#         if not self.head:
#             raise IndexError("Queue is empty")
#
#         val = self.head 
#         self.head = self.head.next 
#         return val 
#
#
#     def enqueue(self, key) -> None:
#
#         if not self.head:
#             self.head = Node(key, None, None)
#             self.tail = self.head
#         else: 
#             temp = Node(key, None, self.tail)
#             self.tail.next = temp 
#             self.tail = temp 
#
#
#     def print_queue(self) -> None:
#
#         p = self.head 
#         while p != None:
#             print(p.key)
#             p = p.next
#
# q = queue()
#
# q.enqueue(1)
# q.enqueue(2)
# q.enqueue(3)
# q.enqueue(4)
# q.enqueue(5)
# q.enqueue(6)
# q.enqueue(7)
# q.enqueue(8)
# q.enqueue(9)
# q.enqueue(10)
#
# q.print_queue()
#
# q.dequeue()
#
# q.print_queue()
#
# q.dequeue()
# q.dequeue()
# q.dequeue()
# q.dequeue()
# q.dequeue()
# q.dequeue()
# q.dequeue()
# q.dequeue()
# q.dequeue()
# q.dequeue()
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
#     def __init__(self, key, next = None, prev = None) -> None:
#         """
#         Constructor for the Node 
#         """
#
#         self.key = key 
#         self.next = next 
#         self.prev = prev 
#
# class queue:
#
#     def __init__(self) -> None:
#         """ 
#         Constructor for the Node 
#         """
#
#         self.head = None 
#         self.tail = None 
#
#
#     def dequeue(self) -> Optional[Any]:
#         """
#         Remove the element in the front of the queue and return it or None if 
#         the queue is empty 
#         """
#
#         if not self.head:
#             raise IndexError("Queue is empty")
#
#         val = self.head 
#         self.head = self.head.next 
#         return val 
#
#
#     def enqueue(self, key) -> None:
#
#         if not self.head:
#             self.head = Node(key, None, None)
#             self.tail = self.head
#         else: 
#             temp = Node(key, None, self.tail)
#             self.tail.next = temp 
#             self.tail = temp 
#
#
#     def print_queue(self) -> None:
#
#         p = self.head 
#         while p != None:
#             print(p.key)
#             p = p.next
#
# q = queue()
#
# q.enqueue(1)
# q.enqueue(2)
# q.enqueue(3)
# q.enqueue(4)
# q.enqueue(5)
# q.enqueue(6)
# q.enqueue(7)
# q.enqueue(8)
# q.enqueue(9)
# q.enqueue(10)
#
# q.print_queue()
#
# q.dequeue()
#
# q.print_queue()
#
# q.dequeue()
# q.dequeue()
# q.dequeue()
# q.dequeue()
# q.dequeue()
# q.dequeue()
# q.dequeue()
# q.dequeue()
# q.dequeue()
# q.dequeue()
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
